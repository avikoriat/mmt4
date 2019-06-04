#ifndef COURSE_H
#define COURSE_H

typedef enum { FAILURE, SUCCESS } Result;

class Course {
public:
	Course(int courseNum, char* courseName, int numOfHmw, double hmwWeight);
	~Course();
	int getNum() { return courseNum_; }
	char* getName();
	int getExamGrade() { return examGrade_; }
	int getHwGrade(int hmwNum);
	int getHwNum() { return numOfHmw_; }
	double getHwWeight() { return hmwWeight_; }
	double getHwAverage();
	int getCourseGrade();
	Result setExamGrade(int examGrade);
	Result setHwGrade(int hmwNum, int hmwGrade);
private:
	int courseNum_;
	char* courseName_;
	int numOfHmw_;
	double hmwWeight_;
	int examGrade_;
	int* hmwGrades_;
}; 
#endif // !COURSE_H_