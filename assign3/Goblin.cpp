/************************************************
** Program Filename: Goblin.cpp
** Author : Jaehyung You
** Date : 07 - 19 - 2016
** Description : Include Goblin class.
** Input : none
** Output : Goblin attack, armor and defence
*************************************************/

#include <iostream>
#include "Goblin.h"
#include "Dice.h"

using namespace std;

/************************************************
** Function : Goblin constructor
** Description : it has the information of Goblin
** Parameters : none
** Pre-conditions : none
** Post-conditions : none
*************************************************/
Goblin::Goblin()
{
	name = "Goblin";
	Attack = "2d6";
	Defence = "1d6";
	Armor = 3;
	Strength = 8;
}

/************************************************
** Function : int getArmor
** Description : get method
** Parameters : none
** Pre-conditions : it is from the abstract class
** Post-conditions : none
*************************************************/
int Goblin::getArmor()
{
	return Armor;
}

/************************************************
** Function : getAttact()
** Description : get method
** Parameters : none
** Pre-conditions : it is from the abstract class
** Post-conditions : if the dice is 12, the opponent's attack roll is reduced as a half
*************************************************/
int Goblin::getAttack()
{
	int rolls = 0, sides = 0;
	rolls = this->Attack[0] - 48;
	sides = this->Attack[2] - 48;
	if (Roll_dice(rolls, sides) == 12)
	{
		cout << "[Lucky!! Attack Dice is 12, Goblin hits enemy's achilles]" << endl;
		cout << "[From now, enemy's Attack Roll is half - it only occurs once]" << endl;
		Goblin_attack(true);
		return 12;
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
int Goblin::getDefence()
{
	int rolls = 0, sides = 0;

	rolls = Defence[0] - 48;
	sides = Defence[2] - 48;

	return Roll_dice(rolls, sides);
}