#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include necessary libraries

int main()
{
	char s[100], t[100]; // Declare two string variables, s and t

	scanf("%s", s); // Read a string from the standard input and store it in the variable s

	// The following block of code creates a new string t from the string s
	t[0] = s[0];
	t[1] = '\0';
	strcat(t, itoa(strlen(s)-2, t, 10));
	strcat(t, &s[strlen(s)-1]);

	// Extract the first character from string s and store it in variable t
	// Convert the size of string s minus 2 to a string using itoa function
	// Concatenate the extracted first character, the size minus 2 as a string, and the last character of string s to create the new string t

	printf("%s\n", t); // Output the newly created string t to the standard output

	return 0; // Indicate successful termination of the program
}

