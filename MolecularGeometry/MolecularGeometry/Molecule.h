#ifndef _MOLECULE_H
#define _MOLECULE_H

#include <memory>
#include <string>

class Atom;

class Molecule{
private:
	//name of molecule
	std::string name;
	//elemental contents
	int numElements;
	Atom* elements;

public:
	//constructors
	Molecule(){}
	Molecule(std::string fileName);
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