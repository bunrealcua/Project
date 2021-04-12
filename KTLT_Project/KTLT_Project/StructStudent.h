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

struct Course {
	int ID; wstring Name;
	wstring Lecturer; int Credits;
	int StudentLimit; int Weekday;
	int Session; Course* next;
};
struct CourseInfo { wstring info; CourseInfo* next; };

// student
void input(Student*& pHead);
void Signup(Student*& pHead);
///
void Input(string path, wstring& str, Student*& pHead);
void SetUp(wstring str, Student*& pHead);

// course
void crAdd();

// Semester Creation
void SetUpSemester1(int schooyear, CourseInfo* pHead);
void DeleteListCourse(CourseInfo*& pHead);
void ViewListCourse(int schoolyear, int semester);
void SetUpInfoCourse(wstring& wstr, Course*& pHead);

// change password
void changepass(Student*& pHead);

//Register new courses
void register();
#endif



