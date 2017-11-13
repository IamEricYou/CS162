/*********************************************************************
** Program Filename: App.cpp
** Author: Jaehyung You
** Date: 07/11/2016
** Description: App class definition here
** Input: some numbers as selections
** Output: menu
*********************************************************************/
#include "App.h"

/*********************************************************************
** Function: App::run();
** Description: it will run the all classes
** Parameters: none
** Pre-Conditions: list has to be declared
** Post-Conditions:  none
*********************************************************************/

void App::run()
{
	 system("clear");
	 List list;
	
	 while (true)
	{
	  cout << "[Welcome to my Shopping list]" << endl;
	  cout << "[1] ADD ITEM "<< endl;
	  cout << "[2] REMOVE ITEM" << endl;
	  cout << "[3] DISPLAY ITEMS" << endl;
	  cout << "[4] QUIT " << endl;
	  cin >> choice;
 		switch (choice)
		{
	  	case 1:
	   	list.Add_item();
	   	break;
	  	case 2:
	  	list.Remove_item();
	    break;
	 	case 3:
	   	list.Display_item();
	   	break;
	 	case 4:
	   	cout << " Good bye!! " << endl;
	   	exit(1);
	   	break;
	 	default:
	   	cout << "Please enter 1 - 4 " << endl;
	}
	}
}
