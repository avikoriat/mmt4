#ifndef STARRAY_H
#define STARRAY_H
#include "Proj.h"
#include "Student.h"


class StArray
{
public:
	StArray();
	~StArray();
	Result addStudent(int stID, char* Name);
	Result addEE_Course(int stID,
		int courseNum,
		char* courseName,
		int numOfHmw,
		double HmwWeight);
	Result addCS_Course(int stID,
		int courseNum,
		char* courseName,
		int numOfHmw,
		double HmwWeight,
		bool takef,
		char* bookName);
	Result setHwGrade(int stID,
		int courseNum,
		int HwNum, // if there is no such HW return Failure
		int HwGrade);
	Result setExamGrade(int stID,
		int courseNum,
		int examGrade);
	Result setFactor(int courseNum, int factor);
	int printStudent(int stID);
	void printAll();
	void resetStArray();
private:
	Student* pStudents_[MAX_STUDENT_NUM];
	int StudentCnt_;
};

#endif // !STARRAY_H