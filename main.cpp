#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"
#include <iomanip>
using namespace std;

int main() {
	//printing out course name and WGU student info
	cout << " C867 - SCRIPTING AND PROGRAMMING - APPLICATIONS" << endl;
	cout << " C++ Programming Language" << endl;
	cout << " WGU Student ID: 010388223" << endl;
	cout << " Loc Nguyen" << endl;
	// creating an instance of the class Roster
	Roster classRoster;
	// parse data from student data and add students to the classRoster
	string studentData[] = {
		"A1,John,Smith,John1989@gm al.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Loc,Nguyen,lngu242@wgu.edu,24,10,38,20,SOFTWARE",
	};
	for (int i = 0; i < 5; i++) {
		classRoster.parse(studentData[i]);
	}
	// print out the classRoster
	classRoster.printAll();
	cout << "\n\n";
	//print invalid emails
	cout << "List of Invalid Email Addresses: " << endl;
	classRoster.printInvalidEmails();
	cout << "\n";
	//print average days taken for each student
	cout << "Average Days In Courses for each student: " << endl;
	for (int i = 0; i < 5; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	cout << "\n";
	//print by degree program
	cout << "Students by Degree Program SOFTWARE: " << endl;
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << "\n\n";
	//remove student id A3
	classRoster.remove("A3");
	cout << "\n";
	//print all again
	classRoster.printAll();
	cout << "\n\n";
	//remove student id A3 again
	classRoster.remove("A3");

	//destructor
	classRoster.~Roster();
	
}
	