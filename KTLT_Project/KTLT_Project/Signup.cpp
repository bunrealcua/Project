#include "StructStudent.h"

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

void Signup(Student*& pHead)
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
