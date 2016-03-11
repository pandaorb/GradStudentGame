#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include <cstdlib>
#include <climits>
#include <fstream>
#include "project1_functions.h"

/* Constructor for Encounter */
Encounter::Encounter()
{
}

Encounter::Encounter(Action actionsIn[], u_short numActionsIn): numOfActions(numActionsIn)
{
	for(int i = 0; i < numOfActions; i++)
	{
		actionArray[i] = actionsIn[i];
	}
}


/*
 * An encounter where the character loses time
 * but earns a random amount of money.
 * Parameter: character - attributes change
 * Return: None
 */
void gradePapers(Character& character)
{
	
	cout << "You must stop and grade papers!" << endl;
	int timeLost = 1;
	Action timeDown(PENALTY, TIME, timeLost);
	int moneyGained = rand() % 6;
	Action moneyUp(REWARD, MONEY, moneyGained);
	int numActions = 2;
	Action actionArray[numActions];
	actionArray[0] = timeDown;
	actionArray[1] = moneyUp;
	Encounter gradePapers(actionArray, numActions);
	
	encounterResults(character, gradePapers);
	cout << "You lost " << timeLost << " time and gained $" 
		<< moneyGained << "." << endl;
}

/*
 * An encounter where the character loses time
 * but earns a random amount of intelligence.
 * Parameter: character - attributes change
 * Return: None
 */
void professor(Character& character)
{
	cout << "Dr. Qin wants to tell you how great the music recital was!" << endl;
	int timeLost = 1;
	Action timeDown(PENALTY, TIME, timeLost);
	int intelGained = rand() % 6;
	Action intelUp(REWARD, INTELLIGENCE, intelGained);
	int numActions = 2;
	Action actionArray[numActions];
	actionArray[0] = timeDown;
	actionArray[1] = intelUp;
	Encounter professor(actionArray, numActions);

	encounterResults(character, professor);
	cout << "You lost " << timeLost << " time and gained "
		<< intelGained << " intelligence. " << endl;
}

/*
 * An encounter where the character gains time
 * but loses a random amount of money.
 * Parameter: character - attributes change
 * Return: None
 */
void extension(Character& character)
{
	cout << "Your professor gives you an assignment extension! "
		<< "You buy a gift to say thank you." << endl;
	int timeGained = rand() % 10 + 1;
	Action timeUp(REWARD, TIME, timeGained);
	int moneyLost = rand() % 5;
	Action moneyDown(PENALTY, MONEY, moneyLost);
	int numActions = 2;
	Action actionArray[numActions];
	actionArray[0] = timeUp;
	actionArray[1] = moneyDown;
	Encounter extension(actionArray, numActions);

	encounterResults(character, extension);
	cout << "You gained " << timeGained << " time and lost $" 
		<< moneyLost << endl;
}

/*
 * An encounter where the character loses time
 * and a random amount of money.
 * Parameter: character - attributes change
 * Return: None
 */
void getHungry(Character& character)
{
	cout << "You get hungry and buy food across the street. " << endl;
	int timeLost = rand() % 2;
	Action timeDown(PENALTY, TIME, timeLost);
	int moneyLost = 4 + rand() % 3;
	Action moneyDown(PENALTY, MONEY, moneyLost);
	int numActions = 2;
	Action actionArray[numActions];
	actionArray[0] = timeDown;
	actionArray[1] = moneyDown;
	Encounter buyFood(actionArray, numActions);

	encounterResults(character, buyFood);
	cout << "You lost " << timeLost << " time and $" << moneyLost << endl;
}

/*
 * An encounter where the character gains a 
 * random amount of money and intelligence.
 * Parameter: character - attributes change
 * Return: None
 */
void doResearch(Character& character)
{
	cout << "You sit down to do some research. " << endl;
	int moneyGained = rand() % 6;
	Action moneyUp(REWARD, MONEY, moneyGained);
	int intelGained = rand() % 6;
	Action intelUp(REWARD, INTELLIGENCE, intelGained);
	int numActions = 2;
	Action actionArray[numActions];
	actionArray[0] = moneyUp;
	actionArray[1] = intelUp;
	Encounter research(actionArray, numActions);
	
	encounterResults(character, research);
	cout << "You gained $" << moneyGained << " and " << intelGained
		<< " intelligence. " << endl;
}

/*
 * An encounter where the character gains meager
 * wages and loses a random amount of intelligence.
 * Parameter: character - attributes change
 * Return: None
 */
void gruntWork(Character& character)
{
	cout << "You got stuck with grunt work!" << endl;
	int moneyGain = 1;
	Action moneyUp(REWARD, MONEY, moneyGain);
	int intelLost = rand() % 5 + 1;
	Action intelDown(PENALTY, INTELLIGENCE, intelLost);
	int numActions = 2;
	Action actionArray[numActions];
	actionArray[0] = moneyUp;
	actionArray[1] = intelDown;
	Encounter gruntWork(actionArray, numActions);

	encounterResults(character, gruntWork);
	cout << "You made $" << moneyGain << " and lost " << intelLost
		<< " intelligence. " << endl;
}

/*
 * Breaks down encounters and applies results
 * to character.
 * Parameters: character - attributes change
 * 	depending on encounter.
 *	encounter - holds an action type, 
 *	value, and attribute to be applied to
 * 	character. 
 */
void encounterResults(Character& character, Encounter encounter)
{	
	for(int i = 0; i < encounter.numOfActions; i++)
	{
		action_t result = encounter.actionArray[i].actionType;
		int changeAmt = encounter.actionArray[i].points;
		if(result == PENALTY)
		{
			changeAmt *= -1;
		}
	
			
		attribute_t changedAttribute = encounter.actionArray[i].attributeType;
		switch(changedAttribute)
		{
			case TIME:
				character.time += changeAmt;
				break;
			case MONEY:
				character.money += changeAmt;
				break;
			case INTELLIGENCE:
				character.intelligence += changeAmt;
				break; 
			default:
				break;
		}
	}
}
