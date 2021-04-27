#ifndef Final_Project 
#define Final_Project
#include<ctime>
void SetUpTimeSes(tm& StartSes1, tm& EndSes1, tm& StartSes2, tm& EndSes2, tm& StartSes3, tm& EndSes3); /*Hàm set up thời gian của học kì*/
bool isOutOfDate(tm TimeCur, tm StartSes1, tm EndSes3);/*Kiểm tra xem thời gian hiện tại có ở trong thời gian học kì không*/

#endif
