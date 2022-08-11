#include <iostream>
#include <vector>
#include "student.h"
#include "degree.h"
#include <string>
#include <iomanip>
using namespace std;
//getter
string Student::getStudentID() {
	return studentID;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
string Student::getEmail() {
	return email;
}
int Student::getAge() {
	return age;
}
int* Student::getNumOfDaysToComplete(){
	return numOfDaysToComplete;
}
DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}
//setter
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmail(string email) {
	this->email = email;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setNumOfDaysToComplete(int* numOfDaysToComplete) {
	for (int i = 0; i < 3; i++) {
		this->numOfDaysToComplete[i] = numOfDaysToComplete[i];
	}
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}
//constructor
Student::Student(string studentID, string firstName, string lastName, string email, int age, int numOfDaysToComplete[3], DegreeProgram degreeProgram) {
	setStudentID(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmail(email);
	setAge(age);
	setNumOfDaysToComplete(numOfDaysToComplete);
	setDegreeProgram(degreeProgram);
}
//print
void Student::print() {
	cout << "\nStudent ID: " << getStudentID();
	cout << "\tFirst Name: " << getFirstName();
	cout << "\tLast Name: " << getLastName();
	cout << "\tEmail: " << getEmail();
	cout << "\tAge: " << getAge();
	cout << "\tDays to Complete Degree: " << getNumOfDaysToComplete()[0] << ", " << getNumOfDaysToComplete()[1] << ", " << getNumOfDaysToComplete()[2];
	string nameOfDegreeProgram;
	switch (getDegreeProgram()) {
		case DegreeProgram::NETWORK:
			nameOfDegreeProgram = "NETWORK";
			break;
		case DegreeProgram::SOFTWARE:
			nameOfDegreeProgram = "SOFTWARE";
			break;
		case DegreeProgram::SECURITY:
			nameOfDegreeProgram = "SECURITY";
			break;
		default:
			nameOfDegreeProgram = "ERROR";
			break;
	}
	cout << "\tDegree Program: " << nameOfDegreeProgram;
}
//destructor
Student::~Student(){};