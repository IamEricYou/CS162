#include "Game.h"

/******************************************************
 * function name : Run();
 * Description : will play the game (instruction)
 * Parameters : none
 * pre-conditions : none
 * post-conditions : none
 * **************************************************/

void Game::run()
{
	Floor ff;
	
	int choice;
	cout << "What level do you want to see? " << endl;
	cout << "-> ";
	cin >> choice;

	switch(choice)
	{
	case 1:
		ff.floor_get(1);
		cout << "[Floor_A]" <<endl;
		break;
	case 2:
		ff.floor_get(2);
		cout << "[Floor_B]" <<endl;
		break;
	case 3:		
		ff.floor_get(3);
		cout << "[Floor_C]" << endl;
		break;
	default :
		cout << "input must be 1,2 or 3" <<endl;
		run();
	}
}
