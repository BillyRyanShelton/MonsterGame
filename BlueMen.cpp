/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:  This is a source file which defines the functions
created in the BlueMen.hpp file.
*********************************************************************/

#include <iostream>
#include <string>
#include "BlueMen.hpp"
using std::string;
using std::cout;
using std::cin;

//default constructor
BlueMen::BlueMen()
{
	name = "The Blue Men";
	attack = 20;
	defense = 18;
	armor = 3;
	strength = 12;
}
//user specified constructor
BlueMen::BlueMen(int attackIn, int defenseIn, int armorIn, int strengthIn)
{
	name = "Blue Men";
	attack = attackIn;
	defense = defenseIn;
	armor = armorIn;
	strength = strengthIn;
}
//this functions lowers the Blue Mens' defense by 6 for every 4 strength points they lose
void BlueMen::checkStrength()
{
	if (strength > 4 && strength <= 8)
	{
		setDefense(12);
	}

	if (strength >= 1 && strength <= 4)
	{
		setDefense(6);
	}
}
