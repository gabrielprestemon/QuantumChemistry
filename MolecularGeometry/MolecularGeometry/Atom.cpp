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

void Atom::addDistance(Atom* a)
{
	double bondLen = calculateInteratomicDistance(a->getX(), a->getY(), a->getZ());
	shared_ptr<Atom> bond(a);
	distances.push_back(make_pair(bond, bondLen));
}

double Atom::calculateInteratomicDistance(double x, double y, double z)
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

void Atom::displayDistances()
{
	for (int i = 0; i < distances.size(); i++){
		cout << "Atomic Number: " << distances[i].first->getNumber() << ", Distance: " << distances[i].second << endl;
	}
}

Atom::~Atom()
{
	//dousn't need deallocation because of smart_ptrs
}
