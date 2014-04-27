#include "StudentList.h"

// default constructor
StudentList::StudentList()
{
	studentList = new vector<Student>;
}

// addStudent
void StudentList::addStudent(const Student& newStudent)
{
	studentList->push_back(newStudent);
}

// getNoOfStudents
int StudentList::getNoOfStudents() const
{
	return static_cast<int>(studentList->size());
}

// printStudentByID
void StudentList::printStudentByID(int studentID, double tuitionRate) const
{
	//If list is empty
	if (static_cast<int>(studentList->size()) == 0)
	{
		cerr << "List is empty." << endl;
	}
	//If Student I.D is first in the list
	if (studentList->at(0).getID() == studentID)
	{	
		studentList->at(0).printStudentInfo(tuitionRate);	
	}
	
	else
	{
		vector<Student>::const_iterator constIter = studentList->begin();
		bool isFound = false;

			while (!isFound)
			{
				if (constIter->getID() == studentID) //If data is found.
				{
					constIter->printStudentInfo(tuitionRate);
					isFound = true;
				}
				else if (constIter == studentList->end())
				{
					cerr << "No student with ID " << studentID << " found in the list." << endl;
					isFound = true;
				}
				else
				{
					constIter++;
				}
			}
	}
}

// printStudentsByCourse
void StudentList::printStudentsByCourse(const string& courseNumber) const
{
	//If list is empty
	if (static_cast<int>(studentList->size()) == 0)
	{
		cerr << "List is empty." << endl;
	}
	else
	{
		vector<Student>::const_iterator constIter;
		bool printed = false;

		for (constIter = studentList->begin(); constIter != studentList->end(); ++constIter)
		{
			if (constIter->getNumberOfCourses() != 0 &&
				constIter->isEnrolledInCourse(courseNumber))
			{
				constIter->printStudentInfo();
				printed = true;
			}
		}
		if (!printed)
			cerr << "No student enrolled in " << courseNumber << endl;
	}
}

// printStudentsByName
void StudentList::printStudentsByName(const string& lastName) const
{
	//If list is empty
	if (static_cast<int>(studentList->size()) == 0)
	{
		cerr << "List is empty." << endl;
	}
	else
	{
		vector<Student>::const_iterator constIter;
		bool checkSecond = false;  //Flag to check if 2 students share a last name

		for (constIter = studentList->begin(); constIter != studentList->end(); ++constIter)
		{
			if (constIter->getLastName() == lastName)
			{
				constIter->printStudentInfo();
				checkSecond = true;
			}
			else if (constIter == studentList->end() - 1 && !checkSecond) // studentList is never going to get to the end (constIter != studentList->end())
			{
				cerr << "No student with the last name " << lastName << " is in the list." << endl;
			}
		}
	}
}

// printStudentsOnHold
void StudentList::printStudentsOnHold(double tuitionRate) const
{
	//If list is empty
	if (static_cast<int>(studentList->size()) == 0)
	{
		cerr << "List is empty." << endl;
	}
	else
	{
		vector<Student>::const_iterator constIter;
		bool holds = false;  //check to see if no students on hold.

		for (constIter = studentList->begin(); constIter != studentList->end(); ++constIter)
		{
			if (!constIter->isTuitionPaid())
			{

				constIter->printStudentInfo();
				cout << "   Amount Due: $" << constIter->billingAmount(tuitionRate) << endl;
				holds = true;
			}
			else if (!holds && constIter == studentList->end() - 1)
			{
				cout << "There are no students on hold.\n";
			}
		}
	}

}

// printAllStudents
void StudentList::printAllStudents(double tuitionRate) const
{
	//If list is empty
	if (static_cast<int>(studentList->size()) == 0)
	{
		cerr << "List is empty." << endl;
	}
	else
	{
		vector<Student>::const_iterator constIter;

		for (constIter = studentList->begin(); constIter != studentList->end(); ++constIter)
		{
			constIter->printStudentInfo(tuitionRate);
		}
	}
}

// printStudentsToFile
void StudentList::printStudentsToFile(ofstream& outp, double tuitionRate) const
{
	//If list is empty
	if (static_cast<int>(studentList->size()) == 0)
	{
		cerr << "List is empty." << endl;
	}
	else
	{
		vector<Student>::iterator vectorIter;

		for (vectorIter = studentList->begin(); vectorIter != studentList->end(); ++vectorIter)
		{
			vectorIter->printStudentInfoToFile(outp, tuitionRate);
		}
	}
}

// destroyStudentList
void StudentList::destroyStudentList()
{
	delete studentList;
	studentList = NULL;
}

// destructor
StudentList::~StudentList()
{
	destroyStudentList();
}
