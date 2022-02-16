#pragma once
#include <iostream>
#include "Team.hpp"
#include <bits/stdc++.h>
#include <list>
#include <queue>
#include <stack>
#include <sstream>
#include <cctype>
#include <string>
#include <string.h>
#include <iomanip>
#include <set>
#include <map>
#include <array>
using namespace std;

float find_min(list<Team> e)
{
    float x;
    list<Team>::iterator it = e.begin();
    x = (*it).get_score();
    for(it = e.begin(); it != e.end(); it++)
        if(x > (*it).get_score())
            x = (*it).get_score();
    return x;
}

int main(int argc, char *argv[])
{

    ifstream c(argv[1]);
    if(!c)
        cout<<"Eroare c.in. ";
    ifstream d(argv[2]);
    if(!d)
        cout<<"Eroare d.in. ";
    ofstream r(argv[3]);
    if(!r)
        cout<<"Eroare r.out.";

///declararea variabilelor pentru a nu intampina probleme in if-uri
    queue<Team> queue_of_teams;
    array<Team,8> last_teams;
    array<Team,8>::iterator ti;
    list<Team> teams;
    list<Team>::iterator itd;
    set<Team> final_teams;
    set<Team>::iterator itset;
    std::list<Team>::iterator its;
    stack<Team> winners, defeated;
    int k = 1, z = 1;///cand elimin echipe
    int round = 1;///pentru runde
    int f = 0;//pt array

/// cate echipe contine fisierul
    int nr;
    string data_line;
    getline(d,data_line);
    stringstream convert(data_line);
    convert >> nr;

/// cerintele
    string checker_line;

    int i;
    getline(c,checker_line);
    char task[10];
    for(i=0; i<10; i++)
        task[i] = checker_line[i];
///verificare ca am citit corect din fisier
    for(i=0;i<10;i+=2)
       // cout<<task[i]<<endl;

    if(task[2] == '1')
        {
            Team to_read;
            for(i=0; i<nr; i++)
                {

                    to_read.read_team(d);
                    teams.push_front(to_read);
                }
            do
            {
                k = k*2;
                z = k*2;
            }while(z < nr);
            float y;
            z = nr-k;
            int ok;
            while(z>0)
            {
                ok = 0;
                y = find_min(teams);
                for(itd = teams.begin(); (itd != teams.end()) && ok == 0; itd++)
                {
                    float value = (*itd).get_score();
                    if(value == y)
                    {
                        teams.erase(itd);
                        z = z-1;
                        ok = 1;
                    }
                }
            }
        for(its = teams.begin(); its != teams.end(); its++)
            r << (*its).get_name()<<endl;
        }

        else if(task[0] == '1')
        {
            Team to_read;
            for(i=0; i<nr; i++)
                {
                    to_read.read_team(d);
                    teams.push_front(to_read);
                }
            for(its = teams.begin(); its != teams.end(); its++)
            r << (*its).get_name()<<endl;
        }

    if(task[4] == '1')
        {
        nr = k;
        for(itd = teams.begin(); itd != teams.end(); itd++)
            queue_of_teams.push((*itd));

        while(nr > 1)
        {
            r<<endl<<"--- ROUND NO:"<<round<<endl;
          while(!queue_of_teams.empty())
          {
            Team d,t;
            d = queue_of_teams.front();
            queue_of_teams.pop();
            t = queue_of_teams.front();
            queue_of_teams.pop();
            r<<setw(33)<<left<<d.get_name()<<"-"<<setw(33)<<right<<t.get_name()<<endl;

            ///the winner and the defeated
            if(d.get_score() > t.get_score())
            {
                winners.push(d);
                d.add_point();
                defeated.push(t);
            }
            if(d.get_score() <= t.get_score())
            {
                winners.push(t);
                t.add_point();
                defeated.push(d);
            }
          }
          ///afisez invingatorii in ordine si ii adaug in coada de meciuri
          int h = nr/2;///daca h==8 atunci introduc ultimele 8 echipe in alta coada pentru care afisez meciuri in continuare
          r <<endl<<"WINNERS OF ROUND NO:"<<round<<endl;
          while(!winners.empty())
          {
              winners.top().add_point();
              queue_of_teams.push(winners.top());
              //winners.top().set_score(u);
              r<<setw(33)<<left<<winners.top().get_name()<<" -  "<<fixed<<setprecision(2)<<winners.top().get_score()<<endl;

              if(h == 8)
                last_teams[f++] = winners.top();

              winners.pop();
          }
          nr = nr/2;
          round++;
        }
        }

        if(task[6] == '1')
        {
            Team tud;
            for(i = 0; i < 7; i++)
                for(int j = i+1; j < 8; j++)
                    {
                        if( last_teams[i].get_score() < last_teams[j].get_score() )
                        {
                            tud = last_teams[i];
                            last_teams[i] = last_teams[j];
                            last_teams[j] = tud;
                        }
                        if( last_teams[i].get_score() == last_teams[j].get_score() )
                            if( last_teams[i].get_name() < last_teams[j].get_name() )
                            {
                                tud = last_teams[i];
                                last_teams[i] = last_teams[j];
                                last_teams[j] = tud;
                            }
                    }
            r << endl << "TOP 8 TEAMS:"<<endl;
            for(i = 0; i < 8; i++)
                r <<setw(33)<<left<<last_teams[i].get_name()<<" -  "<<fixed<<setprecision(2)<<last_teams[i].get_score()<<endl;
        }
        if(task[8] == '1')
        {
            r << endl <<"THE LEVEL 2 TEAMS ARE:" << endl;
            r << last_teams[0].get_name()<<endl;
            r << last_teams[2].get_name()<<endl;
            r << last_teams[4].get_name()<<endl;
            r << last_teams[6].get_name()<<endl;
        }
        r.close();
}
