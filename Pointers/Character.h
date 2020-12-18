#pragma once
class Character
{
private:
	float m_health;
	float m_damage;
	char m_name[32];

public:
	Character();
	Character(char name[], float health, float damage);

	char* getName() { return m_name; }
	float getDamage() { return m_damage; }
	float getHealth() { return m_health; }

	bool isAlive();
	void attack(Character* other);
	float takeDamage(float damage);
};

