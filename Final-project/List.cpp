/*********************************************************************
** Program Filename: List.cpp
** Author: Jaehyung You
** Date: 07/11/2016
** Description: contains all functions which are declared by other classes
** Input: some numbers
** Output: display the items
*********************************************************************/

#include "App.h"


/*********************************************************************
** Function: List::List()
** Description: constructor
** Parameters: none	
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
List::List()
{
	 arr_count = 0;
	 shopping = new Item*[SIZE];
	 shopping[0] = 0;
}

/*********************************************************************
** Function: List::~list()
** Description: destructor (deallocate arrays)
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
List::~List()
{
	 for (int i = 0; i < arr_count; i++)
	 {
		  delete[] shopping[i];
	 }
	 delete[] shopping;

}
/*********************************************************************
** Function: List::GetTempName()
** Description: Get method
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
string List::GetTempName()
{
	 return temp_name;
}

/*********************************************************************
** Function: List::Add_item()
** Description: it will ask data from user
** Parameters: none
** Pre-Conditions: inputs should be valid. 
** Post-Conditions: existed item can't be done
*********************************************************************/
void List::Add_item()
{
		  cout << "[-------ADD ITEM-------]" << endl;
		  cout << "[NAME] : ";
		  cin >> temp_name;
		  for (int i = 0; i < arr_count; i++)
		  {
			   if (temp_name == shopping[i]->GetName())
			   {
					App app;
					cin >> temp_count;
					//Add_exist(i);
					app.run();
			   }
		  }
		  cout << "[OK, Now you are adding " << temp_name << "]" << endl;
		  cout << "[UNIT] : ";
		  cin >> temp_unit;
		  cout << "[PRICE] : ";
		  cin >> temp_price;
		  cout << "[QUANTITY] : ";
		  cin >> temp_count;
		  shopping[arr_count++] = new Item(temp_name, temp_unit, temp_price, temp_count);
		  cout << "[YOU HAVE] " << arr_count << " [ITEM(s) in the cart] "<<endl;
}

/*********************************************************************
** Function: List::Add_exist();
** Description: it will delete exist array and create new array from new input
** Parameters: int i
** Pre-Conditions: i is passed by in-loop
** Post-Conditions: none
*********************************************************************/
void List::Add_exist(int i)
{
	 cout << " * Warning * This item is already in the cart ! This will be added into the existed one " << endl;
	 cout << "You can only add or substract item's quantity : ";
	 cin >> temp_count;
	 temp_name = shopping[i]->GetName();
	 temp_count = shopping[i]->GetCount();
	 temp_unit = shopping[i]->GetUnit();
	 temp_price = shopping[i]->GetPrice();
	 for (int j = 0; j < arr_count; ++j)
	 {
		  for (int k = 0; k < arr_count - 1; ++k)
		  {
			   shopping[k] = shopping[k + 1];
		  }
		  --arr_count;
	 }
	 cout << temp_price << endl;
	 shopping[++arr_count] = new Item(temp_name, temp_unit, temp_price, temp_count);
}

/*********************************************************************
** Function: List::Remove_Item()
** Description: It will remove Items
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void List::Remove_item()
{
	 if (shopping[0] == 0)
	 {
		  cout << "[ CART IS EMPTY! ] " << endl;
	 }
	 cout << endl;
	 cout << "[REMOVE ITEM]" << endl;
	 cout << "[NAME]  :";
	 cin >> temp_name;
	 for (int i = 0; i < arr_count; ++i)
	 {
		  if (shopping[i]->GetName() == temp_name)
		  {
			   for (int j = i; j < arr_count - 1; ++j)
			   {
					shopping[j] = shopping[j + 1];
			   }
			   --arr_count;
			   if (arr_count == 0)
					shopping[0] = 0;
			   cout << "[1 ITEM IS JUST REMOVED ] " << endl;
			   cout << endl;
		  }
		  else if (i == arr_count-1)
		  {
			   cout << " [ NO MATCHING ITEM NAME ]  " << endl;
		  }
	 }
}

/*********************************************************************
** Function: List::Display_item();
** Description: it will show all data from user
** Parameters: none
** Pre-Conditions: array shoud be saved correctly
** Post-Conditions: none
*********************************************************************/
void List::Display_item()
{
	 total_sum = 0;
	 cout.width(10);
	 cout << "[DISPLAY ITEM]" << endl;
	 if (shopping[0] == 0)
	 {
		  cout << "[NO ITEM] " << endl;
	 }

	 cout << "[  ITEM(s)  ]     [ UNIT ]   [ $PRICE ]   [ QUANTITY ]   [$EXTENDED PRICE] " << endl; 
	 for (int i = 0; i < arr_count; ++i)
	 {
		  cout << "[" << i + 1 << "] " << shopping[i]->GetName() << setw(10);
		  cout << setw(16) << shopping[i]->GetUnit();
		  cout << setw(10) << shopping[i]->GetPrice();
		  cout << setw(14) << shopping[i]->GetCount();
		  cout << setw(15) << (shopping[i]->GetPrice() * shopping[i]->GetCount());
		  total_sum += (shopping[i]->GetPrice() * shopping[i]->GetCount());
		  cout << endl;
	 }
	 cout << endl;
	 cout << "[TOTAL PRICE] $" << total_sum << endl;
}

/*********************************************************************
** Function: bool operator==
** Description: it will compare two string in object   
** Parameters: object
** Pre-Conditions: it is overloaded operator, so the condition has to be met
** Post-Conditions: none
*********************************************************************/
bool operator==(Item item,Item item1)
{
	 return item.GetName() == item1.GetName();
}
