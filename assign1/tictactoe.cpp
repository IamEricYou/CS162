/*********************************************************************
** Program Filename: tictactoe.cpp
** Author: Jaehyung You
** Date: 06/28/2016
** Description: contains all functions which are declared by the game class
** Input: some numbers of columns and rows
** Output: Tictactoe board
*********************************************************************/

#include "tictactoe.h"

/*********************************************************************
** Function: void setboard()
** Description: it will set the board
** Parameters: none
** Pre-Conditions: enter 1 to play with AI
** Post-Conditions: none
*********************************************************************/ 
void game::setboard()
{
   automate = 0;
   cout << "If you want to play with AI enter 1, otherwise press any number :";
   cin >> automate; // these two lines will ask you to play with AI
   system("clear");
	for(int a=0;a<3;a++)
	   for(int b=0; b<3; b++)
		  tic[a][b] = 0;
	result = 0;
	player = 1;
}

/*********************************************************************
** Function: void move()
** Description: it will make your move
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void game::move()
{
   if(automate == 1 && player == 1)
   {
	    cout << "Now you are playing with AI" << endl;
		cout << "You are ' O ' choose the spot " << endl;
		cout << "Column ? (1~3): ";
		cin >> move1;
		cout << "Row ? (1~3): ";
		cin >> move2;
   }
   else if(automate == 1 && player == 2)
   {
		move1 = rand()%3+1;
		move2 = rand()%3+1;
   }
   else
   {
	cout << "Now Player" << player << " 's turn (Player1 = O / Player2 = X) " << endl; 
	cout << "Column ? (1 ~ 3): ";
	cin >> move1;
	cout << "Row ? (1 ~ 3): ";
	cin >> move2;
   }
	i = move1 - 1;
	j = move2 - 1;
}

/*********************************************************************
** Function: void playgame()
** Description: it will actual run the game
** Parameters: none
** Pre-Conditions: every input should be legit.
** Post-Conditions: none
*********************************************************************/ 
void game::playgame()
{
   setboard();
    while(1)
	{
		status(tic);
		move();
		if((i<0 || i>2) || (j<0 || j>2)) // if input doesn't between 0 ~ 2
		{
			cout << " It is out of range. Please do it again with valid input ! " << endl;
			cout << " You can re-do after a second. " << endl;
			sleep(1);
			move();
		}
		if(tic[i][j] == 0)
		{
			tic[i][j] = player;
			if (player == 1)
			   player = 2;
			else
			   player = 1;
		}
		else
		{
		   if(automate != 1 || player==1)
		   {
		   	cout << "That move can't be made. other player already did that point. " << endl;
		   	cout << "You can re-do after 2 second. " << endl;
		   	sleep(2);
		   }
		}
		if (win(tic,player) == 1) // determine winner 
		   break;
		finalboard(tic, result); 
		if (result == 1)
		{
			status(tic);
			cout << "There is no empty place to put, game is ended" << endl;
			playagain();
		}
	}
	status(tic);
	if(result == 0)
	{
	   cout << "Player" << player << " is winner!!!! " << endl;
	   playagain();
	}
}

/*********************************************************************
** Function: void prt()
** Description: it will set the board from your move
** Parameters: int 2D array, int , int
** Pre-Conditions: should be initialized by function setboard()
** Post-Conditions: it will re-set the board when game is done
*********************************************************************/ 
void game::prt(int t[][3], int i, int j)
{
	if (t[i][j] == 0)
	   cout << " \t*\t|";
	if (t[i][j] == 1)
	   cout << " \tO\t|";
	if (t[i][j] == 2)
	   cout << " \tX\t|";
}

/*********************************************************************
** Function: void status()
** Description: it will display the board
** Parameters: int 2D array
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void game::status(int t[][3])
{
   	 system("clear");
   	 cout << "1|";
	 prt(t, 0, 0);
	 prt(t, 0, 1);
	 prt(t, 0, 2);
	 cout << endl << endl;
	 cout << "2|"; 
	 prt(t, 1, 0);
	 prt(t, 1, 1);
	 prt(t, 1, 2);
	 cout << endl << endl;
	 cout << "3|";
	 prt(t, 2, 0);
	 prt(t, 2, 1);
	 prt(t, 2, 2);
	 cout << endl << endl;
}

/*********************************************************************
** Function: int win()
** Description: it will determine the winner. 
** Parameters: int 2D array, int reference variable
** Pre-Conditions: none
** Post-Conditions: every winning condition should be met
*********************************************************************/ 
int game::win(int t[][3], int &winner)
{
   	 int i, j;
	 	
	 for (j = 1; j<3; j++)
	 {
    	 for (i = 0; i<3; i++) // horizental
		 {
		 	 if (t[i][0] == j&&t[i][1] == j&&t[i][2] == j)
		     {
				winner =j; 		  		  			   			
				return 1; // winner set. return. 
		 	  }
		 }
		 for (i = 0; i<3; i++) // vertical
		 {
		 	if (t[0][i] == j&&t[1][i] == j&&t[2][i] == j)
		 	{
		 		winner = j;
	  		  	return 1;
		    }
		 }
		 if (t[0][0] == j&&t[1][1] == j&&t[2][2] == j) // diogonal
		 {
		 	winner = j;
		    return 1;
		 }
		 if (t[0][2] == j&&t[1][1] == j&&t[2][0] == j)
		 {
		 	winner = j;
		 	return 1;
		 }
	 }
		 return 0; 
}

/*********************************************************************
** Function: int finalboard()
** Description: it will check the board, if the board is full
** Parameters:int 2D array, int reference variable
** Pre-Conditions: none
** Post-Conditions: if the board is full, the game would be over
*********************************************************************/ 
int game::finalboard(int t[][3], int &result) //determine it can go more
{
   	 int i, j;
	 for (i = 0; i<3; i++)
	 {
		for (j = 0; j<3; j++)
		{
		   if (t[i][j] == 0)
			{
			   return 0; // exit funtion
			}
		}
	 }
   	result = 1;
	return 0;
}

/*********************************************************************
** Function: void playagain();
** Description: it will ask you to play again
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void game::playagain()
{
	char select;
   	cout << "Do you want to play again? (y,n) : ";
	cin >> select;
	switch(select)
	{
	case 'y':
		  cout << "start over! " << endl;
		  playgame();
		  break;
	case 'n':
		  cout << " \n Good Bye ! " << endl;
		  exit(1);
		  break;
	default:
		  cout << "Select 'y' or 'n'" << endl;
		  playagain();
		  break;
	}
}
