#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;
class Player
{
private:
    string FirstName, LastName;
    float points;
    friend class Team;
public:
    Player();
    Player(string,string,float);
    ~Player();
    void set_FirstName(string);
    void set_LastName(string);
    void set_points(float);
    string get_FirstName();
    string get_LastName();
    float get_points();
    void add_XP();
};
