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

/*Hàm để sinh viên chọn xóa và update những khóa học mong muốn*/
void registercourse(Student* pHeadStudent, Course* pHeadCourse);
void Register(int schoolyear, int semester, Student* pHead);
void CopyCourse(Course* CourseA, Course* CourseB);
void SetUpRegistration(int schoolyear, int semester, Student* headStudent, Course* headCourse);
void UpdateCourseSelection(int schoolyear, int semester, Student* headStudent);
void DeleteACourseSelection(int schoolyear, int semester, Student* headStudent);
void SelectCourse(Course* pCourse, Course*& CourseSelect);
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

/*Những hàm cần thiết để xem các khóa học đã đăng kí*/
void getData(string str, MaSo*& pHead);
void readFile(string path1, wstring& str, Course* pHead);
void DeleteListMaSo(MaSo*& pHead);
void PrintOutEnrolledCourses(int schoolyear, int semester, MaSo* headMaSo);
void viewEnrolledCourses(int schoolyear, int semester, int tempInput);

int wmain()
{
	SetConsoleTitle(L"HCMUS - Course Registration System");
	/*_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);*/
	wstring_convert <codecvt_utf8_utf16<wchar_t>> convert;
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
	/*Biến linked list các kiểu*/
	Class* headClass = nullptr;
	Student* headStudent = nullptr;
	Course* headCourse = nullptr;

	/*******Đăng nhập để biết*******/
	/*Làm sao log in, log out được nhỉ, đối với giáo viên, à nếu log out thì log out thôi. Có thể hàm tạo tài khoản cho staff*/
	/*Trong quá trình chương trình chạy, có hai biến là Staff và Student để mà giữ trạng thái tài khoản người dùng đang sử dụng, có thể là staff hoặc có thể là sv*/
	/*Nếu log out thì màn hình vẫn màu đen console thôi chứ không có trở về lại return 0*/

	/*Xác định là staff hay là student.*/
	MenuBackGround();
	wcout << ">>> Select your role:" << endl << "1.Staff" << endl << "2.Student" << endl;
	button = _getch();
	/*ASCII code: 1: 49, 2: 50*/
	while (button != 49 && button != 50) button = _getch();
	system("cls");



	/******Công việc của staff nè!******/
	if (button == 49) {
		MenuBackGround();
		wcout << L">>> STAFF <<<" << endl << endl;
		Staff s;

		/*Staff log izn hoặc sign up vào hệ thống*/
		int option = 0;
		wcout << L"Select your option: " << endl << L"1. Log in to system!" << endl << "2. Sign up an account!" << endl;
		/*Dùng option để làm nút chọn luôn.*/
		option = _getch();

		/*ASCII code: 1: 49, 2: 50*/
		while (option != 49 && option != 50) option = _getch();
		system("cls");

		/*Nếu là log in hệ thống*/
		if (option == 49) {

			bool check = false;/*Kiểm tra log in hệ thống có được chưa*/
			wstring tempuser, temppassword;
			string user, password;

			while (option == 49 && check != true) {
				MenuBackGround();
				wcout << L">>> STAFF <<<" << endl << endl;
				wcout << L">>> Username: "; getline(wcin, tempuser);
				wcout << L">>> Password: "; getline(wcin, temppassword);
				user = convert.to_bytes(tempuser);
				password = convert.to_bytes(temppassword);
				loginStaff(path, user, password, check);
				system("cls");
			}
		}
		/*Test*/
		/*Nếu là tạo tài khoản trong hệ thống*/
		if (option == 50) {
			MenuBackGround();
			signUpStaff(s);
			SaveStaffAccount(path, s);
		}
		/*Task Tạo năm học mới*/




	/*Nhận file csv. Đọc và tạo ra các file csv tương ứng là từng loại lớp APCS,CLC,CNTT,... trong file schoolyear1*/
	/*Nhập thời gian học kì 1, học kì 2, học kì 3. Chỉ nhập một lần đầu tiên.*/
		MenuBackGround();
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
		MenuBackGround();
		SchoolYearMenu(schoolyear);

		/*Show ra cái menu*/
		MenuBackGround();

		wcout << L"* Options for schoolyear " << schoolyear << ". *" << endl;
		wcout << L"1.View classes" << endl;
		wcout << L"2.Create/Add courses" << endl;
		wcout << L"3.View courses" << endl;
		wcout << L"4.View student in a course" << endl;
		wcout << L"5.Back" << endl;
		wcout << L"6.Logging out" << endl << endl;
		wcout << L">>> Select your option: ";

		option = _getch();

		while (option != 49 && option != 50 && option != 51 && option != 52 && option != 53) option = _getch();
		if (option == 53) SchoolYearMenu(schoolyear);

	
		/*Khi tạo course thì mặc định là course vừa tạo. Giáo vụ log in, log out thì vẫn là học kì đó. Có thể có hàm switch để chuyển qua lại giữa các học kì*/
		/*Thêm thời hạn (ngày bắt đầu/ngày kết thúc) đăng kí khóa học cho sinh viên*/
		/*View danh sách các lớp*/
		if (option == 49)
		{
			wcout << L"List of classes in schoolyear " << schoolyear << L"(Esc to back)" << endl;
			wcout << L"1.APCS" << endl;
			wcout << L"2.CLC" << endl;
			wcout << L"3.CNTT" << endl;
			wcout << L"4.CTDT" << endl;
			wcout << L"5.VP" << endl;
			option = _getch();
			while (option != 49 && option != 50 && option != 51 && option != 52 && option != 53) option = _getch();
			option = option - 48;

			ViewClass(option, schoolyear, headStudent, headClass);


			/*View danh sách học sinh trong một lớp*/
			string data;
			wcout << "View list of student in class: ";
			getline(cin, data);
			cout << endl;

			viewStudent_InClass(data, headStudent);
			DeleteListStudent(headStudent);
		}
		/*View danh sách khóa học*/
		if (option == 51) {
			ViewListCourse(schoolyear, semester, headCourse);
			DeleteListCourse(headCourse);
		}
		/*View danh sách học sinh trong một course*/
		if (option == 52) {
			ViewListCourse(schoolyear, semester, headCourse);
			int courseID;
			wcout << L"Please input course ID: "; wcin >> courseID;
			ViewStudentInCourse(schoolyear, courseID);
			DeleteListCourse(headCourse);
		}
		if (option == 50) {
			/*Thao tác thêm khóa học*/
			/*Setup để đọc chữ tiếng việt*/
			_setmode(_fileno(stdin), _O_U16TEXT);
			_setmode(_fileno(stdout), _O_U16TEXT);
			system("cls");
			MenuBackGround();
			wcout << L">>> Semester " << semester << L" is coming. Input course in semester " << semester << "." << endl;

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
				wcout << L"Week day: "; wcin >> tempI;
				wstr += to_wstring(tempI) + L",";
				wcout << L"Session Day 1 (Mon/Tue/Wed/Thu/Fri/Sat/Sun) : "; getline(wcin, wtemp);
				wstr += wtemp + L",";
				wcout << L"Time day 1 (hh:mm-hh:mm)"; getline(wcin, wtemp);
				wstr += wtemp + L",";
				wcout << L"Session Day 1 (Mon/Tue/Wed/Thu/Fri/Sat/Sun) : "; getline(wcin, wtemp);
				wstr += wtemp + L",";
				wcout << L"Time day 2 (hh:mm-hh:mm)"; getline(wcin, wtemp);
				wstr += wtemp;
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
			SetUpSemester(schoolyear, semester, pHead);
			DeleteListCourseInfo(pHead);
			/*Xóa, update thông tin khóa học đó.*/
		}


		/*Cuối kì chưa làm được*/
		DeleteListCourse(headCourse);
		DeleteListStudent(headStudent);
	}

	/******Công việc của sinh viên*****/
	if (button == 50) {
		int option;
		wstring tempusername, temppassword;
		string username, password;
		MenuBackGround();
		wcout << L"* You are student!! *" << endl<<endl;
		wcout << L">>> Username: "; getline(wcin, tempusername);
		wcout << L">>> Password: "; getline(wcin, temppassword);
		username = convert.to_bytes(tempusername);
		password = convert.to_bytes(temppassword);
		while (checkLogin(username, password) != true)
		{
			wcout << L"Your logging is invalid. Please check your Username or Password"<<endl<<endl;
			wcout << L">>> Username: "; getline(wcin, tempusername);
			wcout << L">>> Password: "; getline(wcin, temppassword);
			username = convert.to_bytes(tempusername);
			password = convert.to_bytes(temppassword);
		}
		wcout << L"Logging in successfully!"<<endl;
		option = _getch();
		
		headStudent = nullptr;
		Student* curStudent = nullptr;
		curStudent = defineStudent(headStudent, username, password);
		DeleteListStudent(headStudent);

		system("cls");
		MenuBackGround();
		wcout << L"1.Register courses"<<endl;
		wcout<<	 L"2.View courses registered"<<endl;
		wcout << L"3.View scoreboard." << endl;
		wcout << L"4.View profile" << endl;
		wcout << L"5.Logging out." << endl<<endl;

		wcout << L">>> Select your option: ";
		option = _getch();
		while (option != 49 && option != 50 && option != 51 && option != 52 && option != 53) option = _getch();
		/*Hàm đăng nhập của sinh viên*/ /*Tạo file riêng để dễ dàng đăng nhập hơn*/
		/*Hàm nhập thời gian sẽ hoạt động mỗi lần sinh viên log in để kiểm tra đã quá thời hạn đănng kí chưa*/
		/*Đăng kí khóa học nè.*/
		if (option == 49) {
			Course* CourseSelect = nullptr;
			SelectCourse(headCourse, CourseSelect);
		}
		/*Xóa khóa học nè*/
		DeleteACourseSelection(schoolyear, semester, headStudent);
		/*Xem danh sách khóa học đăng kí nè.*/
		if (option == 50) {
			int tempInput = 0;
			viewEnrolledCourses(schoolyear, semester, tempInput);
		}
		if (option == 51) wcout << L"View scoreboard" << endl;
		if (option == 52) wcout << L"View profile" << endl;
		/*Sau khi thời hạn đăng kí kết thúc thì có thể xem danh sách các khóa học đã đăng kí*/
		/*Cuối kỳ thì xem kết quả học phần của mình nè.*/

		/*Tạm thời nếu làm xong chừng này thì ổn vailoz*/

	}






	
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