
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Initialize a new scanner to read from standard input
FILE *sc = stdin;

// nextInt reads the next integer from standard input
int nextInt() {
	int t;
	fscanf(sc, "%d", &t); // Scan the next line of input
	return t; // Return the integer value
}

// scanNums reads a specified number of integers from standard input and returns them as a slice
int *scanNums(int len) {
	int *nums = (int *)malloc(len * sizeof(int)); // Allocate memory for the slice
	int num;
	for (int i = 0; i < len; i++) {
		fscanf(sc, "%d", &num); // Read an integer from standard input
		nums[i] = num; // Append the integer to the slice
	}
	return nums; // Return the slice of integers
}

// pattern1 calculates a specific pattern based on the first five integers in the slice
int pattern1(int *l) {
	int n = (l[0]*l[3]) + (l[1]*l[4]); // Calculate the result based on the formula
	return n; // Return the calculated value
}

// pattern2 calculates another pattern based on the maximum of the last two integers
int pattern2(int *l) {
	int n = 2 * l[2] * max(l[3], l[4]); // Calculate the result using the maximum value
	return n; // Return the calculated value
}

// pattern3 calculates a third pattern that combines the minimum value and a function call
int pattern3(int *l) {
	int n = 2*l[2]*min(l[3], l[4]) + (doch(l)); // Calculate the result using the minimum value and doch function
	return n; // Return the calculated value
}

// min returns the minimum value from a variable number of integer arguments
int min(int nums, ...) {
	va_list args;
	va_start(args, nums);
	int res = va_arg(args, int); // Initialize the result with the first argument
	for (int i = 0; i < nums; i++) {
		res = (int)fmin(res, va_arg(args, int)); // Update the result to the minimum value
	}
	va_end(args);
	return res; // Return the minimum value
}

// max returns the maximum value from a variable number of integer arguments
int max(int nums, ...) {
	va_list args;
	va_start(args, nums);
	int res = va_arg(args, int); // Initialize the result with the first argument
	for (int i = 0; i < nums; i++) {
		res = (int)fmax(res, va_arg(args, int)); // Update the result to the maximum value
	}
	va_end(args);
	return res; // Return the maximum value
}

// doch calculates a value based on the difference between the last two integers in the slice
int doch(int *l) {
	if (l[3] > l[4]) {
		return l[0] * (l[3] - l[4]); // Return the product if the fourth integer is greater
	} else {
		return l[1] * (l[4] - l[3]); // Return the product if the fifth integer is greater
	}
}

// main function where the program execution begins
int main() {
	int len = 5; // Define the number of integers to read
	int *l = scanNums(len); // Read the integers into a slice
	// Print the minimum value from the three calculated patterns
	printf("%d\n", min(3, pattern1(l), pattern2(l), pattern3(l)));
	return 0;
}

