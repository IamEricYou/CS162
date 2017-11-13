/************************************************
** Program Filename: App.cpp
** Author : Jaehyung You
** Date : 07 - 19 - 2016
** Description : it will run the whole program
** Input : numbers from user
** Output : select a creature and to go on.
*************************************************/
#include "App.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/************************************************
** Function : choose_creature
** Description : display the instruction
** Parameters : none
** Pre-conditions : number should be 1 to 5
** Post-conditions : none
*************************************************/
void Choose_creature()
{
	cout << "[Creature Dual]" << endl;
	cout << "[You have to choose your creature to fight]" << endl;
	cout << "[1] Goblin (A: 2d6, D: 1d6, Armor: 3, SP : 8 - Special Ability : Hits achilles)" << endl;
	cout << "[2] Barbarian (A: 2d6, D: 2d6, Armor: 0, SP : 12)" << endl;
	cout << "[3] Medusa (A: 2d6, D: 2d6, Armor: 3, SP : 8 - Special Ability : Glare)" << endl;
	cout << "[4] Blue Men (A: 2d10, D: 3d6, Armor: 3, SP : 12)" << endl;
	cout << "[5] Hydra (A: 1d6, D: 1d6, Armor: 3, SP : 8 - Special Ability : Grows new head)" << endl;
}

/************************************************
** Function : int user_input
** Description : input validation (just for integer)
** Parameters : none
** Pre-conditions : none
** Post-conditions : none
*************************************************/
int User_input()
{
	int input=0;
	do
	{
		cout << "[Your Choice 1 to 5 ] -> ";
		cin >> input;
	} while (input > 5 || input < 1);
	cout << endl;
	return input;
}

/************************************************
** Function : int Make_pause()
** Description :it will pause the program 
** Parameters : none
** Pre-conditions : none
** Post-conditions : none
*************************************************/
int Make_pause()
{
	int pause;
	cout << "Press Any Number To Continue ";
	cin >> pause;
	return pause;
}
