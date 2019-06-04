#include "EE_Course.h"


//class EE_Course : public Course {
//public:
//	EE_Course(int courseNum, char* courseName, int numOfHmw, double hmwWeight);
//	static int getFactor() { return factor_; }
//	static int setFactor(int factor) { factor_ = factor; }
//	int getCourseGrade();
//private:
//	static int factor_;
//};

//initialize factor to 0 for all students:
int EE_Course::factor_ = 0;

EE_Course::EE_Course(int courseNum, char* courseName, int numOfHmw, double hmwWeight):
	Course(courseNum, courseName,numOfHmw, hmwWeight){}

/*course_grade = round( (1 – hw_weight)*exam_grade +
hw_weigh*hw_average) + factor*/
int EE_Course::getCourseGrade() {
	int grade = Course::getCourseGrade() + factor_;
	if (grade > 100) {
		grade = 100;
	}
	return grade;
}


