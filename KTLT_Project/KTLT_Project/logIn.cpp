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

void loginStudent(Student* pHead, string username, string pass);


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
void loginStudent(Student* pHead,string username, string pass) {

	Student* pCur = pHead;
	while (pCur != nullptr && pCur->username!=username ) pCur = pCur->pNext;
	if (pCur != nullptr)
	{
		if (pCur->password != pass) cout << "Wrong password!";
		else cout << "Logging In successfully";
	}
	else
	cout << "Invalid login, please try again !" << endl;
}

/*Hàm kiểm tra xem staff login có đúng hay không!! từ đường dẫn path */
void loginStaff(string path, string Username, string Password,bool& check)
{
	ifstream FileIn;
	FileIn.open(path);
	string strInput = Username + "," + Password;
	string temp = "";
	if (FileIn.is_open() == false) cout << "Error file opening. Can't check login!"<<endl;
	else {

		while (!FileIn.eof()) {
			getline(FileIn, temp);
			if (temp == " ") break;
			if (temp == strInput)  check = true;
		}
		if (check == true) cout << "Logging In successfully!!!" << endl;
		else cout << "Your usename or password is not correct! Try again." << endl;
	}
	FileIn.close();
}