#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <string>
using namespace std;
#include <iostream>
class Student {
public:
	Student(const int sId = 0, const double sGPA = 0.0);
	double getGPA() const;
	int getId() const;
	void setGPA(const double g);
	void setId(const int i);
private:
	int id;
	double gpa;
};
#endif