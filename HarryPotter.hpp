/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description: This is a header file for the derived class HarryPotter
*********************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "Monster.hpp"
#include <string>

class HarryPotter :public Monster
{
	private:
		int livesLeft = 1;

	public:
		void checkStrength();
		HarryPotter();
		HarryPotter(int, int, int, int);
};
#endif
