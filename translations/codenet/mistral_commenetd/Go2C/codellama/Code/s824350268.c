
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Constants definition
const int initialBufSize = 10000;
const int maxBufSize = 1000000;
const int mod = 1e9 + 7;

// Variables definition and initialization
char *scannerBuffer = NULL;
int scannerBufferSize = 0;
int scannerBufferIndex = 0;

// Helper functions for reading integers and strings from the standard input
int getInt() {
	// If the scanner buffer is empty, read a new line from the standard input
	if (scannerBufferIndex == scannerBufferSize) {
		scannerBufferSize = getline(&scannerBuffer, &scannerBufferSize, stdin);
		scannerBufferIndex = 0;
	}

	// Read the next integer from the scanner buffer
	int result = 0;
	while (scannerBufferIndex < scannerBufferSize && scannerBuffer[scannerBufferIndex] != ' ') {
		result = result * 10 + (scannerBuffer[scannerBufferIndex] - '0');
		scannerBufferIndex++;
	}
	scannerBufferIndex++;
	return result;
}

char *getString() {
	// If the scanner buffer is empty, read a new line from the standard input
	if (scannerBufferIndex == scannerBufferSize) {
		scannerBufferSize = getline(&scannerBuffer, &scannerBufferSize, stdin);
		scannerBufferIndex = 0;
	}

	// Read the next string from the scanner buffer
	char *result = malloc(sizeof(char) * 10000);
	int i = 0;
	while (scannerBufferIndex < scannerBufferSize && scannerBuffer[scannerBufferIndex] != ' ') {
		result[i] = scannerBuffer[scannerBufferIndex];
		i++;
		scannerBufferIndex++;
	}
	scannerBufferIndex++;
	result[i] = '\0';
	return result;
}

// Helper functions for basic arithmetic operations
int abs(int a) {
	return (a < 0) ? -a : a;
}

int pow(int p, int q) {
	return (q == 0) ? 1 : p * pow(p, q - 1);
}

int powMod(int n, int p) {
	// Base case: if p is 0, return 1
	if (p == 0) {
		return 1;
	} else if (p % 2 == 0) {
		// Recursive case: if p is even, square the base and recursively call powMod
		int t = powMod(n, p / 2);
		return (t * t) % mod;
	} else {
		// Recursive case: if p is odd, multiply the base with the result of recursively calling powMod with p-1
		return (n * powMod(n, p - 1)) % mod;
	}
}

// Helper functions for finding the minimum and maximum values
int min(int nums[], int n) {
	// Base case: if there are no numbers, panic
	if (n == 0) {
		printf("funciton min() requires at least one argument.\n");
		exit(1);
	}

	// Initialize the minimum value with the first number
	int res = nums[0];

	// Iterate through all numbers and update the minimum value if necessary
	for (int i = 1; i < n; i++) {
		res = (res < nums[i]) ? res : nums[i];
	}

	// Return the minimum value
	return res;
}

int max(int nums[], int n) {
	// Base case: if there are no numbers, panic
	if (n == 0) {
		printf("funciton max() requires at least one argument.\n");
		exit(1);
	}

	// Initialize the maximum value with the first number
	int res = nums[0];

	// Iterate through all numbers and update the maximum value if necessary
	for (int i = 1; i < n; i++) {
		res = (res > nums[i]) ? res : nums[i];
	}

	// Return the maximum value
	return res;
}

// Helper function for searching a string in an array of strings
int strSearch(char *a[], char *b) {
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
void printIntArray(int array[], int n) {
	// Convert the integer array to a string and print it without the brackets and the leading and trailing spaces
	char *strArray = malloc(sizeof(char) * 10000);
	sprintf(strArray, "%d", array);
	printf("%s\n", strArray + 1);
}

// Helper function for calculating the modulo operation
int calcMod(int x) {
	// Calculate the modulo of x with the modulus constant
	return x % mod;
}

// Helper function for reversing a string
char *reverse(char *s) {
	// Create a slice of runes from the input string, reverse it in-place, and convert it back to a string
	int n = strlen(s);
	for (int i = 0; i < n / 2; i++) {
		char tmp = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = tmp;
	}
	return s;
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
	int sqrtN = (int)sqrt(n);
	for (int i = 3; i <= sqrtN; i += 2) {
		// If n is divisible by i, it is not prime
		if (n % i == 0) {
			return 0;
		}
	}

	// If we have reached here, n is prime
	return 1;
}

// Main function
int main() {
	// Read the first integer from the standard input
	int N = getInt();

	// Calculate the square root of N
	int sqrtN = (int)sqrt(N);

	// Initialize the minimum number with N
	int min = N;

	// Iterate through all numbers from 1 to the square root of N
	for (int i = 1; i <= sqrtN; i++) {
		// Check if N is divisible by i
		if (N % i != 0) {
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

	// End of code
	printf("