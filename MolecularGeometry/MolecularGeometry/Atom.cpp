#include "Atom.h"
#include <iostream>
#include <cmath>
#include <memory>

using namespace std;

Atom::Atom(double coordinates[], int aNum)
{
	number = aNum;
	xPos = coordinates[0];
	yPos = coordinates[1];
	zPos = coordinates[2];
}

void Atom::addBond(Atom* a)
{
	double bondLen = calculateBondLength(a->getX(), a->getY(), a->getZ());
	shared_ptr<Atom> bond(a);
	bonds.push_back(make_pair(bond, bondLen));
}

double Atom::calculateBondLength(double x, double y, double z)
{
	//sum coordinates
	double xAvg = xPos - x;
	double yAvg = yPos - y;
	double zAvg = zPos - z;

	//square sums
	xAvg *= xAvg;
	yAvg *= yAvg;
	zAvg *= zAvg;

	//sum squares
	double sum = xAvg + yAvg + zAvg;

	//sqaure root sum
	return sqrt(sum);
}

void Atom::displayBonds()
{
	for (int i = 0; i < bonds.size(); i++){
		cout << "Atomic Number: " << bonds[i].first->getNumber() << ", Distance: " << bonds[i].second << endl;
	}
}

Atom::~Atom()
{
	//dousn't need deallocation because of smart_ptrs
}
