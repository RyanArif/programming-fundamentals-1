/******************************
Ryan Arif
2/19/2019
Arif_Ryan_Lab3.cpp
Take the year some peeps were born and display their names and ages. Neat!
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

const int NUM_MEMBERS = 3;	// number of members
const int CURRENT_YEAR = 2019; // I didn't like not being able to change the current year easily, so I made it easy. 
// Write your three function prototypes here
void printHeading(string heading); //print the heading to console. pass in the heading from somewhere else
int yearToAge(int currentYear, int birthYear); //returns the difference in currentyear and birth year
void printTable(string names[], int birthYears[], int size); //prints the actual table we'll be using

int main()
{
	string familyMembers[NUM_MEMBERS]{ "Dad", "Mom", "Daughter" };	// family members
	int yearBorn[NUM_MEMBERS]{ 1983, 1986, 2010 };					// year each family member was born

	// call printTable, make sure you pass in familyMembers, yearBorn, and NUM_MEMBERS
	printTable(familyMembers, yearBorn, NUM_MEMBERS);

	cout << endl;
	//wasn't in class today, so I can't use this. On linux :D
	//system("PAUSE");
	cout << "Press ENTER to continue.";
	cin.get();
	return 0;
}

// Place your function definition here

void printHeading(string heading)
{
	//just print the heading into the console
	cout << heading << endl;
}

int yearToAge(int currentYear, int birthYear)
{
	//Do I need to store it as an int? No. Does it make it easier to read? Yes. 
	int difference = currentYear - birthYear; //calculates the difference between the currentYear and birthYear
	return difference; //return the difference
}

void printTable(string names[], int birthYears[], int size)
{
	//create the ostringstream
	ostringstream ss;
	//let's build a table!
	ss << setw(14) << left << "Family Member" << setw(7) << right << "Age";
	//let's figure out what the heading should say...
	printHeading(ss.str());
	//alright here's the rest of the table
	cout << setw(14) << left << names[0] << setw(7) << right << yearToAge(CURRENT_YEAR, birthYears[0]) << endl;
	cout << setw(14) << left << names[1] << setw(7) << right << yearToAge(CURRENT_YEAR, birthYears[1]) << endl;
	cout << setw(14) << left << names[2] << setw(7) << right << yearToAge(CURRENT_YEAR, birthYears[2]) << endl;
}


