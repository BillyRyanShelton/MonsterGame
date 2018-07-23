/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:  This is a header file for the base class Monster.
*********************************************************************/

#ifndef MONSTER_HPP
#define MONSTER_HPP
#include <string>

class Monster
{
	protected:
		int attack;
		int defense;
		int armor;
		int strength;
		std::string name;
	public:
		Monster();
		Monster(int, int, int, int);
		int getAttack();
		void setAttack(int);
		int getDefense();
		void setDefense(int);
		int getArmor();
		std::string getName();
		void setArmor(int);
		void setStrength(int);
		int getStrength();
		virtual int attackPlayer();
		virtual int defend();
		virtual void checkStrength();
};


#endif
