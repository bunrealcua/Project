#include "StructStudent.h"

void changepass(Student*& pHead)
{
	string s;
	cout << "Your ID: ";
	cin >> s;
	Student* pCur = pHead;
	while (pCur->username != s)
	{
		pCur = pCur->pNext;
	}
	cout << "Your old password: ";
	cin >> s;
	while (pCur->password != s)
	{
		cout << "Wrong password!" << endl;
		cout << "Your old password: ";
		cin >> s;
	}
	string s1;
	cout << "Your new password: ";
	cin >> s;
	cout << "Confirm new password: ";
	cin >> s1;
	while (s1 != s)
	{
		cout << "Wrong password!" << endl;
		cout << "Confirm new password: ";
		cin >> s1;
	}
	pCur->password = s1;
}