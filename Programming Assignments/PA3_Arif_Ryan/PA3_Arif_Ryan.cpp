/******************************
   Ryan Arif
   4/13/2019
   PA3_Arif_Ryan.cpp
   Takes a list of names & grades from a file, then processes them to display
	 the average, min/max grade in both numerical and letter grade
********************************/

// Headers
#include <iostream>		// cout, cin
#include <cstdlib>		// exit()
#include <string>		// strings
#include <fstream>		// file processing
#include <iomanip>		// stream manipulation
using namespace std;

// Global variables
const int MAX_STUDENTS = 25;	// We will not process more than 25 students even if the file contains more
const int MAX_GRADES = 5;		// Each student has exactly 5 grades
const string FILENAME = "NamesGrades.txt";	// The name of the file that you will read

// Function declarations
int loadStudentNamesGrades(string students[], int grades[][MAX_GRADES], string fileName, int maxStudents);
void displayAverages(string students[], int grades[][MAX_GRADES], int studentCount);
void displayMax(string students[], int grades[][MAX_GRADES], int studentCount);
void displayMin(string students[], int grades[][MAX_GRADES], int studentCount);
char getLetterGrade(double grade);
int getLongestNameLength(string students[], int studentCount);
int displayHeading(string reportTitle, string secondColumnName, int secondColumnWidth, 
					int thirdColumnWidth, string students[], int studentCount);
void linuxFriendlyPause();

int main()
{
	// You will need some variables here
	char choice;	//store the users choice made in the menu
	string students[MAX_STUDENTS];	//array of (at most) MAX_STUDENTS students
	int grades[MAX_STUDENTS][MAX_GRADES];	//array of grades. Each row is a new student, each column is a grade.
	int studentCount = 0;			//keep track of the number of students
	// You need one to keep up with the actual number of students
	// You need and array of strings for the student names
	// You need a two dimensional arry for the grades of the students
	// You need a variable to hold the choice of the user for the menu


    // Get students and grades
	//passing in the address of these arrays so they can be directly modified by this function
	try{
	studentCount = loadStudentNamesGrades(students, grades,FILENAME, MAX_STUDENTS);
	} catch (const char* errorMsg){
		cout << errorMsg << endl;
		linuxFriendlyPause();
		exit(EXIT_FAILURE);
	}

    // Loop until user says to quit'
		do{
    	// present menu and get user's choice
			cout << "Grade Report" << endl;
			cout << "\t1. Display Average Grade" << endl
					<< "\t2. Display Maximum Grade" << endl
					<< "\t3. Display Minimum Grade" << endl
					<< "\t4. Quit" << endl;
			cout << "Enter your choice (1-4): ";
			cin >> choice;
			while(getchar() != '\n');	//flush the toilet

		// Process the choice
		switch (choice) {
		case '1' : //average
			displayAverages(students, grades, studentCount);
			break;

		case '2' : //maximum
			displayMax(students, grades, studentCount);
			break;

		case '3' : //minimum
			displayMin(students, grades, studentCount);
			break;

		case '4' : // quit
			break;
		
		default : 
			cout << "Please try again. Select an option between 1-4.\n\n";

		}	//end of switch

		if (choice != '4'){
			cout << endl;
			linuxFriendlyPause();
			//I'm a linux user, I hate doing anything that requires a specific OS, like SYSTEM("cls")
			//uses escape characters to cleverly clear the screen from "J" (the top) to 2 (the bottom).
			//then, we need to reset the cursor back to row 1, column 1. 
			//https://stackoverflow.com/questions/4062045/clearing-terminal-in-linux-with-c-code
			//Didn't even know you could use escape stuff to do this kinda thing. Really cool stuff!
			cout << "\033[2J\033[1;1H";
		}

	}while(choice != '4');


	// End of program
	//	Make sure we place the end message on a new line
    cout << endl;

	linuxFriendlyPause();

    return 0;
}

/***********************************************************
loadStudentNameGrades opens and read fileName. It will read in two strings, concatenate them, and then save
to the students array. It then reads five integers and save each to the grades array. The function will return
the actual number of student/grade combinations read
PARAM:	students is an array of strings that can hold up ot maxStudents values
		grades is a two dimensional array for holding the grades of each student
		fileName is the name of the file that will be opened and read
		maxStudents is the maximum number of students that we will read from the file
PRE:	students[] is large enough to contain up to maxStudents elements
		grades[] is large enough ot contain up to maxStudents elements
POST:	students[] contains the names of up to maxStudents
		grades[][] contains the grades for up to maxStudents
		The number of student/grade combinations actually read from the file is returned. This value can range
		between 0 <= numStudents <= maxStudents
NOTE:	students[] and grades[] are meant to be parralel arrays. students[0] and grades[0] are the same student
************************************************************/
int loadStudentNamesGrades(string students[], int grades[][MAX_GRADES], string fileName, int maxStudents)
{
	ifstream inFile;			//input file stream
	string studentFirstName,	//first name of student
			studentLastName;	//last name of student
	int numStudents = 0;		//total number of students
	
	//open the file
	inFile.open(fileName);
	if (!inFile) {
		throw "ERROR: File could not be opened.";
	}
	
	//loop through each row of the file
	for (int i = 0; i < maxStudents && (inFile >> studentFirstName >> studentLastName); i++, numStudents++) {
		//combine the month name with the season name
		students[i] = studentFirstName + " " + studentLastName;

		//loop through all the temps of each row
		for (int j = 0; j < MAX_GRADES; j++) {
			inFile >> grades[i][j];
		}
	}

	//close file
	inFile.close();

	//Test
	/*
	for (int i = 0; i < numStudents; i++) {
		cout << students[i] << " ";
		for (int j = 0; j < MAX_GRADES; j++) {
			cout << grades[i][j] << " ";
		}
		cout << endl;
	} 
	*/
	return numStudents;
}

/***********************************************************
displayAverages calculates the average of each student and displays the
students name, average, and letter grade of the average in a table
PARAM:	students[] is an array of strings that contains the names of studentCount students
		grades[] is an array of integers that contains the grades of studentCount students
		studentCount contains the value of the number of elements in the students[] and grades[] arrays
PRE:	students[] and grades[] contain values for studentCount elements
POST:	table of student names, averages, and letter grades is displayed
************************************************************/
void displayAverages(string students[], int grades[][MAX_GRADES], int studentCount)
{
	double average;	//average grade for the student
	int total;		//total of the grades for a student
	int secondColumnWidth = 8;	//width of 2nd column
	int thirdColumnWidth = 10;	//width of 3rd column

	//setup table header
	int maxLength = displayHeading("Average Student Grades", "Averages", secondColumnWidth, thirdColumnWidth, students, studentCount);

	cout << setprecision(1) << fixed << showpoint;
	
	//loop through each student and display a row.
	for (int i = 0; i < studentCount; i++) {
		cout << setw(maxLength + 1) << left << students[i];
		total = 0;
		//loop through the grades of each student
		for (int j = 0; j < MAX_GRADES; j++) {
			total += grades[i][j];
		}
		//calculate the average
		average = static_cast<double>(total) / MAX_GRADES;
		cout << setw(secondColumnWidth) << right << average
			<< setw(thirdColumnWidth ) << getLetterGrade(static_cast<int>(average)) //cast average as an int to ensure teh function works as it
			<< endl;
	}
}

/***********************************************************
displayMax calculates the maximum grade of each student and displays the
students name, maximum grade, and letter grade of the maximum grade in a table
PARAM:	students[] is an array of strings that contains the names of studentCount students
		grades[] is an array of integers that contains the grades of studentCount students
		studentCount contains the value of the number of elements in the students[] and grades[] arrays
PRE:	students[] and grades[] contain values for studentCount elements
POST:	table of student names, maximum grades, and letter grades is displayed
************************************************************/
void displayMax(string students[], int grades[][MAX_GRADES], int studentCount)
{
	int max;	//maximum grade for the student
	int secondColumnWidth = 8;	//width of 2nd column
	int thirdColumnWidth = 10;	//width of 3rd column

	//setup table header
	int maxLength = displayHeading("Maximum Student Grades", "Max", secondColumnWidth, thirdColumnWidth, students, studentCount);

	cout << setprecision(1) << fixed << showpoint;
	
	//loop through each student and display a row.
	for (int i = 0; i < studentCount; i++) {
		cout << setw(maxLength + 1) << left << students[i];
		max = grades[i][0]; //starting highest grade for the given student.
		//loop through the grades of each student
		for (int j = 0; j < MAX_GRADES; j++) {
			if (max < grades[i][j]){
				max = grades[i][j];
			}
		}
		//make the table
		cout << setw(secondColumnWidth) << right << max
			<< setw(thirdColumnWidth ) << getLetterGrade(max) //cast average as an int to ensure teh function works as it
			<< endl;
	}
}

/***********************************************************
displayMin calculates the minimum grade of each student and displays the
students name, minimum grade, and letter grade of the minimum grade in a table
PARAM:	students[] is an array of strings that contains the names of studentCount students
		grades[] is an array of integers that contains the grades of studentCount students
		studentCount contains the value of the number of elements in the students[] and grades[] arrays
PRE:	students[] and grades[] contain values for studentCount elements
POST:	table of student names, minimum grades, and letter grades is displayed
************************************************************/
void displayMin(string students[], int grades[][MAX_GRADES], int studentCount)
{
	int min;	//minimum grade for the student
	int secondColumnWidth = 8;	//width of 2nd column
	int thirdColumnWidth = 10;	//width of 3rd column

	//setup table header
	int maxLength = displayHeading("Minimum Student Grades", "Min", secondColumnWidth, thirdColumnWidth, students, studentCount);

	cout << setprecision(1) << fixed << showpoint;
	
	//loop through each student and display a row.
	for (int i = 0; i < studentCount; i++) {
		cout << setw(maxLength + 1) << left << students[i];
		min = grades[i][0]; //starting lowest grade for the given student.
		//loop through the grades of each student
		for (int j = 0; j < MAX_GRADES; j++) {
			if (grades[i][j] < min){
				min = grades[i][j];
			}
		}
		//make the table
		cout << setw(secondColumnWidth) << right << min
			<< setw(thirdColumnWidth ) << getLetterGrade(min)
			<< endl;
	}
}

/***********************************************************
getLetterGrade converts a numerical grade to a letter grade
PARAM:	grade is the numerical grade to convert. Expected range is 0 <= grade <= 100
PRE:	grade contains a value in the correct range
POST:	The corresponding letter grade of the numerical grade is returned
************************************************************/
char getLetterGrade(double grade)
{
	char letterGrade;	//the final letter grade which will be returned by this function
	//check the range of the grade. Needs to be 0-100, inclusive.
	if (grade <= 100  && grade >= 0){
		//there's probably a better way to do this than a bunch of 'if' statements, 
		//but this will get the job done.
		if (grade >=90)
			letterGrade = 'A';
		else if (grade >= 80)
			letterGrade = 'B';
		else if (grade >= 70)
			letterGrade = 'C';
		else if (grade >= 60)
			letterGrade = 'D';
		else
			letterGrade = 'F';
	} else {
		throw "Invalid numerical grade. Grades must exist between 0 and 100.";
	}
	return letterGrade;
}

/***********************************************************
getLongestNameLength returns the length of the longest string from a list of strings
PARAM:	students[] is an array of strings that contains the name of students
		studentCount is the size of the students[] array
PRE:	students[] contains studentCount names
POST:	The length of the longest string in students[] is returned
************************************************************/
int getLongestNameLength(string students[], int studentCount)
{
	//well, you can't have a name less than 0 characters long
	//so this will work, 100% of the time, and saves one entire array access
	int longestNameLength = students[0].length();
	for (int i = 0; i < studentCount; i++){
		//compare the current longest name to a new challenger, then change it if necessary
		//uhhhh..... idk man, the length of this array element was a long unsigned int
		//stop it. You don't need to be long, or unsigned. >:(
		if (longestNameLength < static_cast<int>(students[i].length())){
			longestNameLength = students[i].length();
		}
	}
	return longestNameLength;
}

/***********************************************************
displayHeading returns the length of the longest string from a list of strings,
and displays a heading for a report.
PARAM:	reportTitle is a string containing the name of the report
		secondColumnName is a string containing the name of the second column
		secondColumnWidth is an integer representing the width of the second column
		thirdColumnWidth is an integer representing the width of the third column
		students is an array of strings containing the first and last names of all students
		studentCount is an integer represetning the total number of students
PRE:	students[] contains studentCount names
POST:	The length of the longest string in students[] is returned
************************************************************/
int displayHeading(string reportTitle, string secondColumnName, int secondColumnWidth, 
					int thirdColumnWidth, string students[], int studentCount)
{
	int maxLength = getLongestNameLength(students, studentCount);	//length of the longest student's name
	//don't let the 3rd Column have too small a width
	if (thirdColumnWidth < 10) {
		thirdColumnWidth = 10;
	}

	cout << "\n\n" << reportTitle << "\n";
	cout << setw(maxLength + 1) << left << "Student"
		<< setw(secondColumnWidth) << right << secondColumnName
		<< setw(thirdColumnWidth) << "Grade" << endl;
	return maxLength;
}

/***********************************************************
linux friendly way of doing SYSTEM("PAUSE")
pauses the terminal until the user presses enter.
PARAM:	none.
PRE:	your code compiles
POST:	your program pauses
************************************************************/
void linuxFriendlyPause()
{
	cout << "Press ENTER to continue";
	while (getchar() != '\n'); //flush
}