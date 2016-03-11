#ifndef PUZZLES_H
#define PUZZLES_H

#include<iostream>
using namespace std;

/* 
 * Puzzle is a special type of encounter in which
 * results are determined by player input.
 */
struct Puzzle {
	int static const MAX_ACT_NUM = 6;
	string question;
	string key;
	Action actionArray[MAX_ACT_NUM];
	u_short numOfActions;
	
	Puzzle();
	Puzzle(string questionIn, string keyIn, Action actionArrayIn[], u_short numOfActionsIn);
};

#endif
