/******************************
   Ryan Arif
   2/7/2019
   Invoice.cpp
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

// Function declarations
template <typename T>
T getValidatedInput();

int main()
{
	string customerName;			//full name of the customer
	string itemNames[NUM_ITEMS];	//Names of NUM_ITEMS items (let's make sure we're doing good programming practices with this - use variables when declaring arrays)
	double itemCosts[NUM_ITEMS];	//Costs of NUM_ITEMS items 
	double totalItemCost;			//total of cost of NUM_ITEMS items
	double averageItemCost;			//average cost of NUM_ITEMS items

	//Get the customer name
	cout << "Yo, like, do you have a name? ";
	getline(cin, customerName);
	//Get the name of three items
	cout << "Aight, watchu buyin? I swear to God if you go over " << NUM_ITEMS << " I'm gonna get real mad." << endl;
	//I would use a loop here so we can get as many items as NUM_ITEMS but we don't know how to do that in class yet shhh
	cout << "Item 1: ";
	getline(cin, itemNames[0]);
	cout << "Item 2: ";
	getline(cin, itemNames[1]);
	cout << "Item 3: ";
	getline(cin, itemNames[2]);
	//aight now to get the costs
	cout << endl << "Enter the cost of " << NUM_ITEMS << " items" << endl;
	cout << "Cost of " << itemNames[0] << ": $";
	cin >> itemCosts[0];
	cout << "Cost of " << itemNames[1] << ": $";
	cin >> itemCosts[1];
	cout << "Cost of " << itemNames[2] << ": $";
	cin >> itemCosts[2];

	//Calculate the total and aaverage cost of the items
	totalItemCost = itemCosts[0] + itemCosts[1] + itemCosts[2];
	averageItemCost = totalItemCost / NUM_ITEMS;

	//Display invoice to customer
	cout << fixed << setprecision(2) << showpoint;
	cout << "\nInvoice for homie: " << customerName << endl << endl;
	cout << "Items Purchased:\n";
	cout << setw(30) << left << "Item Name" << " "
		<< setw(10) << right << "Cost" << endl; //table header
	cout << setw(30) << left << itemNames[0] << "$"
		<< setw(10) << right << itemCosts[0] << endl; //imagine if we used loops
	cout << setw(30) << left << itemNames[1] << "$"
		<< setw(10) << right << itemCosts[0] << endl; 
	cout << setw(30) << left << itemNames[2] << "$"
		<< setw(10) << right << itemCosts[2] << endl;
	cout << setw(30) << left << "Total Cost" << "$"
		<< setw(10) << right << totalItemCost << endl;
	cout << setw(30) << left << "Average Cost" << "$"
		<< setw(10) << right << averageItemCost << endl;
	

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