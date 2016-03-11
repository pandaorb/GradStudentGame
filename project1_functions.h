#ifndef PROJECT1_FUNCTIONS_H
#define PROJECT1_FUNCTIONS_H

#include<iostream>
using namespace std;

/* Structures */

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


/*
 * Character structure will contain attributes for 
 * a character which will be the main player inside
 * of the game.
 */
struct Character {
	int intelligence;
	int time;
	int money;

	Character();
	Character(u_short intIn, u_short timeIn, u_short moneyIn);
};


/* 
 * Possible selections for main menu. Begins
 * at one because menu begins at one.
 */
enum mainMenu {START = 1, DISPLAY, EXIT};

/*
 * Menu will display a greeting an allow the 
 * player to choose a course of action with 
 * the program.
 */
struct Menu {
	string greeting;
	mainMenu selection;

	Menu();
};


/*
 * Hallway represents the hall being walked along
 * by the character. The hall has a total length
 * and keeps track of how many steps the character
 * has already taken.
 */
struct Hallway {
	int length;
	int traversed;
	
	Hallway();
	Hallway(int lengthIn);
};

/*
 * List of character attributes that can be
 * affected by an action.
 */
enum attribute_t {MONEY, TIME, INTELLIGENCE};

/*
 * Allows an action to be either a penalty
 * or reward.
 */
enum action_t {PENALTY, REWARD};

/*
 * Action structure is a type of action that
 * either raises or lowers a character
 * attribute by a certain number of points.
 */
struct Action {
	action_t actionType;
	attribute_t attributeType;
	u_short points;

	Action();
	Action(action_t actionIn, attribute_t attributeIn, u_short pointsIn);
};

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

/* Prototypes */
string getPlayerName(void);
void displayMenu(Menu&, Scoreboard, Character&, Hallway&);
void startGame(Character&, Hallway&);
void generateAttributes(Character&);
void selectStrategy(Character&, Hallway&);
void viewCharacter(Character&, Hallway);
void findChange(Character&, Hallway);
void readPapers(Character&, Hallway);
void walk(Character&, Hallway&);
void puzzle(Character&);
int createPuzzles(Puzzle puzzleArray[], int puzzleArraySize);
void gradePapers(Character&);
void professor(Character&);
void extension(Character&);
void getHungry(Character&);
void doResearch(Character&);
void gruntWork(Character&);
void encounterResults(Character&, Encounter);
bool checkStatus(Character&, Hallway);
bool win(Character&);
void lose(Character&);
int loadScores(Scoreboard& board, char fileName[]);
void viewScores(Menu&, Scoreboard, Character&, Hallway&);
int saveScores(Scoreboard board, char fileName[]);
void insertScore(Scoreboard&, Character, string);
void exitGame(void);
void press_any_key(void);
int mygetch(void);

#endif
