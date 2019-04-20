// Ryan Arif
// COSC 1436 Lab 4

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	// Part A *********************************
	// Part A tests whether or not an initialized value
	// is equal to a value input by the user
	cout << "Part A\n";	// DO NOT CHANGE THIS LINE OF CODE
	
	int num1,		// num1 is not initialized
		num2;	   // num2 is not initialized

	cout << "Please enter an integer" << endl;
	cin >> num1;
	cout << "Please enter a second integer" << endl;
	cin >> num2;

	cout << "num1 = " << num1 << " and num2 = " << num2 << endl;

	if (num1 == num2) //just need to add another =
		cout << "The values are the same\nHey, that's a coincidence!" << endl;
	else
		cout << "The values are not the same" << endl;
	
	// Part B *********************************
	// Part B prints "You Pass" if a student's average is
	// 60 or higher and prints "You Fail" otherwise
		cout << "\n\nPart B\n";	// DO NOT CHANGE THIS LINE OF CODE

		float average;	// holds the grade average

		cout << "Input your average:" << endl;
		cin >> average;

		if (average >= 60) //just missing the "or equal to"
			cout << "You Pass" << endl;
		else
			cout << "You Fail" << endl;
		
	// DO NOT CODE BELOW THIS LINE
	cout << endl;
	system("PAUSE");
	return 0;
}

// Question for Part A
// Question 1
// num2 is always 5 it looks like. Doesn't work correctly.

// Question for Part B
// Question 1
// There is no output when you input "60" as the average.
