#include <iostream>
#include <fstream>
#include "Character.h"

int main()
{

	Character player = Character();
	player.health = 100;
	player.damage = 5;

	// Saving to a text file
	std::fstream file;
	file.open("Save.txt", std::ios::out);
	if (file.is_open())
	{
		file << player.health << std::endl;
		file << player.damage << std::endl;
	}
	file.close();

	// Loading from a text file
	Character player2 = Character();

	file.open("Save.txt", std::ios::in);
	if (file.is_open())
	{
		file >> player2.health;
		file >> player2.damage;
	}
	file.close();


	std::cout << player2.health << std::endl;
	std::cout << player2.damage << std::endl;

	return 0;
}