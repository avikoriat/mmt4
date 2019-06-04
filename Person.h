#ifndef PERSON_H
#define PERSON_H
class Person
{
public:
	Person(int id, char* name);
	~Person();
	int getID() { return id_; }
	char* getName();
private:
	int id_;
	char* name_;
};
#endif
