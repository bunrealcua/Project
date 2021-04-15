#include "StructStudent.h"
#include"Staff.h"
#include"Student.h"
#include<fstream>
#include<conio.h>
#include<iostream>

using namespace std;

 void registercourse(Student* pHeadStudent, Course* pHeadCourse)

{
	string str = "";
	/*Lấy đường dẫn đền file đăng kí course*/
	if (pHeadStudent->SchoolYear == 1) str = "C:\\Users\\Tuong Vi\\Documents\\GitHub\\Project\\InputProject\\SchoolYear1\\Register.txt";
	else if (pHeadStudent->SchoolYear == 2) str = "C:\\Users\\Tuong Vi\\Documents\\GitHub\\Project\\InputProject\\SchoolYear2\\Register.txt";
	else if (pHeadStudent->SchoolYear == 3) str = "C:\\Users\\Tuong Vi\\Documents\\GitHub\\Project\\InputProject\\SchoolYear3\\Register.txt";
	else str = "C:\\Users\\Tuong Vi\\Documents\\GitHub\\Project\\InputProject\\SchoolYear4\\Register.txt";
	fstream f(str, ios::app);
	f << pHeadStudent->ID;
	while (pHeadCourse != nullptr)
	{
		int t;
		cout << "1. Choose" << endl;
		cout << "2. Skip" << endl;
		cin >> t;
		if (t == 1)
		{
			f << "," << pHeadCourse->ID;
		}
		pHeadCourse = pHeadCourse->next;
	}
	f << endl;
	f.close();
}

 /*Hàm đăng ký khóa học của sinh viên: biến struct Student + struct Course -> struct mới để lưu vào file ghi*/
 /*Hàm đăng ký có tham biến là năm học + học kỳ + linked list struct Student*/
 void Register(int schoolyear, int semester, Student* pHead)
 {
	 /*Đầu tiên, show ra danh sách các khóa học học kì. Đồng thời có linked list Course*/
	 wcout << L"List of the course in this semester. Please select your courses. (Maximum 5 courses)." << endl;
	 Course* pCourse = nullptr;
	 ViewListCourse(schoolyear, semester, pCourse);
	 int max = 0;

	 /*Giả định mỗi sinh viên đều phải chọn ít nhất 1 course.*/
	 /*Nhận thông tin từ bàn phím sinh viên nhập*/
	 Course* CourseSelect = nullptr,*CourseCur=nullptr,*CoursePos=nullptr;
	 Course* ptemp = nullptr;
	 int pos = 0; /*Thứ tự course.*/
	 while (max <= 5) {
		max++; /*Kiểm tra số lượng course đăng ký*/
		wcout << L"Choose course number:";
		wcin >> pos;
		CoursePos = pCourse;
		if (pos != 1) for (int i = 2;i < pos - 1;i++) CoursePos = CoursePos->next;
		/*Xác định course cần phải select*/ ptemp = CoursePos->next;
		if (CourseSelect == nullptr)
		{
			CourseSelect = new Course;
			CopyCourse(ptemp, CourseSelect);
			CourseSelect->next = nullptr;
			CourseCur = CourseSelect;
		}
		else {
			CourseCur->next = new Course;
			CourseCur = CourseCur->next;
			CopyCourse(ptemp, CourseCur);
			CourseCur->next = nullptr;
		}
		/*Chưa xong. Cần hàm để mà chép nội dung từ Course đang view sang Course select. :((*/
		/*Kiểm tra thời gian các course*/
	 }
	 /*Kiểm tra tối đa chỉ được đăng ký 5 course. */
	 /*Kiểm tra điều kiện, nếu 2 khóa học trùng thời gian học thì không được chọn*/ /*Tìm hiểu hàm thời gian*/
	 /*Sau khi đăng kí nên show ra list course đã đăng kí*/
	 /*Xóa linked list Course*/
	 DeleteListCourse(CourseSelect);
	 DeleteListCourse(pCourse);
	 /*Kiểm tra hàm hoạt động như thế nào*/
 }

 /*Hàm chép nội dung từ Course A sang Course B*/
 void CopyCourse(Course* CourseA, Course* CourseB)
 {
	 CourseB->ID = CourseA->ID;
	 CourseB->Name = CourseA->Name;
	 CourseB->Lecturer = CourseA->Lecturer;
	 CourseB->Credits = CourseA->Credits;
	 CourseB->StudentLimit = CourseA->StudentLimit;
	 CourseB->Weekday = CourseA->Weekday;
	 CourseB->Session = CourseB->Session;
 }