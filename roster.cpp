#include <iostream>
#include <string>
#include <regex>
#include "student.h"
#include "degree.h"
#include "roster.h"
#include <iomanip>
using namespace std;
//constructor and destructor
Roster::Roster() {
};
Roster::~Roster() {
	for(int i=0; i<5; i++) {
		delete classRosterArray[i];
	}
}
//add and remove
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int numOfDaysToComplete[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
	Student *newStudent = new Student(studentID, firstName, lastName, emailAddress, age, numOfDaysToComplete, degreeProgram);
	for(int i=0; i<5; i++) {
		if(classRosterArray[i] == nullptr) {
			classRosterArray[i] = newStudent;
			break;
		}
	} 
}
void Roster::remove(string studentID) {
	bool found = false;
	for(int i=0; i<5; i++){
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->getStudentID() == studentID) {
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;
				cout << "Deleted Student with ID " << studentID << endl;
				found = true;
				return;
			}
		}
	}
	cout << "Attempted to delete student with ID " << studentID << ". Student with ID " << studentID << " not found." << endl;
}
//print
void Roster::printAll() {
	for(int i=0; i<5; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
}
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for(int i=0; i<5; i++) {
		if(classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}
void Roster::printAverageDaysInCourse(string studentID) {
	for(int i=0; i<5; i++) {
		if(classRosterArray[i]->getStudentID() == studentID) {
			int course1 = classRosterArray[i]->getNumOfDaysToComplete()[0];
			int course2 = classRosterArray[i]->getNumOfDaysToComplete()[1];
			int course3 = classRosterArray[i]->getNumOfDaysToComplete()[2];
			int avg = (course1+course2+course3)/3;
			cout << "The average number of days in course for student with id " << classRosterArray[i]->getStudentID() << " is: " << avg << endl;
		}
	}
}
void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; ++i) {
		string email = classRosterArray[i]->getEmail();
		if ((email.find(' ') != string::npos) || (email.find('@') == string::npos) || (email.find('.') == string::npos)) {
			cout << email << endl;
		}
	}
}
//parse student data
void Roster::parse(string studentData) {
	regex reg("[,]+");
	sregex_token_iterator s(studentData.begin(), studentData.end(), reg, -1);
	sregex_token_iterator e;
	vector<string> tokens(s, e);
	DegreeProgram degree;
	if (tokens[8] == "SECURITY") {
		degree = DegreeProgram::SECURITY;
	}
	if (tokens[8] == "NETWORK") {
		degree = DegreeProgram::NETWORK;
	}
	if (tokens[8] == "SOFTWARE") {
		degree = DegreeProgram::SOFTWARE;
	}
	Roster::add(tokens.at(0), tokens.at(1), tokens.at(2), tokens.at(3), stoi(tokens.at(4)), stoi(tokens.at(5)), stoi(tokens.at(6)), stoi(tokens.at(7)), degree);
}