#include"Menu.h"
#include<Windows.h>
#include<iostream>
using namespace std;

void SchoolYearMenu(int& schoolyear)
{
	wcout << L"Available school year:" << endl;
	wcout << L"1.2020-2021" << endl;
	wcout << L"2.2019-2020" << endl;
	wcout << L"3.2018-2019" << endl;
	wcout << L"4.2017-2018" << endl;
	wcout << L">>> Select your schoolyear: ";
	cin >> schoolyear;
	system("cls");
}

void MenuBackGround()
{
	wcout << "******Course Registration System*******" << endl << endl;
}
