#include <iostream>
#include <string>
#include "Rectangle2D.h"
#include "Course.h"
using namespace std;

int * makeArray(int size);
void enterValues(int* numbers, int size);
int countAbove(int* numbers, int size, double avg);
int* doubleCapacity(const int* list, int size);
int findSmallest(int* numbers, int size);


int main()
{
	//EX04_01 11.1-Completed
	int size;
	double avg;
	int	sum = 0;

	cout << "How many numbers in the array? ";
	cin >> size;

	int* numbers = makeArray(size);
	enterValues(numbers, size);
	
	int* curr = numbers;
	do
	{
		sum = sum + *curr;
		curr++;
	} while (curr < numbers + size);
	avg = (sum / size);

	cout << "The average is: " << avg << endl;
	cout << "There are " << countAbove(numbers, size, avg) << " numbers above the average." << endl << endl;

	delete[] numbers;

	//EX04_02 11.3-Completed
	cout << "Original array size: " << size << endl;
	int* newlist = doubleCapacity(numbers, size); 
	cout << "Increased capacity array size: " << *newlist << endl << endl;

	delete[] newlist;

	//EX04_03 11.5-Completed
	cout << "How many numbers in the array? ";
	cin >> size;

	int* numbers2 = makeArray(size);
	enterValues(numbers2, size);
	cout << "The smallest number is " << findSmallest(numbers2, size) << endl << endl;
	delete[] numbers2;

	//EX04_04 11.9-Complete
	Rectangle2D r1(2, 2, 5.5, 4.9);
	Rectangle2D r2(4, 5, 10.5, 3.2);
	Rectangle2D r3(3, 5, 2.3, 5.4);

	string Bool;
	bool function = r1.contains(3, 3);
	if (function == true)
	{
		Bool = "True";
	}
	else
		Bool = "False";
	cout << "Rectangle 1 contains the point (3, 3): " << Bool << endl;

	function = r1.contains(r2);
	if (function == true)
	{
		Bool = "True";
	}
	else
		Bool = "False";

	cout << "Rectangle 1 contains Rectangle 2: " << Bool << endl;

	function = r1.overlaps(r3);
	if (function == true)
	{
		Bool = "True";
	}
	else
		Bool = "False";

	cout << "Rectangle 1 overlaps Rectangle 3: " << Bool << endl << endl;
	
	//EX04_05 11.13-Complete
	string courseName;
	int capacity;
	cout << "What is the name of the course? ";
	cin >> courseName;
	cout << "How many people can the class hold? ";
	cin >> capacity;

	Course c1(courseName, capacity);
	
	string s1, s2, s3;
	cout << "Enter the names of your new students: ";
	cin >> s1;
	c1.addStudent(s1);
	cin >> s2;
	c1.addStudent(s2);
	cin >> s3;
	c1.addStudent(s3);

	string dropper;
	cout << "Who would you like to drop from the class? " << s1 << ", " << s2 << ", or " << s3 << endl;
	cin >> dropper;
	c1.dropStudent(dropper);

	cout << "The students currently enrolled are: " << c1.getNumberOfStudents() << endl;
	string * students = c1.getStudents();
	for (int i = 0; i < c1.getNumberOfStudents(); i++)
	{
		cout << students[i] << "\n";
	}
	return 0;
}

int * makeArray(int size)
{
	int* pintarray = new int[size];
	for (int i = 0; i < size; i++)
		pintarray[i] = 42;
	return pintarray;
}

void enterValues(int* numbers, int size)
{
	for (int* curr = numbers; curr < numbers + size; curr++)
	{
		cout << "Enter number: ";
		cin >> *curr;
	}
}

int countAbove(int* numbers, int size, double avg)
{
	int above = 0;
	for (int*curr = numbers; curr < numbers + size; curr++)
	{
		if (*curr > avg)
			above++;
	}
	return above;
}

int* doubleCapacity(const int* list, int size)
{
	int* newList = new int(size * 2); 
	int i = (size * 2);
	newList[i] = list[i];
	return newList;
}

int findSmallest(int* numbers, int size)
{
	int* temp = numbers;
	int smallest = *temp;
	do
	{
		if (*temp < smallest)
			smallest = *temp;
		temp++;
	} while (temp < numbers + size);
	return smallest;
}