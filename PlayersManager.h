#ifndef WET2_PLAYERSMANAGER_H
#define WET2_PLAYERSMANAGER_H

#include "UnionFind.h"
#include "HashTable.h"
#include "LevelNode.h"
#include "PlayersManagerExceptions.h"

class PlayersManager
{
private:
    RankTree* all_players_tree;
    UnionFind* union_find_groups;
    HashTable* hash_table_of_players;
    int num_of_groups;
    int score_scale;
    void destroyPlayersInNodes();
    static const int INCREASE;
    static const int PERCENTAGE_FACTOR;

public:
    PlayersManager(int k, int scale);
    PlayersManager(const PlayersManager& other_manager) = default;
    PlayersManager& operator=(const PlayersManager& other_manager) = default;
    ~PlayersManager();
    void mergeGroups(int group1_id, int group2_id);
    void addPlayer(int player_id, int group_id, int score);
    void removePlayer(int player_id);
    void increasePlayerLevel(int player_id, int level_to_increase);
    void changePlayerIDScore(int player_id, int new_score);
    void getPercentOfPlayersWithScoreInBounds(int group_id, int score, int lower_level, int higher_level,
                                              double* players);
    void averageHighestPlayerLevelByGroup(int group_id, int m, double* avg_level);
    void getPlayersBound(int group_id, int score, int m, int* LowerBoundPlayers, int* HigherBoundPlayers);



    /*
    void setNewGroupToPlayer(Node* current_node, Group* player_group);
    void getGroupsLeadersAux(Node *current_node, int *players_arr, int *counter, int num_of_groups);
    static void destroyNode(Node *node_to_destroy);
    void destroyPlayersInNodes(Node* current_node);
    void destroyGroupsInNodes(Node *current_node);
     */

    static Node *createLevelNode(int player_id, int group_id, int score);
};


#endif //WET2_PLAYERSMANAGER_H
