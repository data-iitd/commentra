

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a constant for the modulo value
#define mod 1000000007

// Function to read the next string from input
char* next() {
	char* s = NULL;
	size_t len = 0;
	getline(&s, &len, stdin);
	return s;
}

// Function to read the next integer from input
int nextInt() {
	int i = 0;
	char* s = next();
	i = atoi(s);
	free(s);
	return i;
}

int main() {
	// Read the values of h and n from input
	int h = nextInt();
	int n = nextInt();
	int a = 0; // Initialize a variable to accumulate the sum of integers

	// Loop to read n integers and accumulate their sum
	for (int i = 0; i < n; i++) {
		a += nextInt();
	}

	// Check if the accumulated sum is less than h
	if (h > a) {
		// If h is greater than the sum, print "No"
		printf("No\n");
	} else {
		// Otherwise, print "Yes"
		printf("Yes\n");
	}
}

