#ifndef SYSTEM_H
#define SYSTEM_H

#include<iostream>
using namespace std;
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

#endif
