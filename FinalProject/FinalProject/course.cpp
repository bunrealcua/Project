#include "StructStudent.h"

void crAdd()
{
	int tempI;
	char tempC[100];
	wstring wtemp;
	wofstream crOut("../Resource/courses.csv", fstream::out | fstream::app);
	cout << "Course ID: "; cin >> tempC; crOut << tempC << ",";
	cout << "Course name: "; cin.ignore(); cin.getline(tempC, 100); crOut << tempC << ",";
	cout << "Lecturer: "; wcin.ignore(); getline(wcin, wtemp); crOut << wtemp << ",";
	cout << "Number of credits: "; cin >> tempI; crOut << tempI << ",";
	cout << "Student limit: "; cin >> tempI; crOut << tempI << ",";
	cout << "Week day(1 for Sunday): "; cin >> tempI; crOut << tempI << ",";
	cout << "Session: "; cin >> tempI; crOut << tempI << ",";
	crOut.close();
}