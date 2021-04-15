#ifndef Final_Project
#define Final_Project
#include<iostream>
using namespace std;

struct Course {
	int ID; wstring Name;
	wstring Lecturer; int Credits;
	int StudentLimit; int Weekday;
	int Session; Course* next;
};
struct CourseInfo { wstring info; CourseInfo* next; };


void SetUpSemester(int schooyear,int semester,CourseInfo* pHead); /*Hàm tạo danh sách khóa học học kì*/
void DeleteListCourseInfo(CourseInfo*& pHead); /*Hàm xóa link list CourseInfo*/
void DeleteListCourse(Course*& pHead); /*Hàm này xóa link list Course*/
void ViewListCourse(int schoolyear, int semester,Course*pHead);  /*Hàm xem danh sách các khóa học*/
void SetUpInfoCourse(wstring& wstr, Course*& pHead); /*Hàm biến mỗi string đọc được từ file thành từng phần của struct pHead.*/
void AddCourseSemester(int schoolyear, int semester, CourseInfo* pHead); /*Hàm thêm course vào cuối file danh sách môn học*/
void ChangeCourseToCourseInfo(Course*& pHeadCourse, CourseInfo*& pHeadCourseInfo);/*Hàm chuyển đối struct Course sang struct CourseInfo*/
void UpdateCourse(int schoolyear, int semester, int k, Course*& pHead);/*Hàm cập nhật course*/
void DeleteACourse(int schoolyear, int semester, int k, Course*& pHead);/*Hàm xóa course*/
#endif

