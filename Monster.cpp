/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:  This is a source file which defines the functions
created in the Monster.hpp file.
*********************************************************************/

#include <iostream>
#include <string>
#include "Monster.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using std::string;
using std::cout;
using std::cin;
//default constructor
Monster::Monster()
{	//nothing
}
//virtual function used to check a monster's strength
void Monster::checkStrength()
{	//nothing
}

//user specified constructor
Monster::Monster(int attackIn, int defenseIn, int armorIn, int strengthIn)
{
	attack = attackIn;
	defense = defenseIn;
	armor = armorIn;
	strength = strengthIn;
}
int Monster::getAttack()
{
	return attack;
}
void Monster::setAttack(int attackIn)
{
	attack = attackIn;
}


int Monster::getDefense()
{
	return defense;
}
void Monster::setDefense(int defenseIn)
{
	defense = defenseIn;
}


int Monster::getArmor()
{
	return armor;
}
void Monster::setArmor(int armorIn)
{
	armor = armorIn;
}


int Monster::getStrength()
{
	return strength;
}
void Monster::setStrength(int strengthIn)
{
	strength = strengthIn;
}

string Monster::getName()
{
	return name;
}
int Monster::attackPlayer()
{
	int outcome;
	outcome = (rand() % attack) + 1;													//cout << outcome << endl;									//cout << endl;
	return outcome;
}
int Monster::defend()
{
	int outcome;
	outcome = (rand() % defense) + 1;													//cout << outcome << endl;									//cout << endl;
	return outcome;
}
