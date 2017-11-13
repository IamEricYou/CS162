#include "Item.h"

/*********************************************************************
** Function: Item::Item()
** Description: constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Item::Item()
{
}
/*********************************************************************
** Function: Item::Item()
** Description: overloaded constructor
** Parameters: string , int
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Item::Item(string a, string b, int c, int d)
{
	 item_name = a;
	 item_unit = b;
	 item_price = c;
	 item_count = d;
}
/*********************************************************************
** Function: Item::~Item()
** Description: destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Item::~Item()
{
}
/*********************************************************************
** Function: Item::GetName()
** Description: Get() method
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: return name
*********************************************************************/
string Item::GetName()
{
	 return item_name;
}

/*********************************************************************
** Function: Item::GetUnit()
** Description: Get() method
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: return unit
*********************************************************************/
string Item::GetUnit()
{
	 return item_unit;
}

/*********************************************************************
** Function: Item::GetPrice()
** Description: Get() method
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: return price
*********************************************************************/
int Item::GetPrice()
{
	 return item_price;
}

/*********************************************************************
** Function: Item::GetCount()
** Description: Get() method
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: return count
*********************************************************************/
int Item::GetCount()
{
	 return item_count;
}

/*********************************************************************
** Function: Item::SetName()
** Description: Set() method
** Parameters: string
** Pre-Conditions: none
** Post-Conditions: save string value by using this pointer
*********************************************************************/
void Item::SetName(string a)
{
	 this->item_name = a;
}

/*********************************************************************
** Function: Item::SetUnit()
** Description: Set() method
** Parameters: string
** Pre-Conditions: none
** Post-Conditions: save string value by using this pointer
*********************************************************************/
void Item::SetUnit(string a)
{
	 this->item_unit = a;
}

/*********************************************************************
** Function: Item::SetPrice()
** Description: Set() method
** Parameters: int
** Pre-Conditions: none
** Post-Conditions: save string value by using this pointer
*********************************************************************/
void Item::SetPrice(int a)
{
	 this->item_price = a;
}

/*********************************************************************
** Function: Item::SetCount()
** Description: Set() method
** Parameters: int
** Pre-Conditions: none
** Post-Conditions: save string value by using this pointer
*********************************************************************/
void Item::SetCount(int a)
{
	 this->item_count = a;
}
