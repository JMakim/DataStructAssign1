// Assignment_1.cpp
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Carrier
{
public:
	Carrier();
private:
	string name;
	//Fighter *bayList[20];
	int maxBays;
	int numFighters;
};

Carrier::Carrier()
{
}

class Fighter : public Carrier
{
public:
	Fighter(string n, int d, int s);
	void reduceStructure(int d);
	string getFName();
	int getStructStrength();
	string getInfo();
	int getDamage();
private:
	string fName;
	int damage;
	int structStrenth;
};

Fighter::Fighter(string n, int d, int s)
{
	n = fName;
	d = damage;
	s = structStrenth;
}

void Fighter::reduceStructure(int d)
{
	d = damage;
}

string Fighter::getFName()
{
	return fName;
}

int Fighter::getStructStrength()
{
	return structStrenth;
}

string Fighter::getInfo()
{
	cout << "Fighter Name: " << fName << endl;
	cout << "Structural Strength: " << to_string(structStrenth) << endl;
	cout << "Damage: " << to_string(damage) << endl;

	return 0;
}

int Fighter::getDamage()
{
	return damage;
} 

int main()
{
	return 0;
}