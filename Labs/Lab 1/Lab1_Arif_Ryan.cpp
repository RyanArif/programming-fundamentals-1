// Ryan Arif
// COSC 1436 Lab 1

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Constants for Part B
const float PI = 3.14;
const float RADIUS = 5.4;

// Constants for Part C
const string FAVORITESODA = "Dr. Pepper";	// use double quotes for strings (Sorry, I had to change this. Dr Dolittle is the false prophet.)
const char BESTRATING = 'A';				// use single quotes for characters

int main()
{
	// Part A *********************************
	cout << "Part A\n";	// DO NOT CHANGE THIS LINE OF CODE
	// Write your first and last name
	cout << "Ryan Arf" << endl;
	// Write your address (on new line)
	cout << "1234 Street St." << endl;
	// Write your city, state and zip (on new line)
	cout << "City, Texas 01234" << endl;
	// Write your telephone number (on new line)
	cout << "911" << endl;

	// Part B *********************************
	cout << "\nPart B\n";	// DO NOT CHANGE THIS LINE OF CODE
	float area;								// definition of area of circle 
	int circumference;				        // definition of circumference (left as an int to answer questions)
	circumference = 2 * PI * RADIUS;	    // computes circumference
	area = PI * RADIUS * RADIUS;			// computes area

	// Fill in the code for the cout statement that will output (with description)
	// the circumference
	cout << "The circumference of the circle is " << circumference << endl;
	// Fill in the code for the cout statement that will output (with description)
	// the area of the circle
	cout << "The area of the circle is " << area << endl;

	// Part C *********************************
	cout << "\nPart C\n";	// DO NOT CHANGE THIS LINE OF CODE
	char rating;			// 2nd highest product rating
	string favoriteSnack;	// most preferred snack
	int numberOfPeople;		// the number of people in the survey
	int topChoiceTotal;		// the number of people who prefer the top choice

	// Fill in the code to do the following:
	// Assign the value of "crackers" to favoriteSnack
	favoriteSnack = "crackers";
	// Assign a grade of 'B' to rating
	rating = 'B';
	// Assign the number 250 to the numberOfPeople
	numberOfPeople = 250;
	// Assign the number 148 to the topChoiceTotal
	topChoiceTotal = 14;

	// Replace the blanks in the following with correct code to get the desired output:
	cout << "The preferred soda is " << FAVORITESODA << endl; 
	cout << "The preferred snack is " << favoriteSnack << endl; 
	cout << "Out of " << numberOfPeople << " people "
		 << topChoiceTotal << " chose these items!" << endl;
	cout << "Each of these products were given a rating of " << BESTRATING;
	cout << " from our expert tasters" << endl;
	cout << "The other products were rated no higher than a " << rating << endl;

	// DO NOT CODE BELOW THIS LINE
	cout << endl;
	system("PAUSE");
	return 0;
}

// No questions for Part A

// Questions for Part B
// Question 1
// The circumference of the circle is 33
// The area of the circle is 91.5624
// Question 2
// Explain: the compiler did all the maths then converted it to an int by dropping the .912

// Questions for Part C
// Question 1
//You can NOT change the constant variable FAVORITESODA once it has been declared. The compiler says "no" when you try to do it. It's called a constant, wouldn't make much sense to let it change.
// Question 2
//It is possible to change favoriteSnack. It's a normal variable, so you can change it anywhere within the program (after it was declared). 


