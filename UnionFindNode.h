#ifndef WET2_UnionFindNode_H
#define WET2_UnionFindNode_H

#include "RankTree.h"

class UnionFindNode {
private:
    int key;
    bool is_root;
    UnionFindNode* parent;
    int num_of_descendants;
    RankTree* rank_tree;
    static const int DEFAULT_SIZE;
public:
    UnionFindNode(int key, bool is_root);
    UnionFindNode(const UnionFindNode&) = default; // need to think about it
    UnionFindNode& operator=(const UnionFindNode&) = default; // need to think about it
    ~UnionFindNode(); // need to think about it
    bool operator<(const UnionFindNode& second_node) const;
    bool operator==(const UnionFindNode& second_node) const;
    int getNodeKey() const;
    void setNodeKey(int new_key);
    bool isRoot() const;
    void setIsRoot(bool is_root_result);
    UnionFindNode* getNodeParent();
    void setNodeParent(UnionFindNode* new_parent);
    int getNodeNumOfDescendants() const;
    void setNodeNumOfDescendants(int new_size);
    RankTree *getNodeTree();
    void setNodeTree(RankTree *new_tree);
};

#endif //WET2_UnionFindNode_H
