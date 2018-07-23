/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description: This is a header file for the class derived class Vampire
*********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "Monster.hpp"
#include <string>

class Vampire :public Monster
{
	public:
		Vampire();
		Vampire(int, int, int, int);
};
#endif
