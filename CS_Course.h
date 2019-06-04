#pragma once
#include "Course.h"


class CS_Course : public Course {
public:
	CS_Course(int courseNum,
		char* courseName,
		int numOfHmw,
		double hmwWeight,
		bool takef,
		char* courseBook);
	~CS_Course();
	bool isTakef() { return takef_; }
	char* getBook();
	bool setTakef(bool takef) { takef_ = takef; return true; }
	void setBook(char* bookName);
	int getCourseGrade();
private:
	bool takef_;
	char* courseBook_;
};
