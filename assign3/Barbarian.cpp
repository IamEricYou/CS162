/************************************************
** Program Filename: Barbarian.cpp
** Author : Jaehyung You
** Date : 07 - 19 - 2016
** Description : Barbarican class description
** Input :none
** Output : Barbarian attack, defence and armor
*************************************************/

#include "Barbarian.h"
#include "Dice.h"
#include <iostream>

using namespace std;

/************************************************
** Function :Barbarian constructor
** Description : it has the information of Barbarian
** Parameters : none
** Pre-conditions : none
** Post-conditions : none
*************************************************/
Barbarian::Barbarian()
{
	name = "Barbarian";
	Attack = "2d6";
	Defence = "2d6";
	Armor = 0;
	Strength = 12;
}

/************************************************
** Function : int getArmor
** Description : getArmor
** Parameters : none
** Pre-conditions : it is from abstract class
** Post-conditions : none
*************************************************/
int Barbarian::getArmor()
{
	return Armor;
}

/************************************************
** Function : int getAttack
** Description : it will set the attack value
** Parameters : none
** Pre-conditions : it is from the abstract class
** Post-conditions : sensitive to Goblin_special
*************************************************/
int Barbarian::getAttack()
{
	int rolls = 0, sides = 0;
	rolls = this->Attack[0] - 48;
	sides = this->Attack[2] - 48;
	
	if (Goblin_special)
	{
		return (Roll_dice(rolls, sides) / 2);
	}
	return Roll_dice(rolls, sides);
}

/************************************************
** Function : int getDefence
** Description : get method
** Parameters : none
** Pre-conditions : none
** Post-conditions : none
*************************************************/
int Barbarian::getDefence()
{	
	int rolls = 0, sides = 0;

	rolls = Defence[0] - 48;
	sides = Defence[2] - 48;

	return Roll_dice(rolls, sides);
}