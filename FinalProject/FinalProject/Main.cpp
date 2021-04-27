#include"StructStudent.h"
#include"Time.h"
#include"Staff.h"
#include"Student.h"
#include<iostream>
#include<io.h>
#include<fcntl.h>
#include<locale>
#include<codecvt>
#include<string>
#include<conio.h>
#include<ctime>
#include<Windows.h>
#include"Menu.h"
using namespace std;

void ViewClass(int option, int schoolyear, Student*& headStudent, Class*& headClass);
void viewStudent_InClass(string data, Student* headStudent);

int wmain()
{


	string path = "D:\\InputProject\\StaffAccount.txt";
	int button = 0;
	/*****Danh sách các biến cần sử dụng trong chương trình ******/
	/*Set up thời gian của học kì*/
	tm StartSes1, StartSes2, StartSes3, EndSes1, EndSes2, EndSes3;
	StartSes1.tm_year = 0; StartSes2.tm_year = 0; StartSes3.tm_year = 0;
	EndSes1.tm_year = 0;EndSes2.tm_year = 0;EndSes3.tm_year = 0;
	/*Biến lấy thời gian hiện tại*/
	tm TimeCur;
	/*Biến học kì và năm học*/
	int semester = 0, schoolyear = 0;

	/*******Đăng nhập để biết*******/
	/*Làm sao log in, log out được nhỉ, đối với giáo viên, à nếu log out thì log out thôi. Có thể hàm tạo tài khoản cho staff*/
	/*Trong quá trình chương trình chạy, có hai biến là Staff và Student để mà giữ trạng thái tài khoản người dùng đang sử dụng, có thể là staff hoặc có thể là sv*/
	/*Nếu log out thì màn hình vẫn màu đen console thôi chứ không có trở về lại return 0*/

	/*Xác định là staff hay là student.*/
	wcout << "Are you Staff or Student: (1)Staff or (2)Student" << endl;
	button = _getch();
	system("cls");
	/*ASCII code: 1: 49, 2: 50*/

	while (button != 49 && button != 50) button = _getch();




	/******Công việc của staff nè!******/
	if (button == 49) {
		wcout << L"You are staff!!" << endl;
		Staff s;

		/*Staff log izn hoặc sign up vào hệ thống*/
		int option = 0;
		wcout << L"Do you want: (1) Log in to system! or (2) Sign up an account!" << endl;
		/*Dùng option để làm nút chọn luôn.*/
		option = _getch();
		
		/*ASCII code: 1: 49, 2: 50*/
		while (option != 49 && option != 50) option = _getch();
		system("cls");

		/*Nếu là log in hệ thống*/
		bool check = false;/*Kiểm tra log in hệ thống có được chưa*/
		string user, password;
		while (option == 49 && check != true) {
			wcout << L"Username: "; getline(cin, user);
			wcout << L"Password: "; getline(cin, password);
			loginStaff(path, user, password, check);
		}
		/*Test*/
		/*Nếu là tạo tài khoản trong hệ thống*/
		if (option == 50) {
			signUpStaff(s);
			SaveStaffAccount(path, s);
		}
		/*Task Tạo năm học mới*/


	}

	/*Nhận file csv. Đọc và tạo ra các file csv tương ứng là từng loại lớp APCS,CLC,CNTT,... trong file schoolyear1*/
	/*Nhập thời gian học kì 1, học kì 2, học kì 3. Chỉ nhập một lần đầu tiên.*/
	if (StartSes1.tm_year == 0 || StartSes2.tm_year == 0 || StartSes3.tm_year == 0 || EndSes1.tm_year == 0 || EndSes2.tm_year == 0 || EndSes3.tm_year == 0)
		SetUpTimeSes(StartSes1, EndSes1, StartSes2, EndSes2, StartSes3, EndSes3);
	/*Xác định thời gian hiện tại*/
	/*Xác định học kì và năm học*/
	/*Cập nhật lại học kì nếu thời gian quá năm học*/
	time_t now = time(0);
	localtime_s(&TimeCur, &now);
	TimeCur.tm_mon++;
	while (isOutOfDate(TimeCur, StartSes1, EndSes3) == false) SetUpTimeSes(StartSes1, EndSes1, StartSes2, EndSes2, StartSes3, EndSes3);
	if (TimeCur.tm_mon >= StartSes3.tm_mon) semester = 3;
	else if (TimeCur.tm_mon >= StartSes2.tm_mon) semester = 2;
	else semester = 1;
	system("cls");

	/*Xác định năm học :<<*/
	 SchoolYearMenu( schoolyear);

	/*Show ra cái menu*/
	wcout << L"Options for schoolyear "<<schoolyear<<"."<<endl;
	wcout << L"1.View classes" << endl;
	wcout << L"2.Create/Add courses" << endl;
	wcout << L"3.View courses" << endl;
	wcout << L"4.Back" << endl;
	int option;
	option = _getch();
	while (option != 49 && option != 50 && option != 51 && option != 52) option = _getch();
	if (option == 52) SchoolYearMenu(schoolyear);

	/*Khi tạo course thì mặc định là course vừa tạo. Giáo vụ log in, log out thì vẫn là học kì đó. Có thể có hàm switch để chuyển qua lại giữa các học kì*/
	/*Thêm thời hạn (ngày bắt đầu/ngày kết thúc) đăng kí khóa học cho sinh viên*/
	/*View danh sách các lớp*/
	wcout << L"List of classes in schoolyear (Esc to back) " << schoolyear<<endl;
	wcout << L"1.APCS" << endl;
	wcout << L"2.CLC" << endl;
	wcout << L"3.CNTT" << endl;
	wcout << L"4.CTDT" << endl;
	wcout << L"5.VP" << endl;
	option = _getch();
	while (option != 49 && option != 50 && option != 51 && option != 52 && option != 53) option = _getch();
	option = option - 48;
	Class* headClass = nullptr;
	Student* headStudent = nullptr;

	ViewClass(option, schoolyear,headStudent,headClass);


	/*View danh sách học sinh trong một lớp*/
	string data;
	wcout << "View list of student in class: ";
	getline(cin, data);
	cout << endl;
	viewStudent_InClass(data, headStudent);
	/*View danh sách khóa học*/
	Course* headCourse = nullptr;
	ViewListCourse(schoolyear, semester, headCourse);
	/*View danh sách học sinh trong một course*/

	/*... rồi thao tác xóa, update thông tin khóa học đó.*/
	/*Cuối kì chưa làm được*/
	DeleteListCourse(headCourse);
	DeleteListStudent(headStudent);


	/******Công việc của sinh viên*****/
	if (button == 50) wcout << L"You are student!!" << endl;
	/*Hàm đăng nhập của sinh viên*/
	/*Hàm nhập thời gian sẽ hoạt động mỗi lần sinh viên log in để kiểm tra đã quá thời hạn đănng kí chưa*/
	/*Đăng kí khóa học nè.*/
	/*Xóa khóa học nè*/
	/*Xem danh sách khóa học đăng kí nè.*/
	/*Sau khi thời hạn đăng kí kết thúc thì có thể xem danh sách các khóa học đã đăng kí*/
	/*Cuối kỳ thì xem kết quả học phần của mình nè.*/

	/*Tạm thời nếu làm xong chừng này thì ổn vailoz*/








	
	//SetConsoleTitle(L"HCMUS - Course Registration System");
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
	SetUpSemester(1, 1, pHead);
	DeleteListCourseInfo(pHead);
	wcout << L"Do you want to view the list of courses.";
	*/
		return 0;
}