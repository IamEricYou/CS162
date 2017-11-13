/****************************************************************
** Program Filename : Swan.h
** Author : Jaehyung You
** Date : 08 - 08 - 2016
** Description : Swan's move and validate moving as a random number
** Input : none
** Output : none
*****************************************************************/


#ifndef SWAN_H
#define SWAN_H
#include "Actor.h"
#include <cstdlib>
#include <time.h>

using namespace std;

class Swan : public Actor, public Floor
{
	int swan_move;
public:
	Swan(){};
	~Swan(){};
	void move(Floor&, char);
	bool Validate_move(Position, Floor);
};

#endif