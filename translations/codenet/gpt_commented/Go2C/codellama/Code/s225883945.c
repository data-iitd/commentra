#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the next line of input as a string
char* next() {
	char* str = malloc(1000000); // Allocate memory for the string
	fgets(str, 1000000, stdin); // Read the next line of input
	return str; // Return the string
}

// Function to read the next line of input as an integer
int nextInt() {
	char* str = next(); // Read the next line of input
	int i = atoi(str); // Convert the string to an integer
	return i; // Return the integer value
}

// Function to read the next line of input as a float64
float nextFloat64() {
	char* str = next(); // Read the next line of input
	float f = atof(str); // Convert the string to a float64
	return f; // Return the float64 value
}

// Function to read 'n' integers from input and return them as a slice
int* nextInts(int n) {
	int* slice = malloc(n * sizeof(int)); // Allocate memory for the slice
	for (int i = 0; i < n; i++) {
		slice[i] = nextInt(); // Fill the slice with integers from input
	}
	return slice; // Return the slice of integers
}

int main() {
	// Set the scanner to split input by whitespace
	// <NOT-IMPLEMENTED>
	
	// Read two integers from input: n (number of elements) and k (some parameter)
	int n, k = nextInt(), nextInt();
	
	// Read 'n' integers into slice 'a'
	int* a = nextInts(n);
	
	// Avoid unused variable error by assigning a value to the first element of 'a'
	a[0] = 0;

	// Initialize sum with the value of k and set ans to 1
	int sum = k, ans = 1;
	
	// Loop to calculate how many times we can add k to the sum until it reaches or exceeds n
	while (sum < n) {
		sum = sum - 1 + k; // Update sum by subtracting 1 and adding k
		ans++; // Increment the answer counter
	}
	
	// Print the final answer
	printf("%d\n", ans);
	
	// Free the memory allocated for the slice
	free(a);
	
	// End of code
	return 0;
}


