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
	string path = "D:\\InputProject\\StaffAccount.txt";
	int button = 0;
	/*******Đăng nhập để biết*******/
	/*Làm sao log in, log out được nhỉ, đối với giáo viên, à nếu log out thì log out thôi. Có thể hàm tạo tài khoản cho staff*/
	/*Trong quá trình chương trình chạy, có hai biến là Staff và Student để mà giữ trạng thái tài khoản người dùng đang sử dụng, có thể là staff hoặc có thể là sv*/
	/*Nếu log out thì màn hình vẫn màu đen console thôi chứ không có trở về lại return 0*/
	
	/*Xác định là staff hay là student.*/
	wcout << "Are you Staff or Student: (1)Staff or (2)Student"<<endl;
	button = _getch();
	/*ASCII code: 1: 49, 2: 50*/
	while (button != 49 && button != 50) button = _getch();
	



	/******Công việc của staff nè!******/
	if (button == 49) { wcout << L"You are staff!!" << endl;
	Staff s;

	/*Staff log in hoặc sign up vào hệ thống*/
	int option = 0;
	wcout << L"Do you want: (1) Log in to system! or (2) Sign up an account!"<<endl;
	/*Dùng option để làm nút chọn luôn.*/
	option = _getch();
	/*ASCII code: 1: 49, 2: 50*/
	while (option != 49 && option != 50) option = _getch();
	
	/*Nếu là log in hệ thống*/
	bool check = false;/*Kiểm tra log in hệ thống có được chưa*/
	string user, password;
	while (option == 49 && check!=true) {
		wcout << L"Username: "; getline(cin, user);
		wcout << L"Password: "; getline(cin, password);
		loginStaff(path, user, password,check);

	}

	/*Nếu là tạo tài khoản trong hệ thống*/
	if (option == 50) { 
		signUpStaff(s);
		SaveStaffAccount(path, s);
	}
		

	wcout << L"Semester 1 is coming. Input course in semester 1." << endl;
	CourseInfo *pHead = nullptr;
	SetUpSemester(1, 1, pHead);
	}
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
	if (button == 50) wcout << L"You are student!!" << endl;
	/*Hàm nhập thời gian sẽ hoạt động mỗi lần sinh viên log in để kiểm tra đã quá thời hạn đănng kí chưa*/
	/*Đăng kí khóa học nè.*/
	/*Xóa khóa học nè*/
	/*Xem danh sách khóa học đăng kí nè.*/
	/*Sau khi thời hạn đăng kí kết thúc thì có thể xem danh sách các khóa học đã đăng kí*/

	/*Tạm thời nếu làm xong chừng này thì ổn vailoz*/

	
	
	
	
	


	return 0;
}
