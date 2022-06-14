/**
 * Heading for Schedule class
 *
 * Author: Eyad Amer
 * Since : 2022-06
 */

#pragma once 

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "Game.hpp"
#include "Team.hpp"
#include "Leauge.hpp"

using namespace std;

// class Heading
namespace ariel
{
    class Schedule
    {
        
    private:
        vector<Game *> table_Games; // games list
        vector<Team *> teams; // all the teams in the leauge
        vector<Team *> home_teams; // home teams
        vector<Team *> foreign_teams; // foreign teams
       
    public:
        Schedule(Leauge l); // Parameterized Constructor
        void check_tablegame() const; // check if the table game has a 10 games
        void games(); // all possible games
        void Tow_Groups(); // sort teams by home and foreign teams
        void swichTeams(); // helping function to swich the teams to make a cycles
        vector<Game *> getAllGames() const; // get all the games
        void print() const; // print the table
        
    }; // class Schedule
} // namespace ariel