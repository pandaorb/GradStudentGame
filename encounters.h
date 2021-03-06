#ifndef ENCOUNTERS_H
#define ENCOUNTERS_H

#include<iostream>
using namespace std;

/*
 * Encounter handles an array of Actions that
 * will all affect the character based on a 
 * specified event.
 */
struct Encounter {
	int static const MAX_ACT_NUM = 6;
	Action actionArray[MAX_ACT_NUM];
	u_short numOfActions;
	
	Encounter();
	Encounter(Action actionsIn[], u_short numActionsIn);
};

#endif
