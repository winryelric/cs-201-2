#include "School.h"

School::School() {
	stuNo = 0;
	stu = NULL;
}

School::~School() {
	if (stu != NULL) delete[] stu;
}

void School::addStudent(const int newId, const double newGPA) {
	Student s(newId, newGPA);
	if (stuNo == 0) {
		stu = new Student[1];
		stu[0] = s;
		stuNo++;
	}
	else if ( getIndex(newId) == -1 ) {
		Student* temp = stu;
		stu = new Student[stuNo + 1];
		for (int i = 0; i < stuNo; i++)
			stu[i] = temp[i];
		stu[stuNo] = s;
		stuNo++;
		delete[] temp;
	}
}

unsigned int School::getStudents(Student*& allStudents, unsigned int& noOfStudents)
{
	allStudents = new Student[stuNo];
	for (int i = 0; i < stuNo; i++)
		allStudents[i] = stu[i];
	noOfStudents = stuNo;
	return 0;
}

int School::getIndex(const int id) {
	for (int i = 0; i < stuNo; i++) {
		if (stu[i].getId() == id)
			return i;
	}
	return -1;
}