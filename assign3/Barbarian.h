/************************************************
** Program Filename: Barbarian.h
** Author : Jaehyung You
** Date : 07 - 19 - 2016
** Description : Barbarian class
** Input : none
** Output : none
*************************************************/

#ifndef Barbarian_h
#define Barbarian_h

#include <cstdlib>
#include "Creature.h"

/************************************************
** Function : Barbarian class (child class of Creature)
** Description : Barbarian description
** Parameters : none
** Pre-conditions : none
** Post-conditions : define in Barbarian.cpp
*************************************************/
class Barbarian : public Creature
{
public:
	Barbarian(); 
	int getArmor(); 
	int getAttack();
	int getDefence();
};

#endif