/****************************************************************
** Program Filename : Floor.h
** Author : Jaehyung You
** Date : 08 - 08 - 2016
** Description : Getting board from text file and save into dynamic array
** Input : Text file
** Output : floors
*****************************************************************/

#ifndef FLOOR_H
#define FLOOR_H
#include <iostream>
#include <string>
#include <cstdlib>
#include "Position.h"

using namespace std;

class Floor
{
private:
	char point;
	char** board;
	Position board_size, start, pos;
	string* board_temp; //Save into temporary board and pass to the main board
protected:
	Position set_pos, prev, next;
public:
	Floor()
	{
		board_size.Set_Xpos(0);
		board_size.Set_Ypos(0);
		point = ' ';
	};
	Floor(Position start)
	{
		pos = start;
	}
	Floor(Floor &temp);
	~Floor();
	char** Get_Full_Board();
	char Get_Point_Board(int, int);
	char Get_Standing_Board();
	void Delete_board();
	void Update_Board1(string, int);
	void Update_Board2();
	void Update_size(string);
	void Set_Board(int, int, char);
	void Set_Start(Position);
	void Set_Point(char);
	void Set_Pos(Position);
	void Print_Board();
	string Get_Temp_Size(int);
	Position Get_Board_Size();
	Position Get_Start();
	Position Get_Pos();
};
#endif
