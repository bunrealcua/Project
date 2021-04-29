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
	wcout << L"List of the course in this semester. Please select your courses. (Maximum 5 courses,Minimum 1 course)." << endl;
	Course* pCourse = nullptr;
	ViewListCourse(schoolyear, semester, pCourse);

	/*Giả định mỗi sinh viên đều phải chọn ít nhất 1 course.*/
	Course* CourseCur = nullptr, * CourseSelect = nullptr;
	SelectCourse(pCourse, CourseSelect);/*Hàm chọn course của sinh viên.*/

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
	CourseB->SessionDay1 = CourseA->SessionDay1;
	CourseB->SessionDay2 = CourseA->SessionDay2;
	CourseB->Time1 = CourseA->Time1;
	CourseA->Time2 = CourseA->Time2;
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
	/*Hiển thị ra danh sách các course của staff nhập*/
	wcout << L"List courses in this semester.";
	Course* headCourse = nullptr;
	ViewListCourse(schoolyear, semester, headCourse);
	/*Hiển thị danh sách các course sinh viên đã đăng ký. Hàm của Oanh. Xem và chỉnh sửa lại.*/
	wcout << L"Here your selected courses:" << endl;

	/*Thay đổi lại dòng đã viết trong file Registration.txt.*/
	 /*Xác định lại khóa học mới được update. Chuyển thành chuỗi string mới và Course ID mới. string.*/
	wcout << L"Please select your course again.";
	Course* CourseSelect = nullptr;
	/*Trong đó CourseSelect là linked list danh sách Course sinh viên đã chọn*/
	SelectCourse(headCourse, CourseSelect);

	/*Đọc string ra từ file. Và sửa lại. Xong rồi viết lại tất cả.*/
   /*1.Biến Course ID và MSSV thành chuỗi string.*/
	string strtemp = "";
	strtemp += to_string(headStudent->ID) + ',';
	Course* pCur = CourseSelect;
	while (pCur->next != nullptr) {
		strtemp += to_string(pCur->ID) + ',';
		pCur = pCur->next;
	}
	strtemp += to_string(pCur->ID);

	/*2.Lần lượt đọc ra và ghi lại vào trong file. Nếu gặp file mà có MSSV đầu thì thay thế.*/
	ifstream FileIn;
	ofstream FileOut;

	string str;/*string để đọc ra  từng chuỗi*/
	string strID = "";/*Để lấy MSSV của mỗi string*/

	if (FileIn.is_open() == false || FileOut.is_open() == false) wcout << L"File registration can not be opened." << endl; else
	{
		while (FileIn >> str) {
			for (int i = 0;str[i] != ',';i++) strID += str[i];
			if (strID == to_string(headStudent->ID)) str = strtemp;
			FileOut << str << endl;
		}
	}

	FileIn.close();
	FileOut.close();


	/*Xóa linked list Course*/
	DeleteListCourse(CourseSelect);
	DeleteListCourse(headCourse);
}

/*Hàm để sinh viên xóa 1 course.*/
void DeleteACourseSelection(int schoolyear, int semester, Student* headStudent)
{

}

/*Hàm nhận thông tin từ sinh viên nhập bàn phím khi đăng ký course.*/
/*Trong đó pCourse là linked list danh sách khóa học staff nhập*/
/*Trong đó CourseSelect là linked list danh sách do sinh viên đăng ký.*/
void SelectCourse(Course* pCourse, Course*& CourseSelect)
{
	/*Nhận thông tin từ bàn phím sinh viên nhập*/
	 /*Có một nút _getch() để cho option khi đăng kí*/
	int button;
	Course* CourseCur = nullptr, * CoursePos = nullptr;
	Course* ptemp = nullptr;
	Course* CurCheck = nullptr; /*Dùng để kiểm tra có trùng thời gian hay không*/
	int pos = 0; /*Thứ tự course.*/
	int max = 0;
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
			/*Kiểm tra thời gian có bị trùng hay không đã*/
			CurCheck = CourseSelect;
			while (CurCheck != nullptr && CurCheck->SessionDay1 != ptemp->SessionDay1 && CurCheck->Time1 != ptemp->Time1 && CurCheck->SessionDay2 != ptemp->SessionDay2 && CurCheck->Time2 != ptemp->Time2)
				CurCheck = CurCheck->next;
			if (CurCheck == nullptr) {
				CourseCur->next = new Course;
				CourseCur = CourseCur->next;
				CopyCourse(ptemp, CourseCur);
				CourseCur->next = nullptr;
			}
			else wcout << "This course can not be selected." << endl;
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
}