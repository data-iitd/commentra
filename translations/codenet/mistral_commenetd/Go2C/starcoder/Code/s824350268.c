#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants definition
#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 1000000
#define MOD 1000000007

// Variables definition and initialization
int N;

// Function prototypes
int getInt();
int calcMod(int x);
int min(int a, int b);
int max(int a, int b);
int powMod(int n, int p);
int strSearch(char **a, int n, char *b);
void printIntArray(int *array, int n);
void reverse(char *s);
int isPrime(int n);

// Main function
int main() {
	// Read the first integer from the standard input
	N = getInt();

	// Calculate the square root of N
	int sqrtN = (int) sqrt(N);

	// Initialize the minimum number with N
	int min = N;

	// Iterate through all numbers from 1 to the square root of N
	for (int i = 1; i <= sqrtN; i++) {
		// Check if N is divisible by i
		if (N % i!= 0) {
			continue;
		}

		// Calculate the number of divisors of i and N
		int num = i + (N / i) - 2;

		// Update the minimum number if the current number is smaller
		if (num < min) {
			min = num;
		}
	}

	// Print the minimum number
	printf("%d\n", min);
}

// Helper functions for reading integers and strings from the standard input
int getInt() {
	int res;
	scanf("%d", &res);
	return res;
}

// Helper function for calculating the modulo operation
int calcMod(int x) {
	// Calculate the modulo of x with the modulus constant
	return x % MOD;
}

// Helper functions for finding the minimum and maximum values
int min(int a, int b) {
	// Return the minimum value
	return (a < b)? a : b;
}

int max(int a, int b) {
	// Return the maximum value
	return (a > b)? a : b;
}

// Helper function for calculating the power of a number
int powMod(int n, int p) {
	// Base case: if p is 0, return 1
	if (p == 0) {
		return 1;
	} else if (p % 2 == 0) {
		// Recursive case: if p is even, square the base and recursively call powMod
		int t = powMod(n, p / 2);
		return calcMod(t * t);
	} else {
		// Recursive case: if p is odd, multiply the base with the result of recursively calling powMod with p-1
		return calcMod(n * powMod(n, p - 1));
	}
}

// Helper function for searching a string in an array of strings
int strSearch(char **a, int n, char *b) {
	// Iterate through all strings in the array and return true if the target string is found
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i], b) == 0) {
			return 1;
		}
	}

	// If the target string is not found, return false
	return 0;
}

// Helper function for printing an integer array
void printIntArray(int *array, int n) {
	// Convert the integer array to a string and print it without the brackets and the leading and trailing spaces
	char strArray[10000];
	sprintf(strArray, "%d", array);
	printf("%s", strArray + 1);
}

// Helper function for reversing a string
void reverse(char *s) {
	// Create a new string that is the same as the input string but reversed
	char *newS = malloc(sizeof(char) * (strlen(s) + 1));
	int i, j;
	for (i = 0, j = strlen(s) - 1; i <= j; i++, j--) {
		newS[i] = s[j];
		newS[j] = s[i];
	}
	newS[i] = '\0';

	// Copy the reversed string to the input string
	strcpy(s, newS);

	// Free the memory allocated for the new string
	free(newS);
}

// Helper function for checking if a number is prime
int isPrime(int n) {
	// Base case: if n is less than 2, it is not prime
	if (n < 2) {
		return 0;
	}

	// Base case: if n is 2, it is prime
	if (n == 2) {
		return 1;
	}

	// Base case: if n is even, it is not prime
	if (n % 2 == 0) {
		return 0;
	}

	// Calculate the square root of n and iterate through all odd numbers from 3 to the square root of n
	int sqrtN = (int) sqrt(n);
	for (int i = 3; i <= sqrtN; i += 2) {
		// If n is divisible by i, it is not prime
		if (n % i == 0) {
			return 0;
		}
	}

	// If we have reached here, n is prime
	return 1;
}

