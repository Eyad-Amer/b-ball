/**
 * main function
 *
 * @author Eyad Amer
 * @since 2022-06
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <time.h>

#include "sources/Team.cpp"
#include "sources/Game.cpp"
#include "sources/Leauge.cpp"
#include "sources/Schedule.cpp"
#include "sources/Scoreboard.cpp"

using namespace std;
using namespace ariel;

int main()
{
    srand((unsigned)time(NULL)); // random skill between 0 and 1

    unordered_map<string, double> team; // teams in the leauge

    team.insert({"Maccabi Tel Aviv", (float)rand() / RAND_MAX});
    team.insert({"Hapoel Tel Aviv", (float)rand() / RAND_MAX});
    team.insert({"Hapoel Jerusalem", (float)rand() / RAND_MAX});
    team.insert({"Hapoel Holon", (float)rand() / RAND_MAX});
    team.insert({"Maccabi Haifa", (float)rand() / RAND_MAX});
    team.insert({"Hapoel Galil Elyon", (float)rand() / RAND_MAX});
    team.insert({"Maccabi Rishon LeZion", (float)rand() / RAND_MAX});
    team.insert({"Hapoel Gilboa Galil", (float)rand() / RAND_MAX});
    team.insert({"Hapoel Ramat Gan", (float)rand() / RAND_MAX});
    team.insert({"Ironi Ramat Gan", (float)rand() / RAND_MAX});
    team.insert({"Hapoel Gvat", (float)rand() / RAND_MAX});
    team.insert({"Hapoel Haifa", (float)rand() / RAND_MAX});
    team.insert({"Hapoel Eilat", (float)rand() / RAND_MAX});
    team.insert({"Bnei Herzliya", (float)rand() / RAND_MAX});
    team.insert({"Elitzur Netanya", (float)rand() / RAND_MAX});
    team.insert({"Maccabi Ironi Ra'anana", (float)rand() / RAND_MAX});
    team.insert({"Ironi Nahariya", (float)rand() / RAND_MAX});
    team.insert({"Maccabi Ashdod", (float)rand() / RAND_MAX});
    team.insert({"Maccabi Ariel", (float)rand() / RAND_MAX});
    team.insert({"Hapoel Ariel", (float)rand() / RAND_MAX});

    Leauge leauge(team); // leauge of the teams

    Schedule schedule(leauge); // schedule of the leauge

    Scoreboard scoreboard(leauge, schedule); // scoreboard

    scoreboard.print();

    // Top 3 Teams in the league
    cout << endl << "..............................." << endl << endl;

    cout << "Top 3 Teams: " << endl;
    vector<Team *> topteams = scoreboard.TopTeams(3);
    for (unsigned int i = 0; i < topteams.size(); ++i)
    {
        topteams.at(i)->print(); 
    }

    // Long win in the league
    cout << endl << "..............................." << endl << endl;
    
    cout << "Long win in the league: " <<  scoreboard.CountLongWin() << endl;

    // Long loss in the league
    cout << endl << "..............................." << endl << endl;
    
    cout << "Long loss in the league: " <<  scoreboard.CountLongLoss() << endl;

    // num of teams that have positive Score
    cout << endl << "..............................." << endl << endl;
    
    cout << "num of teams that have positive Score: " <<  scoreboard.positiveScore() << endl;

    // Worst 3 Teams in the league
    cout << endl << "..............................." << endl << endl;

    cout << "Worst 3 Teams: " << endl;
    vector<Team *> worstTeams = scoreboard.WorstTeams(3);
    for (unsigned int i = 0; i < worstTeams.size(); ++i)
    {
        worstTeams.at(i)->print(); 
    }

    // how many games in the league
    cout << endl << "..............................." << endl << endl;

    cout << "how many games in the league: " <<  scoreboard.CountGames() << endl;

    return 0;
}


