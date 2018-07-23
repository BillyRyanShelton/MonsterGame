/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:  This is a source file which defines the functions
created in the Medusa.hpp file.
*********************************************************************/

#include <iostream>
#include <string>
#include "Medusa.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using std::string;
using std::cout;
using std::cin;

//default constructor
Medusa::Medusa()
{
	name = "Medusa";
	attack = 12;
	defense = 6;
	armor = 3;
	strength = 8;
}
//user specified constructor
Medusa::Medusa(int attackIn, int defenseIn, int armorIn, int strengthIn)
{
	name = "Medusa";
	attack = attackIn;
	defense = defenseIn;
	armor = armorIn;
	strength = strengthIn;
}
int Medusa::attackPlayer()
{
	int outcome;
	outcome = (rand() % attack) + 1;	
	if (outcome == 12)
	{
		return 500;
	}
	else
	{
		return outcome;
	}
}
