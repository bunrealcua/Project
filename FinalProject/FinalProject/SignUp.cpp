#include "StructStudent.h"
#include"Student.h"
#include"Staff.h"
#include<iostream>
using namespace std;


void signUpStudent(Student*& pHead);
void input(Student*& pHead);


void input(Student*& pHead)
{
	cout << "Input your first name: ";
	getline(wcin, pHead->First_Name);
	cout << "Input yout last name: ";
	getline(wcin, pHead->Last_Name);
	cout << "Input your gender(1.male,0.female): ";
	cin >> pHead->Gender;
	cout << "Input your date of birth: ";
	for (int i = 0; i < 8; i++) cin >> pHead->DateOfBirth[i];
	cout << "Input your social ID: ";
	cin >> pHead->Social_ID;;
	cout << "Input your username: ";
	cin >> pHead->username;
	cout << "Input your password: ";
	cin >> pHead->password;
	cout << "Input your class: ";
	cin >> pHead->Class;
	cout << "Input your schoolyear: ";
	cin >> pHead->SchoolYear;
}

/*Không có đăng ký sinh viên vì tài khoản sinh viên được tạo sẵn*/
/*Chỉ có đăng ký/ tạo tài khoản cho staff thôi.*/
void signUpStudent(Student*& pHead)
{
	pHead = nullptr;
	int t;
	cout << "Input your ID(Input 0 to stop): ";
	cin >> t;
	Student* pCur = nullptr;
	while (t != 0)
	{
		if (pHead == nullptr)
		{
			pHead = new Student;
			pCur = pHead;
		}
		else
		{
			pCur->pNext = new Student;
			pCur = pCur->pNext;
		}
		input(pCur);
		pCur->pNext = nullptr;
	}
}

/*Hàm tạo tài khoản mới cho staff*/
void  signUpStaff(Staff& s)
{
	string str = "";
	cout << "Creat a new staff account!" << endl;
	cout << "Username: "; getline(cin, str); s.username = str;
	cout << "Password: "; getline(cin, str); s.password = str;
}

/*Hàm để lưu các tài khoản mới tạo của staff vào một file.*/
void SaveStaffAccount(string path, Staff s)
{
	fstream FileOut;
	string temp = "";
	FileOut.open(path, ios::out | ios::in);
	if (FileOut.is_open() == false) cout << "Can't save new staff account!!";
	else {
		FileOut.seekp(0, ios::end);
		FileOut << endl;
		FileOut << s.username << "," << s.password;
		cout << "Successfully!" << endl;
	}
	FileOut.close();
}