/*********************************************************************
** Program Filename: List.h
** Author: Jaehyung You
** Date: 07/11/2016
** Description: All functions are here
** Input: some numbers
** Output: display the items
*********************************************************************/
#include "Item.h"

/*********************************************************************
** class: List 
** Description: It has all functions.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
class List
{
private:
	 Item **shopping;
	 string temp_name, temp_unit;
	 int arr_count,arr_size, temp_price, temp_count, total_sum;
public:
	 List();
	 ~List();
	 string GetTempName();
	 void Add_item();
	 void Add_exist(int i);
	 void Remove_item();
	 void Display_item();
	 bool operator==(Item item);
};
