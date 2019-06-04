  #ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS

#include "Proj.h"
#include "StArray.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

int main() {


	///// parser //////////////////////
  char szLine[MAX_LINE_SIZE];
  const char* delimiters = " \t\n\r";
  char* pszCommand;
  bool res;

  StArray studentArray;

  /*
  * Keep reading the next input line until we reach EOF
  */
  while (fgets(szLine, MAX_LINE_SIZE, stdin))
  {
	  pszCommand = strtok(szLine, delimiters);

	  // Blank line 
	  if (NULL == pszCommand )
	  {
		  continue;
	  }

	  // Add_Student command
	  if (0 == strcmp(pszCommand, "Add_Student"))
	  {
		  int stID = atoi(strtok(NULL, delimiters));
		  char* stName = strtok(NULL, delimiters);

		  res = studentArray.addStudent(stID, stName);
		  if (!res)
			  cout << "Failed: Add_Student" << endl;
	  }

	  // Add_EE_Course command
	  else if (0 == strcmp(pszCommand, "Add_EE_Course"))
	  {
		  int stID = atoi(strtok(NULL, delimiters));
		  int courseNum = atoi(strtok(NULL, delimiters));
		  char* courseName = strtok(NULL, delimiters);
		  int hwNum = atoi(strtok(NULL, delimiters));
		  double hwWeigh = atof(strtok(NULL, delimiters));

		  res = studentArray.addEE_Course(stID, courseNum, courseName, hwNum, hwWeigh);
		  if (!res)
			  cout << "Failed: Add_EE_Course" << endl;
	  }

	  // Add_CS_Course command
	  else if (0 == strcmp(pszCommand, "Add_CS_Course"))
	  {
		  int stID = atoi(strtok(NULL, delimiters));
		  int courseNum = atoi(strtok(NULL, delimiters));
		  char* courseName = strtok(NULL, delimiters);
		  int hwNum = atoi(strtok(NULL, delimiters));
		  double hwWeigh = atof(strtok(NULL, delimiters));
		  bool takef = (atoi(strtok(NULL, delimiters)) > 0);
		  char* bookName = strtok(NULL, delimiters);

		  res = studentArray.addCS_Course(stID, courseNum, courseName, hwNum, hwWeigh, takef, bookName);
		  if (!res)
			  cout << "Failed: Add_CS_Course" << endl;
	  }

	  // Set_HW_Grade command
	  else if (0 == strcmp(pszCommand, "Set_HW_Grade"))
	  {
		  int stID = atoi(strtok(NULL, delimiters));
		  int courseNum = atoi(strtok(NULL, delimiters));
		  int hwNum = atoi(strtok(NULL, delimiters));
		  int hwGrade = atoi(strtok(NULL, delimiters));

		  res = studentArray.setHwGrade(stID, courseNum, hwNum, hwGrade);
		  if (!res)
			  cout << "Failed: Set_HW_Grage" << endl;
	  }

	  // Set_Exam_Grade command
	  else if (0 == strcmp(pszCommand, "Set_Exam_Grade"))
	  {
		  int stID = atoi(strtok(NULL, delimiters));
		  int courseNum = atoi(strtok(NULL, delimiters));
		  int examGrade = atoi(strtok(NULL, delimiters));

		  res = studentArray.setExamGrade(stID, courseNum, examGrade);
		  if (!res)
			  cout << "Failed: Set_Exam_Grade" << endl;
	  }

	  // Set_Factor command
	  else if (0 == strcmp(pszCommand, "Set_Factor"))
	  {
		  int courseNum = atoi(strtok(NULL, delimiters));
		  int factor = atoi(strtok(NULL, delimiters));

		  res = studentArray.setFactor(courseNum, factor);
		  if (!res)
			  cout << "Failed: Set_Factor" << endl;
	  }

	  // Print_Student command
	  else if (0 == strcmp(pszCommand, "Print_Student"))
	  {
		  int stID = atoi(strtok(NULL, delimiters));

		  //cout << "Printing student" << endl;
		  //cout << "================" << endl;
		  res = studentArray.printStudent(stID);
		  if (!res)
			  cout << "Failed: Print_Student" << endl; 
	  }

	  // Print_All command
	  else if (0 == strcmp(pszCommand, "Print_All"))
	  {
		  //cout << "Prining all students" << endl;
		  //cout << "####################" << endl;
		  studentArray.printAll();
	  }

	  // Reset command
	  else if (0 == strcmp(pszCommand, "Reset"))
		  studentArray.resetStArray();

	  // Exit command
	  else if (0 == strcmp(pszCommand, "Exit"))
		  return 0;
  }

  return 0;
}

