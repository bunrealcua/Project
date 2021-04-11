#include"StructStudent.h"
#include<iostream>
#include<fstream>
#include<string>
#include<io.h>
#include<fcntl.h>
#include<locale>
#include<codecvt>
using namespace std;

void SetUpSemester1(int schooyear, CourseInfo* pHead)
{
	// Trong main phải nhập năm học để dùng hàm.
	// Trong main nhập cout << "Semester 1 is coming. Input courses in semester 1." << endl;
	string str = "";
	if (schooyear == 1) str = "D:\\InputProject\\SchoolYear1\\CourseSemester1.txt";
	else if (schooyear == 2) str = "D:\\InputProject\\SchoolYear2\\CourseSemester1.txt";
	else if (schooyear == 3) str = "D:\\InputProject\\SchoolYear3\\CourseSemester1.txt";
	else str = "D:\\InputProject\\SchoolYear4\\CourseSemester1.txt";
	wofstream FileOut;
	FileOut.open(str);
	locale loc(locale(), new codecvt_utf8<wchar_t>);
	_setmode(_fileno(stdout), _O_U16TEXT);
	FileOut.imbue(loc);
	CourseInfo* pCur = pHead;
	while (pCur != nullptr) {
		FileOut << pCur->info << endl;
		pCur = pCur->next;
	}
	FileOut.close();

}
void DeleteListCourse(CourseInfo*& pHead)
{
	if (pHead == nullptr) return;
	CourseInfo* pCur = nullptr;
	while (pHead != nullptr) {
		pCur = pHead;
		pHead = pHead->next;
		delete pCur;
	}
}


void ViewListCourse(int schoolyear, int semester)
{
	string str = "";
	if (schoolyear == 1)
	{
		if (semester == 1) str = "D:\\InputProject\\SchoolYear1\\CourseSemester1.txt";
		else if (semester == 2) str = "D:\\InputProject\\SchoolYear1\\CourseSemester2.txt";
		else  str = "D:\\InputProject\\SchoolYear1\\CourseSemester3.txt";
	}
	else
		if (schoolyear == 2) {
			if (semester == 1) str = "D:\\InputProject\\SchoolYear2\\CourseSemester1.txt";
			else if (semester == 2) str = "D:\\InputProject\\SchoolYear2\\CourseSemester2.txt";
			else str = "D:\\InputProject\\SchoolYear2\\CourseSemester3.txt";
		}
		else
			if (schoolyear == 3) {
				if (semester == 1) str = "D:\\InputProject\\SchoolYear3\\CourseSemester1.txt";
				else if (semester == 2) str = "D:\\InputProject\\SchoolYear3\\CourseSemester2.txt";
				else  str = "D:\\InputProject\\SchoolYear3\\CourseSemester3.txt";
			}
			else {
				if (semester == 1) str = "D:\\InputProject\\SchoolYear4\\CourseSemester1.txt";
				else if (semester == 2) str = "D:\\InputProject\\SchoolYear4\\CourseSemester2.txt";
				else str = "D:\\InputProject\\SchoolYear4\\CourseSemester3.txt";
			}
	_setmode(_fileno(stdin), _O_U16TEXT);
	locale loc(locale(), new codecvt_utf8<wchar_t>);
	wifstream FileIn;
	FileIn.imbue(loc);
	FileIn.open(str);
	if (FileIn.is_open() == false) wcout << L"Course in this semester not created." << endl;
	else {
		wstring wstr;
		Course* pHead = nullptr, * pCur = nullptr;
		while (!FileIn.eof()) {
			getline(FileIn, wstr);
			if (wstr == L"") break;
			if (pHead == nullptr) {
				pHead = new Course;
				SetUpInfoCourse(wstr, pHead);
				pHead->next = nullptr;
				pCur = pHead;
			}
			else
			{
				pCur->next = new Course;
				pCur = pCur->next;
				SetUpInfoCourse(wstr, pCur);
				pCur->next = nullptr;
			}
		}
		pCur = pHead;
		while (pCur != nullptr) {
			wcout << pCur->ID << L" " << pCur->Name << L" " << pCur->Lecturer << L" " << pCur->Credits << L" " << pCur->StudentLimit << L" " << pCur->Weekday << L" " << pCur->Session << endl;
			pCur = pCur->next;
		}
		while (pHead != nullptr) {
			pCur = pHead;
			pHead = pHead->next;
			delete pCur;
		}
	}
	FileIn.close();
}
void SetUpInfoCourse(wstring& wstr, Course*& pHead)
{
	int length = wstr.length();
	int lc1 = 0, lc2 = 0;
	wchar_t ch = wstr[lc2];
	wstring temp = L"";
	string strtemp;
	int tempI;
	wstring_convert <codecvt_utf8_utf16<wchar_t>> convert;
	// Get the ID
	while (ch != L',') { lc2++; ch = wstr[lc2]; }
	for (int j = 0;j < lc2;j++) temp += wstr[j];
	strtemp = convert.to_bytes(temp);
	tempI = atoi(strtemp.c_str());
	pHead->ID = tempI;
	lc1 = lc2; lc2++;
	ch = wstr[lc2];
	//Get the course name
	temp = L"";
	while (ch != L',') { lc2++;ch = wstr[lc2]; }
	for (int j = lc1 + 1;j < lc2;j++) temp += wstr[j];
	pHead->Name = temp;
	lc1 = lc2;
	lc2++; ch = wstr[lc2];
	// Get the course lecturer
	temp = L"";
	while (ch != L',') { lc2++; ch = wstr[lc2]; }
	for (int j = lc1 + 1;j < lc2;j++) temp += wstr[j];
	pHead->Lecturer = temp;
	lc1 = lc2;
	lc2++; ch = wstr[lc2];
	// Get the course credit
	temp = L"";
	while (ch != L',') { lc2++; ch = wstr[lc2]; }
	for (int j = lc1 + 1;j < lc2;j++) temp += wstr[j];
	strtemp = convert.to_bytes(temp);
	tempI = atoi(strtemp.c_str());
	pHead->Credits = tempI;
	lc1 = lc2;
	lc2++; ch = wstr[lc2];
	// Get the course student limit
	temp = L"";
	while (ch != L',') { lc2++; ch = wstr[lc2]; }
	for (int j = lc1 + 1;j < lc2;j++) temp += wstr[j];
	strtemp = convert.to_bytes(temp);
	tempI = atoi(strtemp.c_str());
	pHead->StudentLimit = tempI;
	lc1 = lc2;
	lc2++; ch = wstr[lc2];
	//Get the course Weekdays.
	temp = L"";
	while (ch != L',') { lc2++; ch = wstr[lc2]; }
	for (int j = lc1 + 1;j < lc2;j++) temp += wstr[j];
	strtemp = convert.to_bytes(temp);
	tempI = atoi(strtemp.c_str());
	pHead->Weekday = tempI;
	lc1 = lc2;
	lc2++; ch = wstr[lc2];
	// Get the course session.
	temp = L"";
	for (int j = lc1 + 1;j < length;j++) temp += wstr[j];
	strtemp = convert.to_bytes(temp);
	tempI = atoi(strtemp.c_str());
	pHead->Session = tempI;

}

