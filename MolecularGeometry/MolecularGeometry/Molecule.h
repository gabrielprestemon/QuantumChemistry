#ifndef _MOLECULE_H
#define _MOLECULE_H

#include <memory>
#include <string>
using std::string;

class Atom;

class Molecule{
private:
	//name of molecule
	string name;
	//elemental contents
	int numElements;
	Atom* elements;

public:
	Molecule(){}
	Molecule(string fileName);
	~Molecule();

	void printData();

};

#endif