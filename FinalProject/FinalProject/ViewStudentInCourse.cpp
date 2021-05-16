#include"Student.h"
#include<iostream>
#include<fstream>
#include <string>
#include<io.h>
#include<fcntl.h>
#include<locale>
#include<codecvt>
using namespace std;

void ViewStudentInCourse(int schoolyear, int courseID)
{
	/*Lấy đường dẫn đến file đăng kí.*/
	string str;
	if (schoolyear == 1) str = "Data\\SchoolYear1\\Registration.txt";
	else if (schoolyear == 2) str = "Data\\SchoolYear2\\Registration.txt";
	else if (schoolyear==3) str= "Data\\SchoolYear3\\Registration.txt";
	else "Data\\SchoolYear4\\Registration.txt";

	
	
	/*Mở file thôi nào*/
	ifstream FileIn;
	FileIn.open(str);
	string temp;
	MaSo* headMaSo = nullptr, * curMaSo = nullptr;
	if (FileIn.is_open() == false) wcout << "File registration can not be opened" << endl;
	else {
		getline(FileIn, temp);
		if (temp=="") wcout<< "There is no student in this course" << endl;
		while (!FileIn.eof() && temp != "")
		{
			getData(temp, headMaSo);
			curMaSo = headMaSo;
			while (curMaSo != nullptr) {
				if (curMaSo->ID == courseID) SeekInfoStudent(schoolyear, headMaSo->ID); /*headMaSo->ID là MSSV*/
				curMaSo = curMaSo->next;
			}
			DeleteListMaSo(headMaSo);
			getline(FileIn, temp);
		}
	}
	
	DeleteListMaSo(headMaSo);
	FileIn.close();
}

void SeekInfoStudent(int schoolyear, int IDstudent)
{
	/*Lấy đường dẫn đến file danh sach sinh vieen.*/
	string str;
	wstring wstr;
	Student* headStudent = nullptr,*curStudent=nullptr;
	if (schoolyear == 1)
	{
		str = "Data\\SchoolYear1\\APCS.csv";
		Input(str, wstr, headStudent);
		curStudent = headStudent;
		while (curStudent != nullptr)
		{
			if (curStudent->ID == IDstudent) wcout << curStudent->First_Name << L" " << curStudent->Last_Name;
			curStudent = curStudent->pNext;
		}
		DeleteListStudent(headStudent);
		str = "Data\\SchoolYear1\\CLC.csv";
		Input(str, wstr, headStudent);
		curStudent = headStudent;
		while (curStudent != nullptr)
		{
			if (curStudent->ID == IDstudent) wcout << curStudent->First_Name << L" " << curStudent->Last_Name;
			curStudent = curStudent->pNext;
		}
		DeleteListStudent(headStudent);
		str = "Data\\SchoolYear1\\CNTT.csv";
		Input(str, wstr, headStudent);
		curStudent = headStudent;
		while (curStudent != nullptr)
		{
			if (curStudent->ID == IDstudent) wcout << curStudent->First_Name << L" " << curStudent->Last_Name;
			curStudent = curStudent->pNext;
		}
		DeleteListStudent(headStudent);
		str = "Data\\SchoolYear1\\VP.csv";
		Input(str, wstr, headStudent);
		curStudent = headStudent;
		while (curStudent != nullptr)
		{
			if (curStudent->ID == IDstudent) wcout << curStudent->First_Name << L" " << curStudent->Last_Name;
			curStudent = curStudent->pNext;
		}
		DeleteListStudent(headStudent);
		str = "Data\\SchoolYear1\\CTDT.csv";
		Input(str, wstr, headStudent);
		curStudent = headStudent;
		while (curStudent != nullptr)
		{
			if (curStudent->ID == IDstudent) wcout << curStudent->First_Name << L" " << curStudent->Last_Name;
			curStudent = curStudent->pNext;
		}
		DeleteListStudent(headStudent);
	}
	else if (schoolyear == 2)
	{
		str = "Data\\SchoolYear2\\APCS.csv";
		Input(str, wstr, headStudent);
		curStudent = headStudent;
		while (curStudent != nullptr)
		{
			if (curStudent->ID == IDstudent) wcout << curStudent->First_Name << L" " << curStudent->Last_Name;
			curStudent = curStudent->pNext;
		}
		DeleteListStudent(headStudent);
		str = "Data\\SchoolYear2\\CLC.csv";
		Input(str, wstr, headStudent);
		curStudent = headStudent;
		while (curStudent != nullptr)
		{
			if (curStudent->ID == IDstudent) wcout << curStudent->First_Name << L" " << curStudent->Last_Name;
			curStudent = curStudent->pNext;
		}
		DeleteListStudent(headStudent);
		str = "Data\\SchoolYear2\\CNTT.csv";
		Input(str, wstr, headStudent);
		curStudent = headStudent;
		while (curStudent != nullptr)
		{
			if (curStudent->ID == IDstudent) wcout << curStudent->First_Name << L" " << curStudent->Last_Name;
			curStudent = curStudent->pNext;
		}
		DeleteListStudent(headStudent);
		str = "Data\\SchoolYear2\\VP.csv";
		Input(str, wstr, headStudent);
		curStudent = headStudent;
		while (curStudent != nullptr)
		{
			if (curStudent->ID == IDstudent) wcout << curStudent->First_Name << L" " << curStudent->Last_Name;
			curStudent = curStudent->pNext;
		}
		DeleteListStudent(headStudent);
		str = "Data\\SchoolYear2\\CTDT.csv";
		Input(str, wstr, headStudent);
		curStudent = headStudent;
		while (curStudent != nullptr)
		{
			if (curStudent->ID == IDstudent) wcout << curStudent->First_Name << L" " << curStudent->Last_Name;
			curStudent = curStudent->pNext;
		}
		DeleteListStudent(headStudent);
	}
	else if (schoolyear == 3)
	{
		str = "Data\\SchoolYear3\\APCS.csv";
		Input(str, wstr, headStudent);
		curStudent = headStudent;
		while (curStudent != nullptr)
		{
			if (curStudent->ID == IDstudent) wcout << curStudent->First_Name << L" " << curStudent->Last_Name;
			curStudent = curStudent->pNext;
		}
		DeleteListStudent(headStudent);
		str = "Data\\SchoolYear3\\CLC.csv";
		Input(str, wstr, headStudent);
		curStudent = headStudent;
		while (curStudent != nullptr)
		{
			if (curStudent->ID == IDstudent) wcout << curStudent->First_Name << L" " << curStudent->Last_Name;
			curStudent = curStudent->pNext;
		}
		DeleteListStudent(headStudent);
		str = "Data\\SchoolYear3\\CNTT.csv";
		Input(str, wstr, headStudent);
		curStudent = headStudent;
		while (curStudent != nullptr)
		{
			if (curStudent->ID == IDstudent) wcout << curStudent->First_Name << L" " << curStudent->Last_Name;
			curStudent = curStudent->pNext;
		}
		DeleteListStudent(headStudent);
		str = "Data\\SchoolYear3\\VP.csv";
		Input(str, wstr, headStudent);
		curStudent = headStudent;
		while (curStudent != nullptr)
		{
			if (curStudent->ID == IDstudent) wcout << curStudent->First_Name << L" " << curStudent->Last_Name;
			curStudent = curStudent->pNext;
		}
		DeleteListStudent(headStudent);
		str = "Data\\SchoolYear3\\CTDT.csv";
		Input(str, wstr, headStudent);
		curStudent = headStudent;
		while (curStudent != nullptr)
		{
			if (curStudent->ID == IDstudent) wcout << curStudent->First_Name << L" " << curStudent->Last_Name;
			curStudent = curStudent->pNext;
		}
		DeleteListStudent(headStudent);
	}
	else {
	str = "Data\\SchoolYear4\\APCS.csv";
	Input(str, wstr, headStudent);
	curStudent = headStudent;
	while (curStudent != nullptr)
	{
		if (curStudent->ID == IDstudent) wcout << curStudent->First_Name << L" " << curStudent->Last_Name;
		curStudent = curStudent->pNext;
	}
	DeleteListStudent(headStudent);
	str = "Data\\SchoolYear4\\CLC.csv";
	Input(str, wstr, headStudent);
	curStudent = headStudent;
	while (curStudent != nullptr)
	{
		if (curStudent->ID == IDstudent) wcout << curStudent->First_Name << L" " << curStudent->Last_Name;
		curStudent = curStudent->pNext;
	}
	DeleteListStudent(headStudent);
	str = "Data\\SchoolYear4\\CNTT.csv";
	Input(str, wstr, headStudent);
	curStudent = headStudent;
	while (curStudent != nullptr)
	{
		if (curStudent->ID == IDstudent) wcout << curStudent->First_Name << L" " << curStudent->Last_Name;
		curStudent = curStudent->pNext;
	}
	DeleteListStudent(headStudent);
	str = "Data\\SchoolYear4\\VP.csv";
	Input(str, wstr, headStudent);
	curStudent = headStudent;
	while (curStudent != nullptr)
	{
		if (curStudent->ID == IDstudent) wcout << curStudent->First_Name << L" " << curStudent->Last_Name;
		curStudent = curStudent->pNext;
	}
	DeleteListStudent(headStudent);
	str = "Data\\SchoolYear4\\CTDT.csv";
	Input(str, wstr, headStudent);
	curStudent = headStudent;
	while (curStudent != nullptr)
	{
		if (curStudent->ID == IDstudent) wcout << curStudent->First_Name << L" " << curStudent->Last_Name;
		curStudent = curStudent->pNext;
	}
	DeleteListStudent(headStudent);
	}
}