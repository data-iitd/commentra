
#include <stdio.h>
#include <string.h>

int main()
{
	char s[100], t[100]; // Declare two character arrays, s and t, with a maximum length of 100 characters

	scanf("%s", s); // Read a string from the standard input and store it in the character array s

	// The following block of code creates a new string t from the string s
	t[0] = s[0];
	sprintf(t+1, "%d", strlen(s)-2);
	t[strlen(s)-1] = s[strlen(s)-1];

	// Extract the first character from string s and store it in the first position of the character array t
	// Use sprintf to convert the length of string s minus 2 to a string and store it in the second position of the character array t
	// Concatenate the extracted first character, the length minus 2 as a string, and the last character of string s to create the new string t

	printf("%s\n", t); // Output the newly created string t to the standard output

	return 0; // Indicate successful termination of the program
}
