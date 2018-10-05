// Assignment_1.cpp 
//Marc Brian Molano - 101062818
//Jahn Makim Ramjahn - 101095903

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
		if (numFighters != maxBays) {
			return true;
		}
		else {
			return false;
		}
		if (numFighters == 0) {
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
	Fighter* f1 = NULL;
	Fighter* f2 = NULL;
	c1->launchNextFighter();
	c2->launchNextFighter();

	int turnRoll;
	int currPlayer;

	turnRoll = rand() % 2;
	if (turnRoll == 0) {
		currPlayer = 1;
		cout << f1->getFName() << " goes first." << endl;
	}
	else {
		currPlayer = 2;
		cout << f2->getFName() << " goes first." << endl;
	}
}

int main()
{
	srand((unsigned)time(0));

	return 0;
}