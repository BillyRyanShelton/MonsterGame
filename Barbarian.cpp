/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:  This is a source file which defines the functions
created in the Barbarian.hpp file.
*********************************************************************/

#include <iostream>
#include <string>
#include "Barbarian.hpp"
using std::string;
using std::cout;
using std::cin;
//default constructor
Barbarian::Barbarian()
{
	name = "Conan";
	attack = 12;
	defense = 12;
	armor = 0;
	strength = 12;
}
//user specified constructor
Barbarian::Barbarian(int attackIn, int defenseIn, int armorIn, int strengthIn)
{
	name = "Conan";
	attack = attackIn;
	defense = defenseIn;
	armor = armorIn;
	strength = strengthIn;
}
