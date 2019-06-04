#ifndef EE_COURSE_H
#define EE_COURSE_H
#include "Course.h"

class EE_Course: public Course{
public:
	EE_Course(int courseNum, char* courseName, int numOfHmw, double hmwWeight);
	static int getFactor() { return factor_; }
	static int setFactor(int factor) { factor_ = factor; return 1; }
	int getCourseGrade();
private:
	static int factor_;
};

#endif