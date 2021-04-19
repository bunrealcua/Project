#include "StructStudent.h"
#include"Student.h"
#include"Staff.h"
void Realtime()
{
	__time32_t k = time(0);
	tm s;
	_localtime32_s(&s, &k);
	cout << s.tm_hour << ":" << s.tm_min << ":" << s.tm_sec << " ";
	cout << s.tm_mday << "/" << s.tm_mon + 1 << "/" << s.tm_year + 1900 << endl;
}