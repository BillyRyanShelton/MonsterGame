/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:  The following program implements a 1v1 fantasy creature 
game.  The characters have different abilites and can use them when fighting
opponents.  
*********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Monster.hpp"
#include "Vampire.hpp"
#include <time.h>
#include <stdlib.h>	
#include <stdio.h>
//#include <cstdlib>
//#include <windows.h>
#include <memory>
#include <iomanip>
#include <cmath>
//#include <fmod.h>
using std::setw;
using std::setprecision;
using std::string;
using std::cout;
using std::cin;
float player1InputValidation();
float player2InputValidation();
void welcome();

int main()
{
	std::vector<Monster*> P1;
	std::vector<Monster*> P2;

	//player 1's character choices
	P1.push_back(new Monster);		//fill 0
	P1.push_back(new Vampire);		//position 1
	P1.push_back(new Barbarian);    //position 2
	P1.push_back(new BlueMen);      //position 3
	P1.push_back(new Medusa);       //position 4
	P1.push_back(new HarryPotter);  //position 5
	

	//player 2's character choices
	P2.push_back(new Monster);		//fill 0
	P2.push_back(new Vampire);		//position 1
	P2.push_back(new Barbarian);    //position 2
	P2.push_back(new BlueMen);      //position 3
	P2.push_back(new Medusa);       //position 4
	P2.push_back(new HarryPotter);  //position 5

	//welcome
	welcome();

	//player 1's monster choice
	float C1 = player1InputValidation();  //1-5
	

	//player 2's monster choice
	float C2 = player2InputValidation();  //1-5

	//randomly choose a player to go first  1 or 2
	int seed = (time(NULL));
	int pTurn = (rand() % 2) + 1;
	//cout << pTurn;
	

	/*cout << P1[5]->getDefense();
	cout << "\n\n";
	P1[5]->setDefense(7);
	cout << P1[5]->getDefense();*/
	//initiate game

	cout << setw(12) << " Player    " << setw(12) << " Character " << setw(7) << " Armor" << setw(10) << " Strength" << setw(13) << " Max Attack" << setw(14) << " Max Defense\n";
	cout << setw(12) << "-----------" << setw(12) << "-----------" << setw(7) << "------" << setw(10) << "---------" << setw(13) << "-----------" << setw(14) << "------------\n";
	cout << setw(12) << "    1      " << setw(12) << P1[C1]->getName() << setw(7) << P1[C1]->getArmor() << setw(10) << P1[C1]->getStrength() << setw(13) << P1[C1]->getAttack() << setw(14) << P1[C1]->getDefense();
	cout << "\n";
	cout << setw(12) << "    2      " << setw(12) << P2[C2]->getName() << setw(7) << P2[C2]->getArmor() << setw(10) << P2[C2]->getStrength() << setw(13) << P2[C2]->getAttack() << setw(14) << P2[C2]->getDefense();
	cout << "\n\n";
	//Sleep(4000);



	while (((P1[C1]->getStrength()) > 0) && ((P2[C2]->getStrength()) > 0))
	{
		//player 1's turn to attack
		if (pTurn == 1)
		{
			cout << "Player 1's turn.\n";
			cout << P1[C1]->getName() << " attack(s) " << P2[C2]->getName() << "\n";
			
			

			//calculate charm
			int charm = (rand() % 2) + 1;

			//if character 2 has a vampire and charm is successful
			if ((P2[C2]->getName() == P2[1]->getName()) && (charm == 1))
			{
				cout << "Selene charmed player 1's character and hence dodged their attack.\n";

			}

			//if character 2 does not have a vampire proceed as normal
			else
			{
				//player 1 attacks and player 2 defends
				int damageDone = (P1[C1]->attackPlayer() - P2[C2]->defend());

				//if defense was able to block the attack no strength or armor is lost
				if (damageDone <= 0)
				{
					//nothing happens 
					cout << "No damage was done.\n";
				}

				//if damage is greater than defense
				else
				{
					//left over damage after armor is destroyed is applied to strength points
					if (damageDone > P2[C2]->getArmor())
					{
						P2[C2]->setStrength(P2[C2]->getStrength() - damageDone + P2[C2]->getArmor());
						//armor is destroyed
						P2[C2]->setArmor(0);
						cout << "Player 2's character now has " << P2[C2]->getStrength() << " strength point(s)\n";
						
						//for every 4 strength points lost the blue men lose defense
						if (P2[C2]->getName() == P2[3]->getName())
						{
							P2[3]->checkStrength();
						}

						//if Harry Potter dies once his strength is restored and doubled
						if (P2[C2]->getName() == P2[5]->getName())
						{
							P2[5]->checkStrength();
						}

						//if the strength of player 2's character is 0 or less the game is over
						if (P2[C2]->getStrength() <= 0)
						{
							cout << "\n";
							cout << P2[C2]->getName() << " lost!\n";
							
							if ((P2[C2]->getStrength() < (-300)) && (P2[C2]->getName() == P2[4]->getName()))
							{
								cout << "Medusa's gaze turned " << P2[C2]->getName() << " to stone.\n";
							}
						}
					}
					//armor is reduced or destroyed but not strength points are lost
					else if (damageDone <= P2[C2]->getArmor())
					{
						P2[C2]->setArmor((damageDone - P2[C2]->getArmor()));

						if (P2[C2]->getArmor() < 0)
						{
							P2[C2]->setArmor(0);
						}

						cout << "Player 2:  " << P2[C2]->getName() << "'s armor was reduced to " << P2[C2]->getArmor() << "\n";
					}
				}


			}
			pTurn = 2;
			cout << "\n";
		}





		//player 2's turn to attack
		else   // (pTurn == 2)
		{
			cout << "Player 2's turn.\n";
			cout << P2[C2]->getName() << " attack(s) " << P1[C1]->getName() << "\n";



			//calculate charm
			int charm = (rand() % 2) + 1;

			//if character 2 has a vampire and charm is successful
			if ((P1[C1]->getName() == P1[1]->getName()) && (charm == 1))
			{
				cout << "Selene charmed player 1's character and hence dodged their attack.\n";

			}

			//if character 2 does not have a vampire proceed as normal
			else
			{
				//player 1 attacks and player 2 defends
				int damageDone = (P2[C2]->attackPlayer() - P1[C1]->defend());

				//if defense was able to block the attack no strength or armor is lost
				if (damageDone <= 0)
				{
					//nothing happens 
					cout << "No damage was done.\n";
				}

				//if damage is greater than defense
				else
				{
					//left over damage after armor is destroyed is applied to strength points
					if (damageDone > P1[C1]->getArmor())
					{
						P1[C1]->setStrength(P1[C1]->getStrength() - damageDone + P1[C1]->getArmor());
						P1[C1]->setArmor(0);
						cout << "Player 1's character now has " << P1[C1]->getStrength() << " strength point(s)\n";

						//for every 4 strength points lost the blue men lose defense
						if (P1[C1]->getName() == P1[3]->getName())
						{
							P1[3]->checkStrength();
						}

						//if Harry Potter dies once his strength is restored and doubled
						if (P1[C1]->getName() == P1[5]->getName())
						{
							P1[5]->checkStrength();
						}

						//if the strength of player 1's character is 0 or less the game is over
						if (P1[C1]->getStrength() <= 0)
						{
							cout << "\n";
							cout << P1[C1]->getName() << " lost\n";

							if ((P1[C1]->getStrength() < (-300)) && (P1[C1]->getName() == P1[4]->getName()))
							{
								cout << "Medusa's gaze turned " << P1[C1]->getName() << " to stone.\n";
							}
						}
					}
					//armor is reduced or destroyed but no strength points are lost
					else if (damageDone <= P1[C1]->getArmor())
					{
						P1[C1]->setArmor((damageDone - P1[C1]->getArmor()));

						if (P1[C1]->getArmor() < 0)
						{
							P1[C1]->setArmor(0);
						}


						cout << "Player 1:  " << P1[C1]->getName() << "'s armor was reduced to " << P1[C1]->getArmor() << "\n";
					}
				}


			}
			pTurn = 1;
		}

		cout << "\n";
		//Sleep(4000);

	}


	cout << "Thanks for playing!\n";

	std::vector<Monster*>::iterator i;
	for (i = P1.begin(); i != P1.end(); ++i)
	{
		delete (*i);//delete data that was pointed
		*i = 0;
	}
	P1.clear();


	std::vector<Monster*>::iterator k;
	for (k = P2.begin(); k != P2.end(); ++k)
	{
		delete (*k);//delete data that was pointed
		*k = 0;
	}
	P2.clear();
	return 0;
}





//player 1's monster choice
float player1InputValidation()
{
	cout << "Player 1: Which character do you choose? (1,2,3,4,5)\n";
	float C1;
	char firstChar;
	cin >> C1;
	firstChar = cin.peek();
	cout << firstChar;
	cin.clear();
	cin.ignore(100, '\n');

	while ((C1 < 1) || ((fmod(C1, 1) != 0)) || (firstChar != '\n') || (C1 > 5))
	{
		cout << "Try again player 1.  Which character do you choose? (1,2,3,4,5)\n";
		cin >> C1;
		firstChar = cin.peek();
		cin.clear();
		cin.ignore(100, '\n');
	}
	return C1;
}


//player 2's monster choice
float player2InputValidation()
{
	cout << "Player 2: Which character do you choose? (1,2,3,4,5)\n";
	float C2;
	char firstChar;
	cin >> C2;
	firstChar = cin.peek();
	cout << firstChar;
	cin.clear();
	cin.ignore(100, '\n');

	while ((C2 < 1) || (fmod(C2, 1) != 0) || (firstChar != '\n') || (C2 > 5))
	{
		cout << "Try again player 2.  Which character do you choose? (1,2,3,4,5)\n";
		cin >> C2;
		firstChar = cin.peek();
		cin.clear();
		cin.ignore(100, '\n');
	}
	return C2;
}

//explains game to users
void welcome()
{
	cout << "Hello and welcome to a 1v1 Fantasy Monster game.\n";
	cout << "There are 5 choosable characters.\n";
	cout << "(1) The Vampire Selene from Underworld\n";
	cout << "(2) Conan the Barbarian\n";
	cout << "(3) The Smurfs\n";
	cout << "(4) The Slithering Serpent Medusa\n";
	cout << "(5) The boy who lived...Harry Potter\n\n";

	cout << "Tips:\n";
	cout << "(1) As a Vampire Selene can live for a long time \n";
	cout << "(2) Conan fears not knowing the riddle of steal for \n";
	cout << "when he dies, Crom will cast him out of Valhalla and laugh.\n";
	cout << "(3) Although the Smurfs are small they are large in numbers.\n";
	cout << "(4) This gorgon's gaze can turn man, beast, or God to stone.\n";
	cout << "(5)  He's a Wizard!\n\n";

	cout << "Rules:  A random player goes first and for each turn the attacking\n";
	cout << "player rolls their dice to see their attack power for that turn.\n";
	cout << "Similarly, the defending player rolls their dice to see their defense\n";
	cout << "power for that turn.  Players alternate attacking and defending until\n";
	cout << "the first player who loses all of their strength points.  The other player\n";
	cout << "Wins!\n";
	cout << "Goodluck\n\n";

}
