#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "StArray.h"

using std::cout;
using std::cerr;
using std::endl;

//constructor
StArray::StArray() : StudentCnt_(0)
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		pStudents_[i] = NULL;
	}
}

//destructor
StArray::~StArray()
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		delete pStudents_[i];
	}
}

/*************************************************************************
Function name	: StArray::addStudent()
Description		: creates new student and adds her/him to the array
Paramerters		: stID - student number, Name - student name
Return value	: Result - SUCCESS if executed successfully, FAILURE otherwise
************************************************************************/
Result StArray::addStudent(int stID, char* Name) {
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		if (pStudents_[i] == NULL) {
			pStudents_[i] =  new Student(stID, Name);
			return SUCCESS;
		}
	}
	return FAILURE;
}

/*************************************************************************
Function name	: StArray::addEE_Course()
Description		: creates new EE Course and adds it to the student in the array
Paramerters		: stID - student number, courseNum - course number, 
	courseName - course name, numOfHmw - homework number, HmwWeight - homework weight
Return value	: Result - SUCCESS if executed successfully, FAILURE otherwise
	(for example, if the student does not exist in the array)
************************************************************************/
Result StArray::addEE_Course(int stID,
	int courseNum,
	char* courseName,
	int numOfHmw,
	double HmwWeight) {
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		if (pStudents_[i] != NULL) {
			if (pStudents_[i]->getID() == stID) {
				EE_Course* peeCourse = new EE_Course(courseNum,
					courseName,
					numOfHmw,
					HmwWeight);
				return pStudents_[i]->addEE_Course(peeCourse);
			}
		}
	}
	return FAILURE;
}

/*************************************************************************
Function name	: StArray::addCS_Course()
Description		: creates new CS Course and adds it to the student in the array
Paramerters		: stID - student number, courseNum - course number, 
	courseName - course name, numOfHmw - number of homework assignment,
	HmwWeight - homework weight, takef - if the homework is valid,
	bookName - course book name
Return value	: Result - SUCCESS if executed successfully, FAILURE otherwise
	(if the student does not exist in the array)
************************************************************************/
Result StArray::addCS_Course(int stID,
	int courseNum,
	char* courseName,
	int numOfHmw,
	double HmwWeight,
	bool takef,
	char* bookName) {
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		if (pStudents_[i] != NULL) {
			if (pStudents_[i]->getID() == stID) {
				CS_Course* pcsCourse = new CS_Course(courseNum,
					courseName,
					numOfHmw,
					HmwWeight,
					takef,
					bookName);
				return pStudents_[i]->addCS_Course(pcsCourse);
			}
		}
	}
	return FAILURE;
}

/*************************************************************************
Function name	: StArray::setHwGrade()
Description		: sets the grade of the homework assignment to the student's course
Paramerters		: stID - student number, courseNum - course number, 
	HwNum - homework number, hmwGrade - homework grade
Return value	: Result - SUCCESS if executed successfully, FAILURE otherwise
	(if the student, or the course or the homework assignment does not exist)
************************************************************************/
Result StArray::setHwGrade(int stID,
	int courseNum,
	int HwNum, // if there is no such HW return Failure
	int HwGrade) {
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		if (pStudents_[i] != NULL) {
			if (pStudents_[i]->getID() == stID) {
				if (pStudents_[i]->getCS_Course(courseNum) != NULL) {
					return pStudents_[i]->getCS_Course(courseNum)->setHwGrade(HwNum, HwGrade);
				}
				else if (pStudents_[i]->getEE_Course(courseNum) != NULL) {
					return pStudents_[i]->getEE_Course(courseNum)->setHwGrade(HwNum, HwGrade);
				}
			}
		}
	}
	return FAILURE;
}

/*************************************************************************
Function name	: StArray::setExamGrade()
Description		: sets the grade of the exam to the student's course
Paramerters		: stID - student number, courseNum - course number, 
	examGrade - exam grade
Return value	: Result - SUCCESS if executed successfully, FAILURE otherwise
	(if the student or the course does not exist)
************************************************************************/
Result StArray::setExamGrade(int stID,
	int courseNum,
	int examGrade) {
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		if (pStudents_[i] != NULL) {
			if (pStudents_[i]->getID() == stID) {
				if (pStudents_[i]->getCS_Course(courseNum) != NULL) {
					return pStudents_[i]->getCS_Course(courseNum)->setExamGrade(examGrade);
				}
				else if (pStudents_[i]->getEE_Course(courseNum) != NULL) {
					return pStudents_[i]->getEE_Course(courseNum)->setExamGrade(examGrade);
				}
			}
		}
	}
	return FAILURE;
}

/*************************************************************************
Function name	: StArray::setExamGrade()
Description		: sets the factor to the grade of all the students, who study the course
Paramerters		: courseNum - course number, factor - factor to the grade
Return value	: Result - SUCCESS if executed successfully, FAILURE otherwise
************************************************************************/
Result StArray::setFactor(int courseNum, int factor) {
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		if (pStudents_[i]->getEE_Course(courseNum) != NULL) {
			pStudents_[i]->getEE_Course(courseNum)->setFactor(factor);
			return SUCCESS;
		}
	}
	return FAILURE;
}

/*************************************************************************
Function name	: StArray::printStudent()
Description		: prints the data of the student from the array by the format:
	SName: student_name
	SID: student_id
	Avg.: average_grade
	
	EE:
	course_number course_name course_grade
	…

	CS courses:
	course_number course_name course_grade
	…

Paramerters		: stID - student number
Return value	: Result - SUCCESS if executed successfully, FAILURE otherwise
	(if the student or the course does not exist)
************************************************************************/
int  StArray::printStudent(int stID) {
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		if (pStudents_[i] != NULL) {
			if (pStudents_[i]->getID() == stID) {
				pStudents_[i]->print();
				return 1;
			}
		}
	}
	return 0;
}

/*************************************************************************
Function name	: StArray::printStudent()
Description		: prints the data of all the students from the array by the format:
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
void  StArray::printAll() {
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		if (pStudents_[i] != NULL) {
			pStudents_[i]->print();
		}
	}
}

/*************************************************************************
Function name	: StArray::resetStArray()
Description		: deletes all the students from the array and frees the memory
Paramerters		: none
Return value	: none
************************************************************************/
void StArray::resetStArray() {
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		if (pStudents_[i] != NULL) {
			delete pStudents_[i];
			pStudents_[i] = NULL;
		}
	}

}
