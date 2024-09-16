#ifndef WET1_PLAYER_H
#define WET1_PLAYER_H

class Player{
    int level;
    int score;
    int player_group_id;
public:
    Player(int score, int group_id);
    ~Player() = default;
    Player(const Player& other) = default;
    Player& operator=(const Player& other) = default;

    bool operator<(const Player& other) const;
    bool operator==(const Player& other) const;
    int getLevel() const;
    int getScore() const;
    void setScore(int new_score);
    void setLevel(int new_level);
    int getGroupId() const;
    void setGroupId(int new_group);
};
#endif //WET1_PLAYER_H

