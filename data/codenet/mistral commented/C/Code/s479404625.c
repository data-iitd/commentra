
#include <stdio.h>
#include <string.h>

// Declare three character arrays of size 20 each to store strings A, B, and C
char A[20], B[20], C[20];

int main()
{
	// Initialize the character arrays A, B, and C using scanf function
	scanf("%s %s %s", A, B, C);

	// Calculate the length of strings A and B using strlen function and store the lengths in la and lb respectively
	int la = strlen(A), lb = strlen(B);

	// Logical block to check if the last character of string A is same as the first character of string B
	// and the last character of string B is same as the first character of string C
	if (A[la - 1] == B[0] && B[lb - 1] == C[0])
	{
		// If the condition is true, print YES on the console
		printf("YES\n");
	}
	// Logical block to check if the condition in if block is false
	else
	{
		// If the condition is false, print NO on the console
		printf("NO\n");
	}

	// Return 0 to indicate successful execution of the program
	return 0;
}