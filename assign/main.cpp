/****************************************************
** Program : main.cpp (Every other this description is in header files)
** Description : Get out from the maze
** Parameters : none
** Pre-Conditions : none
** Post-Conditions : none
*****************************************************/
#include "Game.h"
#include "Floor.h"
#include <cstdlib>
#include <time.h>

/****************************************************
** Function : main
** Description : run the program
** Parameters : int argc, char *argv[]
** Pre-Conditions : Command line argument must be valid
** Post-Conditions : none
*****************************************************/
int main(int argc, char *argv[])
{
	srand(time(NULL));
	Game game(argc, argv);
	game.play();
}