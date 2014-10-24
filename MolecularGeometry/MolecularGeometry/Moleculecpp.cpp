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

	//be sure file is open
	assert(input.is_open());

	//set number of elements
	input >> numElements;
	elements = new Atom[numElements];


	while (input){
		int atomNum;
		input >> atomNum;

		cout << atomNum << ": ";
		double x, y, z;
		input >> x >> y >> z;
		cout << x << " " << y << " " << z << endl;
	}

	input.close();
}

Molecule::~Molecule()
{
	delete[] elements;
}