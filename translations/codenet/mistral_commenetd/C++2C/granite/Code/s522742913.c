
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
	// Initialize an empty string variable named'source'
	char source[101] = "";

	// Read a string input from the standard input stream (stdin) and store it in the'source' variable
	scanf("%s", source);

	// Check if the length of the input string is valid (greater than 10 characters or less than 1 character)
	if(strlen(source) > 10 || strlen(source) < 1)
	{
		// If the condition is true, return an error code (-1)
		return -1;
	}

	// Calculate the maximum value of 'i' based on the length of the input string using bitwise operations
	int max_i = (int)pow(2, strlen(source) - 1);

	// Initialize a variable named'sum' with a value of 0
	double sum = 0;

	// Iterate through the range of 'i' from 0 to'max_i' using a for loop
	for (int i = 0; i < max_i; ++i)
	{
		// Create a bitset named 'plus' with the binary representation of 'i'
		bool plus[100] = {0};
		for (int j = 0; j < 100; ++j)
		{
			plus[j] = (i & (1 << j))!= 0;
		}

		// Initialize a variable named 'number' with a value of 0
		double number = 0;

		// Initialize a string variable named 'working' with the value of the input string'source'
		char working[101] = "";
		strcpy(working, source);

		// Iterate through the bits of the 'plus' bitset from the least significant bit to the most significant bit
		int index = 0;
		while(plus[index])
		{
			// Find the index of the first '1' bit in the 'plus' bitset
			while(!plus[index]) ++index;

			// Add the substring of the 'working' string starting from the first '1' bit index to the'sum' variable
			sum += atof(strndup(working, index + 1));

			// Shift the 'plus' bitset to the right by the index of the first '1' bit
			for (int j = index; j < 99; ++j)
			{
				plus[j] = plus[j + 1];
			}

			// Update the value of the 'working' string by removing the substring that has been added to the'sum' variable
			char temp[101] = "";
			strcpy(temp, working + index + 1);
			strcpy(working, temp);
		}

		// Add the remaining substring of the 'working' string to the'sum' variable
		sum += atof(working);
	}

	// Set the precision of the output stream (stdout) to 0 decimal places
	setprecision(0);

	// Print the value of the'sum' variable to the standard output stream (stdout) with no decimal places and append a newline character ('\n')
	printf("%.0f\n", sum);


	// Return 0 to indicate successful execution of the program
	return 0;
}

