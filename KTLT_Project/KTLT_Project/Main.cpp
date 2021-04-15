#include"StructStudent.h"
#include"Staff.h"
#include"Student.h"
#include<iostream>
#include<io.h>
#include<fcntl.h>
#include<locale>
#include<codecvt>
#include<string>
#include<conio.h>
using namespace std;

int wmain()
{
	/*Student* pHead;
	Signup(pHead);*/
	// Hàm này để thêm course, view course.
	int schoolyear;
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"Semester 1 is coming. Input course in semester 1." << endl;
	wcout << L"School year: "; wcin >> schoolyear;
	short tempI;
	wstring wtemp = L"", wstr = L"";

	// Nhập các course.
	CourseInfo* pHead = nullptr, * pCur = nullptr;
	do {
		wstr = L"";
		wcout << L"Course ID: "; wcin >> tempI;
		wstr += to_wstring(tempI) + L',';
		wcout << L"Course name: "; wcin.ignore(); getline(wcin, wtemp);
		wstr += wtemp + L",";
		wcout << L"Lecturer: "; fflush(stdin); getline(wcin, wtemp);
		wstr += wtemp + L",";
		wcout << L"Number of credits: "; wcin >> tempI;
		wstr += to_wstring(tempI) + L",";
		wcout << L"Student limit: "; wcin >> tempI;
		wstr += to_wstring(tempI) + L",";
		wcout << L"Week day(1 for Sunday): "; wcin >> tempI;
		wstr += to_wstring(tempI) + L",";
		wcout << L"Session: "; wcin >> tempI;
		wstr += to_wstring(tempI); // Check lại session sẽ nhập gì.
		if (pHead == nullptr) {
			pHead = new CourseInfo;
			pHead->info = wstr;
			pHead->next = nullptr;
			pCur = pHead;
		}
		else {
			pCur->next = new CourseInfo;
			pCur = pCur->next;
			pCur->info = wstr;
			pCur->next = nullptr;
		}
		wcout << endl;
		wcout << L"Add a new course.?? 1: Yes or 0: No" << endl;
		tempI = _getch();

	} while (tempI == 49);
	SetUpSemester(1,1 ,pHead);
	DeleteListCourseInfo(pHead);
	wcout << L"Do you want to view the list of courses.";
	tempI = _getch();
	return 0;
}