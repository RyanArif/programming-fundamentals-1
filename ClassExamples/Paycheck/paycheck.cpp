/******************************
   Ryan Arif
   03/07/2019
   paycheck.cpp
   Calculate the gross pay based on hourly rate and hours worked
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Global variables
//how many hours worked before overtime
const double REGULAR_TIME_MAX = 40.0;
//overtime adjustment 
const double OVERTIME_FACTOR = 1.5;

// Function declarations
template <typename T>
T getValidatedInput();

string getEmployeeName();
double getHoursWorked();
double getHourlyWage();
double calculateRegtimeWage(double totalHoursWorked, double hourlyWage, double regTimeMax);
double calculateOvertimeWage(double totalHoursWorked, double hourlyWage, double regTimeMax, double otFactor);
double calculateTotalWage(double totalHoursWorked, double hourlyWage, double regTimeMax, double otFactor);

int main()
{
	string employeeName;	//name of employee
	double hourlyWage;		//what do we make per hour
	double hoursWorked;		//how many hours do we give the man
	double totalWage;		//total gross pay

	//get the name of the employee
	employeeName = getEmployeeName();

	//get the hourly wage
	cout << endl;
	hourlyWage = getHourlyWage();

	//get number of hours worked for the week
	cout << endl;
	hoursWorked = getHoursWorked();

	//calculate the total wage
	cout << endl;
	totalWage = calculateTotalWage(hoursWorked, hourlyWage, REGULAR_TIME_MAX, OVERTIME_FACTOR);

	//print report
	cout << "\n\nPaycheckReport\n";
	cout << "Employee: " << employeeName << endl;
	cout << "Hourly Wage: " << hourlyWage << endl;
	cout << "Hours Worked: " << hoursWorked << endl;
	cout << "Total Salary: " << totalWage << endl;
    
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

template <typename T>
T getValidatedInput()
{
	// Get input of type T
	T result;
	cin >> result;

	// Check if the failbit has been set, meaning the beginning of the input
	// was not type T. Also make sure the result is the only thing in the input
	// stream, otherwise things like 2b would be a valid int.
	if (cin.fail() || cin.get() != '\n')
	{
		// Set the error state flag back to goodbit. If you need to get the input
		// again (e.g. this is in a while loop), this is essential. Otherwise, the
		// failbit will stay set.
		cin.clear();

		// Clear the input stream using and empty while loop.
		while (cin.get() != '\n');

		// Throw an exception. Allows the caller to handle it any way you see fit
		// (exit, ask for input again, etc.)
		throw ios_base::failure("Invalid input.");
	}

	return result;
}

//get the name of the employee
string getEmployeeName()
{
	string name; // name of employee
	cout << "Enter the name of the employee: ";
	getline(cin, name);
	return name;
}

//get the number of hours worked by the employee
double getHoursWorked()
{
	double hours; //hours worked
	cout << "Enter the number of hours worked: ";
	cin >> hours;
	return hours;
}

//get hourly wage earned by employee
double getHourlyWage()
{
	double wage;	//wage hourly
	cout << "Enter the hourly wage: ";
	cin >> wage;
	return wage;
}

double calculateRegtimeWage(double totalHoursWorked, double hourlyWage, double regTimeMax)
{
	if (totalHoursWorked > regTimeMax)
		return hourlyWage * regTimeMax;
	else
		return hourlyWage * totalHoursWorked;
}

double calculateOvertimeWage(double totalHoursWorked, double hourlyWage, double regTimeMax, double otFactor)
{
	if (totalHoursWorked < regTimeMax)
		return 0.0;
	else
		return (totalHoursWorked - regTimeMax) * hourlyWage * otFactor;
}

//calculate the total wage of the employee
double calculateTotalWage(double totalHoursWorked, double hourlyWage, double regTimeMax, double otFactor)
{
	return calculateRegtimeWage(totalHoursWorked, hourlyWage, regTimeMax) + calculateOvertimeWage(totalHoursWorked, hourlyWage, regTimeMax, otFactor);
}
