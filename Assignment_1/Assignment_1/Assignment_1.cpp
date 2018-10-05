// Assignment_1.cpp
//

#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>

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

	void reduceStructure(int d) {
		structStrength -= d;
	}

	string getFName() {
		return fName;
	}

	int getStructStrength() {
		return structStrength;
	}

	string getInfo() {
		cout << "Fighter Name: " << fName << endl;
		cout << "Structural Strength: " << to_string(structStrength) << endl;
		cout << "Damage: " << to_string(damage) << endl;

		return 0;
	}

	int getDamage() {
		return damage;
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

	void loadFighter(Fighter* val) {
		if (numFighters == maxBays) {
			cout << "Carrier is Full";
			return;
		}
		bayList[numFighters] = val;
		numFighters++;
	}

	Fighter* launchNextFighter() {
		if (maxBays >= numFighters) {
			Fighter* tempFighter = bayList[0];
			bayList[0] = bayList[0 - 1];
			bayList[-1] = NULL;
			return tempFighter;
		}
	}

	void printInfo() {
		cout << name << endl;
		cout << maxBays << " " << bayList << endl;
		cout << numFighters << endl;
	}

	bool hasFighters() {
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

	int getCapacity() {
		return maxBays;
	}

	string getName() {
		return name;
	}

	int getNumFighters() {
		return numFighters;
	}
};

void battle(Carrier *c1, Carrier *c2) {
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
	return 0;
}