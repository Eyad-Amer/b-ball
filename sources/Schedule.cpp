/**
 * Implementation of the Schedule class
 *
 * Author: Eyad Amer
 * Since : 2022-06
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "Schedule.hpp"
#include "Game.hpp"
#include "Team.hpp"
#include "Leauge.hpp"

using namespace std;

const int NumOfTeams = 20;                     // number of teams in the leauge = 20
const int NumGamesInOneCycle = NumOfTeams / 2; // number of the games in one cycle = 10
const int NumOfCycles = NumOfTeams * 2 - 2;    // number of cycles in the leauge = 38

namespace ariel
{
    // Parameterized Constructor
    Schedule::Schedule(Leauge l)
    {
        check_tablegame(); // check size of table game
        teams = l.getAllTeams(); // gets the teams from the table leauge
        Tow_Groups(); // divice the teams to a home teams and a foreign teams
        games(); // the the possible games
    }

    // all possible games
    void Schedule::games()
    {
        int index = 0;
        while (index < NumOfTeams - 1)
        {
            for (unsigned int i = 0; i < home_teams.size(); i++)
            {
                table_Games.push_back(new Game{*home_teams.at(i), *foreign_teams.at(i)});
            }
            swichTeams();
            index++;
        }

        index = 0;
        while (index < NumOfTeams - 1)
        {
            for (unsigned int i = 0; i < foreign_teams.size(); i++)
            {
                table_Games.push_back(new Game{*foreign_teams.at(i), *home_teams.at(i)});
            }
            swichTeams();
            index++;
        }
    }

    // sort teams by home and foreign teams
    void Schedule::Tow_Groups() 
    {
        // groupe of home teams
        for (unsigned int i = 0; i < teams.size() / 2; i++)
        {
            home_teams.push_back(teams.at(i));
        }

        // gruope of foreign teams
        for (unsigned int i = teams.size() - 1; i > teams.size() / 2 - 1; i--)
        {
            foreign_teams.push_back(teams.at(i));
        }
    }

    // helping function to swich the teams to make a cycles
    void Schedule::swichTeams() 
    {
        home_teams.insert(home_teams.begin() + 1, foreign_teams.at(0));
        foreign_teams.push_back(home_teams.at(home_teams.size() - 1));
        foreign_teams.erase(foreign_teams.begin());
        home_teams.pop_back();
    }

    // check if the table game has a 10 games
    void Schedule::check_tablegame() const
    {
        if (table_Games.size() > NumOfTeams * (NumOfTeams - 1)) // or: table_Games.size() > NumGamesInOneCycle * NumOfCycles
        {
            throw invalid_argument("The table contains too many games");
        }
    }

    // get all the games
    vector<Game *> Schedule::getAllGames() const
    {
        return this->table_Games;
    } 

    // print table games
    void Schedule::print() const
    {
        vector<Game *> OneCycle;

        for (unsigned int i = 0; i < table_Games.size(); i++)
        {
            OneCycle.push_back(table_Games.at(i));

            if (((i+1) % NumGamesInOneCycle) == 0)
            {
                cout << "cycle " << (i / 10) + 1 << ":" << endl;
                for (unsigned int j = 0; j < OneCycle.size(); j++)
                {
                    OneCycle.at(j)->print();
                }
                cout << "........................." << endl;
                OneCycle.clear();
            }
        }
        cout << "size: " << table_Games.size();
    }
}