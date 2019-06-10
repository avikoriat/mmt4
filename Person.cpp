
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Person.h"
using std::cerr;
using std::endl;

//constructor
Person::Person(int id, char* name) :
	id_(id)
{
	if (name == NULL) {//input check
		cerr << "Person constructor error: parameter Name is a NULL pointer" << endl;
		exit(1);
	}
	name_ = new char[strlen(name) + 1];
	strcpy(name_, name);
}

//destructor
Person::~Person()
{
	delete[] name_;
}

/*************************************************************************
Function name	: Person::getName()
Description		: returns a new allocated string that contains the name 
				of the person
Paramerters		: none
Return value	: char* - a pointer to an array of the string
************************************************************************/
char* Person::getName() {
	char* name = new char[strlen(name_) + 1];
	strcpy(name, name_);
	return name;
}

