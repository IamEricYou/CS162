/*********************************************************************
** Program Filename: Item.h
** Author: Jaehyung You
** Date: 07/11/2016
** Description: Item class defined
** Input: none
** Output: none
*********************************************************************/

#include <iostream>
#include <string>

using namespace std;

/*********************************************************************
** class: Item class
** Description: it will ask the user about the data
** Parameters: string, double pointer (array), int
** Pre-Conditions: pointer should be definded in List.h
** Post-Conditions: none
*********************************************************************/
class Item
{
private:
	 string item_name, item_unit;
	 int item_price, item_count, select;
public:
	 Item();
	 Item(string a, string b, int c, int d);
	 ~Item();
	 string GetName();
	 string GetUnit();
	 int GetPrice();
	 int GetCount();
	 void SetName(string a);
	 void SetUnit(string a);
	 void SetPrice(int a);
	 void SetCount(int a);
};
