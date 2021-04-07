#ifndef Project
#define Project
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Student {
	int ID; wstring First_Name;
	wstring Last_Name; string Gender;
	string DateOfBirth; int Social_ID;
	string username; string password;
	string Class; int SchoolYear; Student* pNext;
};

void Input(string path, wstring& str, Student*& pHead);
void SetUp(wstring str, Student*& pHead);
#endif
