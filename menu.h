#ifndef MENU_H
#define MENU_H

#include<iostream>
using namespace std;

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

#endif
