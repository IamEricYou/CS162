/************************************************
** Program Filename: Dice.cpp
** Author : Jaehyung You
** Date : 07 - 19 - 2016
** Description : it has a dice function
** Input : rolls and sides
** Output : points
*************************************************/


#include "Dice.h"
#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

/************************************************
** Function : int Roll_dice
** Description : it is a core function. it will create random value based on Rolls and sides
** Parameters : int
** Pre-conditions : rolls and sides should be correct
** Post-conditions : none
*************************************************/
int Roll_dice(int rolls, int sides)
{
	int num = 0; 
	for (int i = 0; i < rolls; i++)
	{
		num += rand() % sides + 1;
	}

	return num;
}