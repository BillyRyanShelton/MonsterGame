  /*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:  This is a header file for the derived class Medusa
*********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "Monster.hpp"
#include <string>

class Medusa :public Monster
{
	public:
		int attackPlayer();
		Medusa();
		Medusa(int, int, int, int);
};
#endif
