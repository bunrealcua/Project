#include"Staff.h"
#include"Student.h"
#include<iostream>
using namespace std;

void ViewClass(int option,int schoolyear,Student*& headStudent, Class*& headClass)
{
	string str;
	if (schoolyear == 1)
	{
		if (option == 1) str = "D:\\InputProject\\SchoolYear1\\APCS.csv";
		else if (option == 2) str = "D:\\InputProject\\SchoolYear1\\CLC.csv";
		else if (option==3) str= "D:\\InputProject\\SchoolYear1\\CNTT.csv";
		else if (option==4) str= "D:\\InputProject\\SchoolYear1\\CTDT.csv";
		else str="D:\\InputProject\\SchoolYear1\\VP.csv";
	}
	else if (schoolyear == 2)
	{
		if (option == 1) str = "D:\\InputProject\\SchoolYear2\\APCS.csv";
		else if (option == 2) str = "D:\\InputProject\\SchoolYear2\\CLC.csv";
		else if (option == 3) str = "D:\\InputProject\\SchoolYear2\\CNTT.csv";
		else if (option == 4) str = "D:\\InputProject\\SchoolYear2\\CTDT.csv";
		else str = "D:\\InputProject\\SchoolYear2\\VP.csv";
	}
	else if (schoolyear == 3)
	{
		if (option == 1) str = "D:\\InputProject\\SchoolYear3\\APCS.csv";
		else if (option == 2) str = "D:\\InputProject\\SchoolYear3\\CLC.csv";
		else if (option == 3) str = "D:\\InputProject\\SchoolYear3\\CNTT.csv";
		else if (option == 4) str = "D:\\InputProject\\SchoolYear3\\CTDT.csv";
		else str = "D:\\InputProject\\SchoolYear3\\VP.csv";
	}
	else {
		if (option == 1) str = "D:\\InputProject\\SchoolYear1\\APCS.csv";
		else if (option == 2) str = "D:\\InputProject\\SchoolYear1\\CLC.csv";
		else if (option == 3) str = "D:\\InputProject\\SchoolYear1\\CNTT.csv";
		else if (option == 4) str = "D:\\InputProject\\SchoolYear1\\CTDT.csv";
		else str = "D:\\InputProject\\SchoolYear1\\VP.csv";
	}
	wstring wstr;
	Input(str, wstr, headStudent);
	Class*curClass=nullptr;
	Student* curStudent = headStudent;
	Class* tempClass = nullptr;
	bool check=true;

	while (curStudent != nullptr) {
		if (headClass == nullptr) {
			headClass = new Class;
			headClass->data = curStudent->Class;
			headClass->next = nullptr;
			curClass = headClass;
		}
		else
		{
			tempClass = headClass;
			while (tempClass != nullptr)
			{
				if (tempClass->data == curStudent->Class) check = false;
				tempClass = tempClass->next;
			}
			if (check == true) {
				curClass->next = new Class;
				curClass = curClass->next;
				curClass->data = curStudent->Class;
				curClass->next = nullptr;
			}
		}
		curStudent = curStudent->pNext;
	}
	if (headClass == nullptr) cout << "No Student in this class";
	else
	{
		int i = 0;
		curClass = headClass;
		while (curClass != nullptr) {
			i++;
			cout << i << ". " << curClass->data << endl;
			curClass = curClass->next;
		}
	}
	
	DeleteListClass(headClass);
}

void DeleteListClass(Class*& headClass) {
	Class* curClass = nullptr;
	if (headClass != nullptr)
	{
		curClass = headClass;
		headClass = headClass->next;
		delete curClass;
	}
}