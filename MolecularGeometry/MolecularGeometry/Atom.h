#ifndef _ATOM_H
#define _ATOM_H

#include <memory> //smart ptrs
#include <string> //strings
using std::string;

class Atom{
private:
	//atom name
	string name;
	//atomic number
	int number;
	//positional coordinates
	double xPos;
	double yPos;
	double zPos;
	//bonds
	Atom* bonds; //need to use smart ptrs

public:
	//constructors
	Atom(){ number = 0; }
	Atom(double coordinates[], int aNum = 0);
	//destructors
	~Atom();

	//getters
	string getName(){ return name; }
	int getNumber(){ return number; }
	double getX(){ return xPos; }
	double getY(){ return yPos; }
	double getZ(){ return zPos; }
	//setters
	void setName(string aName){ name = aName; }
	void setNumber(int aNum){ number = aNum; }
	void setX(int x){ xPos = x; }
	void setY(int y){ yPos = y; }
	void setZ(int z){ zPos = z; }

	//bond ptr operations


};

#endif