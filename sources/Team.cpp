/**
 * Implementation of the Team class
 *
 * Author: Eyad Amer
 * Since : 2022-06
 */

#include <iostream>
#include <string>
#include <stdexcept>

#include "Team.hpp"

using namespace std;

namespace ariel
{
    // parameterized constructor
    Team::Team(string n, double t)
    {
        check(n, t);
        
        this->name = move(n);
        this->talent_level = t;
    }

    // get the name of the team
    string Team::getName() const
    {
        return this->name;
    }

    // get talent level of the team
    double Team::getTalent_level() const
    {
        return this->talent_level;
    }

    // check if talent level of the team is btween 0 and 1
    void Team::check(string name, double skill) const
    {
        if (skill < 0 || skill > 1 || name.empty())
        {
            throw invalid_argument("The inputs of the Team argument is illegal");
        }
    }

    // print the name and the talent level of the team
    void Team::print() const
    {
        cout << "team name: " << this->getName() << ", team talent: " << this->getTalent_level() << endl;
    }

} // ariel