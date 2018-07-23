/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:  This is a header file for the derived class BlueMen
*********************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "Monster.hpp"
#include <string>

class BlueMen :public Monster
{
	public:
		BlueMen();
		BlueMen(int, int, int, int);
		void checkStrength();
};
#endif
