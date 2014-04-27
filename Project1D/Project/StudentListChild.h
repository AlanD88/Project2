#ifndef STUDENTLISTCHILD_H
#define STUDENTLISTCHILD_H

#include "StudentList.h"

#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class StudentListChild: public StudentList
{
public:

	// default constructor
	StudentListChild();

	// printStudentsInOrder
	void printStudentsInOrder() const;

	// destructor
	~StudentListChild();
};
  
#endif

