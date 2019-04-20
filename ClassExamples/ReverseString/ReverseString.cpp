/******************************
   Ryan Arif
   3/26/2019
   ReverseString.cpp
   Take a string from the user and outputs it in
   reverse order then determines if it is a palindrome
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>	//for character manipulation
using namespace std;

// Global variables
string reverseString(string word, bool caseLower = false);
bool isPalindrome(string word);

// Function declarations

int main()
{
	//	Your code goes here
	string theWord;		//string from the user
	string reverseWord;	//reversed string from the user
	char choice;		//choice for user

	do {
		cout << "Enter a word to be reversed: ";
		getline(cin, theWord);
		cout << theWord << ". Interesting choice..." << endl;
		try {
			reverseWord = reverseString(theWord);
		}
		catch (const char* errorMessage) {
			cout << errorMessage << endl;
			cout << endl;
			choice = 'Y';
			continue;
		}
		// output the reverse word
		cout << theWord << " reversed is " << reverseWord << endl;
		
		//check if palindrome
		cout << theWord << " is ";
		if (!isPalindrome(theWord)) {
			cout << "not ";
		}
		cout << "a palindrome\n";

		//check if the user wants another word reversed
		cout << "\nDo you want to reverse another word? (y/n): ";
		cin >> choice;
		while (getchar() != '\n'); //flush the stream
		cout << endl;
		choice = toupper(choice);
	} while (choice == 'Y');
	
    
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

//Takes a string, optionally changes each letter to 
//lowercase, and then reverses the string. 
string reverseString(string word, bool caseLower)
{
	const int STACK_SIZE = 80;	//max size of stack
	char stack[STACK_SIZE];		//holds a stack of characters
	char reversed[STACK_SIZE];	//cstring, hold chars after reversing
	int top = -1;
	int length = word.length();

	//make sure word isn't too long
	if (length > STACK_SIZE) {
		throw "Word too long";
	}

	//put letters in the stack
	for (int i = 0; i < length; i++) {
		//push
		stack[++top] = word.at(i);	//word[i];
	}

	//pop the stack into reversed
	for (int i = 0; top >= 0; top--, i++) {
		reversed[i] = stack[top];
	}

	//check if we need to make it lowercase
	if (caseLower) {
		for (int i = 0; i < length; i++) {
			reversed[i] = tolower(reversed[i]);
		}
	}

	//add the null terminator
	reversed[length] = '\0';

	return string(reversed);
}

bool isPalindrome(string word)
{
	// reversed is all lower case
	string reversed = reverseString(word, true);

	//make the word all lower case
	for (int i = 0; i < word.length(); i++) {
		word.at(i) = tolower(word.at(i));
	}
	
	//loop through half the letters in word and reversed
	for (int i = 0; i < word.length() / 2 + 1; i++) {
		//Are the two letters in the same position different
		if (word.at(i) != reversed.at(i)) {
			return false;
		}
	}

	return true;
}
