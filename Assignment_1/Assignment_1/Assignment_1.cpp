// Assignment_1.cpp
//

#include <iostream>

using namespace std;

class Carrier
{
public:
	Carrier();
	~Carrier();
private:
	string name;
	Fighter bayList[];
	int maxBays;
	int numFighters;
};

Carrier::Carrier()
{
}

Carrier::~Carrier()
{
}

class Fighter
{
public:
	Fighter();
	~Fighter();

private:
	string fName;
	int damage;
	int structStrenth;
};

Fighter::Fighter()
{
}

Fighter::~Fighter()
{
}

int main()
{
	return 0;
}