#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StudentList
{
public:

	// default constructor
	StudentList();

	// addStudent
	void addStudent(const Student& newStudent);

	// getNoOfStudents
	int getNoOfStudents() const;

	// printStudentByID
	void printStudentByID(int studentID, double tuitionRate) const;

	// printStudentsByCourse
	void printStudentsByCourse(const string& courseNumber) const;

	// printStudentsByName
	void printStudentsByName(const string& lastName) const;

	// printStudentsOnHold
	void printStudentsOnHold( double tuitionRate) const;

	// printAllStudents
	void printAllStudents(double tuitionRate) const;

	// printStudentsToFile
	void printStudentsToFile(ofstream& outp, double tuitionRate) const;

	// destroyStudentList
	void destroyStudentList();
	
	// destructor
	~StudentList();

protected:
	vector<Student> *studentList;
};

#endif

