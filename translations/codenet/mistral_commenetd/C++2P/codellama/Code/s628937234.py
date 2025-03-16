#include <iostream>
#include <algorithm>
#include <string>

#include <string>

// Include necessary libraries

int main()
{
	using namespace std; // Use standard namespace for easier access to functions and objects

	string s, t; // Declare two string variables, s and t

	cin >> s; // Read a string from the standard input and store it in the variable s

	// The following block of code creates a new string t from the string s
	t = s[0];
	t += to_string(s.size()-2);
	t += s[s.size() - 1];

	// Extract the first character from string s and store it in variable t
	// Convert the size of string s minus 2 to a string using to_string function
	// Concatenate the extracted first character, the size minus 2 as a string, and the last character of string s to create the new string t

	cout << t << endl; // Output the newly created string t to the standard output

	return 0; // Indicate successful termination of the program
}


