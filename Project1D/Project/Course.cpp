#include "Course.h"

// default constructor
Course::Course() 
{	
    courseGrade = '*';	
    courseCredits = 0;
}

// setCourseInfo
void Course::setCourseInfo(const string& courseName, const string& courseNo, char courseGrade, int courseCredits) 
{
	this->courseName = courseName;
	this->courseNo = courseNo;
	this->courseGrade = courseGrade;
	this->courseCredits = courseCredits;
	
}

// printCourseInfo
void Course::printCourseInfo(bool isGrade) const
{

	cout << setw(11);
	cout << left << courseNo;
	cout << setw(17);
	cout << left << courseName;
	cout << setw(3) <<  left << courseCredits;
	
	if(isGrade)
	{
		cout << setw(5) << right << courseGrade << endl;
	}
	else
	{
		cout << setw(5) << right << "***" << endl;
	}
}

// getCourseCredits
int Course::getCourseCredits() const
{
	return courseCredits;
}

// getCourseNumber
string Course::getCourseNumber() const
{
	return courseNo;
}

// getCourseName
string Course::getCourseName() const
{
	return courseName;
}

// getCourseGrade
char Course::getCourseGrade() const
{
	return courseGrade;
}

// destructor
Course::~Course(){}

