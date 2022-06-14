/**
 * Unit tests.
 *
 * AUTHORS: Eyad Amer
 * Date:  2022-06
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <unordered_map>
#include <time.h>

#include "doctest.h"
#include "Team.hpp"
#include "Game.hpp"
#include "Leauge.hpp"
#include "Schedule.hpp"

using namespace std;
using namespace ariel;

const int teams = 20;

// Good inputs and results
TEST_CASE("Tests")
{
	srand((unsigned)time(NULL)); // Random Number Between 0 And 1

	SUBCASE("Team tests")
	{
		for (int i = 0; i < teams; i++)
		{
			Team team1(to_string('a' + i), (float)rand() / RAND_MAX);

			CHECK_NOTHROW(Team team1(to_string('a' + i), (float)rand() / RAND_MAX));

			CHECK_NOTHROW(team1.getName());
			CHECK_NOTHROW(team1.getTalent_level());
		}
	}

	SUBCASE("Game tests")
	{
		for (int i = 0; i < teams * (teams - 1); i++)
		{
			Team team1(to_string('a' + i), (float)rand() / RAND_MAX);
			Team team2(to_string('b' + i), (float)rand() / RAND_MAX);
			Game game(team1, team2);

			CHECK_NOTHROW(Game game(team1, team2));

			CHECK_NOTHROW(game.getForeignTeam());
			CHECK_NOTHROW(game.getHomeTeam());
			CHECK_NOTHROW(game.getPointsScore(team1));
			CHECK_NOTHROW(game.winner());
			CHECK_NOTHROW(game.loser());
		}
	}

	SUBCASE("Leauge tests")
	{
		unordered_map<string, double> tableTeams; // table of the teams in the leauge
		int i = 0;

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

		for (int j = 0; j < teams; j++)
		{
			Leauge leauge1(team);
			CHECK_NOTHROW(Leauge leauge1(team));

			Leauge leauge2;
			CHECK_NOTHROW(Leauge leauge2);

			CHECK_NOTHROW(leauge1.checkTeamsNum());
		}
	}

	SUBCASE("Schedule tests")
	{

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

		for (int i = 0; i < teams; i++)
		{
			Schedule schedule(leauge);

			CHECK_NOTHROW(Schedule schedule(leauge));

			CHECK_NOTHROW(schedule.check_tablegame());
			CHECK_NOTHROW(schedule.games());
			CHECK_NOTHROW(schedule.getAllGames());
			CHECK_NOTHROW(schedule.swichTeams());
			CHECK_NOTHROW(schedule.Tow_Groups());
		}
	}
}