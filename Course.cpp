#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Proj.h"
#include "Course.h"
#define NO_GRADE -1
using std::endl;
using std::cerr;

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
	for (int i = numOfHmw; i < numOfHmw; i++) {
		hmwGrades_[i] = NO_GRADE;
	}

}

Course::~Course() {
	delete[] courseName_;
	delete[] hmwGrades_;
}


char* Course::getName() {
	char* name = new char[strlen(courseName_) + 1];
	strcpy(name, courseName_);
	return name;
}

int Course::getHwGrade(int hmwNum) {
	if ((hmwNum >= 0) && hmwNum < numOfHmw_) {
		return hmwGrades_[hmwNum];
	}
}

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

//course_grade = round( (1 – hw_weigh)*exam_grade + hw_weigh*hw_average )
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

//why could it fail?
Result Course::setExamGrade(int examGrade){
	examGrade_ = examGrade; 
	return SUCCESS;
}

Result Course::setHwGrade(int hmwNum, int hmwGrade) {
	if ((hmwNum >= 0) && hmwNum < numOfHmw_) {
		hmwGrades_[hmwNum] = hmwGrade;
		return SUCCESS;
	}
	else {
		return FAILURE;
	}
}
