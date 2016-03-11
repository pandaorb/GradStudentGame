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

/* Constructors for Score */
Score::Score()
{
}

Score::Score(string nameIn, int scoreIn): name(nameIn), score(scoreIn), next(NULL)
{
}

Score::Score(string nameIn, int scoreIn, ScorePtr nextIn): name(nameIn), score(scoreIn), next(nextIn)
{
}

/* Constructors for Scoreboard */
Scoreboard::Scoreboard() : numScores(0)
{
}

Scoreboard::Scoreboard(u_short totalScores, ScorePtr startingScore): numScores(totalScores), firstScore(startingScore)
{
}


/*
 * Displays scores from scoreboard.
 * Parameters: menu - return to menu
 * 	board - contains scores
 * 	character - return to menu
 *	hall - return to menu
 * Return: None
 */
void viewScores(Menu& menu, Scoreboard board, Character& character, Hallway& hall)
{
	ScorePtr current = board.firstScore;
	cout << "Name \t\t Score" << endl;
	for(int i = 1; i <= board.NUM_HIGH_SCORES; i++)
	{
		cout << i << "." << current->name << "\t" << current->score << endl;
		current = current->next;
	}
	delete current;
	current = NULL;
	press_any_key();
	displayMenu(menu, board, character, hall);
}

/*
 * Load scores from a file provided by player.
 * Parameters: board - stores scores in board
 * 	fileName[] - file to read scores from
 * Return 0 if successful.
 */
int loadScores(Scoreboard& board, char fileName[])
{
	string data;
	ifstream inStream;
	inStream.open(fileName);
	if(inStream.fail())
	{
		cout << "Input file opening failed. " << endl;
		exit(1);
	}
	inStream >> data;
	ScorePtr root = NULL;
	ScorePtr current = NULL;
	while(!inStream.eof())
	{
		try
		{
			ScorePtr newScore = new Score();
			newScore->name = data;
			inStream >> data;
			newScore->score = atoi(data.c_str());
			if(root == NULL)
			{
				current = newScore;
				root = newScore;
			}
			else
			{
				current->next = newScore;
				current = newScore;
			}
			board.numScores++;
			inStream >> data;
			newScore = newScore->next;
			delete newScore;
		}
		catch (exception e)
		{
			cout << "An exception occured." << endl;
		}
	}
	inStream.close();
	board.firstScore = root;
	current = current->next;
	delete current;
	root = NULL;
	delete root;
	return 0;
}

/*
 * Saves scores from scoreboard to an output
 * file specified by the player.
 * Parameters: board - copy of the scoreboard
 *	fileName[] - file to save scores to
 * Return 0 if successful
 */
int saveScores(Scoreboard board, char fileName[])
{
	ofstream outStream;
	outStream.open(fileName);
	ScorePtr current = board.firstScore;
	for(int i = 0; i < board.numScores; i++)
	{
		outStream << current->name << endl;
		outStream << current->score << endl;
		
		if(current->next != NULL)
		{
			current = current->next;
		}
	}
	current = NULL;
	delete current;
	outStream.close();
	cout << "Please check the new file - " << fileName << endl;
	return 0;
}

/*
 * Inserts a score in order to the scoreboard.
 * Parameters: board - access to scores on board
 *	character - calculates winning score
 *	playerName - stores player name with score
 * Returns: None
 */
void insertScore(Scoreboard& board, Character character, string playerName)
{
	ScorePtr newScore = new Score();
	newScore->score = character.time * character.intelligence * character.money;
	newScore->name = playerName;
	ScorePtr previous = NULL;
	ScorePtr current = board.firstScore;
	for(int i = 0; i < board.numScores; i++)
	{
		//insert first
		if (current->score < newScore->score && previous == NULL) 
		{
			newScore->next = current;
			board.firstScore = newScore;
			break;
		}
		else if (current->score < newScore->score)
		{
			newScore->next = current;
			previous->next = newScore;
			break;
		}
		//insert last
		else if(current->next == NULL)
		{
			current->next = newScore;
			break;
		}
		previous = current;
		current = current->next;
	}
	current = NULL;
	delete current;
	previous = NULL;
	delete previous;
	board.numScores++;
}
