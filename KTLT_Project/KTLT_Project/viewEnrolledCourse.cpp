#include"Staff.h"
#include"Student.h"
#include<iostream>
#include<fstream>
#include<string>
#include<io.h>
#include<fcntl.h>
#include<locale>
#include<codecvt>
using namespace std;

void getData(string str, MaSo*& pHead);
void readFile(string path1, wstring& str, Course* pHead);
void DeleteListMaSo(MaSo*& pHead);
void PrintOutEnrolledCourses(int schoolyear, int semester, MaSo* headMaSo);
void viewEnrolledCourses(int schoolyear, int semester, int tempInput);

/*Hàm này có tác dụng đọc chuỗi từ file và gắn cho chuỗi linked list Course. */
/*Tạo linked list Course sẽ tốn dung lượng vì các thành phần như Lecturer, Name, Session, Weekday không cần thiết dùng*/
/*Nên dùng một linked list mới ID{ string; ID* next;};*/
/*node head sẽ là MSSV*/
void getData(string str, MaSo*& pHead) {
			
	//get data from file: student id and course id
	int lc1 = 1, lc2 = 0, i = 2;
	string tempInt = "";
	string tempString = "";
	int temp = 0;
	char ch = str[lc2];
	
	//get ID of student
	while (ch != ',') { lc2++; ch = str[lc2]; }
	for (i = 0; i < lc2; i++) tempInt += str[i];
	temp = atoi(tempInt.c_str());
	pHead = new MaSo;
	pHead->ID = temp;
	pHead->next = nullptr;


	//get ID course
	MaSo* pCur = pHead;
	lc1 = lc2;
	lc2++;
	while (lc2 != '\0') {
		ch = str[i];
		while (ch != ',') { i++; ch = str[i]; }
		tempInt = "";
		for (i = lc1 + 1;i < lc2;i++) tempInt += str[i];
		temp = atoi(tempInt.c_str());
		pCur->next = new MaSo;
		pCur = pCur->next;
		pCur->ID = temp;
		pCur->next = nullptr;
		lc1 = lc2;
		lc2++;
		ch = str[lc2];
	}
}

/*Hàm này xác định chuỗi có MSSV đúng với MSSV được nhập từ bàn phím*/
/*File được đọc là Registration.txt*/

void viewEnrolledCourses(int schoolyear, int semester, int tempInput ) {
	/*tempInput được nhập từ bàn phím sẵn trước rồi. Hihi:))*/
	/*Mở file Registration*/
	string path = "";
	if (schoolyear == 1) {
		if (semester == 1) path = "D:\\InputProject\\SchoolYear1\\Registration1.txt";
		else if (semester == 2) path = "D:\\InputProject\\SchoolYear1\\Registration2.txt";
		else path = "D:\\InputProject\\SchoolYear1\\Registration3.txt";
	}
	else
		if (schoolyear == 2) {
			if (semester == 1) path = "D:\\InputProject\\SchoolYear2\\Registration1.txt";
			else if (semester == 2) path = "D:\\InputProject\\SchoolYear2\\Registration2.txt";
			else path = "D:\\InputProject\\SchoolYear2\\Registration3.txt";
		}
		else {
			if (semester == 1) path = "D:\\InputProject\\SchoolYear3\\Registration1.txt";
			else if (semester == 2) path = "D:\\InputProject\\SchoolYear3\\Registration2.txt";
			else path = "D:\\InputProject\\SchoolYear3\\Registration3.txt";
		}
	ifstream FileIn;
	FileIn.open(path);
	if (FileIn.is_open() == false) cout << "FileIn cannot be opened." << endl; else cout << "FileIn can be opened" << endl;
	
	/*Xác định chuỗi mà có MSSV = tempInnput*/
	/*String để đọc từng dòng trong file*/
	string str;
	MaSo *headMaSo = nullptr;
	getline(FileIn, str);
	while (!FileIn.eof() && str!="") {	
		getData(str, headMaSo);
		if (headMaSo->ID == tempInput) break;
		DeleteListMaSo(headMaSo);
		headMaSo = nullptr;
		getline(FileIn, str);
		}
	/*In ra các khóa học đã đăng kí*/
	PrintOutEnrolledCourses(schoolyear, semester, headMaSo);
	FileIn.close();
	/*Kiểm tra hàm có hoạt động không*/
	/*Đồng thời xóa linked list tránh gây memory leak*/
	DeleteListMaSo(headMaSo);
}

void PrintOutEnrolledCourses(int schoolyear, int semester, MaSo* headMaSo) {
	
	/*Mở file ra đọc. File này là file Semester.*/
	/*Tìm đường dẫn để mở file Semester.*/
	string path="";
	if (schoolyear == 1)
	{
		if (semester == 1) path = "D:\\InputProject\\SchoolYear1\\CourseSemester1.txt";
		else if (semester == 2) path = "D:\\InputProject\\SchoolYear1\\CourseSemester2.txt";
		else  path = "D:\\InputProject\\SchoolYear1\\CourseSemester3.txt";
	}
	else
		if (schoolyear == 2) {
			if (semester == 1) path = "D:\\InputProject\\SchoolYear2\\CourseSemester1.txt";
			else if (semester == 2) path = "D:\\InputProject\\SchoolYear2\\CourseSemester2.txt";
			else path = "D:\\InputProject\\SchoolYear2\\CourseSemester3.txt";
		}
		else
			if (schoolyear == 3) {
				if (semester == 1) path = "D:\\InputProject\\SchoolYear3\\CourseSemester1.txt";
				else if (semester == 2) path = "D:\\InputProject\\SchoolYear3\\CourseSemester2.txt";
				else  path = "D:\\InputProject\\SchoolYear3\\CourseSemester3.txt";
			}
			else {
				if (semester == 1) path = "D:\\InputProject\\SchoolYear4\\CourseSemester1.txt";
				else if (semester == 2) path = "D:\\InputProject\\SchoolYear4\\CourseSemester2.txt";
				else path = "D:\\InputProject\\SchoolYear4\\CourseSemester3.txt";
			}
	wifstream FileIn;
	FileIn.open(path);
	
	/*Set up Tiếng Việt*/
	locale loc(locale(), new codecvt_utf8<wchar_t>());
	FileIn.imbue(loc);
	_setmode(_fileno(stdin), _O_U16TEXT);
	if (FileIn.is_open() == false) cout << "FileIn cannot be opened."; 

	/*Set up chuỗi đọc từ file Semester.txt thành linked list Course */
	Course* headCourse = nullptr,*CurCourse=nullptr;
	wstring str;
	getline(FileIn, str);
	while (!FileIn.eof() && str!=L""){
		if (headCourse == nullptr) {
			headCourse = new Course;
			SetUpInfoCourse(str, headCourse);
			headCourse->next = nullptr;
			CurCourse = headCourse;
		}
		else {
			CurCourse->next = new Course;
			CurCourse = CurCourse -> next;
			SetUpInfoCourse(str, CurCourse);
			CurCourse->next = nullptr;
		}
		getline(FileIn, str);
	}
	wcout << L"Các khóa học mà bạn đã đăng ký là: " << endl;
	/*Dò tìm nếu mà Course nào mà có ID trùng thì in ra.*/
	MaSo* CurMaSo = headMaSo->next; /*vì node head là MSSV, không phải course ID*/
	
	while (CurMaSo != nullptr) {
		/*Kiểm tra mã số khóa học có trùng không*/
		CurCourse = headCourse;
		while (CurCourse->ID != CurMaSo->ID) CurCourse = CurCourse->next;
		/*Xác định được course rồi thì in ra*/
	wcout <<CurCourse->ID<<L" "<< CurCourse->Name << L" " << CurCourse->Lecturer << L" " << CurCourse->Credits << L" " << CurCourse->StudentLimit<<L" "<<CurCourse->Weekday<<L" "<<CurCourse->Session ;
	CurMaSo = CurMaSo->next;
	}

	/*Hàm Mở file Semester.txt để đọc từ ra hiện ra danh sách các khóa học đã đăng ký*/
	/*Xóa linked list Course*/
	DeleteListCourse(headCourse);
}

/*Hàm xóa linked list MaSo.*/
void DeleteListMaSo(MaSo*& pHead)
{
	MaSo* pCur = nullptr;
	while (pHead != nullptr) {
		pCur = pHead;
		pHead = pHead->next;
		delete pCur;
	}
}
