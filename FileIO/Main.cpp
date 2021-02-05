#include <iostream>
#include <fstream>
#include "Character.h"

/*
* 
* This is all just keeping the two save systems separate so I can use them later
* Binary File IO is in main
* 
void textFileIO()
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
}

void binaryFileIO()
{
	Character sbeve = Character();
	sbeve.health = 200;
	sbeve.damage = 10;

	Character sbeve2 = Character();
	sbeve2.health = 5;
	sbeve2.damage = 3;

	Character sbeve3 = Character();
	sbeve3.health = 1000;
	sbeve3.damage = 40;

	std::fstream file;
	file.open("data.dat", std::ios::out | std::ios::binary);
	if (file.is_open())
	{
		file.write((char*)&sbeve, sizeof(Character));
		file.write((char*)&sbeve2, sizeof(Character));
		file.write((char*)&sbeve3, sizeof(Character));
	}
	file.close();


	Character covfefe = Character();

	file.open("data.dat", std::ios::in | std::ios::binary);
	if (file.is_open())
	{
		file.seekg(sizeof(Character) * 2, std::ios::beg);
		file.read((char*)&covfefe, sizeof(Character));
	}
	file.close();

	std::cout << covfefe.health << std::endl;
	std::cout << covfefe.damage << std::endl;

}
*/

int main()
{
	std::fstream file;
	Character sbeve = Character();
	file.open("save.dat", std::ios::in | std::ios::binary);
	if (file.is_open())
	{
		int input;
		std::cout << "Which character would you like to load?" << std::endl;
		std::cout << "> ";
		std::cin >> input;

		file.seekg(sizeof(Character) * input, std::ios::beg);
		file.read((char*)&sbeve, sizeof(Character));
	}
	else
		std::cout << "No save file found. Will create one this run." << std::endl;
	file.close();

	std::cout << sbeve.health << std::endl;
	std::cout << sbeve.damage << std::endl;
	std::cout << std::endl;

	std::cout << "What stats would you like to have?" << std::endl;
	std::cout << "Health: ";
	std::cin >> sbeve.health;
	std::cout << "Damage:";
	std::cin >> sbeve.damage;

	file.open("save.dat", std::ios::out | std::ios::app | std::ios::binary);
	if (!file.is_open())
		return 1;

	file.write((char*)&sbeve, sizeof(Character));
	file.close();


	return 0;
}