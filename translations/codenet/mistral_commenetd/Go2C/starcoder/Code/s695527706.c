// Package main is the entry point of the program
#include <stdio.h>
#include <string.h>

int main() {
	// Declare two variables, n and s
	int n;
	char s[1000];

	// Read the input from the standard input
	scanf("%d %s", &n, s);

	// Print the result of the strings.Count function
	printf("%d\n", strings.Count(s, "ABC"));
}

// The main function is the entry point of the program
int main() {
	// Declare two variables, n and s
	int n;
	char s[1000];

	// Read the input from the standard input
	scanf("%d %s", &n, s);

	// Call the strings.Count function to count the number of occurrences of "ABC" in the string s
	// Print the result using the printf function
	printf("%d\n", strings.Count(s, "ABC"));
}

// This is the end of the code

