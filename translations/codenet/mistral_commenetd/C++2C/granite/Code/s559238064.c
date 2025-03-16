
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

// Initialize input/output streams and read input data
int main()
{
	char z[100005]; // Initialize character array to store input
	int a; // Initialize integer variable to store the size of the string

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
