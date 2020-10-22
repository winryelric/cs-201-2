#include "Student.h"
#include "School.h"

void getHonorList(const Student* stuList, const unsigned int sSize, Student*& honorList, unsigned int& hSize) {
	hSize = 0;
	for (int i = 0; i < sSize; i++) {
		if (stuList[i].getGPA() >= 3.0) 
			hSize++;
	}
	if (hSize == 0)
		honorList = NULL;
	else {
		unsigned int hIndex = 0;
		honorList = new Student[hSize];
		for (int i = 0; i < sSize; i++) {
			if (stuList[i].getGPA() >= 3.0) {
				honorList[hIndex] = stuList[i];
				hIndex++;
			}
		}
	}
}

void dismiss(Student** stuList, unsigned int* size, const unsigned int index) {
	if ((*size) == 1 && index == 0) {
		delete[](*stuList);
		(*stuList) = NULL;
		(*size) = 0;
	}
	else if ((*size) > 1) {
		Student* temp = (*stuList);
		(*stuList) = new Student[(*size) - 1];
		for (int i = 0; i < index; i++)
			(*stuList)[i] = temp[i];
		for (int i = index + 1; i < (*size); i++)
			(*stuList)[i - 1] = temp[i];
		(*size)--;
		delete[] temp;
	}
}

int main() {
	School s;
	s.addStudent(10, 1.7);
	s.addStudent(20, 2.3);
	s.addStudent(30, 3.7);
	s.addStudent(40, 2.90);
	s.addStudent(50, 3.10);
	s.addStudent(60, 3.2);
	Student *honorList, *allStudents;
	unsigned int hSize = 0, lSize = 0;
	s.getStudents(allStudents, lSize);
	for (int i = 0; i < lSize; i++)
		cout << allStudents[i].getId() << endl;
	cout << endl;
	getHonorList(allStudents, lSize, honorList, hSize);
	for ( int i = 0; i < hSize; i++)
		cout << honorList[i].getId() << endl;
	cout << endl;
	Student** allStudentsPtr = &allStudents;
	unsigned int* lSizePtr = &lSize;
	dismiss(allStudentsPtr, lSizePtr, 4);
	for (int i = 0; i < lSize; i++)
		cout << allStudents[i].getId() << endl;
	return 0;
}