#include "Game.h"
#include <iostream>

void Game::run()
{
	m_gameOver = false;
	start();
	while (!getGameOver())
	{
		update();
		draw();
		system("pause");
	}
	end();
}

void Game::start()
{
	m_player1 = Character(10, 10);
	m_player2 = Character(10, 10);
}

void Game::update()
{
	m_player1.attack(m_player2);
}

void Game::draw()
{
	std::cout << "Player 1 has " << m_player1.getHealth() << " health\n";
}

void Game::end()
{
}
