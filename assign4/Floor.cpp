#include "Floor.h"

/***********************************************************
 * Fucntion name : floor_get()
 * Description : will load the floor from the text file, save into the array and display the array.
 * Parameters : int level
 * precondition : text file should be correct!
 * postcondition : none
 * *********************************************************/

#define FloorA "FloorA.txt"
#define FloorB "FloorB.txt"
#define FloorC "FloorC.txt"

void Floor::floor_get(int choice)
{
	fstream fstream;
	if(choice == 1)
		fstream.open(FloorA);
	else if(choice == 2)
		fstream.open(FloorB);
	else
		fstream.open(FloorC);

	if(fstream.fail())

	{
		cout << "Board DOESN'T EXIST" <<endl;
		exit(1);
	}
	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<=COL;j++)
		{		
			board[i][j] = fstream.get();
		}
	}

	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<COL-1;j++)
		{
			if(!(board[i][j] == '#' || board[i][j] == 'D' || board[i][j] == 'L' || board[i][j] == 'P' || board[i][j] == 'S' || board[i][j] == 'K' || board[i][j] == 'A' || board[i][j] == 'E' || board[i][j] == 'X' || board[i][j] == ' '))
			{
				cout << "Board has some weird character. The game is ended. " << endl;
				exit(1);
			}
		}
	}	
	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<=COL;j++)
		{		
			cout << board[i][j];
		}
	}
	fstream.close();
}

