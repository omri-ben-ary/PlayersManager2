#include "HashTable.h"

const int HashTable::START_SIZE = 5;
const double HashTable::MAX_LOAD_FACTOR = 0.75;
const int HashTable::EXTEND_FACTOR = 2;
const double HashTable::MIN_LOAD_FACTOR = MAX_LOAD_FACTOR/((2*EXTEND_FACTOR));


HashTable::HashTable(): table(new Node*[START_SIZE]()), table_size(START_SIZE), num_of_nodes(0), load_factor(0) {

}

HashTable::HashTable(HashTable &other): table(new Node*[other.table_size]()), table_size(other.table_size),
                                        num_of_nodes(other.num_of_nodes), load_factor(other.load_factor) {
    copyTable(other.table);
}

HashTable &HashTable::operator=(const HashTable &other) {
    if(&other == this)
    {
        return *this;
    }
    destroyTable();
    table_size = other.table_size;
    num_of_nodes = other.num_of_nodes;
    load_factor = other.load_factor;
    table = new Node*[other.table_size]();
    copyTable(other.table);
    return *this;
}

void HashTable::copyTable(Node** other_table) {
    for(int i = 0; i < table_size; i++)
    {
        Node* itr_other = other_table[i];
        if(itr_other != nullptr)
        {
            table[i] = itr_other->clone();
            Node* itr_this = table[i];
            itr_other = itr_other->getNodeLeftSon();

            while(itr_other != nullptr)
            {
                Node* next = itr_other->clone();
                itr_this->setNodeLeftSon(next);
                next->setNodeParent(itr_this);
                itr_this = next;
                itr_other = itr_other->getNodeLeftSon();
            }
        } else
        {
            table[i] = nullptr;
        }
    }
}

void HashTable::destroyTable() {
    for(int i = 0; i< table_size; i++)
    {
        Node* itr = table[i];
        while(itr != nullptr)
        {
            Node* temp = itr->getNodeLeftSon();
            delete itr;
            itr = temp;
        }
    }
    delete[] table;
}

HashTable::~HashTable() {
    destroyTable();
}

int HashTable::hash(int id) const {
    return id % table_size;
}

void HashTable::insert(Node *node_to_insert) {
    if(find(node_to_insert) != nullptr)
    {
        throw HashTableKeyIsAlreadyTaken();
    }
    Node* new_node = node_to_insert->clone();
    int index = hash(new_node->getNodeKey());
    new_node->setNodeLeftSon(table[index]);
    new_node->setNodeParent(nullptr);
    if(table[index] != nullptr)
    {
        table[index]->setNodeParent(new_node);
    }
    table[index] = new_node;
    num_of_nodes++;
    updateLoadFactor();
    if(load_factor > MAX_LOAD_FACTOR)
    {
        extendTable();
    }
}

void HashTable::updateLoadFactor() {
    load_factor = double(num_of_nodes)/table_size;
}

void HashTable::extendTable() {
    Node** new_table = new Node*[table_size*EXTEND_FACTOR]();
    int old_size = table_size;
    table_size *= EXTEND_FACTOR;
    for(int i = 0; i < old_size; i++)
    {
        Node* itr = table[i];
        while(itr != nullptr)
        {
            int new_index = hash(itr->getNodeKey());
            Node* new_node = itr->clone();
            new_node->setNodeLeftSon(new_table[new_index]);
            new_node->setNodeParent(nullptr);
            if(new_table[new_index] != nullptr)
            {
                new_table[new_index]->setNodeParent(new_node);
            }
            new_table[new_index] = new_node;
            itr = itr->getNodeLeftSon();
        }
    }
    updateLoadFactor();
    table_size = old_size;
    destroyTable();
    table_size *= EXTEND_FACTOR;
    table = new_table;
}

void HashTable::remove(Node *node_to_remove) {
    if(find(node_to_remove) == nullptr)
    {
        throw HashTableNodeDoesNotExist();
    }
    int index = hash(node_to_remove->getNodeKey());
    Node* itr = table[index];
    while(itr != nullptr && itr->getNodeKey() != node_to_remove->getNodeKey())
    {
        itr = itr->getNodeLeftSon();
    }
    if(itr != nullptr)
    {
        Node* parent = itr->getNodeParent();
        Node* son = itr->getNodeLeftSon();
        if(parent == nullptr)
        {
            table[index] = son;
        }
        else{
            parent->setNodeLeftSon(son);
        }
        if(son != nullptr)
        {
            son->setNodeParent(parent);
        }
        delete itr;
        num_of_nodes--;
        updateLoadFactor();
        if(table_size != START_SIZE && load_factor < MIN_LOAD_FACTOR)
        {
            shrinkTable();
        }
    }
}

void HashTable::shrinkTable() {
    Node** new_table = new Node*[table_size/EXTEND_FACTOR]();
    int old_size = table_size;
    table_size /= EXTEND_FACTOR;
    for(int i = 0; i < old_size; i++)
    {
        Node* itr = table[i];
        while(itr != nullptr)
        {
            int new_index = hash(itr->getNodeKey());
            Node* new_node = itr->clone();
            new_node->setNodeLeftSon(new_table[new_index]);
            new_node->setNodeParent(nullptr);
            if(new_table[new_index] != nullptr)
            {
                new_table[new_index]->setNodeParent(new_node);
            }
            new_table[new_index] = new_node;
            itr = itr->getNodeLeftSon();
        }
    }
    updateLoadFactor();
    table_size = old_size;
    destroyTable();
    table_size /= EXTEND_FACTOR;
    table = new_table;
}

Node* HashTable::find(Node *node_to_find) {
    int index = hash(node_to_find->getNodeKey());
    Node* itr = table[index];
    while(itr != nullptr)
    {
        if(itr->getNodeKey() == node_to_find->getNodeKey())
        {
            return itr;
        }
        itr = itr->getNodeLeftSon();
    }
    return nullptr;
}

int HashTable::getTableSize() const {
    return table_size;
}

Node *HashTable::getFirstNodeInCell(int index) {
    return table[index];
}

