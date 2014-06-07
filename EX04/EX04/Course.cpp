#include <iostream>
#include <string>
#include "Course.h"
using namespace std;

Course::Course(const string& courseName, int capacity)
{
	numberOfStudents = 0;
	this->courseName = courseName;
	this->capacity = capacity;
	students = new string[capacity];
}

Course::~Course()
{
	delete[] students;
}

Course::Course(const Course& course)
{
	courseName = course.courseName;
	numberOfStudents = course.numberOfStudents;
	capacity = course.capacity;
	students = new string[capacity];
}

string Course::getCourseName() const
{
	return courseName;
}

void Course::addStudent(const string& name)
{
	students[numberOfStudents] = name;
	numberOfStudents++;
	if (numberOfStudents > capacity)
	{
		capacity++;
		string* newList = new string[capacity];
		for (int i = 0; i < (capacity); i++)
		{
			newList[i] = students[i];
		}
	}
}

void Course::dropStudent(const string& name)
{
	students[numberOfStudents] = name;
	numberOfStudents--;
}

string* Course::getStudents() const
{
	return students;
}

int Course::getNumberOfStudents() const
{
	return numberOfStudents;
}

void Course::clear()
{
	numberOfStudents = 0;
}