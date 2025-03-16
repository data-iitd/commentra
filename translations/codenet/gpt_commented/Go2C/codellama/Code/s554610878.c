
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Constants for buffer sizes
const int initialBufSize = 10000;
const int maxBufSize = 1000000;

// Global variables for scanner and modulus
int mod = 1e9 + 7; // Modulus value for calculations

// Function to read an integer from input
int getInt() {
	char *str = malloc(maxBufSize * sizeof(char)); // Allocate memory for the string
	fgets(str, maxBufSize, stdin); // Read a string from input
	int i = atoi(str); // Convert the string to an integer
	free(str); // Free the allocated memory
	return i; // Return the integer value
}

// Function to read a string from input
char *getString() {
	char *str = malloc(maxBufSize * sizeof(char)); // Allocate memory for the string
	fgets(str, maxBufSize, stdin); // Read a string from input
	str[strcspn(str, "\n")] = 0; // Remove the newline character
	return str; // Return the string
}

// Function to compute the absolute value of an integer
int abs(int a) {
	return (int)fabs(a); // Use fabs to get the absolute value
}

// Function to compute p raised to the power of q
int pow(int p, int q) {
	return (int)pow(p, q); // Use pow for exponentiation
}

// Function to find the minimum value among given integers
int min(int nums[], int n) {
	int res = nums[0]; // Initialize result with the first number
	for (int i = 0; i < n; i++) {
		res = (int)fmin(res, nums[i]); // Update result with the minimum value
	}
	return res; // Return the minimum value
}

// Function to find the maximum value among given integers
int max(int nums[], int n) {
	int res = nums[0]; // Initialize result with the first number
	for (int i = 0; i < n; i++) {
		res = (int)fmax(res, nums[i]); // Update result with the maximum value
	}
	return res; // Return the maximum value
}

// Function to check if a string exists in a slice of strings
int strSearch(char *a[], char *b) {
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		if (strcmp(a[i], b) == 0) {
			return 1; // Return true if the string is found
		}
	}
	return 0; // Return false if the string is not found
}

// Function to print an array of integers
void printIntArray(int array[], int n) {
	char *str = malloc(maxBufSize * sizeof(char)); // Allocate memory for the string
	sprintf(str, "%d", array); // Convert the array to a string
	printf("%s\n", str); // Print the string representation
	free(str); // Free the allocated memory
}

// Function to calculate the modulus of x with respect to the defined mod
int calcMod(int x) {
	return x % mod; // Return the result of x modulo mod
}

