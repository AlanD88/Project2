#include "StudentList.h"



// default constructor
StudentList::StudentList() : first(NULL), last(NULL), count(0) {}

// addStudent
void StudentList::addStudent(const Student& newStudent)
{
	Node *temp = new Node(newStudent, first);
	++count;

	if (first == NULL)
	{
		first = temp;
		last = temp;
	}
	else
	{	
		temp->setNext(first);
		first = temp;
	}

	


}

// getNoOfStudents
int StudentList::getNoOfStudents() const
{
	return count;
}

// printStudentByID
void StudentList::printStudentByID(int studentID, double tuitionRate) const
{
	//If list is empty
	if (first == NULL)
	{
		cerr << "List is empty." << endl;
	}
	//If Student I.D is first in the list
	if (first->getStudent().getID() == studentID)
	{
		first->getStudent().printStudentInfo(tuitionRate);
		
	}
	
	else
	{
		Node *current = first;
		bool isFound = false;

			while (!isFound)
			{
				if (current->getStudent().getID() == studentID) //If data is found.
				{
					current->getStudent().printStudentInfo(tuitionRate);
					//current = current->getNext();
					isFound = true;
				}
				else if (current == last && current->getStudent().getID() != studentID)
				{
					cerr << "No student with ID " << studentID << " found in the list." << endl;
					//current = current->getNext();
					isFound = true;
				}
				else
				{
					current = current->getNext();
				}
				
			}
		
	}


}

// printStudentsByCourse
void StudentList::printStudentsByCourse(const string& courseNumber) const
{
	if (first == NULL)
		cout << "List is empty.\n";
	else
	{
		Node *current = first;
		bool printed = false;
		while (current != NULL)
		{
			if (current->getStudent().getNumberOfCourses() != 0 &&
				current->getStudent().isEnrolledInCourse(courseNumber))
			{
				current->getStudent().printStudentInfo();
				printed = true;
			}
			current = current->getNext();
		}
		if (!printed)
			cerr << "No student enrolled in " << courseNumber << endl;
	}
	

}

// printStudentsByName
void StudentList::printStudentsByName(const string& lastName) const
{
	if (first == NULL)
	{
		cerr << "List is empty.";
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
