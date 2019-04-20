/******************************
   Ryan Arif
   2/21/2019
   InvoiceRefactored.cpp
   This program will ask the user for their name, ask for  the
   names and costs of three items, then calculate the total
   cost and average of the three items.
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

// Global variables (ONLY PUT CONTSTANTS HERE. global variables = bad)
const int NUM_ITEMS = 3;	// number of items 

//Functions Declarations
string getCustomerName();
void getItemNames(string names[], int size);
void getItemCosts(double costs[], string names[], int size);
double getTotalCost(double costs[], int size);
double getAverageCost(double costs[], int size);
void displayInvoice(string custName, string names[], double costs[], int size);

int main()
{
	string customerName;			//full name of the customer
	string itemNames[NUM_ITEMS];	//Names of NUM_ITEMS items (let's make sure we're doing good programming practices with this - use variables when declaring arrays)
	double itemCosts[NUM_ITEMS];	//Costs of NUM_ITEMS items 

	//Get the customer name
	customerName = getCustomerName();
	//Get the names of the items
	getItemNames(itemNames, NUM_ITEMS);
	//Get the costs of the items
	getItemCosts(itemCosts, itemNames, NUM_ITEMS);
	//Calculate the total cost of the items 
	getTotalCost(itemCosts, NUM_ITEMS);
	//Calculate the average cost of the items
	getAverageCost(itemCosts, NUM_ITEMS);
	//Display invoice to customer	
	displayInvoice(customerName, itemNames, itemCosts, NUM_ITEMS);

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

//Asks for and return the name of the customer
string getCustomerName()
{
	string customerName; //name of the customer
	cout << "Yo, like, do you have a name? ";
	getline(cin, customerName);
	return customerName;
}

//Get the names of items
void getItemNames(string names[], int size)
{
	//Get the name of three items
	cout << "Aight, watchu buyin? I swear to God if you go over " << size << " I'm gonna get real mad." << endl;
	//I would use a loop here so we can get as many items as NUM_ITEMS but we don't know how to do that in class yet shhh
	cout << "Item 1: ";
	getline(cin, names[0]);
	cout << "Item 2: ";
	getline(cin, names[1]);
	cout << "Item 3: ";
	getline(cin, names[2]);
}

//get the costs of the items by name
void getItemCosts(double costs[], string names[], int size)
{
	cout << endl << "Enter the cost of " << size << " items" << endl;
	cout << "Cost of " << names[0] << ": $";
	cin >> costs[0];
	cout << "Cost of " << names[1] << ": $";
	cin >> costs[1];
	cout << "Cost of " << names[2] << ": $";
	cin >> costs[2];
}

//get the total costs of the items
double getTotalCost(double costs[], int size)
{
	return costs[0] + costs[1] + costs[2];
}

//get the average cost of the items
double getAverageCost(double costs[], int size)
{
	return (getTotalCost(costs, size) / size);
}

//displays the invoice as a table
void displayInvoice(string custName, string names[], double costs[], int size)
{
	cout << fixed << setprecision(2) << showpoint;
	cout << "\nInvoice for homie: " << custName << endl << endl;
	cout << "Items Purchased:\n";
	cout << setw(30) << left << "Item Name" << " "
		<< setw(10) << right << "Cost" << endl; //table header
	cout << setw(30) << left << names[0] << "$"
		<< setw(10) << right << costs[0] << endl; //imagine if we used loops
	cout << setw(30) << left << names[1] << "$"
		<< setw(10) << right << costs[0] << endl;
	cout << setw(30) << left << names[2] << "$"
		<< setw(10) << right << costs[2] << endl;
	cout << setw(30) << left << "Total Cost" << "$"
		<< setw(10) << right << getTotalCost(costs, size) << endl;
	cout << setw(30) << left << "Average Cost" << "$"
		<< setw(10) << right << getAverageCost(costs, size) << endl;
}
