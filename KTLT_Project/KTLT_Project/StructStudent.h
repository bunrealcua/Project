
#ifndef FinalProject
#define FinalProject
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

typedef struct Student {
	int ID; wstring First_Name;
	wstring Last_Name; bool Gender;
	string DateOfBirth; int Social_ID;
	string username; string password;
	string Class; int SchoolYear; Student* pNext;
}stu;

typedef struct Course {
	int ID;
	string name;
	wstring lecturer;
	int credits;
	int maxStu;
	int weekDay;
	int session;
	string fileDir;
} cr;

// student
void input(Student*& pHead);
void Signup(Student*& pHead);
///
void Input(string path, wstring& str, Student*& pHead);
void SetUp(wstring str, Student*& pHead);

// course
void crAdd();
#endif



