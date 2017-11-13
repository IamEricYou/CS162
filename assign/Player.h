/****************************************************************
** Program Filename : Player.h
** Author : Jaehyung You
** Date : 08 - 08 - 2016
** Description : Player move, having apple, having keys. All player moves here
** Input : none
** Output : player moving, show status of the player
*****************************************************************/

#ifndef PLAYER_H
#define PLAYER_H
#include "Actor.h"
using namespace std;

class Player : public Actor, public Floor
{
private:
	int count_keys;
	int count_apples;
	bool apple_beats_swan;
	char player_board;
public:
	Player();
	~Player(){};
	void power_on();
	void power_off();
	void Consume_Apple();
	void Check_Player_board(Position, Floor&);
	void move(Floor&, char);
	int getKeys();
	int getApples();
};
#endif