#ifndef WET2_PLAYERSMANAGEREXCEPTIONS_H
#define WET2_PLAYERSMANAGEREXCEPTIONS_H

#include <iostream>

class PlayersManagerExceptions : public std::exception {
public:
    PlayersManagerExceptions() = default;
    ~PlayersManagerExceptions() override = default;
};

class InvalidInput : public PlayersManagerExceptions {
public:
    InvalidInput() =  default;
};

class AllocationError : public PlayersManagerExceptions {
public:
    AllocationError() =  default;
};

class GroupIDIsAlreadyTaken : public PlayersManagerExceptions {
public:
    GroupIDIsAlreadyTaken() = default;
};

class PlayerIDIsAlreadyTaken : public PlayersManagerExceptions {
public:
    PlayerIDIsAlreadyTaken() = default;
};

class GroupDoesNotExist : public PlayersManagerExceptions {
public:
    GroupDoesNotExist() = default;
};

class PlayerDoesNotExist : public PlayersManagerExceptions {
public:
    PlayerDoesNotExist() = default;
};

class TooFewFullGroups : public PlayersManagerExceptions {
public:
    TooFewFullGroups() = default;
};

class NoPlayersInRange : public PlayersManagerExceptions {
public:
    NoPlayersInRange() = default;
};

class TooFewPlayers : public PlayersManagerExceptions {
public:
    TooFewPlayers() = default;
};

#endif //WET2_PLAYERSMANAGEREXCEPTIONS_H
