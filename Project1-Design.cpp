/*
 * Allison Macdonald
 * amm0086
 * Project1-Design.cpp
 * Written in Vim; Compiled with g++;
 */

/* Prototypes */

//Asks player for name and stores it for greeting later
string getPlayerName(void);
//launches game by generating character and then
//calling selectAction()
void startGame(void);
//exits the game directly from the main menu
void exitGame(void);
//displays possible strategies and allows the player
//to choose one
void selectStrategy(Character& character);
//creates a Character struct with randomly generated attributes
Character generateCharacter(void);
//displays main menu
void displayMenu(Menu menu, Scoreboard board, Character& character);
//displays attributes of character
void viewCharacter(Character character);
//character loses a fixed amount of time and gains random money
void findChange(Character& character);
//character loses a fixed amount of time and gains random intel
void readPapers(Character& character);
//moves the character one unit of length down the hall and 
//randomly selects an encounter (which may include nothing)
void move(Character& character, Hallway& hall);
//checks to see if either character is dead (game is lost) or
//hallway is traversed (game is won), if neither game cont.
void checkStatus(Character character, Hallway hall);
//displays win message and ends game
void win(Character character);
//displys lose message and ends game
void lose(Character character);
//displays high scores
void viewScores(Scoreboard scores);
//loads high scores
int loadScores(Scoreboard& scores, char fileName[]);
//saves changed scores
int saveScores(Scoreboard scores, char fileName[]); 



void lose(void);

struct Score {
	string name;
	int score;
	Score* next;
};

typedef Score* scorePtr;
typedef unsigned short u_short;

struct ScoreBoard {
	u_short numScores;
	scorePtr firstScore;
};

Scoreboard gameBoard = {0, NULL};

struct Character {
	u_int intelligence;
	u_int time;
	u_int money;
	int score;
};

enum attribute_t {MONEY, TIME, INTELLIGENCE};
enum action_t {PENALTY, REWARD};

struct Action {
	action_t actionType;
	attrubute_t attributeType;
	u_short points;
};

int MAX_LENGTH = 5000;
int MAX_ACT_NUM = 6; //attributes*actions 

struct Puzzle {
	char question[MAX_LENGTH];
	char key[MAX_LENGTH];
	Action actionArray[MAX_ACT_NUM];
	u_short numOfActions;
};

struct Encounter {
	Action actionArray[MAX_ACT_NUM];
	u_short numOfActions;
};

enum mainMenu {START, DISPLAY, EXIT};

struct Menu {
	char greeting[MAX_LENGTH];
	mainMenu selections;
};

struct Hallway {
	int length; //length 20
	int traversed;
};

int main()
{
	//print welcome message
	//displayMenu();
	return 0;
}

string getPlayerName() {
	return ' ';
}


void startGame() {
}

void exitGame() {
}

void selectStrategy(Character& character) {
	//viewCharacter
	//quitGame & lose
	//look for change
	//move
	//readPapers
}

void generateCharacter() {
}

void displayMenu() {
}

void viewCharacter() {
}

void findChange() {
}

void readPapers() {
}

void move(Character& character, Hallway& hall) {
}

void checkStatus() {
}

void win(Character character) {
}

void lose(Character character) {
}

void viewScores(Scoreboard board) {
}

int loadScores(Scoreboard& board, char fileName[]) {
	return 0;
}

int saveScores(Scoreboard board, char fileName[]){
	return 0;
}



/* Begin Test Cases */

void testGetPlayerName()

{

string playerName = null;

getPlayerName();

assert(playerName != NULL);

}

void testStartGame()

{

testGenerateCharacter();

assert(hall != NULL);

assert(board != NULL);

}

void testExitGame()

{

//game quit

//not sure I can test this?

}

void testSelectStrategy()

{

int startTime = character.time;

selectStrategy(character);

int endTime = character.time;

assert(startTime > endTime);

}

void testGenerateCharacter()

{

startGame(character);

assert(character.intelligence != 0);

}

void testDisplayMenu()

{

int startTime = character.time;

displayMenu();

int endTime = character.time;

assert(startTime == endTime);

}

void testViewCharacter()

{

int startTime = character.time;

viewCharacter(character);

int endTime = character.time;

assert(startTime == endTime);

}

void testFindChange()

{

int startMoney = character.money;

findChange();

int endMoney = character.money;

assert(startMoney < endMoney);

}

void testReadPapers()

{

int startIntel = character.intelligence;

readPapers();

int endIntel = character.intelligence;

assert(startIntel < endIntel);

}

void testmove()

{

int startPosition = hall.traverse;

move();

int endPosition = hall.traverse;

assert(startPosition < endPosition);

//encounters and puzzles

int startTime = character.time;

int startIntel = character.intelligence;

int startMoney = character.money;

move();

assert(startTime != character.time || startIntel != character.intelligence || startMoney != character.money);

}

void testCheckStatus()

{

character.time = 0

checkStatus();

testLose();

hall.traverse = 20;

checkStatus();

testWin();

character.time = 10;

character.money = 10;

character.intelligence = 10;

hall.traverse = 10;

checkStatus();

testSelectStrategy();

}

void testWin()

{

character.time = 3

character.money = 2

character.intelligence = 1

int finalScore = win();

assert(finalScore = 6);

}

void testLose()

{

character.time = 0;

lose();

//prints a losing message

}

void testViewScores()

{

viewScores();

assert(board != NULL);

}

void testLoadScores()

{

loadScores();

assert(board.firstScore.score == 600);

}

void testSaveScores()

{

int score = 800;

saveScores(score);

assert(board.firstScore.score == 800);

} 
