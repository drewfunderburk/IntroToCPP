#include <iostream>;

int positions[3][3];
char player1Name[64];
char player2Name[64];
bool player1Victory = false;
bool player2Victory = false;

// Set a player's name
void setName(int index)
{
	if (index == 1)
	{
		std::cout << "Please enter a name for Player 1: ";
		std::cin >> player1Name;
		std::cout << "Welcome " << player1Name << "!\n";
	}
	else if (index == 2)
	{
		std::cout << "Please enter a name for Player 2: ";
		std::cin >> player2Name;
		std::cout << "Welcome " << player2Name << "!\n";
	}
}

// Draw the TicTacToe grid to the console
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

	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
	{
		char arr[6];
		for (int n = 0; n < 3; n++)
		{
			arr[n * 2] = charGrid[i][n];
		}
		arr[1] = '|';
		arr[3] = '|';
		// Zero terminate the char array
		arr[5] = 0;
		
		std::cout << "  " << arr << std::endl;
	}
}

// Cin an integer and return it
int getIntegerInput()
{
	int input;
	std::cin >> input;
	return input;
}

// Get a grid position from a player and set it to their char
void setGrid(int index)
{
	if (index == 1)
		std::cout << player1Name << "! It's your turn! [X]\n";
	else if (index == 2)
		std::cout << player2Name << "! It's your turn! [O]\n";

	int x = 0;
	int y = 0;
	// Loop until valid input
	while (true)
	{
		while (x == 0)
		{
			std::cout << " Enter a row: ";
			int input = getIntegerInput();
			if (input > 0 && input < 4)
				x = input;
			else
				continue;
		}
		while (y == 0)
		{
			std::cout << " Enter a column: ";
			int input = getIntegerInput();
			if (input > 0 && input < 4)
				y = input;
			else
				continue;
		}
		if (positions[x - 1][y - 1] == 0)
		{
			positions[x - 1][y - 1] = index;
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

// Check for 3 in a row or cat game
bool checkWin()
{
	for (int i = 0; i < 3; i++)
	{
		// Player 1
		// Columns
		if (positions[0][i] == 1 &&
			positions[1][i] == 1 &&
			positions[2][i] == 1)
			return player1Victory = true;

		// Rows
		else if (positions[i][0] == 1 &&
			positions[i][1] == 1 &&
			positions[i][2] == 1)
			return player1Victory = true;

		// Player 2
		// Columns
		if (positions[0][i] == 2 &&
			positions[1][i] == 2 &&
			positions[2][i] == 2)
			return player2Victory = true;

		// Rows
		else if (positions[i][0] == 2 &&
			positions[i][1] == 2 &&
			positions[i][2] == 2)
			return player2Victory = true;
	}

	// Player 1
	// Diag 1
	if (positions[0][0] == 1 &&
		positions[1][1] == 1 &&
		positions[2][2] == 1)
		return player1Victory = true;
	// Diag 2
	else if (positions[2][0] == 1 &&
		positions[1][1] == 1 &&
		positions[0][2] == 1)
		return player1Victory = true;

	// Player 2
	// Diag 1
	if (positions[0][0] == 2 &&
		positions[1][1] == 2 &&
		positions[2][2] == 2)
		return player2Victory = true;
	// Diag 2
	else if (positions[2][0] == 2 &&
		positions[1][1] == 2 &&
		positions[0][2] == 2)
		return player2Victory = true;

	// If all victory checks fail and there are no open spaces, cat game
	bool cat = true;
	for (int i = 0; i < 3; i++)
		for (int n = 0; n < 3; n++)
			if (positions[i][n] == 0)
				cat = false;

	if (cat)
	{
		player1Victory = true;
		player2Victory = true;
		return true;
	}

	return false;
}

int main()
{
	while (true)
	{
		system("cls");
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

		// Set victories false
		player1Victory = false;
		player2Victory = false;

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
			if (checkWin())
				break;
			setGrid(2);
			checkWin();
		}

		system("cls");
		drawGrid();

		// Victory messages
		if (player1Victory && !player2Victory)
		{
			std::cout << std::endl;
			std::cout << player1Name << " wins!\n\n";
		}
		else if (player2Victory && !player1Victory)
		{
			std::cout << std::endl;
			std::cout << player2Name << " wins!\n\n";
		}
		else if (player2Victory && player1Victory)
		{
			std::cout << std::endl;
			std::cout << "Cat!\n\n";
		}

		// Check for play again
		std::cout << "Would you like to play again?\n";
		std::cout << " [1] Yes\n";
		std::cout << " [2] No\n";
		std::cout << "> ";

		int input = getIntegerInput();
		if (input == 2)
			break;
	}

	return 0;
}