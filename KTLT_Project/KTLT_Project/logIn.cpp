#include"StructStudent.h"
#include"Student.h"
#include<iostream>
#include<fstream>
#include<string>
#include<io.h>
#include<fcntl.h>
#include<locale>
#include<codecvt>
using namespace std;

void login(Student* pHead);

/*void login(Student* pHead) {
	string un;
	string pass;
	cout << "Insert your username, please!  " << endl;
	cin >> un;
	cout << "Insert your password, please! " << endl;
	cin >> pass;
	Student* pCur = pHead;
	while (pCur->pNext != nullptr) {
		if (un == pCur->username && pass == pCur->password) {
			cout << "Login successfully !" << endl;
			return;
		}
		pCur = pCur->pNext;
	}
	cout << "Invalid login, please try again !" << endl;
}
*/

/*Thử hàm log in này xem*/
void login(Student* pHead) {
	string username;
	string pass;
	cout << "Insert your username, please!  " ;
	getline(cin, username);
	cout << "Insert your password, please! " ;
	getline(cin, pass);
	Student* pCur = pHead;
	while (pCur != nullptr && pCur->username!=username ) pCur = pCur->pNext;
	if (pCur != nullptr)
	{
		if (pCur->password != pass) cout << "Wrong password!";
		else cout << "Log in successfully";
	}
	else
	cout << "Invalid login, please try again !" << endl;
}