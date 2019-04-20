/******************************
   Ryan Arif
   2/07/2019
   PA1_Arif_Ryan.cpp
   Displays student grade information neatly and organized
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
// Function declarations

int main()
{
	//variables
	string studentName;				 //name of the student
	string assignmentNames[NUM_ASSIGNMENTS];	 //array of the names of assignments, size is # of assignments
	int assignmentGrades[NUM_ASSIGNMENTS];		 //array of grades, size is the number of assignments
	double averageGrade;			//this will store our computation of the average grade later. Initialize it to 0 if you want to uncomment and use the for loops.
	int firstColumnWidth = 30;			 //let's us change the column widths if we need to.
	int secondColumnWidth = 10;			 //second verse same as the first.

	//input starts here
	cout << "Name? ";
	getline(cin, studentName); //let's get the student's name and store it in studentName

	cout << "Name of Assignment 1: "; //let's get the names of the three assignments and store them in the array
	getline (cin, assignmentNames[0]);
	cout << "Name of Assignment 2: ";
	getline (cin, assignmentNames[1]);
	cout << "Name of Assignment 3: ";
	getline (cin, assignmentNames[2]);

	cout << "Grade on " << assignmentNames[0] << ": "; //get the integer grades from the user
	cin >> assignmentGrades[0];
	cout << "Grade on " << assignmentNames[1] << ": ";
	cin >> assignmentGrades[1];
	cout << "Grade on " << assignmentNames[2] << ": ";
	cin >> assignmentGrades[2];
	cin.ignore(); //burn the whitespace from the last cin statement to make our pause work
	averageGrade =( assignmentGrades[0] + assignmentGrades[1] + assignmentGrades[2] ) / NUM_ASSIGNMENTS; //compute the average of the 3 grades
	//Now let's go ahead and begin our output, since we've completed the info.
	cout << fixed << setprecision(AVERAGE_PRECISION); //AVERAGE_PRECISION amount past the decimal
	cout << endl << "Grades: " << endl;
	//let's start up a neat table
	cout << setw(firstColumnWidth) << right << assignmentNames[0] << ": "; //make this column firstColumnWidth long, right align, and display the assignment name
	cout << setw(secondColumnWidth) << left << assignmentGrades[0] << endl; //make the second column secondColumnWidth long, and left align. Show the grades here
	cout << setw(firstColumnWidth) << right << assignmentNames[1] << ": ";
	cout << setw(secondColumnWidth) << left << assignmentGrades[1] << endl;
	cout << setw(firstColumnWidth) << right << assignmentNames[2] << ": ";
	cout << setw(secondColumnWidth) << left << assignmentGrades[2] << endl;

/* Gonna keep the for loops commented out.
	for (int i = 0; i < NUM_ASSIGNMENTS; i++) //Start the loop. Will repeat NUM_ASSIGNMENTS times.
	{
		cout << "Assignment " << i+1 << "'s Name: ";	 //we need to do i+1 because user doesn't have 0th assignment
		getline(cin, assignmentNames[i]);		//Get data from user, put in i'th place of the array
		cout << "Grade: ";				//second verse same as the first
		cin >> assignmentGrades[i];
		cin.ignore();					 //ignore the \n from the cin statement above
		averageGrade += assignmentGrades[i]; //We're gonna store the grade info during the loop
	}
	averageGrade = averageGrade / NUM_ASSIGNMENTS; //Now we'll do the actual computationn to get the actual average grade/
	//output starts here
	cout << fixed << setprecision(AVERAGE_PRECISION); //let's lower the precision to AVERGE_PRECISION amount. 
	cout << endl << "Grades: " << endl;

	//start up another for loop to output information to the user.
	for (int i =0; i < NUM_ASSIGNMENTS; i++) //just like before, let's run through a loop NUM_ASSIGNMENTS times.
	{ 
		cout << setw(firstColumnWidth) << right; //Make our collumn with words be some amount width and right alligned
		cout << assignmentNames[i] << ": "; //outputs the i'th assignment name
		cout << setw(secondColumnWidth) << left; //make the 2nd column smaller, and alligned differently
		cout << assignmentGrades[i] << endl; //outputs the i'th grade
	}
*/

	cout << endl << "The average grade for " << studentName << " is " << averageGrade << endl; //Displays the average of the grades

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
