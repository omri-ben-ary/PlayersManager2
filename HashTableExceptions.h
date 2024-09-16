#ifndef WET2_HASHTABLEEXCEPTIONS_H
#define WET2_HASHTABLEEXCEPTIONS_H

#include <iostream>

class HashTableExceptions : public std::exception {
public:
    HashTableExceptions() = default;
    ~HashTableExceptions() override = default;
};

class HashTableKeyIsAlreadyTaken : public HashTableExceptions {
public:
    HashTableKeyIsAlreadyTaken() = default;
};

class HashTableNodeDoesNotExist : public HashTableExceptions {
public:
    HashTableNodeDoesNotExist() = default;
};
#endif //WET2_HASHTABLEEXCEPTIONS_H
