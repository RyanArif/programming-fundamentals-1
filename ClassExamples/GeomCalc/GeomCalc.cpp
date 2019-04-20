/******************************
   Ryan Arif
   2/28/2019
   GeomCalc.cpp
   Calculate the area of various shapes
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class InvalidDimensionException {};

// Global variables
const double PI = 3.14159; //PI are round

// Function declarations
template <typename T>
T getValidatedInput();

double areaCircle(double radius);
double areaRectangle(double width, double length);
double areaTriangle(double base, double height);

int main()
{
	double width, height, radius, area; //holds our dimensions for shapes
	char choice;						//users choice

	do
	{
		//display the menu and get the choice
		cout << "Geometry Calculator! \n\n"
			<< "\t1. Calculate teh Area of a Circle\n"
			<< "\t2. Calculate the Area of a Rectangle\n"
			<< "\t3. Calculate the Area of a Triangle\n"
			<< "\t4. Quit\n";
		cout << "Enter your choice (1-4): ";
		cin >> choice;
		while (getchar() != '\n'); //empty the buffer

		//processs the choice and display the results
		switch (choice)
		{
		case '1': //circle
			try
			{
				cout << "\nEnter the radius of the circle: ";
				radius = getValidatedInput<double>();
				area = areaCircle(radius);
				cout << "The area of a circle with radius "
					<< radius << " is " << area << ".\n";
			}
			catch (ios_base::failure e)
			{
				cout << e.what() << endl;
			}
			catch (InvalidDimensionException e)
			{
				cout << "Invalid radius";
			}
			break;

	case '2': //rectangle
		try
		{
			cout << "\nEnter the width of the rectangle: ";
			width = getValidatedInput<double>();
			cout << "\nEnter the length of the rectangle: ";
			height = getValidatedInput<double>();

			area = areaRectangle(width, height);
			cout << "The area of a rectangle with width of "
				<< width << " and length of " << height
				<< " is " << area << endl;
		}
		catch (ios_base::failure e)
		{
			cout << e.what() << endl;
		}
		catch (InvalidDimensionException e)
		{
			cout << "Invalid length or width\n";
		}
		break;

	case '3': //triangle
		try
		{
			cout << "\nEnter the base of the triangle: ";
			width = getValidatedInput<double>();
			cout << "\nEnter the height of the triangle: ";
			height = getValidatedInput<double>();

			area = areaTriangle(width, height);
			cout << "The area of a triangle with base "
				<< width << " and height " << height
				<< " is " << area << endl;
		}
		catch (ios_base::failure e)
		{
			cout << e.what() << endl;
		}
		catch (InvalidDimensionException e)
		{
			cout << "Invalid base or height\n";
		}
		break;

	case '4': //Quit
		cout << "\nQuitter!\n";
		break;

	default: 
		cout << "Are you fucking stupid? I tell you '1-4' and you pick some retarded shit, " << choice << "? Lmao.";
	} //switch end

	//pause to read screen and then clear the screen
	if (choice != '4')
	{
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

//calculate area of circle from radius
double areaCircle(double radius)
{
	if (radius < 0.0)
		throw InvalidDimensionException();
	return PI * radius * radius;
}

//caclulate the area of rectangle from width & length
double areaRectangle(double width, double length)
{
	if (width < 0.0 || length < 0.0)
		throw InvalidDimensionException();
	return width * length;
}

//Calculate the area of a triangle using base and height
double areaTriangle(double base, double height)
{
	if (base < 0.0 || height < 0.0)
		throw InvalidDimensionException();
	return 0.5 * base * height;
}
