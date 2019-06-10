#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Student.h"

#define NO_GRADE -1
using std::cout;
using std::cerr;
using std::endl;

//constructor
Student::Student(int id, char* name):
	Person(id, name),eeCourseCnt_(0),csCourseCnt_(0)
{
	for (int i = 0; i < MAX_COURSE_NUM; i++) {
		peeCourses_[i] = NULL;
		pcsCourses_[i] = NULL;
	}
}

//destructor
Student::~Student()
{
	for (int i = 0; i < MAX_COURSE_NUM; i++) {
		delete peeCourses_[i];
		delete pcsCourses_[i];
	}
	
}

/*************************************************************************
Function name	: Student::addEE_Course()
Description		: adds new EE Course to the student
Paramerters		: peeCourse - pointer to the new EE Course
Return value	: Result - SUCCESS if executed successfully, FAILURE otherwise
************************************************************************/
Result Student::addEE_Course(EE_Course* peeCourse) {
	for (int i = 0; i < MAX_COURSE_NUM; i++) {
		if (peeCourses_[i] == NULL) {
			peeCourses_[i] = peeCourse;
			eeCourseCnt_++;
			return SUCCESS;
		}
	}
	return FAILURE;
}

/*************************************************************************
Function name	: Student::addCS_Course()
Description		: adds new CS Course to the student
Paramerters		: pcsCourse - pointer to the new CS Course
Return value	: Result - SUCCESS if executed successfully, FAILURE otherwise
************************************************************************/
Result Student::addCS_Course(CS_Course* pcsCourse) {
	for (int i = 0; i < MAX_COURSE_NUM; i++) {
		if (pcsCourses_[i] == NULL) {
			pcsCourses_[i] = pcsCourse;
			csCourseCnt_++;
			return SUCCESS;
		}
	}
	return FAILURE;
}

/*************************************************************************
Function name	: Student::remCourse()
Description		: removes course from the student's courses
Paramerters		: courseNum - Course number
Return value	: Result - SUCCESS if there is a course with this number, FAILURE otherwise
************************************************************************/
Result Student::remCourse(int courseNum) {
	for (int i = 0; i < MAX_COURSE_NUM; i++) {
		if (pcsCourses_[i] != NULL) {
			if (pcsCourses_[i]->getNum() == courseNum) {
				delete pcsCourses_[i];
				pcsCourses_[i] = NULL;
				csCourseCnt_--;
				return SUCCESS;
			}
		}
		else if (peeCourses_[i] != NULL) {
			if (peeCourses_[i]->getNum() == courseNum) {
				delete peeCourses_[i];
				peeCourses_[i] = NULL;
				eeCourseCnt_--;
				return SUCCESS;
			}
		}
	}	
	return FAILURE;
}

/*************************************************************************
Function name	: Student::getEE_Course()
Description		: returns a pointer to the EE Course studied by the student
Paramerters		: eeCourseNum - EE Course number
Return value	: EE_Course* - a pointer to the EE Course if there is a 
		course with this number, NULL otherwise
************************************************************************/
EE_Course* Student::getEE_Course(int eeCourseNum) {
	for (int i = 0; i < MAX_COURSE_NUM; i++) {
		if (peeCourses_[i] != NULL) {
			if ((peeCourses_[i]->getNum()) == eeCourseNum) {
				return peeCourses_[i];
			}
		}
	}
	return NULL;
}

/*************************************************************************
Function name	: Student::getCS_Course()
Description		: returns a pointer to the CS Course studied by the student
Paramerters		: csCourseNum - CS Course number
Return value	: CS_Course* - a pointer to the CS Course if there is a 
		course with this number, NULL otherwise
************************************************************************/
CS_Course* Student::getCS_Course(int csCourseNum) {
	for (int i = 0; i < MAX_COURSE_NUM; i++) {
		if (pcsCourses_[i] != NULL) {
			if ((pcsCourses_[i]->getNum()) == csCourseNum) {
				return pcsCourses_[i];
			}
		}
	}
	return NULL;
}

/*************************************************************************
Function name	: Student::getAvg()
Description		: calculates the average grade of the student by the formula:
	average_grade = round( sum_of_grades_in_all_courses / number_of_courses )
Paramerters		: none
Return value	: int - the average grade
************************************************************************/
int Student::getAvg() {
	double sum = 0;
	int courseCnt = 0;
	int CurrentCsCourseGrade;
	for (int i = 0; i < MAX_COURSE_NUM; i++) {
		if (pcsCourses_[i] != NULL) {
			CurrentCsCourseGrade = pcsCourses_[i]->getCourseGrade();
			if (CurrentCsCourseGrade != NO_GRADE) {
				sum += CurrentCsCourseGrade;
				courseCnt++;
			}
		}
		
		if (peeCourses_[i] != NULL) {
			CurrentCsCourseGrade = peeCourses_[i]->getCourseGrade();
			if (CurrentCsCourseGrade != NO_GRADE) {
				sum += (peeCourses_[i]->getCourseGrade());
				courseCnt++;
			}
		}
	}
	if (courseCnt == 0) return 0;

	double grade = sum / courseCnt;
	int wholePartGrade = static_cast<int>(grade);

	if (grade - wholePartGrade > 0.5) {
		return wholePartGrade + 1;
	}
	else {
		return wholePartGrade;
	}
}

/*************************************************************************
Function name	: Student::print()
Description		: prints the data of the student by the format:
	SName: student_name
	SID: student_id
	Avg.: average_grade
	
	EE:
	course_number course_name course_grade
	…

	CS courses:
	course_number course_name course_grade
	…

Paramerters		: none
Return value	: none
************************************************************************/
void Student::print() {
	char* studentName = getName();
	cout << "Student name: " << studentName << endl;
	cout << "Student ID: " << getID() << endl;
	cout << "Average grade: " << getAvg() << endl;
	cout << endl;
	delete[] studentName;
	cout << "EE courses:" << endl;
	for (int i = 0; i < MAX_COURSE_NUM; i++) {
		if (peeCourses_[i] != NULL) {
			char* currentEeCourseName = peeCourses_[i]->getName();
			cout << (peeCourses_[i]->getNum()) << " " << currentEeCourseName <<
				": " << (peeCourses_[i]->getCourseGrade()) << endl;
			delete[] currentEeCourseName;
		}
	}
	cout << endl;
	cout << "CS courses:" << endl;
	for (int i = 0; i < MAX_COURSE_NUM; i++) {
		if (pcsCourses_[i] != NULL) {
			char* currentCsCourseName = pcsCourses_[i]->getName();
			cout << (pcsCourses_[i]->getNum()) << " " << currentCsCourseName <<
				": " << (pcsCourses_[i]->getCourseGrade()) << endl;
			delete[] currentCsCourseName;
		}
	}
	cout << endl;
}
