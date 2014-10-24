#include "Atom.h"
#include <iostream>

using namespace std;

Atom::Atom(double coordinates[], int aNum)
{
	number = aNum;
	xPos = coordinates[0];
	yPos = coordinates[1];
	zPos = coordinates[2];
}

Atom::~Atom()
{
	//MEMORY DEALLOCATION!!!
	//(must implement when we tackle ptrs)
}
