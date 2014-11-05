#include "Molecule.h"
#include "Atom.h"
#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <assert.h>

using namespace std;

Molecule::Molecule(string fileName)
{
	//open file stream
	fileName += ".txt";
	ifstream input;
	input.open(fileName);

	//be sure file is open, crash if not
	assert(input.is_open());

	//set number of elements
	input >> numElements;
	elements = new Atom[numElements];

	int i = 0;
	while (input){
		//retrieve, set the atomic number
		int atomNum;
		input >> atomNum;
		elements[i].setNumber(atomNum);

		//retrieve, set the positional coordinates
		double x, y, z;
		input >> x >> y >> z;
		elements[i].setX(x);
		elements[i].setY(y);
		elements[i].setZ(z);

		i++;
	}

	findInteratomicDistances();

	input.close();
}

void Molecule::findInteratomicDistances()
{
	for (int i = 0; i < numElements; i++){
		for (int j = 0; j < numElements; j++){
			if (i != j){
				elements[i].addDistance(&elements[j]);
			}
		}
	}
}

void Molecule::printData()
{
	cout << endl << "Contents:" << endl;
	listAtoms();
	//any other printing operations here
	listInteratomicDistances();
}

void Molecule::listAtoms()
{
	for (int i = 0; i < numElements; i++){
		//display the atomic number
		cout << "Atomic Number: " << elements[i].getNumber() << " : : Position: (";
		//retrieve, display, set the positional coordinates
		cout << elements[i].getX() << ", " << elements[i].getY() << ", " << elements[i].getZ() << ")" << endl;
	}
}

void Molecule::listInteratomicDistances()
{
	cout << endl << "Bonds and Distances: " << endl;
	for (int i = 0; i < numElements; i++){
		cout << "This atom: " << elements[i].getNumber() << endl;
		elements[i].displayDistances();
		cout << endl;
	}
	cout << endl;
}

Molecule::~Molecule()
{
	//doesn't need deallocation because of smart_ptrs
}