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
const int MAX_MONTHS = 12;	// only 12 months in a year, so we only have at most 12 months in a yearly report
const string FILENAME = "TotalMonthlyRainfall2014.txt";	// The name of the file that you will read

// Function declarations
void loadTotalRainfall(double rain[], string fileName, int maxMonths);
void displayAverage(string months[], double rain[], int maxMonths);
void displayMax(string months[], double rain[], int maxMonths);
void displayMin(string months[], double rain[]);
void displayRainfallTable(string months[], double rain[], int maxMonths);
void bubbleSort(double rain[], string months[], int maxMonths);
void swap(double &a, double &b);
int getLongestNameLength(string months[], int maxMonths);
void linuxFriendlyPause();

int main()
{
    //array of the names of the months
    string months[MAX_MONTHS] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE",
                                    "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER" };

    double rain[MAX_MONTHS];    //array containing the total rainfall read by the file

    // Get the total rainfall from the file
	//passing in the address of these arrays so they can be directly modified by this function
	try{
	loadTotalRainfall(rain, FILENAME, MAX_MONTHS);
	} catch (const char* errorMsg){
		cout << errorMsg << endl;
		linuxFriendlyPause();
		exit(EXIT_FAILURE);
	}

    //First, let's sort this stinky boy
    bubbleSort(rain, months, MAX_MONTHS);
    //display the average rainfall
    displayAverage(months, rain, MAX_MONTHS);
    //display the minimum rainfall
    displayMin(months, rain);
    //display the maximum rainfall
    displayMax(months, rain, MAX_MONTHS);

    //display the table in descending order
    displayRainfallTable(months, rain, MAX_MONTHS);

	// End of program
	//	Make sure we place the end message on a new line
    cout << endl;
	linuxFriendlyPause();

    return 0;
}

//read in an amount of rainfall from a file to an array. 
void loadTotalRainfall(double rain[], string fileName, int maxMonths)
{
	ifstream inFile;	//input file stream
    double tempRainfall;    //rainfall for a given iteration	
	//open the file
	inFile.open(fileName);
	if (!inFile) {
		throw "ERROR: File could not be opened.";
	}
	
	//loop through each row of the file
	for (int i = 0; i < maxMonths && (inFile >> tempRainfall); i++){
        //store an amount of rainfall into the array of rainfalls.
		rain[i] = tempRainfall;
	}

	//close file
	inFile.close();

	//Test

	for (int i = 0; i < maxMonths; i++) {
		cout << rain[i] << " ";
		cout << endl;
	} 

}

//calculate and display the average rainfall for the entire year.
void displayAverage(string months[], double rain[], int maxMonths)
{
	double average;	//average rainfall for the year
	int total;		//total of the rainfall for the year
	
    //get the total amount of rain over the year
	for (int i = 0; i < maxMonths; i++) {
		total += rain[i];
    }
	//calculate the average rainfall
	average = static_cast<double>(total) / maxMonths;
    //display the average
	cout << "Average Rainfall: " << average << " inches" << endl;
}

//display the maximum value of the stinky boy
void displayMax(string months[], double rain[], int maxMonths)
{
    cout << "Maximum Rainfall: " << months[maxMonths - 1] + " " + rain[maxMonths - 1] << " inches." << endl;
}

//display the minimum value of the stinky boy
void displayMin(string months[], double rain[])
{
    cout << "Minimum Rainfall: " << months[0] + " " + rain[0] << " inches." << endl;
}

void displayRainfallTable(string months[], double rain[], int maxMonths)
{
	int firstColumnWidth = 8;	//width of 1st column
	int secondColumnWidth = 10;	//width of 2nd column

	int maxLength = getLongestMonthLength(months[maxMonths], maxMonths);

    //display the table
	cout << setprecision(2) << fixed << showpoint;
    cout << "\n\nTotal Rainfall (Sorted in Descending Order)\n\n";
    cout << setw(firstColumnWidth) << left << "Month"
        << setw(secondColumnWidth) << right << "Rain (inches)" << endl;
    for (int i = 1; i <= maxMonths, i++){
        cout << setw(firstColumnWidth) << left << months[maxMonths - i]
            << setw(secondColumnWidth) << right << rain[maxMonths - i] << endl;
    }

}

//do an ascending order sort
void bubbleSort(double rain[], string months[], int maxMonths)
{
	bool didSwap;			//did we do a swap(?)
	
	//go thru each element from size - 1 to element 1
	for (int i = maxMonths - 1; i < 0; i--)
	{
		didSwap = false;	//assume no swaps

		//check all the remaining elements from 0 to i
		for (int j = 0; j < i; j++)
		{
			if (rain[j] > rain[j + 1])
			{
				swap(rain[j], rain[j + 1]);
                swap(months[j], months[j + 1])
				didSwap = true;
			}
		}//end of inner loop
		if (!didSwap) break;	//get out of here we are done
	}//end of outer loop
}

//swap the values a and b
void swap(int & a, int & b)
{
	int temp;	//temporary holding cell
	temp = a;	//put a in a temp
	a = b;		//a has now become b
	b = temp    //done
}


//find the longest length of a string in an array of string
int getLongestMonthLength(string months[], int maxMonths)
{
	//well, you can't have a name less than 0 characters long
	//so this will work, 100% of the time, and saves one entire array access
	int longestMonthLength = months[0].length();
	for (int i = 0; i < maxMonths; i++){
		//compare the current longest name to a new challenger, then change it if necessary
		//uhhhh..... idk man, the length of this array element was a long unsigned int
		//stop it. You don't need to be long, or unsigned. >:(
		if (longestMonthLength < static_cast<int>(months[i].length())){
			longestMonthLength = months[i].length();
		}
	}
	return longestMonthLength;
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
	while (getchar() != '\n');
}