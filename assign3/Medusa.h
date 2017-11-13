/************************************************
** Program Filename: Medusa.h
** Author : Jaehyung You
** Date : 07 - 19 - 2016
** Description : Medusa class
** Input : none
** Output : none
*************************************************/
#ifndef Medusa_h
#define Medusa_h

#include <cstdlib>
#include "Creature.h"

/************************************************
** Function : Medusa class
** Description : What Medusa does
** Parameters : none
** Pre-conditions : has to have all virtual functions from the abstract class
** Post-conditions : none
*************************************************/
class Medusa : public Creature
{
public:
	Medusa();  
	int getArmor(); 
	int getAttack();
	int getDefence();
};

#endif