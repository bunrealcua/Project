#include "StructStudent.h"
#include"Staff.h"
#include"Student.h"



void registercourse(Student* pHead, Course* pHead1);
{
	string str = "";
	/*Lấy đường dẫn đền file đăng kí course*/
	if (pHead->SchoolYear == 1) str = "C:\\Users\\Tuong Vi\\Documents\\GitHub\\Project\\InputProject\\SchoolYear1\\Register.txt";
	else if (pHead->SchoolYear == 2) str = "C:\\Users\\Tuong Vi\\Documents\\GitHub\\Project\\InputProject\\SchoolYear2\\Register.txt";
	else if (pHead->SchoolYear == 3) str = "C:\\Users\\Tuong Vi\\Documents\\GitHub\\Project\\InputProject\\SchoolYear3\\Register.txt";
	else str = "C:\\Users\\Tuong Vi\\Documents\\GitHub\\Project\\InputProject\\SchoolYear4\\Register.txt";
	fstream f(str, ios::app);
	f << pHead->ID;
	while (pHead1 != nullptr)
	{
		int t;
		cout << "1. Choose" << endl;
		cout << "2. Skip" << endl;
		cin >> t;
		if (t == 1)
		{
			f << "," << pHead1->ID;
		}
		pHead1 = pHead1->next;
	}
	f << endl;
	f.close();
}