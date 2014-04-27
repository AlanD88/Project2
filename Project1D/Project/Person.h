#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class Person{
public:
	//Default Constructor
	Person();

	//Overloaded Constructor
	Person(const string& fName, const string& lName);

	//setName
	void setName(const string& fName, const string& lName);
	//@Param fName - Persons first name stored as a string.
	//@Param lName - Persons last name stored as a string.

	//getLastName
	string getLastName() const;
	//@Return the persons last name.

	//getName
	void getName(string& first, string& last) const;
	//@Return the persons first name.

	//printName
	void printName() const;
	// printName prints the firt and last name of the person.

	//Destructor
	~Person();

private:
	string fName;
	string lName;
};

#endif // PERSON_H
