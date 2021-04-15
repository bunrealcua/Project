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


void SetUpSemester1(int schooyear, CourseInfo* pHead); /*Hàm tạo danh sách khóa học học kì*/
void DeleteListCourseInfo(CourseInfo*& pHead); /*Hàm xóa link list CourseInfo*/
void ViewListCourse(int schoolyear, int semester);  /*Hàm xem danh sách các khóa học*/
void SetUpInfoCourse(wstring& wstr, Course*& pHead); /*Hàm biến mỗi string đọc được từ file thành từng phần của struct pHead.*/
#endif

