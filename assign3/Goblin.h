/************************************************
** Program Filename: Goblin.h
** Author : Jaehyung You
** Date : 07 - 19 - 2016
** Description : Goblin class
** Input : none
** Output : none
*************************************************/
#ifndef Goblin_h
#define Goblin_h

#include "Creature.h"

/************************************************
** Function : Goblin class
** Description : What Goblin does
** Parameters : none
** Pre-conditions : has to have all virtual fucntions from the abstract class
** Post-conditions : none
*************************************************/
class Goblin : public Creature
{
public:

	Goblin(); 
	int getArmor(); 
	int getAttack();
	int getDefence();
};

#endif