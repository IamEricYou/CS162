/************************************************
** Program Filename: Game.cpp
** Author : Jaehyung You
** Date : 07 - 19 - 2016
** Description : Game class description
** Input : numbers
** Output : it will display all the current score or board
*************************************************/

#include <iostream>
#include "Game.h"
#include "App.h"
#include "Barbarian.h"
#include "Medusa.h"
#include "BlueMan.h"
#include "Goblin.h"
#include "Hydra.h"
#include "Creature.h"

using namespace std;

/************************************************
** Function : Game contructor
** Description : initialize player1 and player2
** Parameters : none
** Pre-conditions : none
** Post-conditions : none
*************************************************/
Game::Game()
{
	player1 = NULL;
	player2 = NULL;
}

/************************************************
** Function : Dual_over()
** Description : it will delete players for preventing leak memory
** Parameters : none
** Pre-conditions : player should be allocated 
** Post-conditions : none
*************************************************/
void Game::Dual_over()
{
	delete player1;
	delete player2;
}

/************************************************
** Function : Set_player1
** Description : player1 can choose his/her creature
** Parameters : none
** Pre-conditions : number must be 1 to 5
** Post-conditions : none
*************************************************/
void Game::Set_player1()
{
	int choice = 0;

	cout << "[ Now Player 1 is choosing ]" << endl;

	Choose_creature();
	choice = User_input();

	if (choice == 1)
	{
		player1 = new Goblin();
		name1 = "Player1 - Goblin";
	}
	else if (choice == 2)
	{
		player1 = new Barbarian();
		name1 = "Player1 - Barbarian";
	}
	else if (choice == 3)
	{
		player1 = new Medusa();
		name1 = "Player1 - Medusa";
	}
	else if (choice == 4)
	{
		player1 = new BlueMan();
		name1 = "Player1 - BlueMan";
	}
	else if (choice == 5)
	{
		player1 = new Hydra();
		name1 = "Player1 - Hydra";
	}
}

/************************************************
** Function : Set_player2
** Description : player2 can choose his/her creature
** Parameters : none
** Pre-conditions : number must be 1 to 5
** Post-conditions : none
*************************************************/
void Game::Set_player2()
{
	int choice = 0;

	cout << "[ Now Player 2 is choosing ]" << endl;

	Choose_creature();
	choice = User_input();

	if (choice == 1)
	{
		player2 = new Goblin();
		name2 = "Player2 - Goblin";
	}
	else if (choice == 2)
	{
		player2 = new Barbarian();
		name2 = "Player2 - Barbarian";
	}
	else if (choice == 3)
	{
		player2 = new Medusa();
		name2 = "Player2 - Medusa";
	}
	else if (choice == 4)
	{
		player2 = new BlueMan();
		name2 = "Player2 - BlueMan";
	}
	else if (choice == 5)
	{
		player2 = new Hydra();
		name2 = "Player2 - Hydra";
	}
}

/************************************************
** Function : Dual_start()
** Description : it will display all the current event
** Parameters : none
** Pre-conditions : all data should be valid 
** Post-conditions :  none
*************************************************/
void Game::Dual_start()
{
	 int attackRoll = 0, defenceRoll = 0, damage = 0, armor = 0, round = 0;
	
	 cout << "[Instruction]" << endl;
	 cout << "[Damage = 'Attack Roll' - 'Defence Roll' - 'Armor']" << endl;
	 cout << "[If Defence Roll or Armor is greater than Attack Roll, damage couldn't be taken]" << endl;

	do
	{
		Make_pause();
		cout << endl << "------------------[Round " << round + 1 << "]------------------" << endl;
		cout << endl;
		if (round % 2 == 0)
		{
			cout << "["<<name1 << "] ------> [" << name2 <<"]" << endl;
			cout << endl;
	
			attackRoll = player1->getAttack();
			cout << "[Attack Roll] : " << attackRoll << endl;
			defenceRoll = player2->getDefence();
			cout << "[Defence Roll] : " << defenceRoll << endl;

			if (defenceRoll >= attackRoll)
			{
				cout << "[Attack Blocked] -> [Defence Roll] > [Attack Roll] " << endl;
			}

			else if (attackRoll > defenceRoll)
			{
				armor = player2->getArmor();
				damage = (attackRoll - defenceRoll) - (armor);

				if (damage > 0)
				{
					cout << "[Damage] = [Attack Roll (" << attackRoll << ")] - [Defence Roll (" << defenceRoll << ")] - [Armor (" << armor << ")] = " << damage << endl;
					player2->setStrength(player2->getStrength() - damage);
				}
				else
				{
					cout << "[No Damage] -> [Total Damage] < [Defence Roll] + [Armor] " << endl;
				}
			}

			cout << "[ Player 1 Strength: " << player1->getStrength() <<" ]"<< endl;
			cout << "[ Player 2 Strength: " << player2->getStrength() <<" ]"<< endl;
		}

		else if (round % 2 != 0 && player2->getStrength() > 0)
		{
			cout << "[" << name2 << "] ------> [" << name1 << "]" << endl;
			cout << endl;

			attackRoll = player2->getAttack();

			cout << "[Attack Roll] : " << attackRoll << endl;

			defenceRoll = player1->getDefence();

			cout << "[Defence Roll] : " << defenceRoll << endl;

			if (defenceRoll >= attackRoll)
			{
				cout << "[Attack Blocked] -> [Defence Roll] > [Attack Roll] " << endl;
			}

			else if (attackRoll > defenceRoll)
			{
				armor = player1->getArmor();

				damage = (attackRoll - defenceRoll) - (armor);

				if (damage > 0)
				{
					cout << "[Damage] = [Attack Roll (" << attackRoll << ")] - [Defence Roll (" << defenceRoll << ")] - [Armor (" << armor << ")] = " << damage << endl;
					player1->setStrength(player1->getStrength() - damage);
				}
				else
				{
					cout << "[No Damage] -> [Total Damage] < [Defence Roll] + [Armor] " << endl;
				}
			}

			cout << "[ Player 1 Strength: " << player1->getStrength() << " ]" << endl;
			cout << "[ Player 2 Strength: " << player2->getStrength() << " ]" << endl;
		}
		round++;

	} while (player1->getStrength() > 0 && player2->getStrength() > 0);

	if (player2->getStrength() <= 0)
	{
		cout << endl;
		cout << "[" <<name1 <<"] Wins! "<< endl;
	}

	if (player1->getStrength() <= 0)
	{
		cout << endl;
		cout << "[" << name2 << "] Wins! " << endl;
	}

}
