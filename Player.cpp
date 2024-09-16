#include "Player.h"
Player::Player(int score, int group_id) : level(0), score(score), player_group_id(group_id) {}

bool Player::operator<(const Player &other) const {
    return (this->level < other.level);
}

bool Player::operator==(const Player &other) const {
    return (this->level == other.level);
}

int Player::getLevel() const {
    return level;
}

int Player::getGroupId() const {
    return player_group_id;
}

void Player::setGroupId(int new_group) {
    player_group_id = new_group;
}

void Player::setLevel(int new_level) {
    level = new_level;
}

int Player::getScore() const {
    return score;
}

void Player::setScore(int new_score) {
    score = new_score;
}

