#include"StructStudent.h"
#include"Student.h"
#include"Staff.h"
#include<iostream>
#include<fstream>
#include<string>
#include<io.h>
#include<fcntl.h>
#include<locale>
#include<codecvt>
using namespace std;



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

/*Kiểm tra log in sinh viên có được không*/
bool checkLogin(string username, string pass) {
	Student* headStudent = nullptr;
	wstring str;
	string path="";

	/*Schoolyear 1*/
	path = "D:\\InputProject\\SchoolYear1\\APCS.csv";
	Input(path,str,headStudent);
	if (loginStudent(headStudent, username, pass)==true) return true;
	DeleteListStudent(headStudent);
	path = "D:\\InputProject\\SchoolYear1\\CLC.csv";
	Input(path, str, headStudent);
	if (loginStudent(headStudent, username, pass) == true) return true;
	DeleteListStudent(headStudent);
	path = "D:\\InputProject\\SchoolYear1\\CNTN.csv";
	Input(path, str, headStudent);
	if (loginStudent(headStudent, username, pass) == true) return true;
	DeleteListStudent(headStudent);
	path = "D:\\InputProject\\SchoolYear1\\VP.csv";
	Input(path, str, headStudent);
	if (loginStudent(headStudent, username, pass) == true) return true;
	DeleteListStudent(headStudent);
	path = "D:\\InputProject\\SchoolYear1\\CTDT.csv";
	Input(path, str, headStudent);
	if (loginStudent(headStudent, username, pass) == true) return true;
	DeleteListStudent(headStudent);

	/*Schoolyear 2*/
	path = "D:\\InputProject\\SchoolYear2\\APCS.csv";
	Input(path, str, headStudent);
	if (loginStudent(headStudent, username, pass) == true) return true;
	DeleteListStudent(headStudent);
	path = "D:\\InputProject\\SchoolYear2\\CLC.csv";
	Input(path, str, headStudent);
	if (loginStudent(headStudent, username, pass) == true) return true;
	DeleteListStudent(headStudent);
	path = "D:\\InputProject\\SchoolYear2\\CNTN.csv";
	Input(path, str, headStudent);
	if (loginStudent(headStudent, username, pass) == true) return true;
	DeleteListStudent(headStudent);
	path = "D:\\InputProject\\SchoolYear2\\VP.csv";
	Input(path, str, headStudent);
	if (loginStudent(headStudent, username, pass) == true) return true;
	DeleteListStudent(headStudent);
	path = "D:\\InputProject\\SchoolYear2\\CTDT.csv";
	Input(path, str, headStudent);
	if (loginStudent(headStudent, username, pass) == true) return true;
	DeleteListStudent(headStudent);


	/*Schoolyear 3*/
	path = "D:\\InputProject\\SchoolYear3\\APCS.csv";
	Input(path, str, headStudent);
	if (loginStudent(headStudent, username, pass) == true) return true;
	DeleteListStudent(headStudent);
	path = "D:\\InputProject\\SchoolYear3\\CLC.csv";
	Input(path, str, headStudent);
	if (loginStudent(headStudent, username, pass) == true) return true;
	DeleteListStudent(headStudent);
	path = "D:\\InputProject\\SchoolYear3\\CNTN.csv";
	Input(path, str, headStudent);
	if (loginStudent(headStudent, username, pass) == true) return true;
	DeleteListStudent(headStudent);
	path = "D:\\InputProject\\SchoolYear3\\VP.csv";
	Input(path, str, headStudent);
	if (loginStudent(headStudent, username, pass) == true) return true;
	DeleteListStudent(headStudent);
	path = "D:\\InputProject\\SchoolYear3\\CTDT.csv";
	Input(path, str, headStudent);
	if (loginStudent(headStudent, username, pass) == true) return true;
	DeleteListStudent(headStudent);


	/*Schoolyear 4*/
	path = "D:\\InputProject\\SchoolYear4\\APCS.csv";
	Input(path, str, headStudent);
	if (loginStudent(headStudent, username, pass) == true) return true;
	DeleteListStudent(headStudent);
	path = "D:\\InputProject\\SchoolYear4\\CLC.csv";
	Input(path, str, headStudent);
	if (loginStudent(headStudent, username, pass) == true) return true;
	DeleteListStudent(headStudent);
	path = "D:\\InputProject\\SchoolYear4\\CNTN.csv";
	Input(path, str, headStudent);
	if (loginStudent(headStudent, username, pass) == true) return true;
	DeleteListStudent(headStudent);
	path = "D:\\InputProject\\SchoolYear4\\VP.csv";
	Input(path, str, headStudent);
	if (loginStudent(headStudent, username, pass) == true) return true;
	DeleteListStudent(headStudent);
	path = "D:\\InputProject\\SchoolYear4\\CTDT.csv";
	Input(path, str, headStudent);
	if (loginStudent(headStudent, username, pass) == true) return true;
	DeleteListStudent(headStudent);

	return false;
}

/*Thử hàm log in này xem*/
bool loginStudent(Student* pHead, string username, string pass) {
	
	Student* pCur = pHead;
	while (pCur != nullptr && pCur->username != username) pCur = pCur->pNext;
	if (pCur != nullptr)
	{
		if (pCur->password != pass) return false;
		else return true;
	}
	return false;
}

/*Hàm kiểm tra xem staff login có đúng hay không!! từ đường dẫn path */
void loginStaff(string path, string Username, string Password, bool& check)
{
	ifstream FileIn;
	FileIn.open(path);
	string strInput = Username + "," + Password;
	string temp = "";
	if (FileIn.is_open() == false) cout << "Error file opening. Can't check login!" << endl;
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