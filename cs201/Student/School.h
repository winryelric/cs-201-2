#ifndef __SCHOOL_H_
#define __SCHOOL_H_

#include "Student.h"

class School {
public:
	School();
	~School();
	void addStudent(const int newId, const double newGPA);
	unsigned int getStudents( Student*& allStudents, unsigned int& noOfStudents);
	int getIndex(const int newId);
private:
	int stuNo;
	Student* stu;
};
#endif
