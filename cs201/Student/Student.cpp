#include "Student.h"

Student::Student(const int sId, const double sGPA) {
	id = sId;
	gpa = sGPA;
}
double Student::getGPA() const {return gpa;}
int Student::getId() const {return id;}
void Student::setGPA(const double g) { gpa = g; }
void Student::setId(const int i) { id = i; }
