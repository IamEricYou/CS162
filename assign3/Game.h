/************************************************
** Program Filename: Game.h
** Author : Jaehyung You
** Date : 07 - 19 - 2016
** Description : Game class
** Input : none
** Output : none
*************************************************/

#ifndef Game_h
#define Game_h

#include <cstdlib>
#include "Creature.h"

/************************************************
** Function : Game class
** Description : it has all procedure for the program
** Parameters : none
** Pre-conditions : it is run by App.h
** Post-conditions : none
*************************************************/
class Game
{
private:
	 string name1;
	 string name2;
protected:
	Creature* player1;
	Creature* player2;

public:
	Game();     
	void Dual_over();    
	void Set_player1(); 
	void Set_player2(); 
	void Dual_start();     
	void SetGoblin();
};

#endif
