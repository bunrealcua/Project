#include<iostream>
using namespace std;
#include "StructStudent.h"
#include"Student.h"

void ExportListOfStu(Student* pHead)
{
	string Subject;
	string Class;
	Student* pCur = pHead;
	cout << "Enter the subject title, please! " << endl;
	cin.ignore(1000, '\n');
	getline(cin, Subject);
	cout << "Enter the class, please! " << endl;
	cin.ignore(1000, '\n');
	getline(cin, Class);
	wifstream filein;
	wofstream fileout;
	wchar_t a = ',';
	int count = 0;
	wstring n;
	filein.open(Class + ".csv", ios_base::in);
	if (!filein.is_open()) {
		return;
	}
	fileout.open(Class + Subject + "csv", ios_base::out);
	if (!fileout.is_open()) {
		return;
	}
	fileout << "ID" << a << "first name" << a << "last name" << a << "gender" << a << "social ID" << endl;
	while (!filein.eof()) {
		while (pCur != nullptr) {
			filein >> pCur->ID >> a >> pCur->First_Name >> a >> pCur->Last_Name >> a >> pCur->Gender >> a >> n >> a >> pCur->Social_ID >> a;
		}
	}
}