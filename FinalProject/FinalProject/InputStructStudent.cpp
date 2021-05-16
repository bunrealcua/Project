#include"StructStudent.h"
#include"Student.h"
#include<iostream>
#include<fstream>
#include<string>
#include<io.h>
#include<fcntl.h>
#include<locale>
#include<codecvt>
using namespace std;

/*Hàm này để đọc từ file các chuỗi và chia nhỏ thành các thành phần của struct student*/
void Input(string path, wstring& wstr, Student*& pHead)
{
	wifstream FileIn;
	FileIn.open(path);
	const locale utf8_locale(locale(), new codecvt_utf8<wchar_t>());
	_setmode(_fileno(stdin), _O_U16TEXT);
	if (FileIn.is_open() == false) cout << "FileIn cannot be opened.";
	FileIn.imbue(utf8_locale);
	getline(FileIn, wstr);
	Student* pCur = nullptr;
	getline(FileIn, wstr);
	while (!FileIn.eof() && wstr != L"") {

		if (pHead == nullptr)
		{
			pHead = new Student;
			SetUp(wstr, pHead);
			pHead->pNext = nullptr;
			pCur = pHead;
		}
		else {
			pCur->pNext = new Student;
			pCur = pCur->pNext;
			SetUp(wstr, pCur);
			pCur->pNext = nullptr;
		}
		getline(FileIn, wstr);
	}
	FileIn.close();
}

/*Hàm này để chia chuỗi str thành các thành phần của struct Student*/
void SetUp(wstring str, Student*& pHead)
{
	int lc1 = 1, lc2 = 0, i = 2;
	wstring temp = L"";
	string tempInt = "";
	string tempString = "";
	wchar_t ch = str[i];
	// Get Student ID
	while (ch != ',') { i++; ch = str[i]; }
	lc2 = i;
	for (i = lc1 + 1;i < lc2;i++) tempInt += str[i];
	int x = atoi(tempInt.c_str());
	pHead->ID = x;

	// Get First Name
	lc1 = lc2;
	i = lc2 + 1;
	ch = str[i];
	while (ch != ',') { i++; ch = str[i]; }
	lc2 = i;
	for (i = lc1 + 1;i < lc2;i++) temp += str[i];
	pHead->First_Name = temp;

	//Get Last Name
	lc1 = lc2;
	i = lc2 + 1;
	ch = str[i];
	while (ch != ',') { i++; ch = str[i]; }
	lc2 = i;
	temp = L"";
	for (i = lc1 + 1;i < lc2;i++) temp += str[i];
	pHead->Last_Name = temp;

	//Get gender
	lc1 = lc2;
	i = lc2 + 1;
	ch = str[i];
	while (ch != ',') { i++;ch = str[i]; }
	lc2 = i;
	tempString = "";
	for (i = lc1 + 1;i < lc2;i++) tempString += str[i];
	if (tempString == "Male") pHead->Gender = 1; else pHead->Gender = 0;
	//pHead->Gender = tempString;

	//Get Date of Birth
	lc1 = lc2;
	i = lc2 + 1;
	ch = str[i];
	while (ch != ',') { i++; ch = str[i]; }
	lc2 = i;
	tempString = "";
	for (i = lc1 + 1;i < lc2;i++) tempString += str[i];
	pHead->DateOfBirth = tempString;

	//Get Social ID
	lc1 = lc2;
	i = lc2 + 1;
	ch = str[i];
	while (ch != ',') { i++;ch = str[i]; }
	lc2 = i;
	tempInt = "";
	for (i = lc1 + 1;i < lc2;i++) tempInt += str[i];
	x = atoi(tempInt.c_str());
	pHead->Social_ID = x;

	//Get username
	lc1 = lc2;
	i = lc2 + 1;
	ch = str[i];
	while (ch != ',') { i++; ch = str[i]; }
	lc2 = i;
	tempString = "";
	for (i = lc1 + 1;i < lc2;i++) tempString += str[i];
	pHead->username = tempString;

	//Get password
	lc1 = lc2;
	i = lc2 + 1;
	ch = str[i];
	while (ch != ',') { i++;ch = str[i]; }
	lc2 = i;
	tempString = "";
	for (i = lc1 + 1;i < lc2;i++) tempString += str[i];
	pHead->password = tempString;

	//Get Class
	lc1 = lc2;
	i = lc2 + 1;
	ch = str[i];
	while (ch != ',') { i++; ch = str[i]; }
	lc2 = i;
	tempString = "";
	for (i = lc1 + 1;i < lc2;i++) tempString += str[i];
	pHead->Class = tempString;

	//Get SchoolYear
	lc1 = lc2;
	i = lc2 + 1;
	ch = str[i];
	tempInt = "";
	tempInt += ch;
	x = atoi(tempInt.c_str());
	pHead->SchoolYear = x;
}

/*Hàm xóa linked list Student*/
void DeleteListStudent(Student*& pHead)
{
	Student* pCur = nullptr;
	while (pHead != nullptr)
	{
		pCur = pHead;
		pHead = pHead->pNext;
		delete pCur;
	}
}

/*Hàm in danh sách student ra màn hình*/
void DisplayListStudent(Student* pHead)
{
	if (pHead == nullptr) return;
	Student* pCur = pHead;
	_setmode(_fileno(stdout), _O_U16TEXT);
	while (pCur != nullptr) {
		wcout << pCur->ID << " ";
		wcout << pCur->First_Name << " ";
		wcout << pCur->Last_Name << " ";
		wcout << pCur->Gender << " ";
		wcout << pCur->DateOfBirth.c_str() << " ";
		wcout << pCur->Social_ID << " ";
		wcout << pCur->username.c_str() << " ";
		wcout << pCur->password.c_str() << " ";
		wcout << pCur->Class.c_str() << " ";
		wcout << pCur->SchoolYear << endl;
		pCur = pCur->pNext;
	}
}

Student* defineStudent(Student* &headStudent,string username, string password)
{
	Student *curStudent=nullptr;
	wstring wstr=L"";

	/*Schoolyear 1*/
	string path = "Data\\SchoolYear1\\APCS.csv";
	headStudent = nullptr;
	Input(path, wstr, headStudent);
	curStudent = headStudent;
	while (curStudent != nullptr && curStudent->username != username)
		curStudent = curStudent->pNext;
	if (curStudent != nullptr)  return curStudent;  
	DeleteListStudent(headStudent);
	
	path = "Data\\SchoolYear1\\CNTN.csv";
	headStudent = nullptr;
	Input(path, wstr, headStudent);
	curStudent = headStudent;
	while (curStudent != nullptr && curStudent->username != username)
		curStudent = curStudent->pNext;
	if (curStudent != nullptr)  return curStudent;
	DeleteListStudent(headStudent);
	
	path = "Data\\SchoolYear1\\CLC.csv";
	headStudent = nullptr;
	Input(path, wstr, headStudent);
	curStudent = headStudent;
	while (curStudent != nullptr && curStudent->username != username)
		curStudent = curStudent->pNext;
	if (curStudent != nullptr)  return curStudent;
	DeleteListStudent(headStudent);

	path = "Data\\SchoolYear1\\CTDT.csv";
	headStudent = nullptr;
	Input(path, wstr, headStudent);
	curStudent = headStudent;
	while (curStudent != nullptr && curStudent->username != username)
		curStudent = curStudent->pNext;
	if (curStudent != nullptr)  return curStudent;
	DeleteListStudent(headStudent);

	path = "Data\\SchoolYear1\\VP.csv";
	headStudent = nullptr;
	Input(path, wstr, headStudent);
	curStudent = headStudent;
	while (curStudent != nullptr && curStudent->username != username)
		curStudent = curStudent->pNext;
	if (curStudent != nullptr)  return curStudent;
	DeleteListStudent(headStudent);

	/*SChoolyear 2*/
	/*Schoolyear 3*/
	/*Schoolyear 4*/
}