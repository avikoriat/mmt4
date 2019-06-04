
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Person.h"
using std::cerr;
using std::endl;


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


Person::~Person()
{
	delete[] name_;
}

char* Person::getName() {
	char* name = new char[strlen(name_) + 1];
	strcpy(name, name_);
	return name;
}

