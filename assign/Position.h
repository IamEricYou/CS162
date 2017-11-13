/****************************************************************
** Program Filename : Position.h
** Author : Jaehyung You
** Date : 08 - 08 - 2016
** Description : Define the position and save the coordinates
**				 using Xpos and Ypos to determine the current position
** Input : none
** Output : none
*****************************************************************/

#ifndef POSITION_H
#define POSITION_H
class Position
{
private:
	int x_pos;
	int y_pos;
public:
	Position(){};
	~Position(){};

	int Get_Xpos(){ return x_pos; };
	int Get_Ypos(){ return y_pos; };
	void Set_Xpos(int num){ x_pos = num; };
	void Set_Ypos(int num){ y_pos = num; };
	void Up_Xpos(){ x_pos++; };
	void Down_Xpos(){ x_pos--; };
	void Right_Ypos(){ y_pos++; };
	void Left_Ypos(){ y_pos--; };
};

#endif