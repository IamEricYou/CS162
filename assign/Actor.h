/****************************************************************
** Program Filename : Actor.h
** Author : Jaehyung You
** Date : 08 - 08 - 2016
** Description : Abstract Class for Player.h and Swan.h
** Input : none
** Output : none
*****************************************************************/

#ifndef ACTOR_H
#define ACTOR_H
#include "Floor.h"
#include "Position.h"
using namespace std;

class Actor
{
private:
public:
	virtual void move(Floor&, char) = 0;
};
#endif