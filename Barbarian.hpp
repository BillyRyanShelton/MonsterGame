/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:  This is a header file for the derived class Barbarian.
*********************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "Monster.hpp"
#include <string>

class Barbarian :public Monster
{
	public:
		Barbarian();
		Barbarian(int, int, int, int);
};
#endif
