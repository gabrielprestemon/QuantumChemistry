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
	//constructors
	Molecule(){}
	Molecule(string fileName);
	//destructors
	~Molecule();

	//calculations
	void findInteratomicDistances();

	//printing operations
	void printData();
	void listAtoms();
	void listInteratomicDistances();

};

#endif