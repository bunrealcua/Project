#ifndef Project
#define Project
#include<iostream>
using namespace std;

struct Course {
	int ID; wstring Name;
	wstring Lecturer; int Credits;
	int StudentLimit; int Weekday;
	string SessionDay1; string Time1;
	string SessionDay2; string Time2;
	Course* next;
};
struct CourseInfo { wstring info; CourseInfo* next; };
struct Staff { string username; string password; };

void SetUpSemester(int schooyear,int semester,CourseInfo* pHead); /*Hàm tạo danh sách khóa học học kì*/
void DeleteListCourseInfo(CourseInfo*& pHead); /*Hàm xóa link list CourseInfo*/
void DeleteListCourse(Course*& pHead); /*Hàm này xóa link list Course*/
void ViewListCourse(int schoolyear, int semester,Course*& pHead);  /*Hàm xem danh sách các khóa học*/
void SetUpInfoCourse(wstring& wstr, Course*& pHead); /*Hàm biến mỗi string đọc được từ file thành từng phần của struct pHead.*/
void AddCourseSemester(int schoolyear, int semester, CourseInfo* pHead); /*Hàm thêm course vào cuối file danh sách môn học*/
void ChangeCourseToCourseInfo(Course*& pHeadCourse, CourseInfo*& pHeadCourseInfo);/*Hàm chuyển đối struct Course sang struct CourseInfo*/
void UpdateCourse(int schoolyear, int semester, int k, Course*& pHead);/*Hàm cập nhật course*/
void DeleteACourse(int schoolyear, int semester, int k, Course*& pHead);/*Hàm xóa course*/
void signUpStaff(Staff& s); /*Hàm tạo tài khoản cho staff*/
void SaveStaffAccount(string path, Staff s);/*Hàm lưu tài khoản mới tạo của staff vào hệ thống*/
void loginStaff(string path, string Username, string Password,bool& check);/*Hàm kiểm tra staff log in hệ thống có được không*/
void Realtime();

#endif