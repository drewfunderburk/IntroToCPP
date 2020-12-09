#include <iostream>;

int positions[3][3];
char player1Name[32];
char player2Name[32];
bool player1Victory = false;
bool player2Victory = false;

void setName(int index)
{
	while (true)
	{
		if (index == 1)
		{
			std::cout << "Please enter a name for Player 1: ";
			std::cin >> player1Name;
			std::cout << "Welcome " << player1Name << "!\n";
			break;
		}
		else if (index == 2)
		{
			std::cout << "Please enter a name for Player 2: ";
			std::cin >> player2Name;
			std::cout << "Welcome " << player2Name << "!\n";
			break;
		}
		else
		{
			std::cout << "Invalid entry.\n";
		}
	}
}

void drawGrid()
{
	char charGrid[3][3];
	
	for (int i = 0; i < 3; i++)
	{
		for (int n = 0; n < 3; n++)
		{
			if (positions[i][n] == 0)
			{
				// If nothing is there
				charGrid[i][n] = '_';
			}
			else if (positions[i][n] == 1)
			{
				// If it's an X
				charGrid[i][n] = 'X';
			}
			else if (positions[i][n] == 2)
			{
				// If it's an O
				charGrid[i][n] = 'O';
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		char arr[6];
		for (int n = 0; n < 3; n++)
		{
			arr[n * 2] = charGrid[i][n];
		}
		arr[1] = '|';
		arr[3] = '|';
		std::cout << arr << std::endl;
	}
}

int getInput()
{
	int input;
	std::cin >> input;
	return input;
}

void setGrid(int index)
{
	if (index == 1)
	{
		std::cout << player1Name << "! It's your turn!\n";
		int x = 0;
		int y = 0;
		while (true)
		{
			while (x == 0)
			{
				std::cout << " Enter a row: ";
				int input = getInput();
				if (input > 0 && input < 4)
					x = input;
				else
					continue;
			}
			while (y == 0)
			{
				std::cout << " Enter a column: ";
				int input = getInput();
				if (input > 0 && input < 4)
					y = input;
				else
					continue;
			}
			if (positions[x - 1][y - 1] == 0)
			{
				positions[x - 1][y - 1] = 1;
				break;
			}
			else
			{
				std::cout << "That position is taken!\n\n";
				x = 0;
				y = 0;
			}
		}
	}
	else if (index == 2)
	{
		std::cout << player2Name << "! It's your turn!\n";
		int x = 0;
		int y = 0;
		while (true)
		{
			while (x == 0)
			{
				std::cout << " Enter a row: ";
				int input = getInput();
				if (input > 0 && input < 4)
					x = input;
				else
					continue;
			}
			while (y == 0)
			{
				std::cout << " Enter a column: ";
				int input = getInput();
				if (input > 0 && input < 4)
					y = input;
				else
					continue;
			}
			if (positions[x - 1][y - 1] == 0)
			{
				positions[x - 1][y - 1] = 2;
				break;
			}
			else
			{
				std::cout << "That position is taken!\n\n";
				x = 0;
				y = 0;
			}
		}
	}
}

int main()
{
	// Get names
	setName(1);
	setName(2);
	std::cout << std::endl;
	system("pause");
	system("cls");

	// Init all positions to 0
	for (int i = 0; i < 3; i++)
	{
		for (int n = 0; n < 3; n++)
		{
			positions[i][n] = 0;
		}
	}
	
	// Game Loop
	while (!player1Victory && !player2Victory)
	{
		system("cls");
		drawGrid();
		std::cout << std::endl;
		setGrid(1);
		system("cls");
		drawGrid();
		std::cout << std::endl;
		setGrid(2);
	}

	system("pause");
	return 0;
}