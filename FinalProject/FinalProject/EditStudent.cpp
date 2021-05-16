#include<iostream>
using namespace std;
#include "StructStudent.h"
#include"Student.h"
#include"Staff.h"
#include<ctime>

void EditStudent(Student* pHead,int schoolyear, int option) {
	string str;
	if (schoolyear == 1)
	{
		if (option == 1) str = "Data\\SchoolYear1\\APCS.csv";
		else if (option == 2) str = "Data\\SchoolYear1\\CLC.csv";
		else if (option == 3) str = "Data\\SchoolYear1\\CNTT.csv";
		else if (option == 4) str = "Data\\SchoolYear1\\CTDT.csv";
		else str = "Data\\SchoolYear1\\VP.csv";
	}
	else if (schoolyear == 2)
	{
		if (option == 1) str = "Data\\SchoolYear2\\APCS.csv";
		else if (option == 2) str = "Data\\SchoolYear2\\CLC.csv";
		else if (option == 3) str = "Data\\SchoolYear2\\CNTT.csv";
		else if (option == 4) str = "Data\\SchoolYear2\\CTDT.csv";
		else str = "Data\\SchoolYear2\\VP.csv";
	}
	else if (schoolyear == 3)
	{
		if (option == 1) str = "Data\\SchoolYear3\\APCS.csv";
		else if (option == 2) str = "Data\\SchoolYear3\\CLC.csv";
		else if (option == 3) str = "Data\\SchoolYear3\\CNTT.csv";
		else if (option == 4) str = "Data\\SchoolYear3\\CTDT.csv";
		else str = "Data\\SchoolYear3\\VP.csv";
	}
	else {
		if (option == 1) str = "Data\\SchoolYear1\\APCS.csv";
		else if (option == 2) str = "Data\\SchoolYear1\\CLC.csv";
		else if (option == 3) str = "Data\\SchoolYear1\\CNTT.csv";
		else if (option == 4) str = "Data\\SchoolYear1\\CTDT.csv";
		else str = "Data\\SchoolYear1\\VP.csv";
	}
	int id;
	wstring firstName;
	wstring lastName;
	bool gender;
	string dateOfBirth;
	int socialID;
	string Username;
	string pass;
	string ClassStu;
	int year;
	if (pHead == nullptr)return;
	cout << "Enter the student's ID you want to change " << endl;
	cin >> id;
	ofstream fileout;
	fileout.open("str", std::ofstream::trunc);
		if (!fileout) {
			cout << "Error!" << endl;
		}
		else {
			Student* pCur = pHead;
			while (pCur != nullptr) {
				if(pCur->ID==id){
					cout << "1.Change ID\n" << "2.Change fisrt name\n" << "3.Change last name\n"<<"4.Change gender\n"<<"5.Change dateOfBirth\n"<<"6.Change socialID\n";
					int choose;
					cin >> choose;
					switch (choose) {
					case 1:
						cout << "Ennter your new ID " << endl;
						cin >> id;
						pCur->ID = id;
					case 2:
						cout << "Enter your new first name " << endl;
						wcin >> firstName;
						pCur->First_Name = firstName;
					case 3:
						cout << "Enter your new last name " << endl;
						wcin >> lastName;
						pCur->Last_Name = lastName;
					case 4:
						cout << "Enter your new gender " << endl;
						cin >> gender;
						pCur->Gender = gender;
					case 5:
						cout << "Enter your new date of birth " << endl;
						cin >> dateOfBirth;
						pCur->DateOfBirth = dateOfBirth;
					case 6:
						cout << "Enter your new social ID " << endl;
						cin >>socialID;
						pCur->Social_ID = socialID;

					}
					pCur = pCur->pNext;
				}
			}
		}
}