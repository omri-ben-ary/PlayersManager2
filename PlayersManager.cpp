#include "PlayersManager.h"
#include <cassert>
#include <climits>

const int PlayersManager::INCREASE = 1;
const int PlayersManager::PERCENTAGE_FACTOR = 100;

// complexity: O(1)
PlayersManager::PlayersManager(int k, int scale): all_players_tree(new RankTree()), union_find_groups(new UnionFind(k)),
hash_table_of_players(new HashTable()), num_of_groups(k), score_scale(scale)
{}

void PlayersManager::mergeGroups(int group1_id, int group2_id) // O(log*(k) + n_group1_players + n_group2_players)
{
    // step 1: input check - complexity: O(1)
    if ((group1_id <= 0) || (group2_id <= 0) || (group1_id > this->num_of_groups) || (group2_id > this->num_of_groups))
    {
        throw InvalidInput();
    }

    //step 2: unite two groups into one group - O(log*(k) + n_group1_players + n_group2_players)
    this->union_find_groups->unite(group1_id, group2_id);
}

Node* PlayersManager::createLevelNode(int player_id, int group_id, int score)
{
    return new LevelNode(player_id, score, group_id);
}

void PlayersManager::addPlayer(int player_id, int group_id, int score)
{
    // step 1: input check - complexity: O(1)
    if ((group_id <= 0) || (group_id > this->num_of_groups) || (player_id <= 0) || (score <= 0)
        || (score > this->score_scale))
    {
        throw InvalidInput();
    }

    // step 2 - create levelNode to insert later - complexity O(1)
    Node* tmp_level_node = createLevelNode(player_id, group_id, score);

    // step 3 - enter levelNode to hash table - complexity O(1) amortized
    try
    {
        this->hash_table_of_players->insert(tmp_level_node);
    }
    catch (HashTableKeyIsAlreadyTaken &e)
    {
        LevelNode* player_node_in_all_players_tree = dynamic_cast<LevelNode*>(tmp_level_node);
        Player* player_to_remove = player_node_in_all_players_tree->getPlayerInstance();
        delete tmp_level_node;
        delete player_to_remove;
        throw PlayerIDIsAlreadyTaken();
    }
    delete tmp_level_node;

    // step 5 - enter levelNode to zero-node - complexity O(1)
    this->all_players_tree->updateZeroHistogram(score, false);

    // step 6 - enter levelNode to zero-node - complexity O(log*(k))
    int root_of_group_id = this->union_find_groups->find(group_id);
    UnionFindNode** elements_Arr = union_find_groups->getElementsArr();
    assert(elements_Arr != nullptr);
    assert(elements_Arr[root_of_group_id] != nullptr);
    RankTree* rank_tree = elements_Arr[root_of_group_id]->getNodeTree();
    assert(rank_tree != nullptr);
    rank_tree->updateZeroHistogram(score, false);
}

void PlayersManager::removePlayer(int player_id)
{
    // step 1: input check - complexity: O(1)
    if (player_id <= 0)
    {
        throw InvalidInput();
    }

    // step 2 - create levelNode to find - complexity O(1)
    Node* tmp_level_node = createLevelNode(player_id, 0, 0);
    LevelNode* player_node_in_all_players_tree = dynamic_cast<LevelNode*>(tmp_level_node);

    // step 3 - find levelNode in hash table - complexity O(1) amortized
    Node* level_node_to_remove = this->hash_table_of_players->find(tmp_level_node);
    if (level_node_to_remove == nullptr)
    {
        Player* player_to_remove = player_node_in_all_players_tree->getPlayerInstance();
        delete tmp_level_node;
        delete player_to_remove;
        throw PlayerDoesNotExist();
    }

    // step 4 - get player instance out of level node - complexity O(1)
    LevelNode* casted_level_node_to_remove = dynamic_cast<LevelNode*>(level_node_to_remove);
    Player* player_instance_to_remove = casted_level_node_to_remove->getPlayerInstance();
    player_node_in_all_players_tree->getPlayerInstance()->setLevel(player_instance_to_remove->getLevel());

    // step 5 - remove levelNode from hash table - complexity O(1) amortized
    this->hash_table_of_players->remove(level_node_to_remove);

    // step 6 - remove levelNode from all players tree - complexity O(log(n))
    if (player_instance_to_remove->getLevel() == 0)
    {
        int score = player_instance_to_remove->getScore();
        this->all_players_tree->updateZeroHistogram(score, true); // complexity O(1)
    }
    else
    {
        this->all_players_tree->remove(tmp_level_node);
    }

    // step 7 - remove levelNode from Rank tree inside union find of groups - complexity O(log*(k) + log(n)) amortized
    int group_id = player_instance_to_remove->getGroupId();
    int root_of_group_id = this->union_find_groups->find(group_id);
    UnionFindNode** elements_Arr = union_find_groups->getElementsArr();
    assert(elements_Arr != nullptr);
    assert(elements_Arr[root_of_group_id] != nullptr);
    RankTree* rank_tree = elements_Arr[root_of_group_id]->getNodeTree();
    assert(rank_tree != nullptr);
    if (player_instance_to_remove->getLevel() == 0)
    {
        int score = player_instance_to_remove->getScore();
        rank_tree->updateZeroHistogram(score, true); // complexity O(1)
    }
    else
    {
        rank_tree->remove(tmp_level_node);
    }

    // step 8 - remove player instance - Complexity O(1)
    delete player_instance_to_remove;

    // step 9 - remove temp level node - complexity O(1)
    Player* player_to_remove = player_node_in_all_players_tree->getPlayerInstance();
    delete tmp_level_node;
    delete player_to_remove;

}

void PlayersManager::increasePlayerLevel(int player_id, int level_to_increase)
{
    // step 1: input check - complexity: O(1)
    if ((player_id <=0) || (level_to_increase <= 0))
    {
        throw InvalidInput();
    }

    // step 2 - create levelNode to find - complexity O(1)
    Node* tmp_level_node = createLevelNode(player_id, 0, 0);
    LevelNode* player_node_in_all_players_tree = dynamic_cast<LevelNode*>(tmp_level_node);

    // step 3 - find levelNode in hash table - complexity O(1) amortized
    Node* level_node_to_increase = this->hash_table_of_players->find(tmp_level_node);
    if (level_node_to_increase == nullptr)
    {
        Player* player_to_remove = player_node_in_all_players_tree->getPlayerInstance();
        delete tmp_level_node;
        delete player_to_remove;
        throw PlayerDoesNotExist();
    }

    // step 4 - get player instance out of level node - complexity O(1)
    LevelNode* casted_level_node_to_increase = dynamic_cast<LevelNode*>(level_node_to_increase);
    Player* player_instance_to_increase = casted_level_node_to_increase->getPlayerInstance();

    // step 5- increase level
    // step 5a - save variables - Complexity O(1)
    int level = player_instance_to_increase->getLevel();
    int score = player_instance_to_increase->getScore();
    int group_id = player_instance_to_increase->getGroupId();
    player_node_in_all_players_tree->getPlayerInstance()->setLevel(level);


    // step 5b - taking care of the scenario where the previous level was 0
    if (level == 0)
    {
        // Complexity O(1)
        player_instance_to_increase->setLevel(level_to_increase + level);
        Node* tmp_level_node_2 = dynamic_cast<Node*> (new LevelNode(player_id, player_instance_to_increase));
        // Complexity O(log(n))
        this->all_players_tree->insert(tmp_level_node_2);

        // Complexity O(log*(k) + log(n)) amortized
        int root_of_group_id = this->union_find_groups->find(group_id);
        UnionFindNode** elements_Arr = union_find_groups->getElementsArr();
        assert(elements_Arr != nullptr);
        assert(elements_Arr[root_of_group_id] != nullptr);
        RankTree* rank_tree = elements_Arr[root_of_group_id]->getNodeTree();
        assert(rank_tree != nullptr);
        rank_tree->insert(tmp_level_node_2);

        // Complexity O(1)
        this->all_players_tree->updateZeroHistogram(score, true);
        rank_tree->updateZeroHistogram(score, true);
        delete tmp_level_node_2;
    }
    // step 5c - taking care of the scenario where the previous level wasn't 0
    else
    {
        // Complexity O(log(n))
        this->all_players_tree->remove(tmp_level_node);

        // Complexity O(log*(k) + log(n)) amortized
        int root_of_group_id = this->union_find_groups->find(group_id);
        UnionFindNode** elements_Arr = union_find_groups->getElementsArr();
        assert(elements_Arr != nullptr);
        assert(elements_Arr[root_of_group_id] != nullptr);
        RankTree* rank_tree = elements_Arr[root_of_group_id]->getNodeTree();
        assert(rank_tree != nullptr);
        rank_tree->remove(tmp_level_node);

        // Complexity O(1)
        player_instance_to_increase->setLevel(level_to_increase + level);
        Node* tmp_level_node_2 = dynamic_cast<Node*> (new LevelNode(player_id, player_instance_to_increase));
        // Complexity - O(log(n))
        this->all_players_tree->insert(tmp_level_node_2);

        // Complexity - O(log*(k) + log(n)) amortized
        rank_tree->insert(tmp_level_node_2);
        delete tmp_level_node_2;
    }
    Player* player_to_remove = player_node_in_all_players_tree->getPlayerInstance();
    delete tmp_level_node;
    delete player_to_remove;

}

void PlayersManager::changePlayerIDScore(int player_id, int new_score)
{
    // step 1: input check - complexity: O(1)
    if ((player_id <=0) || (new_score <= 0) || new_score > this->score_scale)
    {
        throw InvalidInput();
    }

    // step 2 - create levelNode to find - complexity O(1)
    Node* tmp_level_node = createLevelNode(player_id, 0, 0);
    LevelNode* player_node_in_all_players_tree = dynamic_cast<LevelNode*>(tmp_level_node);
    // step 3 - find levelNode in hash table - complexity O(1) amortized
    Node* level_node_to_increase = this->hash_table_of_players->find(tmp_level_node);
    if (level_node_to_increase == nullptr)
    {
        Player* player_to_remove = player_node_in_all_players_tree->getPlayerInstance();
        delete tmp_level_node;
        delete player_to_remove;
        throw PlayerDoesNotExist();
    }

    // step 4 - get player instance out of level node - complexity O(1)
    LevelNode* casted_level_node_to_increase = dynamic_cast<LevelNode*>(level_node_to_increase);
    Player* player_instance_to_increase = casted_level_node_to_increase->getPlayerInstance();

    // step 5- change score
    // step 5a - save variables - Complexity O(1)
    int level = player_instance_to_increase->getLevel();
    int old_score = player_instance_to_increase->getScore();
    int group_id = player_instance_to_increase->getGroupId();
    player_node_in_all_players_tree->getPlayerInstance()->setLevel(level);

    player_instance_to_increase->setScore(new_score);
    // step 5b - taking care of the scenario where the previous level was 0
    if (level == 0)
    {
        // Complexity O(1)
        this->all_players_tree->updateZeroHistogram(old_score, true);
        this->all_players_tree->updateZeroHistogram(new_score, false);

        // Complexity O(log*(k)) amortized
        int root_of_group_id = this->union_find_groups->find(group_id);
        UnionFindNode** elements_Arr = union_find_groups->getElementsArr();
        assert(elements_Arr != nullptr);
        assert(elements_Arr[root_of_group_id] != nullptr);
        RankTree* rank_tree = elements_Arr[root_of_group_id]->getNodeTree();
        assert(rank_tree != nullptr);
        rank_tree->updateZeroHistogram(old_score, true);
        rank_tree->updateZeroHistogram(new_score, false);
    }

    // step 5c - taking care of the scenario where the previous level wasn't 0
    else
    {
        // Complexity - 0(1)
        Node* tmp_level_node_2 = dynamic_cast<Node*> (new LevelNode(player_id, player_instance_to_increase));
        // Complexity O(log(n))
        this->all_players_tree->remove(tmp_level_node);

        // Complexity O(log*(k) + log(n)) amortized
        int root_of_group_id = this->union_find_groups->find(group_id);
        UnionFindNode** elements_Arr = union_find_groups->getElementsArr();
        assert(elements_Arr != nullptr);
        assert(elements_Arr[root_of_group_id] != nullptr);
        RankTree* rank_tree = elements_Arr[root_of_group_id]->getNodeTree();
        assert(rank_tree != nullptr);
        rank_tree->remove(tmp_level_node);

        // Complexity - O(log(n))
        this->all_players_tree->insert(tmp_level_node_2);

        // Complexity - O(log*(k) + log(n)) amortized
        rank_tree->insert(tmp_level_node_2);

        delete tmp_level_node_2;
    }
    Player* player_to_remove = player_node_in_all_players_tree->getPlayerInstance();
    delete tmp_level_node;
    delete player_to_remove;

}

void PlayersManager::getPercentOfPlayersWithScoreInBounds(int group_id, int score, int lower_level, int higher_level,
                                                          double *players){
    // step 1: input check - complexity: O(1)
    if ((group_id < 0) || (group_id > this->num_of_groups) || players == nullptr)
    {
        throw InvalidInput();
    }

    // step 2: taking care of the scenario when we want to find specific group's rank tree - complexity: O(log*(k))
    // amortized
    RankTree* rank_tree = this->all_players_tree;
    if (group_id != 0)
    {
        int root_of_group_id = this->union_find_groups->find(group_id);
        UnionFindNode** elements_Arr = union_find_groups->getElementsArr();
        assert(elements_Arr != nullptr);
        assert(elements_Arr[root_of_group_id] != nullptr);
        rank_tree = elements_Arr[root_of_group_id]->getNodeTree();
        assert(rank_tree != nullptr);
    }

    // step 3: creating variables - complexity: O(1)
    double score_rank = 0;
    double total_rank = 0;
    if ((lower_level <= 0) && (higher_level >=0))
    {
        if ((score > 0) && (score <= this->score_scale))
        {
            score_rank += rank_tree->getZeroHistogramValue(score);
        }
        total_rank += rank_tree->getZeroHistogramSum();
    }
    int lower_node_id = 0;
    int lower_node_level = lower_level;
    int upper_node_id;
    int upper_node_level;
    if (higher_level == INT_MAX)
    {
        upper_node_level = higher_level;
        upper_node_id = INT_MAX;
    }
    else
    {
        upper_node_level = higher_level + INCREASE;
        upper_node_id = 0;
    }

    // step 4: creating nodes to search in tree - complexity: O(1)
    LevelNode* upper_node = new LevelNode(upper_node_id, 0, 0);
    upper_node->getPlayerInstance()->setLevel(upper_node_level);
    LevelNode* lower_node = new LevelNode(lower_node_id, 0, 0);
    lower_node->getPlayerInstance()->setLevel(lower_node_level);

    // step 5:
    if ((score > 0) && (score <= this->score_scale))
    {
        score_rank += (rank_tree->scoreRank(upper_node, score) - rank_tree->scoreRank(lower_node, score));
    }
    total_rank += (rank_tree->nodeRank(upper_node) - rank_tree->nodeRank(lower_node));

    Player* upper_player_to_remove = upper_node->getPlayerInstance();
    delete upper_node;
    delete upper_player_to_remove;

    Player* lower_player_to_remove = lower_node->getPlayerInstance();
    delete lower_node;
    delete lower_player_to_remove;
    if (total_rank <= 0)
    {
        throw NoPlayersInRange();
    }

    *players = (score_rank/total_rank)*PERCENTAGE_FACTOR;
}

void PlayersManager::averageHighestPlayerLevelByGroup(int group_id, int m, double *avg_level)
{
    // step 1: input check - complexity: O(1)
    if ((group_id < 0) || (group_id > this->num_of_groups) || (m <= 0) || (avg_level == nullptr))
    {
        throw InvalidInput();
    }

    // step 2: taking care of the scenario when we want to find specific group's rank tree - complexity: O(log*(k))
    // amortized
    RankTree* rank_tree = this->all_players_tree;
    if (group_id != 0)
    {
        int root_of_group_id = this->union_find_groups->find(group_id);
        UnionFindNode** elements_Arr = union_find_groups->getElementsArr();
        assert(elements_Arr != nullptr);
        assert(elements_Arr[root_of_group_id] != nullptr);
        rank_tree = elements_Arr[root_of_group_id]->getNodeTree();
        assert(rank_tree != nullptr);
    }

    // step 3: check if group has enough players - complexity: O(1)
    int number_of_players = rank_tree->getSize() + rank_tree->getZeroHistogramSum();
    if (number_of_players < m)
    {
        throw TooFewPlayers();
    }

    // step 4: creating variables - complexity: O(1)
    double sum = 0;
    int difference = rank_tree->getSize()-m;
    Node* upper_node = rank_tree->getLargestNode();
    Node* lower_node;
    if (difference <= 0)
    {
        lower_node = createLevelNode(0, 0, 0);
    }
    else
    {
        lower_node = rank_tree->select(rank_tree->getSize()-m);
    }
    sum += (rank_tree->sumRank(upper_node) - rank_tree->sumRank(lower_node));
    *avg_level = sum/m;

    if (difference <= 0)
    {
        LevelNode* casted_lower_node = dynamic_cast<LevelNode*>(lower_node);
        Player* lower_player_to_remove = casted_lower_node->getPlayerInstance();
        delete lower_node;
        delete lower_player_to_remove;
    }
}

void PlayersManager::getPlayersBound(int group_id, int score, int m, int *LowerBoundPlayers, int *HigherBoundPlayers)
{
    // step 1: input check - complexity: O(1)
    if ((group_id < 0) || (group_id > this->num_of_groups) || (m < 0) || (score <= 0 ) || (score > this->score_scale))
    {
        throw InvalidInput();
    }

    if (m == 0)
    {
        *LowerBoundPlayers = 0;
        *HigherBoundPlayers = 0;
        return;
    }

    // step 2: taking care of the scenario when we want to find specific group's rank tree - complexity: O(log*(k))
    // amortized
    RankTree* rank_tree = this->all_players_tree;
    if (group_id != 0)
    {
        int root_of_group_id = this->union_find_groups->find(group_id);
        UnionFindNode** elements_Arr = union_find_groups->getElementsArr();
        assert(elements_Arr != nullptr);
        assert(elements_Arr[root_of_group_id] != nullptr);
        rank_tree = elements_Arr[root_of_group_id]->getNodeTree();
        assert(rank_tree != nullptr);
    }

    // step 3: check if group has enough players - complexity: O(1)
    int number_of_players = rank_tree->getSize() + rank_tree->getZeroHistogramSum();
    if (number_of_players < m)
    {
        throw TooFewPlayers();
    }
    *LowerBoundPlayers = 0;
    *HigherBoundPlayers = 0;
    Node* upper_node = rank_tree->getLargestNode();

    if (m > rank_tree->getSize())
    {
        int num_of_players_in_critical_level = rank_tree->getZeroHistogramSum();
        int num_of_players_in_critical_level_with_score = rank_tree->getZeroHistogramValue(score);
        int num_of_players_above_critical_level = rank_tree->getSize();
        int num_of_wanted_players_in_critical_level = m - num_of_players_above_critical_level;
        int num_of_players_above_critical_level_with_score =  rank_tree->scoreRank(upper_node,score);
        *LowerBoundPlayers += num_of_players_above_critical_level_with_score;
        *HigherBoundPlayers += num_of_players_above_critical_level_with_score;

        if (num_of_wanted_players_in_critical_level < num_of_players_in_critical_level_with_score)
        {
            *HigherBoundPlayers += num_of_wanted_players_in_critical_level;
        }
        else
        {
            *HigherBoundPlayers += num_of_players_in_critical_level_with_score;
        }
        int difference = num_of_players_in_critical_level - num_of_players_in_critical_level_with_score;
        if (difference < num_of_wanted_players_in_critical_level)
        {
            *LowerBoundPlayers += (num_of_wanted_players_in_critical_level - difference);
        }
    }

    else
    {
        Node* critical_node = rank_tree->select(rank_tree->getSize() - m + INCREASE);
        int critical_node_level = critical_node->getExtraData();
        LevelNode* temp_node = new LevelNode(0, 0, 0);
        temp_node->getPlayerInstance()->setLevel(critical_node_level + INCREASE);
        int num_of_players_in_less_critical_level = rank_tree->nodeRank(temp_node);
        int num_of_players_in_less_critical_level_with_score = rank_tree->scoreRank(temp_node, score);
        int num_of_players_above_critical_level = rank_tree->getSize() - num_of_players_in_less_critical_level;
        int num_of_wanted_players_in_critical_level = m - num_of_players_above_critical_level;
        temp_node->getPlayerInstance()->setLevel(critical_node_level);
        int num_of_players_in_critical_level = num_of_players_in_less_critical_level -
                rank_tree->nodeRank(temp_node);
        int num_of_players_in_critical_level_with_score = num_of_players_in_less_critical_level_with_score -
                                               rank_tree->scoreRank(temp_node,score);
        int num_of_players_above_critical_level_with_score =  rank_tree->scoreRank(upper_node,score) -
                num_of_players_in_less_critical_level_with_score;
        *LowerBoundPlayers += num_of_players_above_critical_level_with_score;
        *HigherBoundPlayers += num_of_players_above_critical_level_with_score;

        if (num_of_wanted_players_in_critical_level < num_of_players_in_critical_level_with_score)
        {
            *HigherBoundPlayers += num_of_wanted_players_in_critical_level;
        }
        else
        {
            *HigherBoundPlayers += num_of_players_in_critical_level_with_score;
        }
        int difference = num_of_players_in_critical_level - num_of_players_in_critical_level_with_score;
        if (difference < num_of_wanted_players_in_critical_level)
        {
            *LowerBoundPlayers += (num_of_wanted_players_in_critical_level - difference);
        }

        LevelNode* casted_temp_node = dynamic_cast<LevelNode*>(temp_node);
        Player* temp_player_to_remove = casted_temp_node->getPlayerInstance();
        delete temp_node;
        delete temp_player_to_remove;
    }
}

void PlayersManager::destroyPlayersInNodes()
{
    for(int i = 0; i < this->hash_table_of_players->getTableSize(); i++)
    {
        Node* itr = this->hash_table_of_players->getFirstNodeInCell(i);
        while(itr != nullptr)
        {
            LevelNode* level_itr = dynamic_cast<LevelNode*> (itr);
            delete level_itr->getPlayerInstance();
            itr = itr->getNodeLeftSon();
        }
    }
}

// complexity: O(1)
PlayersManager::~PlayersManager()
{
    destroyPlayersInNodes();
    delete hash_table_of_players;
    delete union_find_groups;
    delete all_players_tree;
}


