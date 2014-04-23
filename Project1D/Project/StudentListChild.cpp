#include "StudentListChild.h"

StudentListChild::StudentListChild()
{
}

void StudentListChild::printStudentsInOrder() const
{
	map<string, int> students;
	vector<Student>::const_iterator vectorIter;
	map<string, int>::const_iterator mapIter;
	string first, last, both;

	for (vectorIter = studentList->begin(); vectorIter != studentList->end(); ++vectorIter)
	{
		vectorIter->getName(first, last);
		both = (last + ", " + first);
		students.emplace(both, vectorIter->getID());
	}

	for (mapIter = students.begin(); mapIter != students.end(); ++mapIter)
	{
		cout << mapIter->second << " - " << mapIter->first << endl;
	}
}

StudentListChild::~StudentListChild()
{
}


