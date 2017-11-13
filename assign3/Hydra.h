/************************************************
** Program Filename: Hydra.h
** Author : Jaehyung You
** Date : 07 - 19 - 2016
** Description : Hydra class
** Input : none
** Output : none
*************************************************/
#ifndef Hydra_h
#define Hydra_h

#include <cstdlib>
#include "Creature.h"

/************************************************
** Function : Hydra class
** Description : What Hydra does
** Parameters : none
** Pre-conditions : it has to have all virtual functions from the abstract  class
** Post-conditions :none
*************************************************/
class Hydra : public Creature
{
private:
	int hydra_head;
public:
	Hydra();   
	int getArmor(); 
	int getAttack();
	int getDefence();
};

#endif