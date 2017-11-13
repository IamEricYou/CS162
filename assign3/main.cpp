/************************************************
** Program Filename: main.cpp
** Author : Jaehyung You
** Date : 07 - 19 - 2016
** Description : main function
** Input : none
** Output : none
*************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Game.h"
#include "App.h"

using namespace std;
/************************************************
** Function : main.cpp
** Description : run the program
** Parameters : none
** Pre-conditions : none
** Post-conditions : none
*************************************************/
int main()
{
	system("clear");
	Game Dual;
	srand(time(NULL));

	Dual.Set_player1();
	Dual.Set_player2();
	Dual.Dual_start();
	Dual.Dual_over();
	
	return 0;
}


