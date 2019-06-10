#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Proj.h"
#include "Course.h"
#define NO_GRADE -1
using std::endl;
using std::cerr;
// contstuctor
Course::Course(int courseNum, char* courseName, int numOfHmw, double hmwWeight) :
	courseNum_(courseNum), numOfHmw_(numOfHmw), hmwWeight_(hmwWeight), examGrade_(NO_GRADE)
{
	if (courseName == NULL) {//input check
		cerr << "Course constructor error: parameter courseName is a NULL pointer" << endl;
		exit(1);
	}
	courseName_ = new char[strlen(courseName) + 1];
	strcpy(courseName_, courseName);
	hmwGrades_ = new int[numOfHmw];
	//initialize to illegal value of grades:
	for (int i = 0; i < numOfHmw; i++) {
		hmwGrades_[i] = NO_GRADE;
	}

}
//destructor
Course::~Course() {
	delete[] courseName_;
	delete[] hmwGrades_;
}

/*************************************************************************
Function name	: Course::getName()
Description		: returns a new allocated string that contains the name 
				of the course
Paramerters		: none
Return value	: char* - a pointer to an array of the string
************************************************************************/
char* Course::getName() {
	char* name = new char[strlen(courseName_) + 1];
	strcpy(name, courseName_);
	return name;
}
/*************************************************************************
Function name	: Course::getHwGrade()
Description		: returns the value of the grade of homework the number of 
				which is specified by hmwNum
Paramerters		: hmwNum - an index to the number of the homework
Return value	: int - the homework grade
************************************************************************/
int Course::getHwGrade(int hmwNum) {
	if ((hmwNum >= 0) && hmwNum < numOfHmw_) {
		return hmwGrades_[hmwNum];
	}
}
/*************************************************************************
Function name	: Course::getHwAverage()
Description		: calculates the homework average of the course
Paramerters		: none
Return value	: double - the average
************************************************************************/
double Course::getHwAverage() {
	double  sum = 0;
	int  hwCnt = 0;
	for (int i = 0; i < numOfHmw_; i++) {
		if (hmwGrades_[i] != NO_GRADE) {
			sum += hmwGrades_[i];
			hwCnt++;
		}
	}
	if (hwCnt == 0) {
		return NO_GRADE;
	}
	return sum / hwCnt;
}

/*************************************************************************
Function name	: Course::getCourseGrade()
Description		: calculates the total grade of the course by the formula:
	course_grade = round( (1 – hw_weigh)*exam_grade + hw_weigh*hw_average )
Paramerters		: none
Return value	: int - the grade
************************************************************************/
int Course::getCourseGrade() {
	if (examGrade_ != NO_GRADE) {
			double grade = (1 - hmwWeight_) * examGrade_ + hmwWeight_ * getHwAverage();
			int wholePartGrade = static_cast<int>(grade);
			if (grade - wholePartGrade > 0.5) {
			return wholePartGrade + 1;
		}
		else {
			return wholePartGrade;
		}
	}
	else {
		return NO_GRADE;
	}

}

/*************************************************************************
Function name	: Course::setExamGrade()
Description		: sets the grade of the exam
Paramerters		: examGrade - the grade
Return value	: Result - SUCCESS if executed successfully, FAILURE otherwise
************************************************************************/
Result Course::setExamGrade(int examGrade){
	examGrade_ = examGrade; 
	return SUCCESS;
}

/*************************************************************************
Function name	: Course::setHwGrade()
Description		: sets the grade of a homework assignment with number specified
				by hmwNum
Paramerters		: hmwNum - homework number, hmwGrade - homework grade
Return value	: Result - SUCCESS if executed successfully, FAILURE otherwise
************************************************************************/
Result Course::setHwGrade(int hmwNum, int hmwGrade) {
	if ((hmwNum >= 0) && hmwNum < numOfHmw_) {
		hmwGrades_[hmwNum] = hmwGrade;
		return SUCCESS;
	}
	else {
		return FAILURE;
	}
}
