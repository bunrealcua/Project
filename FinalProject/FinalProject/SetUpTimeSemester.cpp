#include"Time.h"
#include<iostream>
#include<ctime>
using namespace std;

void SetUpTimeSes(tm& StartSes1, tm& EndSes1, tm& StartSes2, tm& EndSes2, tm& StartSes3, tm& EndSes3)
{
	wcout << L"* Please set up the time of 3 semesters of the year! *" << endl<<endl;
	wcout << L">>> Semester 1." << endl;
	wcout << L"Start date (mm dd yyyy): "; wcin >> StartSes1.tm_mon; wcin >> StartSes1.tm_mday; wcin >> StartSes1.tm_year; StartSes1.tm_year -= 1900;
	wcout << L"End date (mm dd yyyy): "; wcin >> EndSes1.tm_mon; wcin >> EndSes1.tm_mday; wcin >> EndSes1.tm_year; EndSes1.tm_year -= 1900;
	wcout << L"*****Set up time for semester 1 successfully!*****" << endl << endl;

	wcout << L">>> Semester 2." << endl;
	wcout << L"Start date (mm dd yyyy): "; wcin >> StartSes2.tm_mon; wcin >> StartSes2.tm_mday; wcin >> StartSes2.tm_year; StartSes2.tm_year -= 1900;
	wcout << L"End date (mm dd yyyy): "; wcin >> EndSes2.tm_mon; wcin >> EndSes2.tm_mday; wcin >> EndSes2.tm_year; EndSes2.tm_year -= 1900;
	wcout << L"*****Set up time for semester 2 successfully!*****" << endl << endl;

	wcout << L">>> Semester 3." << endl;
	wcout << L"Start date (mm dd yyyy): "; wcin >> StartSes3.tm_mon; wcin >> StartSes3.tm_mday; wcin >> StartSes3.tm_year; StartSes3.tm_year -= 1900;
	wcout << L"End date (mm dd yyyy): "; wcin >> EndSes3.tm_mon; wcin >> EndSes3.tm_mday; wcin >> EndSes3.tm_year; EndSes3.tm_year -= 1900;
	wcout << L"*****Set up time for semester 3 successfully!*****" << endl << endl;

}