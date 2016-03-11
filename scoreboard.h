#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include<iostream>
using namespace std;

/*
 * Score structure will hold data for each player and 
 * that player's score. It can also point to another
 * Score.
 */
struct Score {
	string name;
	int score;
	Score* next;

	Score();
	Score(string nameIn, int scoreIn);
	Score(string nameIn, int scoreIn, Score* next);
};


typedef Score* ScorePtr;
typedef unsigned short u_short;


/*
 * Data structure will contain a linked list of all scores
 * sorted from highest to lowest. It also contains the
 * total number of scores as well as how many to report
 * as 'High Scores'.
 */
struct Scoreboard {
	u_short static const NUM_HIGH_SCORES = 5;
	u_short numScores;
	ScorePtr firstScore;

	Scoreboard();
	Scoreboard(u_short totalScores, ScorePtr startingScore); 
};

#endif
