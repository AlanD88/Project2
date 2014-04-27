#include "Student.h"

Student::Student()
{
	studentID = 0;
	numberOfCourses = 0;
	tuitionWasPaid = false;
}

//setStudentInfo
void Student::setStudentInfo(const string& firstName, const string& lastName, int studentID, 
							bool wasTuitionPaid, vector<Course>& course)
{
	setName(firstName, lastName);
	this->studentID = studentID;
	this->tuitionWasPaid = wasTuitionPaid;
	coursesEnrolled = course;
	numberOfCourses = static_cast<int>(coursesEnrolled.size());

}

//getID
int Student::getID() const
{
	return studentID;
}

//getNumberOfCourses
int Student::getNumberOfCourses() const
{
	return numberOfCourses;
}

//getCreditsEnrolled
int Student::getCreditsEnrolled() const
{
	unsigned int len = coursesEnrolled.size();
	int credits = 0;
	for (unsigned int i = 0; i <len; i++)
	{
		credits += coursesEnrolled[i].getCourseCredits();
	}

	return credits;
}

//isTuitionPaid
bool Student::isTuitionPaid() const
{
	return tuitionWasPaid;
}

//isEnrolledInCourse
bool Student::isEnrolledInCourse(const string& courseNumber) const
{
	unsigned int len = coursesEnrolled.size();

	if (len == 0)
	{
		return false;
	}
	else
	{
		for (unsigned int i = 0; i < len; i++)
		{
			if (coursesEnrolled[i].getCourseNumber() == courseNumber)
			{
				return true;
			}

		}
	}

	return false;
}

//getGpa
double Student::getGpa() const
{
	unsigned int len = coursesEnrolled.size();
	double  GPA = 0.0;
	for (unsigned i = 0; i < len; i++)
	{
		
		switch (coursesEnrolled[i].getCourseGrade())
		{
		case 'A': GPA += 4.0 * coursesEnrolled[i].getCourseCredits();
				break;
		case 'B': GPA += 3.0 * coursesEnrolled[i].getCourseCredits();
				break;
		case 'C': GPA += 2.0 * coursesEnrolled[i].getCourseCredits();
				break;
		case 'D': GPA += 1.0 * coursesEnrolled[i].getCourseCredits();
				break;
		case 'F': GPA += 0.0;
				break;
		
		}
		
	}
	return GPA / getCreditsEnrolled();
}

//billingAmount
double Student::billingAmount(double pricePerCredit) const
{
	return pricePerCredit * getCreditsEnrolled();

}

//printStudentInfo
void Student::printStudentInfo() const
{
	cout << studentID << " - ";
	printName();
}

//printStudentInfo
void Student::printStudentInfo(double tuitionRate) const
{
	unsigned int len = coursesEnrolled.size();
	cout << "Student Name: ";
	printName();
	cout << endl;
	cout << "Student ID: " << studentID << endl;
	cout << "Number of courses enrolled: " << numberOfCourses << endl;
	cout << endl;
	cout << setw(11) << left << "Course No" << setw(13) << left << "Course Name" << setw(8)
		<< "Credits" << setw(6) << "Grade" << endl;
	if (tuitionWasPaid)
	{
		for (unsigned int i = 0; i < len; i++)
		{
			coursesEnrolled[i].printCourseInfo(true);
		}
		cout << endl;
		cout << "Total number of credit hours: " << getCreditsEnrolled() << endl;
		cout << "Current Term GPA: " << getGpa() << endl;
		cout << endl;
		cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n";

	}
	else
	{
		for (unsigned int i = 0; i < len; i++)
		{
			coursesEnrolled[i].printCourseInfo(false);
		}

		cout << endl;
		cout << "Total number of credit hours: " << getCreditsEnrolled() << endl;
		cout << "*** Grades are being held for not paying the tuition. ***" << endl;
		cout << "Amount Due: $" << billingAmount(tuitionRate) << endl;
		cout << endl;
		cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n";
	}	
}

//getCoursesEnrolled
vector<Course> Student::getCoursesEnrolled() const
{
	return coursesEnrolled;
}

//printStudentInfoToFile
void Student::printStudentInfoToFile(ofstream& out, double tuitionRate)
{
	out << "Student Name: ";
	string first, last;
	getName(first, last);
	out << last << ", " << first << endl;
	out << "\nStudent ID: " << studentID << endl;
	unsigned int len = coursesEnrolled.size();
	out << "Number of courses enrolled: " << len << endl;
	out << "\nCourse No   Course Name  Credits Grade\n";

	if (tuitionWasPaid)
	{
		for (unsigned i = 0; i < len; i++)
		{
			out << setw(12) << left << coursesEnrolled[i].getCourseNumber() << setw(17) << left 
				<< coursesEnrolled[i].getCourseName() << setw(5) << coursesEnrolled[i].getCourseCredits();
			out << setw(7) << coursesEnrolled[i].getCourseGrade() << endl;
		}
		out << "\nTotal number of credit hours: " << getCreditsEnrolled() << endl;
		out << "Current Term GPA: " << fixed << setprecision(2) << getGpa() << endl;
	}
	else
	{
		for (unsigned i = 0; i < len; i++)
		{
			out << setw(12) << left << coursesEnrolled[i].getCourseNumber() << setw(17) << left 
				<< coursesEnrolled[i].getCourseName() << setw(5) << coursesEnrolled[i].getCourseCredits();
			out << setw(7) << "***" << endl;
		}
		out << "\nTotal number of credit hours: " << getCreditsEnrolled() << endl;
		out << "*** Grades are being held for not paying the tuition. ***" << endl;
		out << "Amount Due: $" << billingAmount(tuitionRate) << endl;
	}

	out << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n" << endl;
}

//Destructor
Student::~Student(){}