#ifndef FinalProject
#define FinalProject
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Student {
	int ID; wstring First_Name;
	wstring Last_Name; wstring Gender; // Change type of data of Gender into bool, true:male and fale:female
	wstring DateOfBirth; int Social_ID; // change type of data of DateOfBirth into int ddmmyyyy
	wstring username; wstring password;
	wstring Class; int SchoolYear; Student* pNext;
};
typedef struct Student Student;
#endif
