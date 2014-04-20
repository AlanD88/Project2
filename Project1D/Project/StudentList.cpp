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
	if (studentList->at(0).getID == studentID)
	{	
		studentList->at(0).printStudentInfo(tuitionRate);	
	}
	
	else
	{
		vector<Student>::iterator iter = studentList->begin();
		bool isFound = false;

			while (!isFound)
			{
				if (iter->getID() == studentID) //If data is found.
				{
					iter->printStudentInfo(tuitionRate);
					//current = current->getNext();
					isFound = true;
				}
				else if (iter == studentList->end())
				{
					cerr << "No student with ID " << studentID << " found in the list." << endl;
					//current = current->getNext();
					isFound = true;
				}
				else
				{
					iter++;
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
		vector<Student>::iterator iter = studentList->begin();
		bool printed = false;
		while (iter != studentList->end())
		{
			if (iter->getNumberOfCourses() != 0 &&
				iter->isEnrolledInCourse(courseNumber))
			{
				iter->printStudentInfo();
				printed = true;
			}
			iter++;
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
		Node *current = first;
		bool isFound = false;
		while (!isFound)
		{
			if (current->getStudent().getLastName() == lastName)
			{
				current->getStudent().printStudentInfo();
				isFound = true;
				//current = current->getNext();
			}
			else if (current == last && current->getStudent().getLastName() != lastName)
			{
				cerr << "No student with the last name " << lastName << " is in the list." << endl;
				isFound = true;
				//current = current->getNext();
			}
			else
			{
				current = current->getNext();
			}
		}
	}
}

// printStudentsOnHold
void StudentList::printStudentsOnHold(double tuitionRate) const
{
	if (first == NULL)
	{
		cerr << "No students in the list" << endl;
	}
	else
	{
		Node *current = first;

		while (current != NULL)
		{
			if (!current->getStudent().isTuitionPaid())
			{
				
				current->getStudent().printStudentInfo();
				cout << "   Amount Due: $" << current->getStudent().billingAmount(tuitionRate) << endl;
				current = current->getNext();
			}
			else
			{
				current = current->getNext();
			}
		}
	}

}

// printAllStudents
void StudentList::printAllStudents(double tuitionRate) const
{
	if (first == NULL)
	{
		cerr << "No students in the list" << endl;
	}
	else
	{
		Node *current = first;

		while (current != NULL)
		{
			current->getStudent().printStudentInfo(tuitionRate);
			current = current->getNext();
		}
	}
}


// printStudentsToFile
void StudentList::printStudentsToFile(ofstream& outp, double tuitionRate) const
{
	if (first == NULL)
		cerr << "Cannot print. No students in the list.\n";
	else
	{
		Node *current = first;

		while (current != NULL)
		{
			current->getStudent().printStudentInfoToFile(outp, tuitionRate);
			current = current->getNext();
		}
	}
}


// destroyStudentList
void StudentList::destroyStudentList()
{
	while (first != NULL)
	{
		Node *temp = first;
		first = first->getNext();
		delete temp;
		--count;
	}
	last = NULL;
	first = NULL;
	count = 0;

}


// destructor
StudentList::~StudentList()
{
	destroyStudentList();
}
