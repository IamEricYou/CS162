/****************************************************************
** Program Filename : Game.h
** Author : Jaehyung You
** Date : 08 - 08 - 2016
** Description : Run the game in here. Every excutable function.
** Input : some charactor
** Output : Moving charactor
*****************************************************************/

#ifndef GAME_H
#define GAME_H
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "Floor.h"
#include "Player.h"
#include "Swan.h"
#include "Position.h"

using namespace std;

class Game
{
private:
	ifstream fstream;
	Floor floor;
	Swan* swans;
	Player player;
	int total_floors, current_floor, swan_count, swan_step, step_apple, howmany;
	string make_pause;
public:
	//Game();
	Game(int, char*[]);
	~Game(){};
	void inst();
	void play();
	void Swan_load();
	void Swan_make();
	void Swan_new();
	void Floor_make();
	void Floor_load(int);
	void Player_load();
	void print_win();
	void Set_Swan_Apple();
	char Validate_input();
	bool Validate_floor(string);
	bool Validate_move(char);
};
#endif
