#include "Character.h"
#include <iostream>;

Character::Character()
{
	strcpy_s(m_name, "Unnamed");
	m_health = 100;
	m_damage = 10;
}

Character::Character(char name[], float health, float damage)
{
	strcpy_s(m_name, name);
	m_health = health;
	m_damage = damage;
}

bool Character::isAlive()
{
	return m_health > 0;
}

void Character::attack(Character* other)
{
	other->takeDamage(getDamage());
}

float Character::takeDamage(float damage)
{
	m_health -= damage;
	return damage;
}
