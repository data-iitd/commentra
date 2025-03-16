#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Initialize input/output streams and read input data
int main()
{
	// Set up fast I/O
	ios::sync_with_stdio(false); cin.tie(0);

	// Declare variables
	int a, b, c, d, e, f, g, T;
	char *z; // Initialize string variable to store input

	// Read input string from standard input
	scanf("%s", z);
	// Assign size of the string to variable 'a'
	a = strlen(z);

	// Check if there are any consecutive identical characters in the string
	for (int i = 0; i < a - 1; i++)
	{
		// Check if current character is same as next character
		if (z[i] == z[i + 1])
		{
			// If yes, print "Bad" and exit the program
			printf("Bad\n");
			return 0;
		}
	}
	// If no consecutive identical characters are found, print "Good"
	printf("Good\n");
}

