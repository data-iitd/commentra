// C++ program to count the number of occurrences of a substring in a string
#include <bits/stdc++.h>
using namespace std;

// Function to count the number of occurrences of a substring in a string
int countOccurrences(string s, string sub)
{
	// Initialize the count variable
	int count = 0;

	// Traverse the string
	for (int i = 0; i < s.length(); i++)
	{
		// Check if the current character matches the first character of the substring
		if (s[i] == sub[0])
		{
			// Check if the substring is present from the current character
			if (s.substr(i, sub.length()) == sub)
			{
				// If the substring is present, increment the count
				count++;
			}
		}
	}

	// Return the count
	return count;
}

// Driver code
int main()
{
	// Declare a variable's' of type string
	string s;
	// Use 'cin' to read a string input from the standard input
	cin >> s;

	// Use 'countOccurrences' to count the number of occurrences of the substring "o" in the string's'
	int n = countOccurrences(s, "o");

	// Calculate the result by adding 700 to the product of 100 and the number of occurrences of "o" in the string
	int result = 700 + n * 100;
	// Use 'cout' to print the result to the standard output
	cout << result;

	// Return 0
	return 0;
}

// The code ends here

