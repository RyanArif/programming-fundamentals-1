/******************************
   Ryan Arif
   04/02/2019
   HighTemps.cpp
   Displays average, max, min for high temps of various months
********************************/

// Headers
#include <iostream>	//cout, cin
#include <cstdlib>	//exit, system
#include <string>	//strings, duh
#include <fstream>	//file processing
#include <iomanip>	//text formatting
using namespace std;

// Global variables
const int MAX_MONTHS = 12;	//maximum months we will process
const int MAX_DAYS = 30;	//maximum days per month we will process
const string FILENAME = "HighTemps2014.txt";		//file to process

int main();

// Function declarations
int loadMonthsTemps(string months[], int temps[][MAX_DAYS], string fileName, int maxMonths);
void displayAvgTemp(string months[], int temps[][MAX_DAYS], int monthCount);
void displayMaxTemp(string months[], int temps[][MAX_DAYS], int monthCount);
void displayMinTemp(string months[], int temps[][MAX_DAYS], int monthCount);
string getTempCondition(int temp);
int getLongestNameLength(string months[], int monthCount);
int displayHeading(string reportTitle, string secondColumnName, int secondColumnWidth, int thirdColumnWidth, string months[], int monthCount);

int main()
{
	int monthCount = 0;
	int temps[MAX_MONTHS][MAX_DAYS];
	string months[MAX_MONTHS];
	char choice;

	//get months and temps
	try {
		monthCount = loadMonthsTemps(months, temps, FILENAME, MAX_MONTHS);
	}
	catch (const char* errorMessage) {
		cout << errorMessage << endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
	
	//loop until the user says to quit
	do {
		//present the menu
		cout << "\nTemperature Report Program\n\n";
		cout << "\t1. Display Average Temperature\n"
			<< "\t2. Display Maximum Temperature\n"
			<< "\t3. Display Minimum Temperature\n"
			<< "\t4. Quit Program\n\n";
		cout << "It's time to decide (1-4): ";
		cin >> choice;

		while (getchar() != '\n'); //flush

		//process the choice
		switch (choice) {
		case '1' : //average
			displayAvgTemp(months, temps, monthCount);
			break;

		case '2' : //maximum
			displayMaxTemp(months, temps, monthCount);
			break;

		case '3' : //minimum
			displayMinTemp(months, temps, monthCount);
			break;

		case '4' : // quit
			break;
		
		default : 
			cout << "Dumbass read the fucking instructions, 1-4 nigga HOW YOU PUTTING IN " << choice << "??!?!?\n\n";

		}	//end of switch

		//clean up screen
		if (choice != '4') {
			cout << endl;
			system("PAUSE");
			system("CLS");
		}
		
	} while (choice != '4');
    
	//	Make sure we place the end message on a new line
    cout << endl;

	//	The following is system dependent.  It will only work on Windows
    system("PAUSE");

	/* 
	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();
	*/
    return 0;
}

//load the file contents into months array and temps array
int loadMonthsTemps(string months[], int temps[][MAX_DAYS], string fileName, int maxMonths)
{
	ifstream inFile;	//input file stream
	string monthName,	//name of month
		seasonName;		//name of the season
	int numMonths = 0;	//number of months actually read
	
	//open the file
	inFile.open(fileName);
	if (!inFile) {
		throw "File could not opened.";
	}
	
	//loop through each row of the file
	for (int i = 0; i < maxMonths && (inFile >> monthName >> seasonName); i++, numMonths++) {
		//combine the month name with the season name
		months[i] = monthName + " " + seasonName;

		//loop through all the temps of each row
		for (int j = 0; j < MAX_DAYS; j++) {
			inFile >> temps[i][j];
		}
	}

	//close file
	inFile.close();

	//Test
	/*for (int i = 0; i < numMonths; i++) {
		cout << months[i] << " ";
		for (int j = 0; j < MAX_DAYS; j++) {
			cout << temps[i][j] << " ";
		}
		cout << endl;
	} */

	return numMonths;
}

void displayAvgTemp(string months[], int temps[][MAX_DAYS], int monthCount)
{
	double average;	//average temp of days in a month
	int total;		//total of all temps in month (accumulator)
	int secondColumnWidth = 8;	//width of 2nd column
	int thirdColumnWidth = 10;	//width of 3rd column

	//setup table header
	int maxLength = displayHeading("Temparature Averages", "Averages", secondColumnWidth, thirdColumnWidth, months, monthCount);

	cout << setprecision(1) << fixed << showpoint;
	
	//loop through each month and display a row.
	for (int i = 0; i < monthCount; i++) {
		cout << setw(maxLength + 1) << left << months[i];
		total = 0;
		//loop through temperatures of the month
		for (int j = 0; j < MAX_DAYS; j++) {
			total += temps[i][j];
		}
		//calculate the average
		average = static_cast<double>(total) / MAX_DAYS;
		cout << setw(secondColumnWidth) << right << average
			<< setw(thirdColumnWidth ) << getTempCondition(static_cast<int>(average))
			<< endl;
	}
}

//calculates and displays maximum temperature for each month
void displayMaxTemp(string months[], int temps[][MAX_DAYS], int monthCount)
{
	int maxTemp;	// max temp so far
	int secondColumnWidth = 4;	//second column's width
	int thirdColumnWidth = 10;	//width of the third column

	//setup table header
	int maxLength = displayHeading("Temparature Maximum", "Max", secondColumnWidth, thirdColumnWidth, months, monthCount);

	//loop through each month and display a row.
	for (int i = 0; i < monthCount; i++) {
		cout << setw(maxLength + 1) << left << months[i];
		maxTemp = temps[i][0]; //temperature of the first day
		//loop through temperatures of the month
		for (int j = 1; j < MAX_DAYS; j++) {
			if (temps[i][j] > maxTemp) {
				maxTemp = temps[i][j];
			}
		}
		cout << setw(secondColumnWidth) << right << maxTemp
			<< setw(thirdColumnWidth) << getTempCondition(maxTemp)
			<< endl;
	}
}

void displayMinTemp(string months[], int temps[][MAX_DAYS], int monthCount)
{
	int minTemp;	// max temp so far
	int secondColumnWidth = 4;	//second column's width
	int thirdColumnWidth = 10;	//width of the third column

	//setup table header
	int maxLength = displayHeading("Temparature Minimum", "Min", secondColumnWidth, thirdColumnWidth, months, monthCount);

	//loop through each month and display a row.
	for (int i = 0; i < monthCount; i++) {
		cout << setw(maxLength + 1) << left << months[i];
		minTemp = temps[i][0]; //first temp of the month
		//loop through temperatures of the month
		for (int j = 1; j < MAX_DAYS; j++) {
			if (temps[i][j] < minTemp) {
				minTemp = temps[i][j];
			}
		}
		cout << setw(secondColumnWidth) << right << minTemp
			<< setw(thirdColumnWidth) << getTempCondition(minTemp)
			<< endl;
	}
}

//return a description of the temperature
string getTempCondition(int temp)
{
	if (temp > 110) {
		return "Hell";
	}
	else if (temp > 100) {
		return "Insane";
	}
	else if (temp > 90) {
		return "Hot";
	}
	else if (temp > 80) {
		return "Warm";
	}
	else if (temp > 70) {
		return "Nice";
	}
	else if (temp > 60) {
		return "Cool";
	}
	else {
		return "Cold";
	}
}

//find the longest string in an array of strings
int getLongestNameLength(string months[], int monthCount)
{
	int maxLength = 0;	//max length so far
	for (int i = 0; i < monthCount; i++) {
		//is it longer
		if (months[i].length() > maxLength) {
			maxLength = months[i].length();
		}
	}

	return maxLength;
}

//displays heading for table
int displayHeading(string reportTitle, string secondColumnName, int secondColumnWidth, int thirdColumnWidth, string months[], int monthCount)
{
	int maxLength = getLongestNameLength(months, monthCount);
	if (thirdColumnWidth < 10) {
		thirdColumnWidth = 10;
	}

	cout << "\n\n" << reportTitle << "\n";
	cout << setw(maxLength + 1) << left << "Month"
		<< setw(secondColumnWidth) << right << secondColumnName
		<< setw(thirdColumnWidth) << "Condition" << endl;
	return maxLength;
}
