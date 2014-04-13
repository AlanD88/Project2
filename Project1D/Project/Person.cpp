#include "Person.h"


//Default Constructor
Person::Person()
{
	fName = "N/A";
	lName = "N/A";
}
//Overloaded Constructor
Person::Person(const string& fName, const string& lName) : fName(fName), lName(lName){}

//setName
void Person::setName(const string& fName, const string& lName)
{
	this->fName = fName;
	this->lName = lName;
}

//getLastName
string Person::getLastName() const
{
	return lName;
}

//getName
void Person::getName(string& first, string& last) const
{
	first = fName;
	last = lName;
}

//printName
void Person::printName() const
{
	cout << lName << ", " << fName << endl;
}

//Destructor
Person::~Person(){}