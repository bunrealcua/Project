#include "StructStudent.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;



void viewEnrolledCourse(string path1,string path2, string& str, Course* pHead) {
	int id;
	int f;
	string tmpID;
	cout << "Enter ID of student: " << endl;
	cin >> id;
	Course* pCur = pHead;
	wifstream FileIn;
	FileIn.open(path1);
	if (FileIn.is_open() == false) cout << "FileIn cannot be opened." << endl;
	while (true) {
    getline(cin, str);
	tmpID = strtok(str, ",");
	pCur->ID = strtok(nullptr, ",");
	}
	pCur = pCur->next;
	FileIn.close();
}

