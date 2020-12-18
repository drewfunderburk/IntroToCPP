#include "Game.h"
#include <iostream>

void Game::run()
{
	m_gameOver = false;
	start();
	// Game Loop
	while (!getGameOver())
	{
		update();
		draw();
	}
	end();
	system("pause");
}

// Get integer input until value is between 1 and numInputs
int Game::getIntInput(int numInputs)
{
	int input = 0;
	while (true)
	{
		std::cin >> input;
		if (input < 1 || input > numInputs)
			std::cout << "Invalid input\n";
		else
			break;
	}
	return input;
}

void Game::doBattle(Character* player1, Character* player2)
{
	bool player1Victory = false;
	bool player2Victory = false;
	while (!player1Victory && !player2Victory)
	{
		system("cls");
		std::cout << player1->getName() << ": " << player1->getHealth() << std::endl;
		std::cout << player2->getName() << ": " << player2->getHealth() << std::endl;
		std::cout << std::endl;

		// Player 1 turn
		std::cout << player1->getName() << ", it's your turn!\n";
		std::cout << " [1] Attack\n";
		std::cout << " [2] Flee\n";
		std::cout << "> ";
		int input = getIntInput(2);
		if (input == 1)
		{
			player1->attack(player2);
		}
		else if (input == 2)
		{
			std::cout << player1->getName() << " flees the battle!\n";
			player2Victory = true;
			break;
		}

		// Player 2 turn
		std::cout << player2->getName() << ", it's your turn!\n";
		std::cout << " [1] Attack\n";
		std::cout << " [2] Flee\n";
		std::cout << "> ";
		input = 0;
		input = getIntInput(2);
		if (input == 1)
		{
			player2->attack(player1);
		}
		else if (input == 2)
		{
			std::cout << player2->getName() << " flees the battle!\n";
			player1Victory = true;
			break;
		}

		// Check for victory
		if (player1->isAlive() && !player2->isAlive())
			player1Victory = true;
		else if (!player1->isAlive() && player2->isAlive())
			player2Victory = true;
	}

	// Print victory
	if (player1Victory)
		std::cout << player1->getName() << " wins!\n\n";
	else if (player2Victory)
		std::cout << player2->getName() << " wins!\n\n";
}

void Game::start()
{
	std::cout << "Welcome to the game!\n\n";

	// Init default characters
	m_player1 = new Character();
	m_player2 = new Character();
}

void Game::update()
{
	// Create player 1
	std::cout << "Player 1, please enter your name: ";
	char name[32];
	std::cin >> name;
	std::cout << "Welcome " << name << "!\n";
	m_player1 = new Character(name, 100, 10);
	std::cout << std::endl;
	// Create player 2
	std::cout << "Player 2, please enter your name: ";
	strcpy_s(name, "");
	std::cin >> name;
	std::cout << "Welcome " << name << "!\n";
	m_player2 = new Character(name, 100, 10);

	doBattle(m_player1, m_player2);

	std::cout << "Would you like to play again?\n";
	std::cout << " [1] Yes\n";
	std::cout << " [2] No\n";
	int input;
	std::cin >> input;
	if (input == 2)
		m_gameOver = true;
}

void Game::draw()
{
}

void Game::end()
{
	// Free memory used by pointers
	delete m_player1;
	delete m_player2;

	std::cout << "\n\nThank you for playing!\n\n";
}
