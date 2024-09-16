#include "UnionFindNode.h"

const int UnionFindNode::DEFAULT_SIZE = 0;

UnionFindNode::UnionFindNode(int key, bool is_root) : key(key), is_root(is_root), parent(nullptr),
                                                      num_of_descendants(DEFAULT_SIZE), rank_tree(new RankTree()) {
}

UnionFindNode::~UnionFindNode()
{
    delete rank_tree;
}

int UnionFindNode::getNodeKey() const
{
    return this->key;
}

void UnionFindNode::setNodeKey(int new_key)
{
    this->key = new_key;
}

bool UnionFindNode::isRoot() const {
    return this->is_root;
}

void UnionFindNode::setIsRoot(bool is_root_result)
{
    this->is_root = is_root_result;
}

UnionFindNode *UnionFindNode::getNodeParent()
{
    return this->parent;
}

void UnionFindNode::setNodeParent(UnionFindNode* new_parent)
{
    this->parent = new_parent;
}

RankTree* UnionFindNode::getNodeTree()
{
    return this->rank_tree;
}

void UnionFindNode::setNodeTree(RankTree* new_tree)
{
    this->rank_tree = new_tree;
}

int UnionFindNode::getNodeNumOfDescendants() const
{
    return this->num_of_descendants;
}

void UnionFindNode::setNodeNumOfDescendants(int new_size)
{
    this->num_of_descendants = new_size;
}

bool UnionFindNode::operator<(const UnionFindNode &second_node) const
{
    return (this->num_of_descendants < second_node.num_of_descendants);
}

bool UnionFindNode::operator==(const UnionFindNode &second_node) const
{
    return (this->num_of_descendants == second_node.num_of_descendants);
}





