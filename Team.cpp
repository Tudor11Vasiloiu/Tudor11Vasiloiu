#include "Team.hpp"
#include <string>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <cctype>
#pragma once
using namespace std;

Team::Team()
{
    this->players_number = 0;
    this->name = "";
    this->score = 0;
}

Team::Team(int numar,string nume, float pct,vector<Player> jucatori)
{
    this->players_number = numar;
    this->name = nume;
    this->score = pct;
    vector<Player>::iterator it;
    for(it = jucatori.begin(); it != jucatori.end(); it++)
        this->players.push_back((*it));
}

Team::~Team()
{

}

string Team::get_name()
{
    return this->name;
}

float Team::get_score()
{
    return this->score;
}

void Team::add_point()
{
    this->score = this->score+1;
    vector<Player>::iterator it;
    for(it = this->players.begin(); it!= this->players.end(); it++)
        (*it).add_XP();

}

void Team::set_score(float p)
{
    this->score = p;
}

bool Team::operator <(Team &a)
{
    if(this->get_score() < a.get_score())
        return true;
    return false;
}

void Team::read_team(ifstream &d)
{
    float suma = 0; ///auxiliar pentru punctajul de echipa
///citirea primei linii care contine numarul de jucatori si numele echipei
    string line,number, team_name;
    char space = ' ';
    getline(d,line);
    int nr;
///transform din string in float
    size_t pos = line.find(space);
    number = line.substr(0,pos);
    line.erase(0,pos);
    stringstream change1(number);
    change1 >> nr;
    this->players_number = nr;
///
    team_name = line;
    team_name.erase(0,1);
    int s = team_name.length();
    if(team_name[s-1] == ' ')
        team_name.pop_back();
    this->name = team_name;
    //cout<<nr<<" ";
///citirea jucatorilor
    for(int i = 0; i<nr; i++)
    {
        size_t space_pos;
        //cout<<"Citesc jucator "<<endl;
        Player x;
        string h1,h2,h3;

        getline(d,line);

        /// First Name
        int pos1 = line.find(space);
        h1 = line.substr(0,pos1);
        space_pos = h1.find(space);
        if(space_pos != std::string::npos)
            h1.erase(space_pos);

        /// Last Name
        int pos2 = line.find(space,pos1+1);
        int len = pos2 - pos1;
        h2 = line.substr(pos1+1,len);
        space_pos = h2.find(space);
        if(space_pos != std::string::npos)
            h2.erase(space_pos);

        /// Each player's score
        h3 = line.substr(pos2+1);
        stringstream transf(h3);
        int pct = 0;
        transf >> pct;
        x.set_points((float) pct);
        x.set_FirstName(h1);
        x.set_LastName(h2);
        this->players.push_back(x);
        suma = suma + pct;
    }
    suma = suma/(float)nr;
    this->set_score(suma);


///citirea spatiului de la finalul listei de jucatori pentru evitarea erorilor
    getline(d,line);
}

const void Team::show_team(ofstream &r) const
{
    r<<this->name<<"- "<<this->score<<endl;
}
