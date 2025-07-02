#include "Enemy.h"

Enemy::Enemy(string name, string description, int maxHealth) : Character(name, description)
{
	enemyMaxHealth = maxHealth;
	enemyCurrentHealth = maxHealth;
}

Enemy::Enemy(string name, string description, int maxHealth, int currentHealth) : Character(name, description)
{
	enemyMaxHealth = maxHealth;
	enemyCurrentHealth = currentHealth;
}

int Enemy::MaxHealth()
{
	return enemyMaxHealth;
}

int Enemy::CurrentHealth()
{
	return enemyCurrentHealth;
}
