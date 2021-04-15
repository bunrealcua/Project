#include"StructStudent.h"
#include"Staff.h"
#include"Student.h"
#include<iostream>
#include<fstream>
#include<string>
#include<io.h>
#include<fcntl.h>
#include<locale>
#include<codecvt>
using namespace std;

void getData(wstring str, Course*& pHead) {//get data from file: student id and course id
	int lc1 = 1, lc2 = 0, i = 2;
	int temp ;
	string tempInt = "";
	string tempString = "";
	wchar_t ch = str[i];
	//get ID of student
	while (ch != ',') { i++; ch = str[i]; }
	lc2 = i;
	for (i = lc1 + 1; i < lc2; i++) tempInt += str[i];
	int x = atoi(tempInt.c_str());
	int idStudent = x;
	//get ID course
	lc1 = lc2;
	i = lc2 + 1;
	ch = str[i];
	while (ch != ',') { i++; ch = str[i]; }
	lc2 = i;
	temp = 0;
	for (i = lc1 + 1; i < lc2; i++) temp += str[i];
	pHead->ID = temp;
}
void readFile(string path1, wstring& str, Course* pHead) {
	wifstream FileIn;
	FileIn.open(path1);
	const locale utf8_locale(locale(), new codecvt_utf8<wchar_t>());
	_setmode(_fileno(stdin), _O_U16TEXT);
	if (FileIn.is_open() == false) cout << "FileIn cannot be opened." << endl; else cout << "FileIn can be opened" << endl;
	FileIn.imbue(utf8_locale);
	getline(FileIn, str);
	Course* pCur = nullptr;
	getline(FileIn, str);
	while (!FileIn.eof()&&str!=L"") {	
		if (pHead == nullptr)
		{
			pHead = new Course;
			getData(str, pHead);
			pHead->next = nullptr;
			pCur = pHead;
		}
		else {
			pCur->next = new Course;
			pCur = pCur->next;
			getData(str, pCur);
			pCur->next = nullptr;
		}
		getline(FileIn, str);
		}
	FileIn.close();
}
void viewEnrolledCourses(string path2, Course* pHead) {
	int idStudent;
	cout << "Enter ID of student to display the details of enrolled courses: " << endl;
	cin >> idStudent;
	//display the details from file : Id course and information of courses




}

