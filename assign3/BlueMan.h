/************************************************
** Program Filename: BlueMan.h
** Author : Jaehyung You
** Date : 07 - 19 - 2016
** Description : BlueMan class
** Input : none
** Output : none
*************************************************/
#ifndef BlueMan_h
#define BlueMan_h

#include <cstdlib>
#include "Creature.h"

/************************************************
** Function : BlueMan class
** Description : What BlueMan does
** Parameters : none
** Pre-conditions : it has to have all virtual functions from the abstract class
** Post-conditions : none
*************************************************/
class BlueMan : public Creature
{
private:
	int mob;
public:
	BlueMan(); 
	int getArmor(); 
	int getAttack();
	int getDefence();
};

#endif