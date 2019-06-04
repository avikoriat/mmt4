#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "StArray.h"

using std::cout;
using std::cerr;
using std::endl;

StArray::StArray() : StudentCnt_(0)
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		pStudents_[i] = NULL;
	}
}

StArray::~StArray()
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		delete pStudents_[i];
	}
}

Result StArray::addStudent(int stID, char* Name) {
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		if (pStudents_[i] == NULL) {
			pStudents_[i] =  new Student(stID, Name);
			return SUCCESS;
		}
	}
	return FAILURE;
}

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

Result StArray::setFactor(int courseNum, int factor) {
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		if (pStudents_[i]->getEE_Course(courseNum) != NULL) {
			pStudents_[i]->getEE_Course(courseNum)->setFactor(factor);
			return SUCCESS;
		}
	}
	return FAILURE;
}

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

void  StArray::printAll() {
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		if (pStudents_[i] != NULL) {
			pStudents_[i]->print();
		}
	}
}

void StArray::resetStArray() {
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		if (pStudents_[i] != NULL) {
			delete pStudents_[i];
			pStudents_[i] = NULL;
		}
	}

}
