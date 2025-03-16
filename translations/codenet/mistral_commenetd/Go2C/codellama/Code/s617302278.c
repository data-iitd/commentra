
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to read a line text from stdin and return its string
char* NextLine() {
	// Initializing empty string
	char* str = "";
	// Scanning next line from stdin
	scanf("%[^\n]", str);
	// Returning the scanned line text
	return str;
}

// Function to read a line text, that consists of ONLY INTEGERS DELIMITED BY SPACES, from stdin
// And then returns integers slice
int* NextIntsLine() {
	// Initializing empty integers slice
	int* ints = (int*)malloc(sizeof(int) * 1000000);
	// Reading a line text from stdin
	char* intsStr = NextLine();
	// Splitting the line text by space
	char* tmp = strtok(intsStr, " ");
	// Iterating through the split text and converting each string to integer
	// and appending it to the integers slice
	int i = 0;
	while (tmp != NULL) {
		// Converting string to integer
		ints[i] = atoi(tmp);
		// Appending integer to integers slice
		i++;
		// Fetching next token
		tmp = strtok(NULL, " ");
	}
	// Returning the integers slice
	return ints;
}

// Function to read a line text, that consists of ONLY CHARACTERS ARRANGED CONTINUOUSLY, from stdin
// And then returns runes slice
char* NextRunesLine() {
	// Returning the next line text as runes slice
	return NextLine();
}

// Function to find the maximum integer among input integers
// This function needs at least 1 argument (no argument causes panic)
int Max(int* integers, int len) {
	// Initializing maximum integer as first integer
	int m = integers[0];
	// Iterating through the input integers
	for (int i = 1; i < len; i++) {
		// If current integer is greater than maximum integer, update maximum integer
		if (m < integers[i]) {
			m = integers[i];
		}
	}
	// Returning the maximum integer
	return m;
}

// Function to find the minimum integer among input integers
// This function needs at least 1 argument (no argument causes panic)
int Min(int* integers, int len) {
	// Initializing minimum integer as first integer
	int m = integers[0];
	// Iterating through the input integers
	for (int i = 1; i < len; i++) {
		// If current integer is smaller than minimum integer, update minimum integer
		if (m > integers[i]) {
			m = integers[i];
		}
	}
	// Returning the minimum integer
	return m;
}

// Function to calculate integer power
int PowInt(int a, int e) {
	// Checking for negative integers
	if (a < 0 || e < 0) {
		printf("[argument error]: PowInt does not accept negative integers");
		return 0;
	}
	// Converting base and exponent to float64
	float fa = (float)a;
	float fe = (float)e;
	// Calculating the power using math.Pow
	float fanswer = pow(fa, fe);
	// Converting the answer back to integer
	return (int)fanswer;
}

// Function to calculate absolute value of an integer
int AbsInt(int a) {
	// Converting integer to float64
	float fa = (float)a;
	// Calculating the absolute value using math.Abs
	float fanswer = fabs(fa);
	// Converting the answer back to integer
	return (int)fanswer;
}

// Function to delete an element from a slice
int* DeleteElement(int* s, int len, int i) {
	// Checking for negative index or empty slice
	if (i < 0 || len <= i) {
		printf("[index error]");
		return NULL;
	}
	// Creating a new slice with zero capacity
	int* n = (int*)malloc(sizeof(int) * 1000000);
	// Appending elements before the index to the new slice
	for (int j = 0; j < i; j++) {
		n[j] = s[j];
	}
	// Appending elements after the index to the new slice
	for (int j = i + 1; j < len; j++) {
		n[j - 1] = s[j];
	}
	// Returning the new slice
	return n;
}

// Function to concatenate two slices
char* Concat(char* s, char* t) {
	// Creating a new slice with zero capacity
	char* n = (char*)malloc(sizeof(char) * 1000000);
	// Appending elements of the first slice to the new slice
	for (int i = 0; i < strlen(s); i++) {
		n[i] = s[i];
	}
	// Appending elements of the second slice to the new slice
	for (int i = 0; i < strlen(t); i++) {
		n[i + strlen(s)] = t[i];
	}
	// Returning the new slice
	return n;
}

// Variable declaration and initialization
int x;

// Main function
int main() {
	// Reading integers from stdin as a line text
	int* tmp = NextIntsLine();
	// Assigning the first integer to variable x
	x = tmp[0];
	// Initializing sum variable as zero
	int sum = 0;
	// Initializing index variable as one
	int i = 1;
	// Looping until the sum is greater than or equal to x
	while (sum < x) {
		// Adding current index to sum
		sum += i;
		// Incrementing index
		i++;
	}
	// Printing the index
	printf("%d\n", i);
	return 0;
}

