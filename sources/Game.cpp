/**
 * Implementation of the Game class
 *
 * Author: Eyad Amer
 * Since : 2022-06
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <time.h>

#include "Game.hpp"
#include "Team.hpp"

using namespace std;

const int max_score = 100;           // max score
const int min_foreignteamScore = 50; // min foreign team score
const int min_hometeamScore = 55;    // min home team score
const int bonus = 10;                // up to 10 bonus points

namespace ariel
{
    // parameterized constructor
    Game::Game(Team &home_team, Team &foreign_team)
    {
        // Home Team
        this->home_team = &home_team;
        this->homeTeam_scoring = randomBetween(min_hometeamScore, max_score); // random number between 55 and 100
        this->homeTeam_scoring += addBonus(home_team); // Add up to 10 bonus points to the home team.

        // Foreign Team
        this->foreign_team = &foreign_team;
        this->foreignTeam_scoring = randomBetween(min_foreignteamScore, max_score); // random number between 50 and 100
        this->foreignTeam_scoring += addBonus(foreign_team); // Add up to 10 bonus points to the foreign team.
    }

    // random number between min and max
    int Game::randomBetween(int min, int max) const
    {
        int random = rand() % (max - min + 1) + min;
        return random;
    }

    // Add up to 10 bonus points to the team
    int Game::addBonus(const Team &team) const
    {
        int bons = team.getTalent_level() * bonus;
        return bons;
    }

    // get the score of the team
    int Game::getPointsScore(const Team &team) const
    {
        return (team.getName() == this->home_team->getName()) ? this->homeTeam_scoring : this->foreignTeam_scoring;
    }

    // get the team winner
    Team &Game::winner() const
    {
        if (this->homeTeam_scoring > this->foreignTeam_scoring)
        {
            return *home_team;
        }

        else if (this->homeTeam_scoring < this->foreignTeam_scoring)
        {
            return *foreign_team;
        }

        else
        {
            if (this->home_team->getTalent_level() >= this->foreign_team->getTalent_level())
            {
                return *home_team;
            }

            else
            {
                return *foreign_team;
            }
        }
    }

    // get the team winner
    Team &Game::loser() const
    {
        if (this->winner().getName() == home_team->getName())
        {
            return *foreign_team;
        }

        else
        {
            return *home_team;
        }
    }

    // get home team
    Team &Game::getHomeTeam() const
    {
        return *home_team;
    }

    // get foreign team
    Team &Game::getForeignTeam() const
    {
        return *foreign_team;
    }

    // print the game
    void Game::print() const
    {
        cout << home_team->getName() << " - " << foreign_team->getName() << endl;
    }

}