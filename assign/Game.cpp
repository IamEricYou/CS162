#include "Game.h"

//Game::Game(){};

/****************************************************
** Function : Game Constructor
** Description : This will bring the command line arguments and set everything for game 
** Parameters : int argc, char* argv[] 
** Pre-Conditions :  Command line argument must be valid
** Post-Conditions :  none
*****************************************************/
Game::Game(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "[Error - invalid command line arguments]" << endl;
		cout << "[Must run by the following instruction ]" << endl;
		cout << " ./prog1 # (number of the text file) "<< endl;
		exit(1);
	}
	
	total_floors = atoi(argv[1]);

	howmany = atoi(argv[1]);
	swan_step = 0;
	current_floor = 1;
	step_apple = -1;
	Floor_load(current_floor);
	Player_load();
	Swan_load();
}

/****************************************************
** Function : Validate_floor(string)
** Description : This will validate array for invalid input in Text file
** Parameters : string
** Pre-Conditions : using temp array to check
** Post-Conditions : if it contains any of these, the program is over
*****************************************************/
bool Game::Validate_floor(string board_check)
{
	for (int i = 0; i<board_check.size(); i++)
	{
		if (board_check[i] != '#' && board_check[i] != 'D' && board_check[i] != 'L' && board_check[i] != 'S' && board_check[i] != 'K' && board_check[i] != 'A' && board_check[i] != 'E' && board_check[i] != 'X' && board_check[i] != ' ' && board_check[i] != 13)
		{
			cout << "Wrong file input!!!!! -> " << board_check[i] << endl;
			return false;
		}
	}
	return true;
}

/****************************************************
** Function : Floor_load
** Description : It will load floors from the text file
** Parameters : int
** Pre-Conditions : Text file name must be valid
** Post-Conditions : none
*****************************************************/
void Game::Floor_load(int num)
{
	stringstream file;
	string input;

	file << "floor_" << num << ".txt";
	fstream.open(file.str().c_str(), ifstream::in);
	if (!fstream)
	{
		cout << "[Error - Floor file can't be valid] " << endl;
		cout << "[Floor name must be floor_#.txt   ] " << endl;
		cout << "[Please try again with valid file!] " << endl;
		exit(1);
	}
	else
	{
		getline(fstream, input);
		floor.Update_size(input);
		Position size = floor.Get_Board_Size();

		for (int i = 0; i<size.Get_Xpos(); i++)
		{
			input = "";
			getline(fstream, input);
			if (Validate_floor(input))
			{
				floor.Update_Board1(input, i);
			}
			else
			{
				cout << "[INVAILD FLOOR MAP FILE]" << endl;
				cout << "[PLEASE CHECK AND RETRY]" << endl;
				exit(1);
			}
		}
		floor.Update_Board2();
		fstream.close();
	}
}

/****************************************************
** Function : Player_load()
** Description : It will find 'E' and place 'P'
** Parameters : none
** Pre-Conditions : 'E' Must be in the floor
** Post-Conditions : none
*****************************************************/
void Game::Player_load()
{
	Position start = floor.Get_Board_Size();
	Position size = floor.Get_Board_Size();

	for (int i = 0; i<size.Get_Xpos(); i++)
	{
		for (int j = 0; j<size.Get_Ypos(); j++)
		{
			if (floor.Get_Point_Board(i, j) == 'E')
			{
				start.Set_Xpos(i);
				start.Set_Ypos(j);
			}
		}
	}
	player.Set_Point('E');
	player.Set_Start(start);
	player.Set_Pos(start);
	swan_step = 0;
}

/****************************************************
** Function : Swan_load()
** Description : it will find 'S' and bring Swans
** Parameters : none
** Pre-Conditions : Floor should have 'S'
** Post-Conditions : none
*****************************************************/
void Game::Swan_load()
{
	Position start, size;
	size = floor.Get_Board_Size();
	int k = 0;
	for (int i = 0; i<size.Get_Xpos(); i++)
	{
		for (int j = 0; j<size.Get_Ypos(); j++)
		{
			if (floor.Get_Point_Board(i, j) == 'S')
			{
				k++;
			}
		}
	}

	swan_count = k;
	swans = new Swan[swan_count];
	k = 0;

	for (int i = 0; i<size.Get_Xpos(); i++)
	{
		for (int j = 0; j<size.Get_Ypos(); j++)
		{
			if (floor.Get_Point_Board(i, j) == 'S')
			{
				start.Set_Xpos(i);
				start.Set_Ypos(j);
				swans[k].Set_Start(start);
				swans[k].Set_Pos(start);
				k++;
			}
		}
	}
}

/****************************************************
** Function : Validate_input()
** Description : It will determine your input is legit
** Parameters : none
** Pre-Conditions : W,A,S,D,E,U,Q or invalid
** Post-Conditions : none
*****************************************************/
char Game::Validate_input()
{
	char input;

	while (true)
	{
		Floor_make();
		cin >> input;
		input = toupper(input); // lowercase to uppercase 
		if (input == 'W')
			return 'W';
		else if (input == 'A')
			return 'A';
		else if (input == 'S')
			return 'S';
		else if (input == 'D')
			return 'D';
		else if (input == 'E')
			return 'E';
		else if (input == 'U')
			return 'U';
		else if (input == 'Q')
		{
			cout << "[You press 'Q']" << endl;
			cout << "[The game is ended! Thanks !]" << endl;
			exit(1);
		}
		else
		{
			cout << "[     Error - Invalid input   ] " << endl;
			cout << "[The Game will resume in a sec] " << endl;
			usleep(1000);
		}
	}
}

/****************************************************
** Function : Validate_move(char)
** Description : it will validate move.
**				 check your next step is blocked by walls or locked door
** Parameters : char
** Pre-Conditions : none
** Post-Conditions : if it is true, it means it is  invalid.
*****************************************************/
bool Game::Validate_move(char ch)
{
	Position set_pos, next, pos, floorSize;
	pos = player.Get_Pos();
	floorSize = floor.Get_Board_Size();
	set_pos.Set_Xpos(0);
	set_pos.Set_Ypos(0);
	next = pos;

	if (ch == 'W')
	{
		set_pos.Down_Xpos();
	}
	else if (ch == 'A')
	{
		set_pos.Left_Ypos();
	}
	else if (ch == 'S')
	{
		set_pos.Up_Xpos();
	}
	else if (ch == 'D')
	{
		set_pos.Right_Ypos();
	}
	else
	{
		return false;
	}

	next.Set_Xpos(next.Get_Xpos() + set_pos.Get_Xpos());
	next.Set_Ypos(next.Get_Ypos() + set_pos.Get_Ypos());

	char checker = floor.Get_Point_Board(next.Get_Xpos(), next.Get_Ypos());

	if (checker == '#')
	{
		return true;
	}
	if (checker == 'D' && player.getKeys()<1)
	{
		return true;
	}
	if (next.Get_Xpos()<0 || next.Get_Ypos()<0 || next.Get_Xpos()>floorSize.Get_Xpos() || next.Get_Ypos()>floorSize.Get_Ypos())
	{
		return true;
	}
	return false;
}

/****************************************************
** Function : Print_win()
** Description : Print winning message
** Parameters : none
** Pre-Conditions : none
** Post-Conditions : none
*****************************************************/
void Game::print_win()
{
	cout << endl;
	cout << "[You just get away from the maze!]" << endl;
	cout << "[Congratuation, you are free now!]" << endl;
}

/****************************************************
** Function : Floor_make()
** Description : it shows current status of the player
** Parameters : none
** Pre-Conditions : none
** Post-Conditions : none
*****************************************************/
void Game::Floor_make()
{
	Swan_make();
	floor.Print_Board();
	cout << "[ You are in : " << current_floor << " floor ]" << endl;
	cout << "[ Keys: " << player.getKeys() << " / Apples: " << player.getApples() << " / Left Step for new swan: " << swan_step << "/30 ] " << endl;
	cout << "[ Number of Swan in this floor " << swan_count << " ]" << endl;
	if (step_apple == -1)
		cout << endl;
	else
		cout << "[ You ate the apple. You are safe before: " << 15 - step_apple << " Steps ! " << endl;;
	cout << "Move : ";
}

/****************************************************
** Function : Swan_make()
** Description : Find 'S' sign and make the swan
** Parameters : none
** Pre-Conditions : Swan can be more than 1.
** Post-Conditions : none
*****************************************************/
void Game::Swan_make()
{
	Position size = floor.Get_Board_Size();
	for (int i = 0; i<size.Get_Xpos(); i++)
	{
		for (int j = 0; j<size.Get_Ypos(); j++)
		{
			if (floor.Get_Point_Board(i, j) == 'S')
			{
				floor.Set_Board(i, j, ' ');
			}
		}
	}
	for (int i = 0; i<swan_count; i++)
	{
		Position swanPos = swans[i].Get_Pos();
		floor.Set_Board(swanPos.Get_Xpos(), swanPos.Get_Ypos(), 'S');
	}
}

/****************************************************
** Function : Swan_new()
** Description : Every 30steps of the player,
**				 new swan will show up in random place in current floor
** Parameters : none
** Pre-Conditions : none
** Post-Conditions : Swan can't be made in the wall or door.
*****************************************************/
void Game::Swan_new()
{
	Position size = floor.Get_Board_Size();
	int rand_input1 = rand() % (size.Get_Xpos() - 1);
	int rand_input2 = rand() % (size.Get_Ypos() - 1);
	if (floor.Get_Point_Board(rand_input1, rand_input2) != '#' && floor.Get_Point_Board(rand_input1, rand_input2) != 'D' && floor.Get_Point_Board(rand_input1, rand_input2) != 'L' && floor.Get_Point_Board(rand_input1, rand_input2) != 'S' &&floor.Get_Point_Board(rand_input1, rand_input2) != 'K' && floor.Get_Point_Board(rand_input1, rand_input2) != 'A' &&floor.Get_Point_Board(rand_input1, rand_input2) != 'E' && floor.Get_Point_Board(rand_input1, rand_input2) != 'X')
	{
		floor.Set_Board(rand_input1, rand_input2, 'S');
		swan_count++;
		Swan_load();
	}
	else
		Swan_new();
}

/****************************************************
** Function : Set_Swan_Apple()
** Description : Set method to count apple and swan step
** Parameters : none
** Pre-Conditions : none
** Post-Conditions : Eatting apple gives you power for 15 steps
**					 Every 30 steps makes new swan
*****************************************************/
void Game::Set_Swan_Apple()
{
	swan_step++;
	if (swan_step > 30)
	{
		swan_step = 0;
		Swan_new();
	}
	if (step_apple>-1)
	{
		step_apple++;
	}
	if (step_apple>15)
	{
		player.power_off();
		step_apple = -1;
	}

}

/****************************************************
** Function : play()
** Description : Main play function.
** Parameters : none
** Pre-Conditions : Every function must be valid
** Post-Conditions : none
*****************************************************/
void Game::play()
{
	char input;
	Position size = floor.Get_Board_Size();

	inst();
	while(1)
	{
		do
		{
			input = Validate_input();
		} while (Validate_move(input));

		if (input == 'E')
		{
			if (player.getApples()>0)
			{
				player.power_on();
				step_apple = 0;
				player.Consume_Apple();
				for (int i = 0; i<swan_count; i++)
				{
					swans[i].move(floor,input);
				}
			}
			else
			{
				cout << "[ ERROR ] " << endl;
				cout << "[ You Don't have any apples     ]" << endl;
				cout << "[ The game will resume in a sec ]" << endl;
				usleep(1000);

			}
		}
		else if (input == 'U')
		{
			if (player.Get_Standing_Board() == 'L')
			{
				current_floor++;
				if (current_floor > total_floors)
				{
					print_win();
					cout << "[Because, there is no more Floor!]" << endl;
					exit(1);
				}
				step_apple = -1;
				swan_step = 0;
				floor.Delete_board();
				Floor_load(current_floor);
				Player_load();
				Swan_load();
			}
			else if (player.Get_Standing_Board() == 'X')
			{
				print_win();
				exit(1);
			}
			else
			{
				cout << "[ ERROR ] " << endl;
				cout << "[ You can't use ladder or get out  ]" << endl;
				cout << "[ Because you aren't on the ladder ]" << endl;
				cout << "[ The game will resume in a sec    ]" << endl;
				usleep(1000);
			}
		}
		else
		{
			for (int i = 0; i<swan_count; i++)
			{
				swans[i].move(floor,input);
			}
			player.move(floor, input);
			Set_Swan_Apple();
		}
	}
}

/****************************************************
** Function : inst()
** Description : Print instruction of the game
** Parameters : none
** Pre-Conditions : Starts first 
** Post-Conditions : none
*****************************************************/
void Game::inst()
{
	system("clear");
	cout << "[Instruction]" << endl;
	cout << endl;
	cout << "W,A,S,D - moving" << endl;
	cout << "E - eat apple / U - going up when you are on the ladder or exit" << endl;
	cout << "Q - quit the game in anytime" << endl;
	cout << "Now, You are using total '" << howmany << "' of floors" << endl;
	cout << "Every invalid input will show error message and resume the game in a sec" << endl;
	cout << "You can get out if there is no more upper floor or you get the exit" << endl;
	cout << endl;
	cout << " *IMPORTANT - If you are surrounded by swans in starting location, you lose!" << endl;
	cout << "              In this case, you have to re-start the game." << endl;
	cout << endl;
	cout << " *If you have 3keys or 2apples, the player will ignore keys or apples on the ground " << endl;
	cout << "  If you want to get out, use apples proper time and pick more! " << endl;
	cout << endl;
	cout << "I hope you enjoy the game." << endl;
	cout << "Press Enter to continue.... ";
	getline(cin, make_pause);
}
