//
// Created by DELL on 31/12/2021.
//

#include "UnionFind.h"

#include <cassert>

const int UnionFind::SIZE_FACTOR = 1;

UnionFind::UnionFind(int n): num_of_disjoint_groups(n), elements_arr(nullptr)
{
    elements_arr = new UnionFindNode*[n + SIZE_FACTOR]; // dont forget number 0 !!!!!!!!!!!!!!!!
    for (int i = SIZE_FACTOR; i < this->num_of_disjoint_groups + SIZE_FACTOR; i++)
    {
        elements_arr[i] = new UnionFindNode(i, true);
    }
}

UnionFind::~UnionFind()
{
    for (int i = SIZE_FACTOR; i < this->num_of_disjoint_groups + SIZE_FACTOR; i++)
    {
        delete elements_arr[i];
    }
    delete[] elements_arr;
}

int UnionFind::find(int group_id)
{
    UnionFindNode* current_node = elements_arr[group_id];
    while (!(current_node->isRoot()))
    {
        assert(current_node->getNodeParent() != nullptr);
        current_node = current_node->getNodeParent();
    }
    UnionFindNode* group_root = current_node;
    current_node = elements_arr[group_id];
    UnionFindNode* previous_node = current_node;
    while (current_node != group_root)
    {
        current_node = current_node->getNodeParent();
        previous_node->setNodeParent(group_root);
        previous_node = current_node; // operator = between pointers
    }
    return current_node->getNodeKey();
}

void UnionFind::setNewGroupToPlayer(Node* current_node, int group_id)
{
    if (current_node == nullptr)
    {
        return;
    }
    setNewGroupToPlayer(current_node->getNodeLeftSon(), group_id);
    LevelNode* level_node = dynamic_cast<LevelNode*>(current_node);
    level_node->getPlayerInstance()->setGroupId(group_id);
    setNewGroupToPlayer(current_node->getNodeRightSon(), group_id);
}

void UnionFind::replaceGroup(int smaller_group_id, int bigger_group_id)
{
    // step 1: get the UnionFindNodes with smaller_group_id and bigger_group_id - complexity: O(1)
    UnionFindNode* smaller_root = elements_arr[smaller_group_id];
    UnionFindNode* bigger_root = elements_arr[bigger_group_id];

    // step 2: update the group of the players in the rank tree of the smaller group to the group
    // id of the bigger group - complexity O(n_smaller_group)
    //setNewGroupToPlayer(smaller_root->getNodeTree()->getRoot(), bigger_group_id); // need to implement new code

    // step 3: merge the two trees and enter the result into the merged_tree - complexity
    // O(n_smaller_group+ n_bigger_group)
    RankTree* merged_tree = smaller_root->getNodeTree()->mergeRankTrees(smaller_root->getNodeTree(),
                                                                    bigger_root->getNodeTree());

    // step 4: remove previous rank trees inside smaller_root and bigger_root
    delete smaller_root->getNodeTree();
    smaller_root->setNodeTree(nullptr);
    delete bigger_root->getNodeTree();
    bigger_root->setNodeTree(merged_tree);
}

UnionFindNode *UnionFind::unite(int group1, int group2)
{
    int group1_root_id = find(group1);
    int group2_root_id = find(group2);
    UnionFindNode* group1_root = elements_arr[group1_root_id];
    UnionFindNode* group2_root = elements_arr[group2_root_id];
    if (group1_root_id == group2_root_id)
    {
        return group1_root; // maybe better to return num of group instead?
    }

    UnionFindNode* smaller_root;
    UnionFindNode* bigger_root;
    int smaller_root_id;
    int bigger_root_id;

    if (*group1_root < *group2_root)
    {
        smaller_root_id = group1_root_id;
        bigger_root_id = group2_root_id;
        smaller_root = group1_root;
        bigger_root = group2_root;
    }
    /*else if (*group1_root == *group2_root)
    {
        if (group1_root_id < group2_root_id)
        {
            smaller_root_id = group1_root_id;
            bigger_root_id = group2_root_id;
            smaller_root = group1_root;
            bigger_root = group2_root;
        }
        else
        {
            smaller_root_id = group2_root_id;
            bigger_root_id = group1_root_id;
            smaller_root = group2_root;
            bigger_root = group1_root;
        }
    }*/
    else
    {
        smaller_root_id = group2_root_id;
        bigger_root_id = group1_root_id;
        smaller_root = group2_root;
        bigger_root = group1_root;
    }

    replaceGroup(smaller_root_id, bigger_root_id);
    smaller_root->setNodeParent(bigger_root);
    smaller_root->setIsRoot(false);
    bigger_root->setNodeNumOfDescendants(smaller_root->getNodeNumOfDescendants() +
                                                 bigger_root->getNodeNumOfDescendants() + SIZE_FACTOR);
    return bigger_root;
}

UnionFindNode **UnionFind::getElementsArr()
{
    return this->elements_arr;
}




