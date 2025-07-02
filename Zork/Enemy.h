#pragma once

#include "Character.h"

class Enemy : public Character
{
private:
	int enemyMaxHealth;		//The maximum health that the enemy can have
	int enemyCurrentHealth;	//The current health that the enemy has

public:
	Enemy(string name, string description, int maxHealth);						//Constructor of the class Enemy, that sets the current health to the maximum health
	Enemy(string name, string description, int maxHealth, int currentHealth);	//Constructor of the class Enemy, that sets the current health and the max health

	int MaxHealth();		//Returns the maximum health of the enemy
	int CurrentHealth();	//Returns the current health of the enemy 
};

