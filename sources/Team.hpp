/**
 * Heading for Team class
 *
 * Author: Eyad Amer
 * Since : 2022-06
 */

#pragma once 

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// class Heading
namespace ariel
{
    class Team
    {
        
    private:
        string name; // name of the team
        double talent_level; // talent level of the team (0-1)

    public:
        Team(string, double); // parameterized constructor
        string getName() const; // get the name of the team
        double getTalent_level() const; // get talent level of the team
        void check(string, double) const; // check if talent level of the team is btween 0 and 1
        void print() const; // print the name and the talent level of the team
       
    }; // class Team
} // namespace ariel