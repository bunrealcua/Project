#ifndef FinalProject
#define FinalProject
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Student {
	int ID; wstring First_Name;
	wstring Last_Name; wstring Gender;
	wstring DateOfBirth; int Social_ID;
	wstring username; wstring password;
	wstring Class; int SchoolYear; Student* pNext;
};
typedef struct Student Student;
#endif
