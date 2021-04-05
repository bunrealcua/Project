#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;


struct Node {
	int data;
	Node* pNext;
};
struct Student {
	int ID; wstring First_Name;
	wstring Last_Name; string Gender;
	string DateOfBirth; int Social_ID;
	string username; string password;
	string Class; int SchoolYear; Student* pNext;
};
typedef struct Student Student;
void SetUp(wstring str, Student*& pHead);

