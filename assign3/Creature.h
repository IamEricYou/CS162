/************************************************
** Program Filename: Creature.h
** Author : Jaehyung You
** Date : 07 - 19 - 2016
** Description : Parent class. it has virtual classes
** Input : none
** Output : none
*************************************************/
#ifndef Creature_h
#define Creature_h

#include <cstdlib>
#include <string>
using std::string;

/************************************************
** Function : Creature class
** Description : Parent class have three virtual classes
** Parameters : none
** Pre-conditions : none
** Post-conditions : all virtual class must be defined in childern class
*************************************************/
class Creature
{
protected:
	string name;
	string Attack;
	string Defence;
	int Armor;
	int Strength;
	bool Goblin_special;

public:
	Creature();    
	Creature(string, string, string, int, int); 
	~Creature(); 
	string getName();   
	virtual int getAttack() = 0;   
	virtual int getDefence() = 0;  
	virtual int getArmor() = 0;
	int getStrength();  
	void setStrength(int); 
	void Goblin_attack(bool check);
};

#endif