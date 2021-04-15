#ifndef Final_Project
#define Final_Project


struct Student {
	int ID; wstring First_Name;
	wstring Last_Name; bool Gender;
	string DateOfBirth; int Social_ID;
	string username; string password;
	string Class; int SchoolYear; Student* pNext;
};
struct Course {
	int ID; wstring Name;
	wstring Lecturer; int Credits;
	int StudentLimit; int Weekday;
	int Session; Course* next;
};

void registercourse(Student* pHead, Course* pHead1);

// student
void input(Student*& pHead);
void Signup(Student*& pHead);
///
void Input(string path, wstring& str, Student*& pHead);
void SetUp(wstring str, Student*& pHead);
// change password
void changepass(Student*& pHead);

#endif

