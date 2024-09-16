//
// Created by DELL on 31/12/2021.
//

#ifndef WET2_UNIONFIND_H
#define WET2_UNIONFIND_H

#include "UnionFindNode.h"
#include "LevelNode.h"

class UnionFind
{
private:
    int num_of_disjoint_groups;
    UnionFindNode** elements_arr;
    static const int SIZE_FACTOR;
public:
    explicit UnionFind(int n);
    UnionFind(const UnionFind& other) = default; //?
    UnionFind& operator=(const UnionFind&) = default; //?
    ~UnionFind();
    int find(int group_id);
    UnionFindNode* unite(int group1, int group2);
    void replaceGroup(int smaller_group_id, int bigger_group_id);
    void setNewGroupToPlayer(Node *current_node, int group_id);
    UnionFindNode** getElementsArr();
};

#endif //WET2_UNIONFIND_H
