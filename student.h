// Student class header file
#include <iostream>
#include <vector>
#include <string>
#include "degree.h"
#include <iomanip>
#ifndef STUDENT_H
#define STUDENT_H
using std::string;

class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int numOfDaysToComplete[3];
	DegreeProgram degreeProgram;
public:
	//constructor
	Student();
	Student(string studentID, string firstName, string lastName, string email, int age, int numOfDaysToComplete[3], DegreeProgram degreeProgram);
	//getter
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getNumOfDaysToComplete();
	DegreeProgram getDegreeProgram();
	//setter
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setNumOfDaysToComplete(int numOfDaysToComplete[3]);
	void setDegreeProgram(DegreeProgram degreeProgram);
	//print student info
	void print();
	//destructor
	~Student();
};
#endif