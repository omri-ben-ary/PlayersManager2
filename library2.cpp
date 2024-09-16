#include "library2.h"
#include "PlayersManager.h"
#define MAX_SCALE 200

void* Init(int k, int scale)
{
    PlayersManager* DS;
    if ((k <= 0) || (scale <= 0) || (scale > MAX_SCALE))
    {
        return nullptr;
    }
    try
    {
        DS = new PlayersManager(k, scale);
    }
    catch (std::bad_alloc& bad_alloc)
    {
        return nullptr;
    }
    return DS;
}

StatusType MergeGroups(void *DS, int GroupID1, int GroupID2)
{
    if (DS == nullptr)
    {
        return INVALID_INPUT;
    }
    try
    {
        (static_cast<PlayersManager*>(DS)->mergeGroups(GroupID1, GroupID2));
    }
    catch (InvalidInput& invalid_input)
    {
        return INVALID_INPUT;
    }
    catch (std::bad_alloc& bad_alloc)
    {
        return ALLOCATION_ERROR;
    }
     return SUCCESS;
}

StatusType AddPlayer(void *DS, int PlayerID, int GroupID, int score)
{
    if (DS == nullptr)
    {
        return INVALID_INPUT;
    }
    try
    {
        (static_cast<PlayersManager*>(DS))->addPlayer(PlayerID, GroupID, score);
    }
    catch (InvalidInput& invalid_input)
    {
        return INVALID_INPUT;
    }
    catch (std::bad_alloc& bad_alloc)
    {
        return ALLOCATION_ERROR;
    }
    catch (PlayerIDIsAlreadyTaken& player_id_already_taken)
    {
        return FAILURE;
    }
    return SUCCESS;
}

StatusType RemovePlayer(void *DS, int PlayerID)
{
    if (DS == nullptr)
    {
        return INVALID_INPUT;
    }
    try
    {
        (static_cast<PlayersManager*>(DS)->removePlayer(PlayerID));
    }
    catch (InvalidInput& invalid_input)
    {
        return INVALID_INPUT;
    }
    catch (std::bad_alloc& bad_alloc)
    {
        return ALLOCATION_ERROR;
    }
    catch (PlayerDoesNotExist& player_does_not_exists)
    {
        return FAILURE;
    }
    return SUCCESS;
}

StatusType IncreasePlayerIDLevel(void *DS, int PlayerID, int LevelIncrease)
{
    if (DS == nullptr)
    {
        return INVALID_INPUT;
    }
    try
    {
        (static_cast<PlayersManager*>(DS)->increasePlayerLevel(PlayerID, LevelIncrease));
    }
    catch (InvalidInput& invalid_input)
    {
        return INVALID_INPUT;
    }
    catch (std::bad_alloc& bad_alloc)
    {
        return ALLOCATION_ERROR;
    }
    catch (PlayerDoesNotExist& player_does_not_exists)
    {
        return FAILURE;
    }
    return SUCCESS;
}

StatusType ChangePlayerIDScore(void *DS, int PlayerID, int NewScore)
{
    if (DS == nullptr)
    {
        return INVALID_INPUT;
    }
    try
    {
        (static_cast<PlayersManager*>(DS)->changePlayerIDScore(PlayerID, NewScore));
    }
    catch (InvalidInput& invalid_input)
    {
        return INVALID_INPUT;
    }
    catch (std::bad_alloc& bad_alloc)
    {
        return ALLOCATION_ERROR;
    }
    catch (PlayerDoesNotExist& player_does_not_exists)
    {
        return FAILURE;
    }
    return SUCCESS;
}

StatusType GetPercentOfPlayersWithScoreInBounds(void *DS, int GroupID, int score, int lowerLevel, int higherLevel,
                                                double * players){

    if (DS == nullptr)
    {
        return INVALID_INPUT;
    }
    try
    {
        (static_cast<PlayersManager*>(DS)->getPercentOfPlayersWithScoreInBounds(GroupID, score, lowerLevel,
                                                                                higherLevel, players));
    }
    catch (InvalidInput& invalid_input)
    {
        return INVALID_INPUT;
    }
    catch (std::bad_alloc& bad_alloc)
    {
        return ALLOCATION_ERROR;
    }
    catch (NoPlayersInRange& no_players_in_range)
    {
        return FAILURE;
    }
    return SUCCESS;
}

StatusType AverageHighestPlayerLevelByGroup(void *DS, int GroupID, int m, double *level)
{
    if (DS == nullptr)
    {
        return INVALID_INPUT;
    }
    try
    {
        (static_cast<PlayersManager*>(DS)->averageHighestPlayerLevelByGroup(GroupID, m, level));
    }
    catch (InvalidInput& invalid_input)
    {
        return INVALID_INPUT;
    }
    catch (std::bad_alloc& bad_alloc)
    {
        return ALLOCATION_ERROR;
    }
    catch (TooFewPlayers& too_few_players)
    {
        return FAILURE;
    }
    return SUCCESS;
}

StatusType GetPlayersBound(void *DS, int GroupID, int score, int m,
                           int * LowerBoundPlayers, int * HigherBoundPlayers)
{
    if (DS == nullptr)
    {
        return INVALID_INPUT;
    }
    try
    {
        (static_cast<PlayersManager*>(DS)->getPlayersBound(GroupID, score, m, LowerBoundPlayers,
                                                           HigherBoundPlayers));
    }
    catch (InvalidInput& invalid_input)
    {
        return INVALID_INPUT;
    }
    catch (std::bad_alloc& bad_alloc)
    {
        return ALLOCATION_ERROR;
    }
    catch (TooFewPlayers& too_few_players)
    {
        return FAILURE;
    }
    return SUCCESS;
}

void Quit(void **DS)
{
    if(DS == nullptr)
    {
        return;
    }
    delete static_cast<PlayersManager*>(*DS);
    *DS = nullptr;
}