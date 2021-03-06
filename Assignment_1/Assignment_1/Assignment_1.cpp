// Assignment_1.cpp 
//Marc Brian Molano - 101062818
//Jahn Makim Ramjahn - 101095903
//Given Date - September 10, 2018
//Due Date - October 7, 2018 11:59pm

#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>

using namespace std;

class Fighter
{
private:
	string fName;
	int damage;
	int structStrength;

public:
	Fighter(string n, int d, int s) {
		n = fName;
		d = damage;
		s = structStrength;
	}

	void reduceStructure(int d) { // reduces the structural strength by the parameter damage
		structStrength -= d;
	}

	string getFName() { // returns the name of the fighter
		return fName;
	}

	int getStructStrength() { // returns the structural strength of the fighter
		return structStrength;
	}

	int getDamage() { // returns the damage done by the fighter
		return damage;
	}

	string getInfo() { // returns a string containing fighter information
		ostringstream ss;
		ss << "Fighter Name: " << fName << "\n";
		ss << "Structural Strength: " << structStrength << "\n";
		ss << "Damage: " << damage << "\n";

		return ss.str();
	}
};

class Carrier
{
private:
	string name;
	Fighter** bayList;
	int maxBays;
	int numFighters;

public:
	Carrier(string n, int m){
	name = n;
	maxBays = m;
	bayList = new Fighter*[maxBays];
	}

	void loadFighter(Fighter* val) { // takes a fighter object and adds it to the array of fighters
		if (numFighters == maxBays) {
			cout << "Carrier is Full";
			return;
		}
		bayList[numFighters] = val;
		numFighters++;
	}

	Fighter* launchNextFighter() { // removes the next fighter
		if (maxBays >= numFighters) {
			Fighter* tempFighter = bayList[0];
			bayList[0] = bayList[0 - 1];
			bayList[-1] = NULL;
			return tempFighter;
		}
	}

	string printInfo() { // returns a string containing Carrier information
		ostringstream ss;
		ss << name << "\n";
		ss << maxBays << " " << bayList << "\n";
		ss << numFighters << "\n";

		return ss.str();
	}

	bool hasFighters() { // returns a boolean value indicationg if the carrier has fighters available 
		if (numFighters <= maxBays) {
			return true;
		}
		else if (numFighters <= 0){
			return false;
		}
		else {
			return false;
		}
	}

	int getCapacity() { // returns the maximum capacity of the bus
		return maxBays;
	}

	string getName() { // returns the name of the carrier
		return name;
	}

	int getNumFighters() { //returns the number of fighters on the bus
		return numFighters;
	}
};

void battle(Carrier *c1, Carrier *c2) { // fighter battle functionality
	int turnRoll;
	int currPlayer;
	int attackRoll = NULL;
	int damageRoll;
	
	Fighter* f1 = NULL;
	Fighter* f2 = NULL;
	c1->launchNextFighter();
	c2->launchNextFighter();

	do
	{
		turnRoll = rand() % 2;
		if (turnRoll == 0) {
			currPlayer = 1;
			cout << f1->getFName() << " goes first." << endl;
			do {
				if (attackRoll >= 50) { // hit
					damageRoll = rand() % f1->getDamage() + 1;
					f2->reduceStructure(damageRoll);
					cout << "****" << f1->getFName() << " hits " << f2->getFName() << " for " << damageRoll << "****";
					currPlayer = 2;
				}
				else { // miss
					cout << "****" << f1->getFName() << " misses****";
					currPlayer = 2;
				}
				if (f2->getStructStrength() == 0) {
					cout << "BOOOOOMMMM " << f2->getFName() << " destroyed!!!!!";
					c2->loadFighter(f1);
				}
			} while (currPlayer == 1 && f2->getStructStrength() > 0 || f1->getStructStrength() > 0);
		}
		else {
			currPlayer = 2;
			cout << f2->getFName() << " goes first." << endl;
			do {
				if (attackRoll >= 50) { // hit
					damageRoll = rand() % f2->getDamage() + 1;
					f1->reduceStructure(damageRoll);
					cout << "****" << f2->getFName() << " hits " << f1->getFName() << " for " << damageRoll << "****";
					currPlayer = 1;
				}
				else { // miss
					cout << "****" << f2->getFName() << " misses****";
					currPlayer = 1;
				}
				if (f1->getStructStrength() == 0) {
					cout << "BOOOOOMMMM " << f1->getFName() << " destroyed!!!!!";
					c2->loadFighter(f2);
				}
			} while (currPlayer == 2 && f1->getStructStrength() > 0 || f2->getStructStrength() > 0);
		}
	} while (c1->hasFighters() == true || c2->hasFighters() == true);
}

int main()
{
	srand((unsigned)time(0));

	return 0;
}