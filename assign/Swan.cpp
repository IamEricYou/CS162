#include "Swan.h"

/****************************************************
** Function : move(reference object, object)
** Description : virtual class from the base class
** Parameters : reference object, object
** Pre-Conditions : using random number, so rand() is needed
** Post-Conditions : none
*****************************************************/
void Swan::move(Floor& floor, char temp)
{
	prev = Get_Pos();

	do{
		set_pos.Set_Xpos(0);
		set_pos.Set_Ypos(0);
		next = prev;
		swan_move = rand() % 4;
		if (swan_move == 0)
		{
			set_pos.Down_Xpos();
		}
		else if (swan_move == 1)
		{
			set_pos.Left_Ypos();
		}
		else if (swan_move == 2)
		{
			set_pos.Up_Xpos();
		}
		else if (swan_move == 3)
		{
			set_pos.Right_Ypos();
		}

		next.Set_Xpos(next.Get_Xpos() + set_pos.Get_Xpos());
		next.Set_Ypos(next.Get_Ypos() + set_pos.Get_Ypos());

	} while (Validate_move(next, floor));

	floor.Set_Board(prev.Get_Xpos(), prev.Get_Ypos(), Get_Standing_Board());

	if (Get_Standing_Board() == 'P')
		floor.Set_Board(prev.Get_Xpos(), prev.Get_Ypos(), ' ');

	Set_Point(floor.Get_Point_Board(next.Get_Xpos(), next.Get_Ypos()));
	Set_Pos(next);
	floor.Set_Board(next.Get_Xpos(), next.Get_Ypos(), 'S');
}

/****************************************************
** Function : Validate_move(object,object)
** Description : Validate Swan's move.
**				Every move is same as the player, but random
**				it can't go through the wall or locked door
** Parameters : object, object
** Pre-Conditions : none
** Post-Conditions : none
*****************************************************/
bool Swan::Validate_move(Position pos, Floor floor)
{
	Position Boardsize = floor.Get_Board_Size();
	char chekcer = floor.Get_Point_Board(pos.Get_Xpos(), pos.Get_Ypos());
	if (chekcer == '#')
	{
		return true;
	}
	if (chekcer == 'D')
	{
		return true;
	}
	if (chekcer == 'E')
	{
		return true;
	}
	if (pos.Get_Xpos()<0 || pos.Get_Ypos()<0 || pos.Get_Xpos()>Boardsize.Get_Xpos() || pos.Get_Ypos()>Boardsize.Get_Ypos())
	{
		return true;
	}
	return false;
}
