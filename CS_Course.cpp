
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Proj.h"
#include "CS_Course.h"

using std::cerr;
using std::endl;

//constructor
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

//destructor
CS_Course::~CS_Course() {
	delete[] courseBook_;
}

/*************************************************************************
Function name	: CS_Course::getBook()
Description		: allocates a new string containing the name of the course book 
	and returns	a pointer to it
Paramerters		: none
Return value	: char* - a pointer to an array of the string
************************************************************************/
char* CS_Course::getBook() {
	char* name = new char[strlen(courseBook_) + 1];
	strcpy(name, courseBook_);
	return name;
}

/*************************************************************************
Function name	: CS_Course::getBook()
Description		:sets the name of course book to be 'bookName'
Paramerters		: bookName - a string containing the course-book name
Return value	: none
************************************************************************/
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
/*************************************************************************
Function name	: max
Description		: returns the maximum between to numbers
Paramerters		: x , y - two integers
Return value	: int - the maximum
************************************************************************/
static int max(int x, int y) {
	return x > y ? x : y;
}

/*************************************************************************
Function name	: CS_Course::getCourseGrade()
Description		: returns the weighted grade of the course
Paramerters		: none
Return value	: int - the grade
************************************************************************/
int CS_Course::getCourseGrade() {
	int gradeWeightedWithHw = Course::getCourseGrade();
	if (!takef_) {
		return max(gradeWeightedWithHw, getExamGrade());
	}
	return gradeWeightedWithHw;
}