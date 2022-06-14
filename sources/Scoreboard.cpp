/**
 * Implementation of the Scoreboard class
 *
 * Author: Eyad Amer
 * Since : 2022-06
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <time.h>

#include "Scoreboard.hpp"

using namespace std;

const int Numteams = 20; // num of the teams in the leauge

namespace ariel
{
    // parameterized constructor
    Scoreboard::Scoreboard(Leauge &leauge, Schedule &schedule)
    {
        this->league = &leauge;
        this->schedule = &schedule;

        this->Score_board = this->league->getAllTeams();
        this->games_board = this->schedule->getAllGames();
        clac();
        sortBoard();

        this->count_games = (Numteams - 1) * 2; // How many games has the team played
    }

    // get score board
    vector<Team *> Scoreboard::getScoreBoard() const
    {
        return this->Score_board;
    }

    // get teams table by wins
    vector<int> Scoreboard::getTableWins() const
    {
        return this->table_wins;
    }

    // teams table by score
    vector<int> Scoreboard::getTableScores() const
    {
        return this->table_scores;
    }

    // sort score board
    void Scoreboard::clac()
    {
        int CountWin = 0;
        int CountScore = 0;

        for (unsigned int i = 0; i < this->Score_board.size(); i++)
        {
            CountWin = 0;
            CountScore = 0;
            for (unsigned int j = 0; j < this->games_board.size(); j++)
            {
                if (this->Score_board.at(i)->getName() == this->games_board.at(j)->winner().getName())
                {
                    CountWin++;
                }
/*
                if (this->Score_board.at(i)->getName() == this->games_board.at(j)->loser().getName())
                {
                    CountWin--;
                }*/

                if (this->Score_board.at(i)->getName() == this->games_board.at(j)->getHomeTeam().getName())
                {
                    CountScore += this->games_board.at(j)->getPointsScore(this->games_board.at(j)->getHomeTeam());
                    CountScore -= this->games_board.at(j)->getPointsScore(this->games_board.at(j)->getForeignTeam());
                }

                if (this->Score_board.at(i)->getName() == this->games_board.at(j)->getForeignTeam().getName())
                {
                    CountScore += this->games_board.at(j)->getPointsScore(this->games_board.at(j)->getForeignTeam());
                    CountScore -= this->games_board.at(j)->getPointsScore(this->games_board.at(j)->getHomeTeam());
                }
            }
            this->table_wins.push_back(CountWin);
            this->table_scores.push_back(CountScore);
        }
    }

    // sort the Score board
    void Scoreboard::sortBoard()
    {
        vector<Team *> tempTeam = this->Score_board;
        vector<int> tempWin = this->table_wins;
        vector<int> tempScore = this->table_scores;
        this->Score_board.clear();
        this->table_wins.clear();
        this->table_scores.clear();
        int max = INT8_MIN;
        unsigned int index = 0;

        for (unsigned int i = 0; i < tempTeam.size(); i++)
        {
            max = INT8_MIN;
            index = 0;
            for (unsigned int j = 0; j < tempWin.size(); j++)
            {
                if (tempWin.at(j) > max)
                {
                    max = tempWin.at(j);
                    index = j;
                }
            }
            this->Score_board.push_back(tempTeam.at(index));
            this->table_wins.push_back(max);
            this->table_scores.push_back(tempScore.at(index));

            tempWin.at(index) = INT8_MIN;
        }
    }

    // who are the top teams in the league
    vector<Team *> Scoreboard::TopTeams(unsigned int num) const
    {
        vector<Team *> temp;

        for (unsigned int i = 0; i < num; i++)
        {
            temp.push_back(Score_board.at(i));
        }

        return temp;
    }

    // who are the worst teams in the league
    vector<Team *> Scoreboard::WorstTeams(unsigned int num) const
    {
        vector<Team *> temp;

        for (unsigned int i = Score_board.size() - 1; i > Score_board.size() - num - 1; i--)
        {
            temp.push_back(Score_board.at(i));
        }

        return temp;
    }

    // the length of the longest winning in the year
    int Scoreboard::CountLongWin() const
    {
        int count = 0;
        int maxCount = 0;

        for (unsigned int i = 0; i < this->Score_board.size(); i++)
        {
            count = 0;
            for (unsigned int j = 0; j < this->games_board.size(); j++)
            {
                if (this->Score_board.at(i)->getName() == this->games_board.at(j)->winner().getName())
                {
                    count++;
                }
            }

            if (count > maxCount)
            {
                maxCount = count;
            }
        }
        return maxCount;
    }

    // the length of the longest losing in the year
    int Scoreboard::CountLongLoss() const
    {
        int count = 0;
        int maxCount = 0;

        for (unsigned int i = 0; i < this->Score_board.size(); i++)
        {
            count = 0;
            for (unsigned int j = 0; j < this->games_board.size(); j++)
            {
                if (this->Score_board.at(i)->getName() == this->games_board.at(j)->loser().getName())
                {
                    count++;
                } 
            }

            if (count > maxCount)
            {
                maxCount = count;
            }
        }
        return maxCount;
    }

    // teams that scored more points than conceded
    int Scoreboard::positiveScore() const
    {
        int count = 0;
        for (unsigned int i = 0; i < table_scores.size(); i++)
        {
            if (table_scores.at(i) > 0)
            {
                count++;
            }
        }
        return count;
    }

    // How many games has the team played: (Numteams-1) * 2
    int Scoreboard::CountGames() const
    {
        return count_games;
    }

    // print Score board
    void Scoreboard::print() const
    {

        cout << "     Teams name            |  "
             << "wins%  |  "
             << "points" << endl
             << endl;

        for (unsigned int i = 0; i < Score_board.size(); i++)
        {
            string s = "  ", t = "  ", w = "   ";

            if (table_scores.at(i) < 0)
            {
                w = "  ";
            }

            string b, u = " ";
            int f = 24 - Score_board.at(i)->getName().length();

            for (int j = 0; j < f; j++)
            {
                b += u;
            }
            double x =  (double)((table_wins.at(i) * 100)) / 38;

            cout << "   " << Score_board.at(i)->getName() << b << "|" << t << setprecision(3) << x << "%" << s << "|" << w << table_scores.at(i) << endl;
        }
    }
}