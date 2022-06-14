/**
 * Heading for Leauge class
 *
 * Author: Eyad Amer
 * Since : 2022-06
 */

#pragma once 

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stdexcept>

#include "Team.hpp"

using namespace std;

// class Heading
namespace ariel
{
    class Leauge
    {
        
    private:
        unordered_map<string, double> tableTeams; // table of the teams in the leauge

    public:
        Leauge(); // Default Constructor, create 20 basketball teams at random.
        Leauge(unordered_map<string, double>); // Parameterized Constructor, create and gets some of teams.
        Leauge(const Leauge& other); // Copy Constructor, gets a given set of basketball teams.
        void random_teams(); // to create a random teams.
        vector<Team*> getAllTeams() const; // get thr teams from the table leauge
        void checkTeamsNum() const; // check if we have a 20 teams in the leauge.
        void print() const; // print table leauge
       
    }; // class Leauge
} // namespace ariel