#include"StructStudent.h"
#include"Staff.h"
#include"Student.h"
#include<iostream>
#include<io.h>
#include<fcntl.h>
#include<locale>
#include<codecvt>
#include<string>
#include<conio.h>
using namespace std;

/*Làm sao để làm cái session đây.*/
/*Session dùng thư viện ctime để lấy thời gian nhe.*/
/*Vào thay đổi hàm thời gian.*/
struct Session { tm time; };
int wmain()
{
	/*******Đăng nhập để biết*******/
	/*Làm sao log in, log out được nhỉ, đối với giáo viên, à nếu log out thì log out thôi. Có thể hàm tạo tài khoản cho staff*/
	/*Trong quá trình chương trình chạy, có hai biến là Staff và Student để mà giữ trạng thái tài khoản người dùng đang sử dụng, có thể là staff hoặc có thể là sv*/
	/*Nếu log out thì màn hình vẫn màu đen console thôi chứ không có trở về lại return 0*/





	/******Công việc của staff nè!******/
	/*Task Tạo năm học mới*/
	/*Nhận file csv. Đọc và tạo ra các file csv tương ứng là từng loại lớp APCS,CLC,CNTT,... trong file schoolyear1*/
	/*Nhập thời gian học kì 1, học kì 2, học kì 3.*/
	/*Khi tạo course thì mặc định là course vừa tạo. Giáo vụ log in, log out thì vẫn là học kì đó. Có thể có hàm switch để chuyển qua lại giữa các học kì*/
	/*Kiểm tra cuối kì, làm sao để kiểm tra thời gian cuối kì nhỉ*/
	/*View danh sách các lớp*/
	/*View danh sách học sinh trong một lớp*/
	/*View danh sách khóa học*/
	/*View danh sách học sinh trong một course*/
	/*... rồi thao tác xóa, update thông tin khóa học đó.*/
	/*Cuối kì chưa làm được*/



	/******Công việc của sinh viên*****/
	/*Hàm nhập thời gian sẽ hoạt động mỗi lần sinh viên log in để kiểm tra đã quá thời hạn đănng kí chưa*/
	/*Đăng kí khóa học nè.*/
	/*Xóa khóa học nè*/
	/*Xem danh sách khóa học đăng kí nè.*/
	/*Sau khi thời hạn đăng kí kết thúc thì có thể xem danh sách các khóa học đã đăng kí*/

	/*Tạm thời nếu làm xong chừng này thì ổn vailoz*/

	/*Student* pHead;
	Signup(pHead);*/
	// Hàm này để thêm course, view course.
	/*int schoolyear;
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"Semester 1 is coming. Input course in semester 1." << endl;
	wcout << L"School year: "; wcin >> schoolyear;
	short tempI;
	wstring wtemp = L"", wstr = L"";

	// Nhập các course.
	CourseInfo* pHead = nullptr, * pCur = nullptr;
	do {
		wstr = L"";
		wcout << L"Course ID: "; wcin >> tempI;
		wstr += to_wstring(tempI) + L',';
		wcout << L"Course name: "; wcin.ignore(); getline(wcin, wtemp);
		wstr += wtemp + L",";
		wcout << L"Lecturer: "; fflush(stdin); getline(wcin, wtemp);
		wstr += wtemp + L",";
		wcout << L"Number of credits: "; wcin >> tempI;
		wstr += to_wstring(tempI) + L",";
		wcout << L"Student limit: "; wcin >> tempI;
		wstr += to_wstring(tempI) + L",";
		wcout << L"Week day(1 for Sunday): "; wcin >> tempI;
		wstr += to_wstring(tempI) + L",";
		wcout << L"Session: "; wcin >> tempI;
		wstr += to_wstring(tempI); // Check lại session sẽ nhập gì.
		if (pHead == nullptr) {
			pHead = new CourseInfo;
			pHead->info = wstr;
			pHead->next = nullptr;
			pCur = pHead;
		}
		else {
			pCur->next = new CourseInfo;
			pCur = pCur->next;
			pCur->info = wstr;
			pCur->next = nullptr;
		}
		wcout << endl;
		wcout << L"Add a new course.?? 1: Yes or 0: No" << endl;
		tempI = _getch();

	} while (tempI == 49);
	SetUpSemester(1,1 ,pHead);
	DeleteListCourseInfo(pHead);
	wcout << L"Do you want to view the list of courses.";
	tempI = _getch();*/
	return 0;
}