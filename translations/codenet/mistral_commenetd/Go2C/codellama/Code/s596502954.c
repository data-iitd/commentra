
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a single word as a string from the input
char* next() {
	char* word = malloc(sizeof(char) * 100);
	scanf("%s", word);
	return word;
}

// Function to read an integer from the input
int nextInt() {
	int i;
	scanf("%d", &i);
	return i;
}

// Function to read a float64 from the input
float nextFloat64() {
	float f;
	scanf("%f", &f);
	return f;
}

// Function to read n integers from the input and return as a slice
int* nextInts(int n) {
	int* slice = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		slice[i] = nextInt();
	}
	return slice;
}

// Main function
int main() {
	// Read the first three integers from the input
	int a = nextInt();
	int b = nextInt();
	int c = nextInt();

	// Check if the condition is true
	if (a + b >= c) {
		// If true, print "Yes" to the output
		printf("Yes\n");
	} else {
		// If false, print "No" to the output
		printf("No\n");
	}

	// End of code
	return 0;
}

