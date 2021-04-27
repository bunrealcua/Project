#include"Staff.h"
#include"Student.h"
#include<io.h>
#include<fcntl.h>
#include<locale>
#include<codecvt>
#include<iostream>
using namespace std;

void viewStudent_InClass(string data, Student* headStudent)
{
	Student* curStudent = headStudent;
	if (headStudent == nullptr) 
		cout << "There is no student in this class."; 
	else {
		int i = 0;
		_setmode(_fileno(stdout), _O_U16TEXT);
		_setmode(_fileno(stdin), _O_U16TEXT);
		while (curStudent != nullptr)
		{
			i++;
			wcout << i << ". " << curStudent->First_Name << " " << curStudent->Last_Name << endl;
				curStudent = curStudent->pNext;
		}
	}
}