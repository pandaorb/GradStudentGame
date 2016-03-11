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

/* Constructors for Puzzle */
Puzzle::Puzzle()
{
}

Puzzle::Puzzle(string questionIn, string keyIn, Action actionArrayIn[], u_short numOfActionsIn) : question(questionIn), key(keyIn), numOfActions(numOfActionsIn) 
{
	for(int i = 0; i < numOfActions; i++)
	{
		actionArray[i] = actionArrayIn[i];
	}
}

/* 
 * An encounter in which the player must answer
 * a question to determine the effect of the 
 * encounter on the character.
 * Parameter: Character& - attributes change
 * Return: None
 */
void puzzle(Character& character)
{
	int const MAX_PUZZLES = 10;
	Puzzle allPuzzles[MAX_PUZZLES];
	int numPuzzles = createPuzzles(allPuzzles, 0);
	int randIndex = rand() % numPuzzles;
	Puzzle currentPuzzle = allPuzzles[randIndex];

	string answer;
	cout << currentPuzzle.question << endl;
	getline(cin, answer);
	
	for(int i = 0; i < currentPuzzle.numOfActions; i++)
	{			
		int changedAttribute = currentPuzzle.actionArray[i].attributeType;
		int changeAmt = currentPuzzle.actionArray[i].points;
		action_t result = REWARD;
		string messageStart = "You gained ";
		string messageEnd;
		if (answer != currentPuzzle.key) 
		{
			result = PENALTY;
			changeAmt *= -1;
			messageStart = "You lost ";
		}
		if(currentPuzzle.actionArray[i].actionType == result)
		{
			 switch(changedAttribute)
               		 {
                        	case TIME:
                               		character.time += changeAmt;
					messageEnd = " time.";
                                	break;
                        	case MONEY:
                                	character.money += changeAmt;
					messageEnd = " money.";
                                	break;
                        	case INTELLIGENCE:
                                	character.intelligence += changeAmt;
					messageEnd = " intelligence.";
                                	break;
                        	default:
                                	break;
                	}
			if(changeAmt < 0) { changeAmt *= -1; }
			cout << messageStart << changeAmt << messageEnd << endl;
		}
	}

}

/* 
 * Creates an array of Puzzles that can be 
 * randomly selected from when the player
 * encounters a puzzle.
 * Parameters: Puzzle[] - takes an array of puzzles
 * 	puzzleArraySize - takes size of puzzle array
 * Return: Puzzle array size.
 */
int createPuzzles(Puzzle puzzleArray[], int puzzleArraySize)
{
	int numResults = 2;
	int randReward = rand() % 5 + 1;
	int randPenalty = rand() % 5 + 1;
	Action timeCorrect(REWARD, TIME, randReward);
	Action timeIncorrect(PENALTY, TIME, randPenalty);
	Action moneyCorrect(REWARD, MONEY, randReward);
	Action moneyIncorrect(PENALTY, MONEY, randPenalty);
	Action intelCorrect(REWARD, INTELLIGENCE, randReward);
	Action intelIncorrect(PENALTY, INTELLIGENCE, randPenalty);

	Action timeResults[numResults];
	timeResults[0] = timeCorrect;
	timeResults[1] = timeIncorrect;
	Action moneyResults[numResults];
	moneyResults[0] = moneyCorrect;
	moneyResults[1] = moneyIncorrect;
	Action intelResults[numResults];
	intelResults[0] = intelCorrect;
	intelResults[1] = intelIncorrect;

	int index = 0;

	Puzzle puzzle1("How long was the shortest war on record? (Hint: how many minutes?)", "38", timeResults, numResults);
	puzzleArray[index] = puzzle1;
	index++;
	
	Puzzle puzzle2("What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany?)", "Bank of Italy", moneyResults, numResults);	
	puzzleArray[index] = puzzle2;
	index++;

	Puzzle puzzle3("What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports?)", "Wii Sports", intelResults, numResults);
	puzzleArray[index] = puzzle3;
	index++;

	Puzzle puzzle4("What is 2 + 2? ", "4", intelResults, numResults);
	puzzleArray[index] = puzzle4;
	index++;

	Puzzle puzzle5("In the Disney movie, Big Hero 6, Hiro tells Baymax he is allergic to what?", "Bacitracin", moneyResults, numResults);
	puzzleArray[index] = puzzle5;
	index++;

	Puzzle puzzle6("What is the name of the enemy dragon in Elder Scrolls IV: Skyrim? ", "Alduin", timeResults, numResults);
	puzzleArray[index] = puzzle6;
	index++;
	
	Puzzle puzzle7("Where is Frozone's super-suit?", "Why do you need to know?", moneyResults, numResults);
	puzzleArray[index] = puzzle7;
	index++;

	puzzleArraySize = index;

	return puzzleArraySize;
}
