#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer from input
int readInt() {
	char *str;
	int i;
	scanf("%s", str);
	i = atoi(str);
	return i;
}

// Function to read a float64 from input
float readFloat64() {
	char *str;
	float f;
	scanf("%s", str);
	f = atof(str);
	return f;
}

// Function to read a string from input
char *readString() {
	char *str;
	scanf("%s", str);
	return str;
}

int main() {
	// Set the scanner to split input by whitespace
	// Read two integers n and m from input
	int n, m;
	n = readInt();
	m = readInt();

	// Initialize a slice to hold m integers
	int a[n];

	// Initialize a variable to hold the sum of the integers read
	int sum = 0;

	// Read m integers from input and calculate their sum
	for (int i = 0; i < m; i++) {
		a[i] = readInt(); // Read an integer and store it in the slice
		sum += a[i]; // Add the integer to the sum
	}

	// Check if the sum of the integers exceeds n
	if (sum > n) {
		printf("-1\n"); // Print -1 if the sum is greater than n
		return 0; // Exit the function
	}

	// Print the difference between n and the sum of the integers
	printf("%d\n", n - sum);
	return 0;
}
