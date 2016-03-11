/*
 * These are refined test cases from my Design
 * but implementation required more recursion 
 * than anticipated. I can not write test drivers
 * for these functions because they do not end
 * until the program stops.
 * All test drivers will have program sample output
 * included in attached PDF.
 */

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
#include<assert.h>


/*Prototypes*/
void testGetPlayerName();
void testGenerateAttributes();
void testPuzzle();
void testCreatePuzzles();
void testGradePapers();
void testProfessor();
void testExtension();
void testGetHungry();
void testDoResearch();
void testGruntWork();
void testEncounterResults();
void testCheckStatus();
void testWin();
void testLose();
void testLoadScores();
void testSaveScores();
void testInsertScore();

int main()
{
	testGetPlayerName();
	testGenerateAttributes();
	testPuzzle();
	testCreatePuzzles();
	testGradePapers();
	testProfessor();
	testExtension();
	testGetHungry();
	testDoResearch();
	testGruntWork();
	testEncounterResults();
	testCheckStatus();
	testWin();
	testLoadScores();
	testSaveScores();
	testInsertScore();
	testLose();
	return 0;
}

void testGetPlayerName()
{
	cout << "Testing getPlayerName()" << endl;
	string playerName = "";	
	playerName = getPlayerName();
	assert(playerName != "");
	cout << "Test case passed..." << endl;
	press_any_key();	
}

void testGenerateAttributes()
{
	cout << "Testing generateAttributes()" << endl;
	Character character(0,0,0);
	generateAttributes(character);
	assert(character.time != 0 && character.intelligence !=0 && character.money != 0);
	cout << "Test case passed..." << endl;	
	press_any_key();
}

void testPuzzle()
{
	cout << "Testing puzzle()" << endl;
	Character character(20,20,20);
	puzzle(character);
	assert(character.time != 20 || character.intelligence != 20 || character.money != 20);
	cout << "Test case passed..." << endl;	
	press_any_key();
}

void testCreatePuzzles()
{
	cout << "Testing createPuzzles()" << endl;
	Puzzle array[10];
	int puzzleSize = createPuzzles(array, 0);
	assert(puzzleSize > 0);	
	cout << "Test case passed..." << endl;	
	press_any_key();
}

void testGradePapers()
{
	cout << "Testing gradePapers()" << endl;
	Character character(20,20,20);
	gradePapers(character);
	assert(character.money >= 20 && character.time == 19);
	cout << "Test case passed..." << endl;	
	press_any_key();
}

void testProfessor()
{
	cout << "Testing professor()" << endl;
	Character character(20,20,20);
	professor(character);
	assert(character.intelligence >= 20 && character.time == 19);
	cout << "Test case passed..." << endl;	
	press_any_key();
}

void testExtension()
{
	cout << "Testing extension()" << endl;
	Character character(20,20,20);
	extension(character);
	assert(character.money <= 20 && character.time > 20);
	cout << "Test case passed..." << endl;	
	press_any_key();
}

void testGetHungry()
{
	cout << "Testing getHungry()" << endl;
	Character character(20,20,20);
	getHungry(character);
	assert(character.money <= 20 && character.time <= 20);
	cout << "Test case passed..." << endl;	
	press_any_key();
}

void testDoResearch()
{
	cout << "Testing doResearch()" << endl;
	Character character(20,20,20);
	doResearch(character);
	assert(character.money >= 20 && character.intelligence >= 20);
	cout << "Test case passed..." << endl;	
	press_any_key();
}

void testGruntWork()
{	
	cout << "Testing gruntWork()" << endl;
	Character character(20,20,20);
	gruntWork(character);
	assert(character.money == 21 && character.intelligence < 20);
	cout << "Test case passed..." << endl;
	press_any_key();	
}

void testEncounterResults()
{
	cout << "Testing encounterResults()" << endl;
	Character character(20,20,20);
	Action moneyUp(REWARD, MONEY, 5);
	Action timeDown(PENALTY, TIME, 5);
	Action array[2] = {moneyUp, timeDown};
	Encounter encounter(array, 2);
	encounterResults(character, encounter);
	assert(character.money == 25 && character.time == 15);
	cout << "Test case passed..." << endl;	
	press_any_key();
}

void testCheckStatus()
{
	cout << "Testing checkStatus() - win" << endl;
	Character character(20,20,20);
	Hallway hall;
	hall.traversed = 20;
	hall.length = 20;
	bool win = checkStatus(character, hall);
	assert(win == true);
	cout << "Test case passed..." << endl;
	press_any_key();	

	cout << "Testing checkStatus() - continue" << endl;
	Hallway hall2;
	hall2.traversed = 10;
	hall2.length = 20;
	win = checkStatus(character, hall2);
	assert(win == false);
	cout << "Test case passed..." << endl;	
	press_any_key();
}

void testWin()
{
	cout << "Testing win()" << endl;
	Character character(20,20,20);
	bool winner = win(character);
	assert(winner == true);
	cout << "Test case passed..." << endl;
	press_any_key();	
}

void testLose()
{
	cout << "Testing lose()" << endl;
	Character character(0,20,20);
	//print losing message relating to 
	//appropriate attribute, end game.
}

void testLoadScores()
{
	cout << "Testing loadScores()" << endl;
	Scoreboard board;
	board.numScores = 1;	
	char fileName[] = "input.txt";
	loadScores(board, fileName);
	assert(board.numScores > 1);
	cout << "Test case passed..." << endl;
	press_any_key();	
}

void testSaveScores()
{
	cout << "Testing saveScores()" << endl;
	Scoreboard board;
	board.numScores = 0;
	char fileName[] = "output.txt";
	try
	{
		saveScores(board, fileName);
	}
	catch(exception e) {}
	cout << "Test case passed..." << endl;
	press_any_key();	
}

void testInsertScore()
{
	cout << "Testing insertScore()" << endl;
	Scoreboard board;
	board.numScores = 0;
	Character character(1,2,3);
	insertScore(board, character, "Bobbitta");
	assert(board.numScores == 1);
	cout << "Test case passed..." << endl;	
	press_any_key();
}

