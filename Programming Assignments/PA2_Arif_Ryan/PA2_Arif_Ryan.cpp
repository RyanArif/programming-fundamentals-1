/******************************
   Ryan Arif
   2/26/2019
   PA2_Arif_Ryan.cpp
   Displays student grade information neatly and organized, but with functions this time.
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

// Global variables
const int NUM_ASSIGNMENTS = 3; //number of assignments the student will be inputting
const int AVERAGE_PRECISION = 1; //What if we're in a competitive school where the top 10 students are all within .1 of each other? They might want to touch this constant.
// Function prototypes
string getName(); //get the name of the student and return it
void getAssignmentNames(string (&assingmentNames)[NUM_ASSIGNMENTS]); //gets the name of three assignments. Pass by reference an array of strings, because in C++ you apparently can't just return an array.
void getAssignmentGrades(string assignmentNames[NUM_ASSIGNMENTS], int (&assignmentGrades)[NUM_ASSIGNMENTS]); //get the grades corresponding to assignment names
double getAverageGrade(int assignmentGrades[NUM_ASSIGNMENTS]); //return the average of the grades
void gradeTable(string studentName, string assignmentNames[NUM_ASSIGNMENTS], int assignmentGrades[NUM_ASSIGNMENTS], double averageGrade); //make the table

//function declarations

int main()
{
	//variables
	string studentName;				 //name of the student
	string assignmentNames[NUM_ASSIGNMENTS];	 //array of the names of assignments, size is # of assignments
	int assignmentGrades[NUM_ASSIGNMENTS];		 //array of grades, size is the number of assignments
	double averageGrade;			//this will store our computation of the average grade later. Initialize it to 0 if you want to uncomment and use the for loops.

	//get the name of the student and assign it to a string variable
	studentName = getName();
	//pass by reference an array of strings to become the names of the assignments
	getAssignmentNames(assignmentNames);
	//pass by reference an array of integers to become the grades of some assignmentNames
	getAssignmentGrades(assignmentNames, assignmentGrades);
	//compute the average of the assignments and store it as a double
	averageGrade = getAverageGrade(assignmentGrades);
	//make the table.
	gradeTable(studentName, assignmentNames, assignmentGrades, averageGrade);
	//	Make sure we place the end message on a new line
	cout << endl;

	//	The following is system dependent.  It will only work on Windows
	//	I'm on Linux. Just gonna use that other method so I can actually do things.
	//	system("PAUSE");

	// A non-system dependent method is below.
	cout << "Press ENTER to continue";
	cin.get();

  return 0;
}

//take in information from the user to get their name, and return it as a string.
string getName()
{
	string studentName;
	cout << "Please enter your name: ";
	getline(cin, studentName);
	return studentName;
}

//get the names of the assignments from the user
void getAssignmentNames(string (&assignmentNames)[NUM_ASSIGNMENTS])
{
	cout << "Name of Assignment 1: "; //get the names of the three assignments and store them in the array
	getline (cin, assignmentNames[0]);
	cout << "Name of Assignment 2: ";
	getline (cin, assignmentNames[1]);
	cout << "Name of Assignment 3: ";
	getline (cin, assignmentNames[2]);
}

//get the grades of each of the assignments, taking in some array of assignment names
void getAssignmentGrades(string assignmentNames[NUM_ASSIGNMENTS], int (&assignmentGrades)[NUM_ASSIGNMENTS])
{
	cout << "Grade on " << assignmentNames[0] << ": "; //get the integer grades from the user
	cin >> assignmentGrades[0];
	cout << "Grade on " << assignmentNames[1] << ": ";
	cin >> assignmentGrades[1];
	cout << "Grade on " << assignmentNames[2] << ": ";
	cin >> assignmentGrades[2];
	cin.ignore(); //burn the whitespace from the last cin statement
}

//return a double to get the value of the students average grade, taking in some array of integers representing their grades
double getAverageGrade(int assignmentGrades[NUM_ASSIGNMENTS])
{
	//Do computation to get average. Must cast one thing as a double for the rest of the statement to force double division and display a double as the output, rather than a truncated integer
	return ( assignmentGrades[0] + assignmentGrades[1] + assignmentGrades[2] ) / static_cast<double>(NUM_ASSIGNMENTS);
}

//draw the rest of the owl -- make the table, taking in all previous information.
void gradeTable(string studentName, string assignmentNames[NUM_ASSIGNMENTS], int assignmentGrades[NUM_ASSIGNMENTS], double averageGrade)
{
	//set the precision, and begin our table!
	cout << fixed << setprecision(AVERAGE_PRECISION); //AVERAGE_PRECISION amount past the decimal
	cout << endl << "The average grade for " << studentName << " is " << averageGrade << endl; //Displays the average of the grades
	cout << endl << "Grades: " << endl;
	//let's start up a neat table (code taken from the solution of last assignment)
	cout << setw(30) << assignmentNames[0] << ": " << setw(4) << assignmentGrades[0] << endl;
	cout << setw(30) << assignmentNames[1] << ": " << setw(4) << assignmentGrades[1] << endl;
	cout << setw(30) << assignmentNames[2] << ": " << setw(4) << assignmentGrades[2] << endl;

}
