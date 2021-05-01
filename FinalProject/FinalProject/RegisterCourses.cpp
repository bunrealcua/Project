#include "StructStudent.h"
#include"Staff.h"
#include"Student.h"
#include<fstream>
#include<conio.h>
#include<iostream>

using namespace std;



void registercourse(Student* pHeadStudent, Course* pHeadCourse)

{
	string str = "";
	/*Lấy đường dẫn đền file đăng kí course*/
	if (pHeadStudent->SchoolYear == 1) str = "C:\\Users\\Tuong Vi\\Documents\\GitHub\\Project\\InputProject\\SchoolYear1\\Register.txt";
	else if (pHeadStudent->SchoolYear == 2) str = "C:\\Users\\Tuong Vi\\Documents\\GitHub\\Project\\InputProject\\SchoolYear2\\Register.txt";
	else if (pHeadStudent->SchoolYear == 3) str = "C:\\Users\\Tuong Vi\\Documents\\GitHub\\Project\\InputProject\\SchoolYear3\\Register.txt";
	else str = "C:\\Users\\Tuong Vi\\Documents\\GitHub\\Project\\InputProject\\SchoolYear4\\Register.txt";
	fstream f(str, ios::app);
	f << pHeadStudent->ID;
	while (pHeadCourse != nullptr)
	{
		int t;
		cout << "1. Choose" << endl;
		cout << "2. Skip" << endl;
		cin >> t;
		if (t == 1)
		{
			f << "," << pHeadCourse->ID;
		}
		pHeadCourse = pHeadCourse->next;
	}
	f << endl;
	f.close();
}

