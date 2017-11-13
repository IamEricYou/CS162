#include "Player.h"
#include <iostream>

/****************************************************
** Function : Player constructor
** Description : Initialize all value
** Parameters : none
** Pre-Conditions : it has keys, apples and apple_beats_swan(power)
** Post-Conditions : none
*****************************************************/
Player::Player()
{
	count_keys = 0;
	count_apples = 0;
	apple_beats_swan = false;
}

/****************************************************
** Function : power_on()
** Description : Ate apple.
** Parameters : none
** Pre-Conditions : none
** Post-Conditions : bool type will be true
*****************************************************/
void Player::power_on()
{
	apple_beats_swan = true;
}
/****************************************************
** Function : power_off()
** Description : didn't eat apple
** Parameters : none
** Pre-Conditions : none
** Post-Conditions : bool type will be false
*****************************************************/
void Player::power_off()
{
	apple_beats_swan = false;
}

/****************************************************
** Function : Consume_apple()
** Description : If the player ate apple, it reduces 1 apple
** Parameters : none
** Pre-Conditions : Apple can't be more than 2
** Post-Conditions : none
*****************************************************/
void Player::Consume_Apple()
{
	count_apples--;
}

/****************************************************
** Function : Check_Player_Board(Object,reference Object)
** Description : it will find right move. (if the player steps on the
**               'K', the player gets the key.
** Parameters :object, reference object
** Pre-Conditions : Array must be valid and accurate
** Post-Conditions : none
*****************************************************/
void Player::Check_Player_board(Position pos, Floor& floor)
{
	player_board = Get_Standing_Board();
	if (player_board == 'K')
	{
		if (count_keys<3)
		{
			count_keys++;
			Set_Point(' ');
		}
	}
	if (player_board == 'D')
	{
		count_keys--;
		Set_Point(' ');
	}
	if (player_board == 'A')
	{
		if (count_apples<2)
		{
			count_apples++;
			Set_Point(' ');
		}
	}
	if (player_board == 'S')
	{
		Set_Point(' ');
	}
	for (int i = -1; i<2; i++)
	{
		for (int j = -1; j<2; j++)
		{
			if (floor.Get_Point_Board(pos.Get_Xpos() + i, pos.Get_Ypos() + j) == 'S' && !apple_beats_swan)
			{
				floor.Set_Board(pos.Get_Xpos(), pos.Get_Ypos(), Get_Standing_Board());
				Set_Pos(Get_Start());
				Set_Point('E');
			}
		}
	}
}

/****************************************************
** Function : move(reference object, char)
** Description : Virtual function from the base class
** Parameters : reference object, char
** Pre-Conditions : Parent class's fucntion must be defined as a pure virtual fucntion
** Post-Conditions : none
*****************************************************/
void Player::move(Floor &floor, char input)
{
	prev = Get_Pos();

	set_pos.Set_Xpos(0);
	set_pos.Set_Ypos(0);
	next = prev;

	if (input == 'W')
	{
		set_pos.Down_Xpos();
	}
	else if (input == 'A')
	{
		set_pos.Left_Ypos();
	}
	else if (input == 'S')
	{
		set_pos.Up_Xpos();
	}
	else if (input == 'D'){
		set_pos.Right_Ypos();
	}

	next.Set_Xpos(next.Get_Xpos() + set_pos.Get_Xpos());
	next.Set_Ypos(next.Get_Ypos() + set_pos.Get_Ypos());

	floor.Set_Board(prev.Get_Xpos(), prev.Get_Ypos(), Get_Standing_Board());
	Set_Point(floor.Get_Point_Board(next.Get_Xpos(), next.Get_Ypos()));
	Set_Pos(next);
	floor.Set_Board(next.Get_Xpos(), next.Get_Ypos(), 'P');
	Check_Player_board(next, floor);
}

/****************************************************
** Function : getKeys()
** Description : get method to count the keys
** Parameters : none
** Pre-Conditions : none 
** Post-Conditions : none
*****************************************************/
int Player::getKeys()
{
	return count_keys;
}

/****************************************************
** Function :getApples()
** Description : get method to count the apples
** Parameters : none
** Pre-Conditions : none
** Post-Conditions : none
*****************************************************/
int Player::getApples()
{
	return count_apples;
}
