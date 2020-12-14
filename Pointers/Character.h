#pragma once
class Character
{
public:
	Character();
	Character(float health, float damage);

	void attack(Character* other);
	float takeDamage(float damage);

	float getDamage() { return m_damage; }
	float getHealth() { return m_health; }
private:
	float m_health;
	float m_damage;

};

