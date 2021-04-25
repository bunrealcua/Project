#include"Time.h"
#include<iostream>
#include<ctime>
using namespace std;

bool isOutOfDate(tm TimeCur, tm StartSes1, tm EndSes3)
{
	if (TimeCur.tm_year<StartSes1.tm_year || TimeCur.tm_year>EndSes3.tm_year) return false;
	if (TimeCur.tm_year == StartSes1.tm_year && TimeCur.tm_mon < StartSes1.tm_mon) return false;
	if (TimeCur.tm_year == EndSes3.tm_year && TimeCur.tm_year > EndSes3.tm_mon) return false;
	if (TimeCur.tm_year == StartSes1.tm_year && TimeCur.tm_mon == StartSes1.tm_mon && TimeCur.tm_mday < StartSes1.tm_mday) return false;
	if (TimeCur.tm_year == EndSes3.tm_year && TimeCur.tm_mon == EndSes3.tm_mon && TimeCur.tm_mday > EndSes3.tm_mday) return false;
	return true;
}