/************************************************
** Program Filename: Hydra.cpp
** Author : Jaehyung You
** Date : 07 - 19 - 2016
** Description : Hydra class description
** Input : none
** Output : hydra attack, armor, and defence. (it has special ability)
*************************************************/
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Hydra.h"
#include "Dice.h"

using namespace std;
/************************************************
** Function : Hydra constructor
** Description : it has the information of Hydra
** Parameters : none
** Pre-conditions : none
** Post-conditions : none
*************************************************/
Hydra::Hydra()
{
	name = "Hydra";
	Attack = "1d6";
	Defence = "1d6";
	Armor = 3;
	Strength = 12;
	hydra_head = 0;
}

/************************************************
** Function : int getArmor()
** Description : get method
** Parameters : none
** Pre-conditions : it is from the abstarct class
** Post-conditions : it has a random number. if 20% chance is met, the hydra has another a head for him
*************************************************/
int Hydra::getArmor()
{
	int hydra_special = rand()%5 + 1;

	if (hydra_special == 1)
	{
		this->Armor += 3;
		cout << "[ 20% chance ] " << endl;
		cout << "[ Hydra has one more head. Attack roll and armor is getting double ]" << endl;
		hydra_head++;
		return this->Armor;
	}
	else
	{
		return this->Armor;
	}
}

/************************************************
** Function :int getAttack()
** Description : get method
** Parameters : none
** Pre-conditions : it is from the abstract class
** Post-conditions : if the head is more than 1, the damage is double
*************************************************/
int Hydra::getAttack()
{
	int rolls = 0, sides = 0;
	rolls = (this->Attack[0] - 48) + hydra_head;
	sides = this->Attack[2] - 48;
	if (Goblin_special)
	{
		return (Roll_dice(rolls, sides) / 2);
	}
	return Roll_dice(rolls, sides);
}

/************************************************
** Function : int getDefence()
** Description :get method
** Parameters : none
** Pre-conditions : it is from the abstract class
** Post-conditions : none
*************************************************/
int Hydra::getDefence()
{
	int rolls = 0, sides = 0;

	rolls = Defence[0] - 48;
	sides = Defence[2] - 48;

	return Roll_dice(rolls, sides);
}

