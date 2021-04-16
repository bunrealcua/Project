#include "StructStudent.h"
#include"Staff.h"
#include"Student.h"
#include<fstream>
#include<conio.h>
#include<iostream>

using namespace std;

void registercourse(Student* pHeadStudent, Course* pHeadCourse);
void Register(int schoolyear, int semester, Student* pHead);
void CopyCourse(Course* CourseA, Course* CourseB);
void SetUpRegistration(int schoolyear, int semester, Student* headStudent, Course* headCourse);
void UpdateCourseSelection(int schoolyear, int semester, Student* headStudent);
void DeleteACourseSelection(int schoolyear, int semester, Student* headStudent);


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
	 wcout << L"List of the course in this semester. Please select your courses. (Maximum 5 courses,Minimum 1 course)." << endl;
	 Course* pCourse = nullptr;
	 ViewListCourse(schoolyear, semester, pCourse);
	 int max = 0;

	 /*Giả định mỗi sinh viên đều phải chọn ít nhất 1 course.*/
	 /*Nhận thông tin từ bàn phím sinh viên nhập*/
	 /*Có một nút _getch() để cho option khi đăng kí*/
	 int button;
	 Course* CourseSelect = nullptr, * CourseCur = nullptr, * CoursePos = nullptr;
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
		 wcout << L"Successfully!" << endl;
		 /*Cần phải xác định lại update và xóa.*/
		 wcout << L"Option: 1. Select next  2. Select again  3. Done registration"; /*Biến nhận option*/
		 button = _getch();
		 /* 1.49(ASCII) 2.50(ASCII) 3.51(ASCII) */
		 while (button != 49 && button != 50 && button != 51) button = _getch();
		 if (button == 49) continue;
		 if (button == 50)/*Chọn lại*/
		 {
			 /*Trường hợp chọn lại course đầu*/
			 if (CourseCur == CourseSelect) { delete CourseSelect; CourseSelect = nullptr; }
			 /*Trường hợp chọn lại course sau*/
			 else {
				 ptemp = CourseSelect;
				 while (ptemp->next != CourseCur) ptemp = ptemp->next;
				 delete CourseCur;
				 ptemp->next = nullptr;
				 CourseCur = ptemp;
			 }
		 }
		 if (button == 51) break;
		 /*Kiểm tra thời gian các course*/
	 }
	 /*Kiểm tra điều kiện, nếu 2 khóa học trùng thời gian học thì không được chọn*/ /*Tìm hiểu hàm thời gian*/
	 /*Sau khi đăng kí nên show ra list course đã đăng kí*/
	 wcout << L"Here is the course you selected.";
	 CourseCur = CourseSelect;
	 while (CourseCur != nullptr) {
		 wcout << CourseCur->Name << L" by lecturer ";
		 wcout << CourseCur->Lecturer;
		 CourseCur = CourseCur->next;
	 }

	 /*Hàm Từ các course đã đăng ký viết vào file.*/
	 SetUpRegistration(schoolyear, semester, pHead, CourseSelect);

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

 /*Hàm từ các course đăng ký, viết vào file registration*/
 void SetUpRegistration(int schoolyear, int semester, Student* headStudent, Course* headCourse)
 {
	 string str = "";
	 /*Lấy đường dẫn ghi file registration*/
	 if (schoolyear == 1) {
		 if (semester == 1) str = "D:\\InputProject\\SchoolYear1\\Registration1.txt";
		 else if (semester == 2) str = "D:\\InputProject\\SchoolYear1\\Registration2.txt";
		 else str = "D:\\InputProject\\SchoolYear1\\Registration3.txt";
	 }
	 else
		 if (schoolyear == 2) {
			 if (semester == 1) str = "D:\\InputProject\\SchoolYear2\\Registration1.txt";
			 else if (semester == 2) str = "D:\\InputProject\\SchoolYear2\\Registration2.txt";
			 else str = "D:\\InputProject\\SchoolYear2\\Registration3.txt";
		 }
		 else {
			 if (semester == 1) str = "D:\\InputProject\\SchoolYear3\\Registration1.txt";
			 else if (semester == 2) str = "D:\\InputProject\\SchoolYear3\\Registration2.txt";
			 else str = "D:\\InputProject\\SchoolYear3\\Registration3.txt";
		 }
	 ofstream FileOut;
	 /*Lúc đăng ký thì ghi tiếp nội dung đăng ký, vì có nhiều sinh viên*/
	 FileOut.open(str);
	 /*Đưa con trỏ file đến cuối file*/
	 FileOut.seekp(0, ios::end);
	 /*Viết file thôi nào*/
	 if (FileOut.is_open() == false) cout << "File Registration can not be opened!" << endl;
	 else {
		 FileOut << headStudent->ID << ",";
		 Course* ptemp = headCourse;
		 while (ptemp->next != nullptr) {
			 FileOut << ptemp->ID << ",";
			 ptemp = ptemp->next;
		 }
		 FileOut << ptemp->ID;
	 }

	 FileOut.close();
 }

 /*Sau khi log out, sinh viên có nhu cầu log in và thay đổi đăng ký học phần hoặc xóa 1 số học phần*/
/*Hàm để sinh viên thay đổi, update lựa chọn.*/
 void UpdateCourseSelection(int schoolyear, int semester, Student* headStudent)
 {

 }
/*Hàm để sinh viên xóa 1 course.*/
void DeleteACourseSelection(int schoolyear, int semester, Student*headStudent)
{}
 