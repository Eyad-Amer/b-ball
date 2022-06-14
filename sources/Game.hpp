/**
 * Heading for Game class
 *
 * Author: Eyad Amer
 * Since : 2022-06
*/

#pragma once 

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "Team.hpp"

using namespace std;

// class Heading
namespace ariel
{
    class Game
    {
        
    private:
        // Home Team
        Team *home_team; // home team
        int homeTeam_scoring; // home team score

        // Foreign Team
        Team *foreign_team; // foreign team
        int foreignTeam_scoring; // foreign team score
        
    public:
        
        Game(Team &home_team, Team &foreign_team); // parameterized constructor
        int randomBetween(int min, int max) const; // random number between min and max
        int addBonus(const Team &team) const; // Add up to 10 bonus points to the team
        int getPointsScore(const Team &team) const; // get the score of the team
        Team &winner() const; // get the team winner
        Team &loser() const; // get the team winner
        Team &getHomeTeam() const; // get home team
        Team &getForeignTeam() const; // get foreign team
        void print() const; // print the game
       
    }; // class Game
} // namespace ariel 