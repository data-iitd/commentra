
#include<stdio.h>         // Include stdio.h for input and output operations
#include<string.h>        // Include string.h for string manipulation functions
#include<stdlib.h>        // Include stdlib.h for memory allocation and deallocation functions
#include<math.h>          // Include math.h for mathematical functions
#include<algorithm>       // Include algorithm for general algorithms like sort

int main()
{
	char z[100005]; // Declare a character array variable to store input string
	scanf("%s", z); // Read input string from standard input
	int a = strlen(z); // Calculate the length of the string and store it in a
	for (int i = 0; i < a - 1; i++) // Iterate through the string
	{
		if (z[i] == z[i + 1]) // Check if any two consecutive characters are the same
		{
			printf("Bad\n"); // Print "Bad" if a pair is found and exit
			return 0;
		}
	}
	printf("Good\n"); // Print "Good" if no pair is found
}


