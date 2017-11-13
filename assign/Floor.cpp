#include "Floor.h"
/****************************************************
** Function : Floor Constructor
** Description : It will create dynamic 2D arrays based on the size of the text file
** Parameters :  Floor referense value
** Pre-Conditions : Text file must have number of the size
** Post-Conditions : none
*****************************************************/

Floor::Floor(Floor &temp)
{
	board_size = temp.Get_Board_Size();
	board = new char*[board_size.Get_Xpos()];
	for (int i = 0; i<board_size.Get_Xpos(); i++)
	{
		board[i] = new char[board_size.Get_Ypos()];
	}
	board_temp = new string[board_size.Get_Xpos()];

	for (int i = 0; i<board_size.Get_Xpos(); i++)
	{
		for (int j = 0; j<board_size.Get_Ypos(); j++)
		{
			board[i][j] = temp.Get_Point_Board(i, j);
		}
		board_temp[i] = temp.Get_Temp_Size(i);
	}
}

/****************************************************
** Function : Floor Destructor
** Description : It will delete all allocated memory
** Parameters : none
** Pre-Conditions : none
** Post-Conditions : none
*****************************************************/
Floor::~Floor()
{
	if (board_size.Get_Xpos()>0 || board_size.Get_Ypos()>0)
	{
		for (int i = 0; i<board_size.Get_Xpos(); i++)
		{
			delete[] board[i];
		}
		delete[] board;
	}
	delete[] board_temp;
}

/****************************************************
** Function : Get_Full_board()
** Description : Get method to bring the board (double pointer = 2D array)
** Parameters : none
** Pre-Conditions : none
** Post-Conditions : none
*****************************************************/
char** Floor::Get_Full_Board()
{
	return board;
}

/****************************************************
** Function : Get_Point_Board(int,int)
** Description : Getting specific point on the board
** Parameters : int, int
** Pre-Conditions : none
** Post-Conditions : none
*****************************************************/
char Floor::Get_Point_Board(int xpos, int ypos)
{
	return board[xpos][ypos];
}

/****************************************************
** Function : Get_Standing_Board()
** Description : Getting the point that you currently stand on
** Parameters : none
** Pre-Conditions : none
** Post-Conditions : none
*****************************************************/
char Floor::Get_Standing_Board()
{
	return point;
}

/****************************************************
** Function : Delete_board()
** Description : Delete current floor to get next floor
** Parameters : none
** Pre-Conditions : array must be allocated properly
** Post-Conditions : none
*****************************************************/
void Floor::Delete_board()
{
	if (board_size.Get_Xpos()>0 || board_size.Get_Ypos()>0)
	{
		for (int i = 0; i<board_size.Get_Xpos(); i++)
		{
			delete[] board[i];
		}
		delete[] board;
		delete[] board_temp;
	}
}

/****************************************************
** Function : Update_Board1(string,int)
** Description : It will update new board as saving into a temporary board
** Parameters :string ,num
** Pre-Conditions : this function will work as a tester for getting right board (also chekcing size)
** Post-Conditions : none
*****************************************************/
void Floor::Update_Board1(string str, int num)
{
	board_temp[num] = str;
}

/****************************************************
** Function : Update_Board2()
** Description : If the board is legit, temporary board will be saved into main board.
** Parameters : none
** Pre-Conditions : the board must be legit
** Post-Conditions : none
*****************************************************/
void Floor::Update_Board2()
{
	for (int i = 0; i<board_size.Get_Xpos(); i++)
	{
		for (int j = 0; j<board_size.Get_Ypos(); j++)
		{
			board[i][j] = board_temp[i][j];
		}
	}
}

/****************************************************
** Function : Set_Board(int,int,char)
** Description : You can put charactor on the floor in specific location with using this function
** Parameters : int, int, char
** Pre-Conditions : none
** Post-Conditions : none
*****************************************************/
void Floor::Set_Board(int xpos, int ypos, char ch)
{
	board[xpos][ypos] = ch;
	board_temp[xpos][ypos] = ch;
}

/****************************************************
** Function : Update_size(string)
** Description : This will check the size of the new floor
** Parameters : string
** Pre-Conditions : TEXT FILE MUST HAVE SIZE IN THE FIRST LINE 
** Post-Conditions : none
*****************************************************/
void Floor::Update_size(string str)
{
	string size_row, size_col;
	for (int i = 0; i<str.size(); i++)
	{
		if (str[i] == ' ')
		{
			size_row = str.substr(0, i);
			size_col = str.substr(i + 1, str.size());
			board_size.Set_Xpos(atoi(size_row.c_str()));
			board_size.Set_Ypos(atoi(size_col.c_str()));
		}
	}
	board = new char*[board_size.Get_Xpos()];
	for (int i = 0; i<board_size.Get_Xpos(); i++)
	{
		board[i] = new char[board_size.Get_Ypos()];
	}
	board_temp = new string[board_size.Get_Xpos()];
}

/****************************************************
** Function : Print_Board()
** Description : This will print board.
** Parameters : none
** Pre-Conditions : none
** Post-Conditions : none
*****************************************************/
void Floor::Print_Board()
{
	system("clear");
	for (int i = 0; i<board_size.Get_Xpos(); i++)
	{
		for (int j = 0; j<board_size.Get_Ypos(); j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}

/****************************************************
** Function : Set_Start(object)
** Description : Set Method
** Parameters : object
** Pre-Conditions : none
** Post-Conditions : none
*****************************************************/
void Floor::Set_Start(Position temp)
{
	start = temp;
}

/****************************************************
** Function : Set_Point(char)
** Description : Set Method
** Parameters : char
** Pre-Conditions : none
** Post-Conditions : none
*****************************************************/
void Floor::Set_Point(char ch)
{
	point = ch;
}

/****************************************************
** Function : Set_pos(object)
** Description : Set Method
** Parameters : object
** Pre-Conditions : none
** Post-Conditions : none
*****************************************************/
void Floor::Set_Pos(Position temp)
{
	pos = temp;
}

/****************************************************
** Function : Get_Temp_Size(int)
** Description : Get Method
** Parameters : integer
** Pre-Conditions : none
** Post-Conditions : none
*****************************************************/
string Floor::Get_Temp_Size(int num)
{
	return board_temp[num];
}

/****************************************************
** Function : Get_Board_Size()
** Description : Get Method
** Parameters : none
** Pre-Conditions : none
** Post-Conditions : none
*****************************************************/
Position Floor::Get_Board_Size()
{
	return board_size;
}

/****************************************************
** Function : Get_Start()
** Description : Get Method
** Parameters : none
** Pre-Conditions : none
** Post-Conditions : none
*****************************************************/
Position Floor::Get_Start()
{
	return start;
}

/****************************************************
** Function : Get_Pos()
** Description : Get Method
** Parameters : none
** Pre-Conditions : none
** Post-Conditions : none
*****************************************************/
Position Floor::Get_Pos()
{
	return pos;
}
