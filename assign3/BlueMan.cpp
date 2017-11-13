#include "BlueMan.h"
#include "Dice.h"
/************************************************
** Program Filename: BlueMan.cpp
** Author : Jaehyung You
** Date : 07 - 19 - 2016
** Description : BlueMan class description
** Input : none
** Output : BlueMan attack,defence, and armor
*************************************************/

#include <iostream>

using namespace std;

/************************************************
** Function : BlueMan constructor
** Description : initialize all BlueMan data (get the information)
** Parameters : none
** Pre-conditions : none
** Post-conditions : none
*************************************************/
BlueMan::BlueMan()
{
	name = "Blue Man";
	Attack = "2d10";
	Defence = "3d6";
	Armor = 3;
	Strength = 12;
	mob = 0;
}

/************************************************
** Function : int getArmor
** Description : get method
** Parameters : none
** Pre-conditions : it is from the abstract class
** Post-conditions : none
*************************************************/
int BlueMan::getArmor()
{
	return Armor;
}

/************************************************
** Function : getAttack()
** Description : get method
** Parameters : none
** Pre-conditions : it is from the abstract class
** Post-conditions : blueman loses his defence every 4 points lost his SP
*************************************************/
int BlueMan::getAttack()
{
	int rolls = 0, sides = 0;

	rolls = (this->Attack[0] - 48);
	sides = (this->Attack[2] - 48) * 10;

	if (this->getStrength() <= 8 && mob == 0)
	{
		cout << "[BlueMan loses 1 defence, because it loses 4 points of SP]" << endl;
		mob++;
	}
	if (this->getStrength() <= 4 && mob == 1)
	{
		cout << "[BlueMan loses 1 defence, because it loses 4 points of SP]" << endl;
		mob++;
	}
	if (Goblin_special)
	{
		return (Roll_dice(rolls, sides) / 2);
	}
	return Roll_dice(rolls, sides);
}

/************************************************
** Function : getDefence()
** Description : get method
** Parameters : none
** Pre-conditions : it is from the abstract class
** Post-conditions : none
*************************************************/
int BlueMan::getDefence()
{
	int rolls = 0, sides = 0;

	rolls = Defence[0] - 48 - mob;
	sides = Defence[2] - 48;

	return Roll_dice(rolls, sides);
}