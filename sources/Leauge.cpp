/**
 * Implementation of the Leauge class
 *
 * Author: Eyad Amer
 * Since : 2022-06
 */

#include <iostream>
#include <string>
#include <stdexcept>

#include "Leauge.hpp"

using namespace std;

const int teams = 20;

namespace ariel
{
    // Default Constructor, create 20 basketball teams at random.
    Leauge::Leauge()
    {
        checkTeamsNum(); // check number of the teams in the leauge
        random_teams();
    }

    // Parameterized Constructor, create and gets some of teams.
    Leauge::Leauge(unordered_map<string, double> leauge)
    {
        checkTeamsNum(); // check number of the teams in the leauge

        for (auto it = leauge.cbegin(); it != leauge.cend(); ++it)
        {
            tableTeams.insert({it->first, it->second});
        }

        random_teams();
    }

    // Copy Constructor, gets a given set of basketball teams.
    Leauge::Leauge(const Leauge &other)
    {
        checkTeamsNum(); // check number of the teams in the leauge
        this->tableTeams = other.tableTeams;
    }

    // to create a random teams.
    void Leauge::random_teams()
    {
        string teamName; // team name
        double talent; // team skill
        Team *t; // new team

        while (tableTeams.size() < teams)
        {
            int ran = rand() % (25 - 0 + 1) + 0; // name random a - z
            teamName = char('a' + ran);          // team names
            talent = (float)rand() / RAND_MAX;   // talent level between 0 and 1

            t = new Team(teamName, talent); // new team

            tableTeams.insert({t->getName(), t->getTalent_level()});
        }
    }

    // get the teams from the table leauge
    vector<Team*> Leauge::getAllTeams() const
    {
        vector<Team*> t;
        for (auto it = tableTeams.cbegin(); it != tableTeams.cend(); ++it)
        {
            Team *team = new Team(it->first, it->second);
            t.push_back(team);
        }
        return t;
    } 

    // check if we have a 20 teams in the leauge.
    void Leauge::checkTeamsNum() const
    {
        if (tableTeams.size() > teams)
        {
            throw invalid_argument("you have more than 20 teams!");
        }
    }

    // print table leauge
    void Leauge::print() const
    {
        for (auto it = tableTeams.cbegin(); it != tableTeams.cend(); ++it)
        {
            cout << "team name: " << it->first << ", team talent: " << it->second << endl;
        }
    }

}