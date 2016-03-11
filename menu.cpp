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

/* Constructor for Menu */
Menu::Menu(): greeting("Hello. Please enter the number for your selection: ")
{
} 

/*
 * Displays main menu to player. Player may start
 * game, view high scores, or exit program. If an 
 * invalid option is selected, the function will 
 * ask the player again.
 * Parameters: Menu&, Scoreboard, Character&, Hallway& 
 * 	all neccesary for the game to proceed.
 * Returns: None
 */
void displayMenu(Menu& menu, Scoreboard board, Character& character, Hallway& hall)
{
	int selection;
	cout << menu.greeting << endl
		<< "1. Start Game " << endl
		<< "2. View High Scores " << endl
		<< "3. Exit " << endl
		<< "Enter number here: ";
	cin >> selection;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	cout << endl;

	menu.selection = static_cast<mainMenu>(selection);

	switch(menu.selection)
	{
		case START:
			startGame(character, hall);
			break;
		case DISPLAY:
			viewScores(menu, board, character, hall);
			break;
		case EXIT: 
			exitGame();
			break;
		default:
			cout << "Please select a valid option. " << endl;
			displayMenu(menu, board, character, hall);
			break;
	}
}

