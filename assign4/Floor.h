/**********************************************************
 * Program filename : Floor.h Floor.cpp
 * Author : Jaehyung You
 * Data: 07 - 29 - 2016
 * Description : will save and print the floor
 * Input : none
 * Output : current floor
 * ******************************************************/

#ifndef FLOOR_H_
#define FLOOR_H_

#define ROW 20
#define COL 31

#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

class Floor
{
private:
	char **board;
public:
	Floor()
	{
		board = new char*[COL+1];
		for(int i=0;i<COL+1;i++)
		{
			board[i] = new char[COL+1];
		}
	};
	~Floor()
	{
		for(int i=0;i<COL+1;i++)
			delete[] board[i];
		delete[] board;
	};
	void floor_get(int choice);
};

#endif
