#ifndef STUDENT_H
#define STUDENT_H
#include "EE_Course.h"
#include "CS_Course.h"
#include "Person.h"
#include "Proj.h"

class Student: public Person {
public:
	Student(int id, char* name);
	~Student();
	int getCourseCount() { return eeCourseCnt_ + csCourseCnt_; }
	Result addEE_Course(EE_Course* peeCourse);
	Result addCS_Course(CS_Course* pcsCourse);
	Result remCourse(int courseNum);
	EE_Course* getEE_Course(int eeCourseNum);
	CS_Course* getCS_Course(int csCourseNum);
	int getAvg();
	void print();
private:
	EE_Course* peeCourses_[MAX_COURSE_NUM];
	int eeCourseCnt_;
	CS_Course* pcsCourses_[MAX_COURSE_NUM];
	int csCourseCnt_;
};

#endif // !STUDENT_H
