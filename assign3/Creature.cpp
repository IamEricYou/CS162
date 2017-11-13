/************************************************
** Program Filename: Creature.cpp
** Author : Jaehyung You
** Date : 07 - 19 - 2016
** Description : Creature class description // parent class
** Input : none
** Output : save all object
*************************************************/
#include <iostream>
#include "Creature.h"
#include "Dice.h"

using namespace std;

/************************************************
** Function : Creature constructor
** Description : initialize all variable
** Parameters : none
** Pre-conditions : none
** Post-conditions : none
*************************************************/
Creature::Creature()
{
	name = "";
	Attack = "";
	Defence = "";
	Armor = 0;
	Strength = 0;
	Goblin_special = false;
}
/************************************************
** Function : Creature destructor
** Description : delete every object in here
** Parameters : none
** Pre-conditions : none
** Post-conditions : none
*************************************************/
Creature::~Creature()
{
}

/************************************************
** Function : Creature constructor
** Description : it will get data from object
** Parameters : string, int
** Pre-conditions : none
** Post-conditions : data type will be returned by using get method
*************************************************/
Creature::Creature(string a, string b, string c, int d, int e)
{
	name = a;
	Attack = b;
	Defence = c;
	Armor = d;
	Strength = e;
}

/************************************************
** Function :string getName()
** Description : get method
** Parameters : none
** Pre-conditions : none
** Post-conditions : none
*************************************************/
string Creature::getName()
{
	return name;
}

/************************************************
** Function :int getStrength()
** Description :get method
** Parameters : none
** Pre-conditions : none
** Post-conditions : none
*************************************************/
int Creature::getStrength()
{
	return Strength;
}
/************************************************
** Function : void setStrength
** Description : set method
** Parameters : int
** Pre-conditions : none
** Post-conditions : none
*************************************************/
void Creature::setStrength(int s)
{
	Strength = s;
}
/************************************************
** Function : Goblin_attack
** Description : if goblin hits achilles, it will change value to 'true'
** Parameters : bool
** Pre-conditions : none
** Post-conditions : once it will turn to true, it is never change
*************************************************/
void Creature::Goblin_attack(bool check)
{
	if (check)
	{
		Goblin_special = true;
	}
}