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
void getData(string str, MaSo*& pHead);/*Hàm đọc chuỗi đăng kí gồm MSSV và course id.*/
void ViewStudentInCourse(int schoolyear, int courseID);/*Ham xem danh sach hoc sinh trong khoa hoc*/
void DeleteListMaSo(MaSo*& pHead);
void SeekInfoStudent(int schoolyear, int IDstudent);
void loginStudent(Student* pHead, string username, string pass);
/*Những hàm cần thiết để xem các khóa học đã đăng kí*/
void getData(string str, MaSo*& pHead);
void readFile(string path1, wstring& str, Course* pHead);
void DeleteListMaSo(MaSo*& pHead);
void PrintOutEnrolledCourses(int schoolyear, int semester, MaSo* headMaSo);
void viewEnrolledCourses(int schoolyear, int semester, int tempInput);
/*Hàm để sinh viên chọn xóa và update những khóa học mong muốn*/
void registercourse(Student* pHeadStudent, Course* pHeadCourse);
void Register(int schoolyear, int semester, Student* pHead);
void CopyCourse(Course* CourseA, Course* CourseB);
void SetUpRegistration(int schoolyear, int semester, Student* headStudent, Course* headCourse);
void UpdateCourseSelection(int schoolyear, int semester, Student* headStudent);
void DeleteACourseSelection(int schoolyear, int semester, Student* headStudent);
void SelectCourse(Course* pCourse, Course*& CourseSelect);
#endif

