#ifndef KTLT
#define KTLT
#include<iostream>

using namespace std;

struct Student {
	int ID; wstring First_Name;
	wstring Last_Name; bool Gender;
	string DateOfBirth; int Social_ID;
	string username; string password;
	string Class; int SchoolYear; Student* pNext;
};

struct MaSo { int ID; MaSo* next; };


// student
void input(Student*& pHead);
void Signup(Student*& pHead);
///
void Input(string path, wstring& str, Student*& pHead);
void SetUp(wstring str, Student*& pHead);
// change password
void changepass(Student*& pHead);

/*Hàm xóa linked list Student*/
void DeleteListStudent(Student*& pHead);

/*Hàm in danh sách Student ra màn hình*/
void DisplayListStudent(Student* pHead);
#endif

