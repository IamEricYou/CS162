/*********************************************************************
** Program Filename: tictactoe.h
** Author: Jaehyung You
** Date: 06/28/2016
** Description: game class and the libraries
** Input: none
** Output: none
*********************************************************************/

#include <iostream>
#include <cstdlib> 
#include <unistd.h>
#include <time.h>
#include <string.h>

using namespace std;

class game
{
   int tic[3][3];
   int player,i,j,result,move1,move2,automate;
   public:
	  void setboard();
   	  void move();
	  void playgame();
	  void prt(int t[][3], int i, int j); 
	  void status(int t[][3]);
	  int win(int t[][3], int &winner);
	  int finalboard(int t[][3], int &result);
	  void playagain();
};
