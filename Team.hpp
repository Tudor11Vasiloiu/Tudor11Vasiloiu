#pragma once
#include "Player.hpp"
#include <vector>
class Team
{
private:
    int players_number;
    string name;
    float score;
    vector<Player> players;
    friend class Player;
public:
    Team();
    Team(int,string,float,vector<Player>);
    ~Team();
    string get_name();
    float get_score();
    void add_point();
    void read_team(ifstream&);
    void set_score(float);
    bool operator <(Team&);
    const void show_team(ofstream&) const;
};
