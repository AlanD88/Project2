#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Course.h"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>

using namespace std;

class Student: public Person
{
public:

	//Default constructor   
	Student();

	//setStudentInfo
	void setStudentInfo(const string& firstName, const string& lastName, int studentID, 
						bool wasTuitionPaid, vector<Course>& course);

	//getID
	int getID() const;

	//getNumberOfCourses
	int getNumberOfCourses() const;

	//getCreditsEnrolled
	int getCreditsEnrolled() const;

	//isTuitionPaid
	bool isTuitionPaid() const;

	//isEnrolledInCourse
	bool isEnrolledInCourse(const string& courseNumber) const;

	//getGpa
	double getGpa() const;

	//billingAmount
	double billingAmount(double pricePerCredit) const;

	//printStudentInfo
	void printStudentInfo() const;

	//printStudentInfo
	void printStudentInfo(double tuitionRate) const;

	//getCoursesEnrolled
	vector<Course> getCoursesEnrolled() const;

	void printStudentInfoToFile(ofstream& out, double tuitionRate);

	//Destructor
	~Student();

private:
    int studentID;				
    int numberOfCourses;	
    bool tuitionWasPaid;		
    vector<Course> coursesEnrolled; 
};

#endif



