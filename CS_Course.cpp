
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Proj.h"
#include "CS_Course.h"

using std::cerr;
using std::endl;

CS_Course::CS_Course(int courseNum,
	char* courseName,
	int numOfHmw,
	double hmwWeight,
	bool takef,
	char* courseBook) :
	Course(courseNum, courseName, numOfHmw, hmwWeight), takef_(takef) {
		if (courseBook == NULL) {//input check
			cerr << "CS_Course constructor error: parameter courseBook is a NULL pointer" << endl;
			exit(1);
		}
		courseBook_ = new char[strlen(courseBook) + 1];
		strcpy(courseBook_, courseBook);
}

CS_Course::~CS_Course() {
	delete[] courseBook_;
}

char* CS_Course::getBook() {
	char* name = new char[strlen(courseBook_) + 1];
	strcpy(name, courseBook_);
	return name;
}

void CS_Course::setBook(char* bookName) {
	if (bookName == NULL) {//input check
		cerr << "CS_Course constructor error: parameter courseBook is a NULL pointer" << endl;
		exit(1);
	}
	if (courseBook_ != NULL) {
		delete[] courseBook_;
	}
	courseBook_ = new char[strlen(bookName) + 1];
	strcpy(courseBook_, bookName);
}

static int max(int x, int y) {
	return x > y ? x : y;
}

int CS_Course::getCourseGrade() {
	int gradeWeightedWithHw = Course::getCourseGrade();
	if (!takef_) {
		return max(gradeWeightedWithHw, getExamGrade());
	}
	return gradeWeightedWithHw;
}