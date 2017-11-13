/************************************************
** Program Filename: Medusa.cpp
** Author : Jaehyung You
** Date : 07 - 19 - 2016
** Description : Meduca class description
** Input : none
** Output : Medusa attack,armor and defence
*************************************************/
#include "Medusa.h"
#include "Dice.h"
#include <iostream>

using namespace std;

/************************************************
** Function : Medusa constructor
** Description : it has the information of Medusa
** Parameters : none
** Pre-conditions : none
** Post-conditions : none
*************************************************/
Medusa::Medusa()
{
	name = "Medusa";
	Attack = "2d6";
	Defence = "1d6";
	Armor = 3;
	Strength = 8;
}

/************************************************
** Function : int getArmor()
** Description : get method
** Parameters : none
** Pre-conditions : it is from the abstract class
** Post-conditions : none
*************************************************/
int Medusa::getArmor()
{
	return Armor;
}

/************************************************
** Function : int getAttack()
** Description : set the attack of medusa
** Parameters : none
** Pre-conditions : it is from the abstract class
** Post-conditions : if the dice is 12, the game is over immediately
*************************************************/
int Medusa::getAttack()
{
	int rolls = 0, sides = 0;
	rolls = this->Attack[0] - 48;
	sides = this->Attack[2] - 48;

	if (Roll_dice(rolls, sides) == 12)
	{
		cout << "[Lucky ! DICE is rolled 12 in attack]" << endl;
		cout << "[Medusa used GLARE] - Opponent is turned into stone. You are the winner ! " << endl;
		return 10000;
	}
	if (Goblin_special)
	{
		return (Roll_dice(rolls, sides) / 2);
	}
	return Roll_dice(rolls, sides);
}

/************************************************
** Function :int getDefence()
** Description : get method
** Parameters : none
** Pre-conditions : none
** Post-conditions : none
*************************************************/
int Medusa::getDefence()
{
	int rolls = 0, sides = 0;

	rolls = Defence[0] - 48;
	sides = Defence[2] - 48;

	return Roll_dice(rolls, sides);
}