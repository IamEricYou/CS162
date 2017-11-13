/*********************************************************************
** Program Filename: App.h
** Author: Jaehyung You
** Date: 07/11/2016
** Description: Executive header file
** Input: none
** Output: none
*********************************************************************/


#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#define SIZE 4
#include "List.h"

using namespace std;

/*********************************************************************
** class: App class
** Description: executive class
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
class App
{
private:
	 int choice;
public:
	 App(){};
	 ~App(){};
	 void run();
};
