#ifndef FinalProject
#define FinalProject
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Student {
	int ID; wstring First_Name;
	wstring Last_Name; bool Gender;
	int DateOfBirth[8]; int Social_ID;
	string username; string password;
	string Class; int SchoolYear; Student* pNext;
};
typedef struct Student Student;

void input(Student*& pHead);
void Signup(Student*& pHead);
#endif
