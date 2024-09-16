#ifndef WET2_HASHTABLE_H
#define WET2_HASHTABLE_H

#include "Node.h"
#include "HashTableExceptions.h"

class HashTable {
private:
    static const int START_SIZE;
    static const double MAX_LOAD_FACTOR;
    static const double MIN_LOAD_FACTOR;
    static const int EXTEND_FACTOR;

    Node** table;
    int table_size;
    int num_of_nodes;
    double load_factor;

    void updateLoadFactor();
    void copyTable(Node** other_table);
    void extendTable();
    void shrinkTable();
    void destroyTable();
public:
    HashTable();
    HashTable(HashTable& other);
    HashTable& operator=(const HashTable& other);
    ~HashTable();
    int hash(int id) const;
    void insert(Node* node_to_insert);
    void remove(Node* node_to_remove);
    Node* find(Node* node_to_find);
    int getTableSize() const;
    Node* getFirstNodeInCell(int index);
};

#endif //WET2_HASHTABLE_H
