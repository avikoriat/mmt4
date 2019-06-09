#include "EE_Course.h"



//initialize factor to 0 for all students:
int EE_Course::factor_ = 0;

EE_Course::EE_Course(int courseNum, char* courseName, int numOfHmw, double hmwWeight):
	Course(courseNum, courseName,numOfHmw, hmwWeight){}
/*************************************************************************
Function name	: EE_Course::getCourseGrade()
Description		: calculates the total grade of the course by the formula:
	course_grade = round( (1 – hw_weight)*exam_grade +
hw_weigh*hw_average) + factor
Paramerters		: none
Return value	: int - the grade
************************************************************************/
/*course_grade = round( (1 – hw_weight)*exam_grade +
hw_weigh*hw_average) + factor*/
int EE_Course::getCourseGrade() {
	int grade = Course::getCourseGrade() + factor_;
	if (grade > 100) {
		grade = 100;
	}
	return grade;
}


