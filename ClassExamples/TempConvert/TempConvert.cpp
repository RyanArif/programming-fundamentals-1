/******************************
   Ryan Arif
   1/24/2019
   TempConvert.cpp
   Ask for the date and temperature in F and convert it to C
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Global variables
//Month Names
const string MONTHS[12] = { "Jan", "Feb", "Mar", "Apr", "May",
							"Jun", "Jul", "Aug",
							"Sep", "Oct", "Nov", "Dec" };

// Function declarations
template <typename T>
T getValidatedInput();

int main()
{
	int month,  // month number (1 - Jan, 12 - Dec)
		day,	// day of the month (1 through 31)
		year;	// current year
	double f,   // temperature in farenheit
		c;	    // temperature in celcius 
    
    
	//	Get info from user
	cout << "What is the current year?";
	cin >> year;
	cout << "What is the current month? (1-12 for Jan-Dec)";
	cin >> month;
	cout << "What is the current day?";
	cin >> day;
	cout << "What is the current emperature in degrees farenheit?";
	cin >> f;

	// Convert farenheit to celsius 
	c = (5.0 / 9.0) * (f - 32.0);


	// Output the results
	cout << endl << endl;
	cout << "Date: " << MONTHS[month - 1] << " " << day <<
		", " << year << endl;

	cout << "Faherenheit: " << f << '\370' << "F\n";
	cout << "Celsius: " << c << '\370' << "C\n";

	//	The following is system dependent.  It will only work on Windows
    system("PAUSE");

	/* 
	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();
	*/
    return 0;
}