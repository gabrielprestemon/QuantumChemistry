#include "Atom.h"
#include <iostream>
#include <cmath>

using namespace std;

Atom::Atom(double coordinates[], int aNum)
{
	number = aNum;
	xPos = coordinates[0];
	yPos = coordinates[1];
	zPos = coordinates[2];
}

void Atom::addBond(Atom& a)
{
	double bondLen = calculateBondLength(a.getX(), a.getY(), a.getZ());
	shared_ptr<Atom> aPtr;
	//aPtr = a;
	bonds.push_back(make_pair(aPtr, bondLen));
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

Atom::~Atom()
{
	//MEMORY DEALLOCATION!!!
	//(must implement when we tackle ptrs)
}
