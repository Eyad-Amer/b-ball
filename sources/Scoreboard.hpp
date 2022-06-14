/**
 * Heading for Scoreboard class
 *
 * Author: Eyad Amer
 * Since : 2022-06
 */

#pragma once 

#include <iostream>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include <vector>

#include "Team.hpp"
#include "Game.hpp"
#include "Leauge.hpp"
#include "Schedule.hpp"

using namespace std;

// class Heading
namespace ariel
{
    class Scoreboard
    {
        
    private:
        Leauge *league; // leauge table
        Schedule *schedule; // game board
        vector<Team *> Score_board; // score board
        vector<Game *> games_board; // games board
        vector<int> table_wins; // teams table by wins
        vector<int> table_scores; // teams table by score
        int count_games; // How many games has the team played
        
    public:
        
        Scoreboard(Leauge &leauge, Schedule &schedule); // parameterized constructor
        vector<Team *> getScoreBoard() const; // get score board
        vector<int> getTableWins() const; // get teams table by wins
        vector<int> getTableScores() const; // teams table by score
        void clac(); // calc wins and points 
        void sortBoard(); // sort the Score board
        vector<Team *> TopTeams(unsigned int) const; // who are the top teams in the league
        vector<Team *> WorstTeams(unsigned int) const; // who are the worst teams in the league
        int CountLongWin() const; // the length of the longest winning in the year
        int CountLongLoss() const; // the length of the longest losing in the year
        int positiveScore() const; // teams that scored more points than conceded
        int CountGames() const; // How many games has the team played: (Numteams-1) * 2
        void print() const; // print Score board
       
    }; // class Leauge
} // namespace ariel