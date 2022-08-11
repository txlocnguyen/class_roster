#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
#include <iomanip>
#ifndef roster_h
#define roster_h
#include <stdio.h>
class Roster {
public:
	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	//parse
	void parse(string studentData);
	//add or remove student from roster
	
	void add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	//print student datas
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	//constructor destructor
	Roster();
	~Roster();
};
#endif