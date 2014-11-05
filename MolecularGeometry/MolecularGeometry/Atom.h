#ifndef _ATOM_H
#define _ATOM_H

#include <memory> //smart ptrs
#include <string> //strings
#include <vector> //bonds

class Atom{
private:
	//atom name
	std::string name;
	//atomic number
	int number;
	//positional coordinates
	double xPos;
	double yPos;
	double zPos;
	//bonds
	std::vector<std::pair<std::shared_ptr<Atom>, double>> distances;

public:
	//constructors
	Atom(){ number = 0; }
	Atom(double coordinates[], int aNum = 0);
	//destructors
	~Atom();

	//getters
	std::string getName(){ return name; }
	int getNumber(){ return number; }
	double getX(){ return xPos; }
	double getY(){ return yPos; }
	double getZ(){ return zPos; }
	//setters
	void setName(std::string aName){ name = aName; }
	void setNumber(int aNum){ number = aNum; }
	void setX(double x){ xPos = x; }
	void setY(double y){ yPos = y; }
	void setZ(double z){ zPos = z; }

	//bond ptr operations
	void addDistance(Atom* a);
	double calculateInteratomicDistance(double x, double y, double z);
	void displayDistances();

};

#endif