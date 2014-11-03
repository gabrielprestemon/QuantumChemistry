/*
Authors: Miguel Arroyo, Gabriel Prestemon
Project: Quantum Chemistry
Website: http://sirius.chem.vt.edu/wiki/doku.php?id=crawdad%3Aprogramming
*/
#include "Atom.h"
#include "Molecule.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Enter molecule:" << endl;
	string input;
	cin >> input;

	Molecule ourCreation(input);
	ourCreation.printData();

	cout << endl;
	system("pause");
	return 0;
}