/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:  This is a source file which defines the functions
created in the Vampire.hpp file.
*********************************************************************/

#include <iostream>
#include <string>
#include "Vampire.hpp"
using std::string;
using std::cout;
using std::cin;

//default constructor
Vampire::Vampire()
{
	name = "Vampire Selene";
	attack = 12;
	defense = 6;
	armor = 1;
	strength = 18;
}

//user specified constructor
Vampire::Vampire(int attackIn, int defenseIn, int armorIn, int strengthIn)
{
	name = "Vampire Selene";
	attack = attackIn;
	defense = defenseIn;
	armor = armorIn;
	strength = strengthIn;
}

