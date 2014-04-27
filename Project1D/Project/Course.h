#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Course
{
public:

	// default constructor
	Course();

	// setCourseInfo
	void setCourseInfo(const string& courseName, const string& courseNo, char courseGrade, int courseCredits);
	/*
	@Param courseName - Name of the course stored as a string.
	@Param courseNo - The Course number stored as a string.
	@Param courseGrade - The Course grade stored as a char.
	@Param courseCredits - The credits for the course stored as an int.
	*/

	// printCourseInfo
	void printCourseInfo(bool isGrade) const;
	//printCourseInfo const - Prints the course info.
	// @Param isGrade - Returns true if student has a grade.

	// getCourseCredits
	int getCourseCredits() const;
	// getCourseCredits const - Returns the course Credits.
	//Returns the Course Credits.

	// getCourseNumber
	string getCourseNumber() const;
	// getCourseNumber const - Returns the course number.
	//@Return - Returns the Course Number.

	// getCourseName
	string getCourseName() const;
	// getCourseName const - returns the course name.
	//@Return the course name.

	// getCourseGrade
	char getCourseGrade() const;
	// getCourseGrade const - Returns the course grade.
	// @Return the course grade.

	// destructor
	~Course();


private:
    string courseName; 	
    string courseNo; 	
    char courseGrade;	
    int courseCredits;	
};

#endif
