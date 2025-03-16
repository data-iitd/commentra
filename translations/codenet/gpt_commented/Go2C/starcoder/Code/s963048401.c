

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// Initialize a new scanner to read input from standard input
char* input = NULL;
size_t inputSize = 0;

// Scanner function reads a line of input and returns it as a string
char* Scanner() {
	if (getline(&input, &inputSize, stdin) == -1) {
		return NULL;
	}
	return input;
}

// intScanner function reads an integer from input and returns it
int intScanner() {
	char* s = Scanner();
	return atoi(s);
}

// floatScanner function reads a float64 from input and returns it
double floatScanner() {
	char* s = Scanner();
	return atof(s);
}

// stringToInt converts a string to an integer
int stringToInt(char* s) {
	return atoi(s);
}

// Declare a variable for the modulus value
int mod = 1000000007;

// Function to find the position to insert an integer in a sorted array
int binarySearch(int* arr, int arrSize, int x) {
	int l = 0;
	int r = arrSize - 1;
	int m = 0;
	
	// Iterate while the left index is less than the right index
	while (l <= r) {
		// Find the middle index
		m = l + (r - l) / 2;
		
		// If the middle index is equal to the target index, return it
		if (arr[m] == x) {
			return m;
		}
		
		// If the middle index is less than the target index, set the left index to the middle index + 1
		if (arr[m] < x) {
			l = m + 1;
		} else {
			// Otherwise, set the right index to the middle index - 1
			r = m - 1;
		}
	}
	
	// If the left index is greater than the right index, return the right index + 1
	return l;
}

// Function to find the number of unique integers in an array
int countUnique(int* arr, int arrSize) {
	// Initialize a slice to hold the unique sorted integers
	int* xs = malloc(arrSize * sizeof(int));
	xs[0] = arr[0];
	int xsSize = 1;
	
	// Iterate through the input integers starting from the second element
	for (int j = 1; j < arrSize; j++) {
		// Use binary search to find the position to insert the current integer
		int idx = binarySearch(xs, xsSize, arr[j]);
		
		// If the index is equal to the length of xs, append the integer
		if (idx == xsSize) {
			xs[xsSize] = arr[j];
			xsSize++;
		} else {
			// Otherwise, replace the existing integer at the found index
			xs[idx] = arr[j];
		}
	}
	
	// Return the number of unique integers found
	return xsSize;
}

// Main function
int main(int argc, char* argv[]) {
	// Set the scanner to split input by whitespace
	setbuf(stdin, NULL);
	
	// Read the number of elements
	int n = intScanner();
	
	// Initialize a slice to hold the integers
	int* as = malloc(n * sizeof(int));
	
	// Read n integers from input
	for (int i = 0; i < n; i++) {
		as[i] = intScanner();
	}
	
	// Find the number of unique integers in the array
	int xsSize = countUnique(as, n);
	
	// Print the number of unique integers found
	printf("%d\n", xsSize);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// Initialize a new scanner to read input from standard input
char* input = NULL;
size_t inputSize = 0;

// Scanner function reads a line of input and returns it as a string
char* Scanner() {
	if (getline(&input, &inputSize, stdin) == -1) {
		return NULL;
	}
	return input;
}

// intScanner function reads an integer from input and returns it
int intScanner() {
	char* s = Scanner();
	return atoi(s);
}

// floatScanner function reads a float64 from input and returns it
double floatScanner() {
	char* s = Scanner();
	return atof(s);
}

// stringToInt converts a string to an integer
int stringToInt(char* s) {
	return atoi(s);
}

// Declare a variable for the modulus value
int mod = 1000000007;

// Function to find the position to insert an integer in a sorted array
int binarySearch(int* arr, int arrSize, int x) {
	int l = 0;
	int r = arrSize - 1;
	int m = 0;
	
	// Iterate while the left index is less than the right index
	while (l <= r) {
		// Find the middle index
		m = l + (r - l) / 2;
		
		// If the middle index is equal to the target index, return it
		if (arr[m] == x) {
			return m;
		}
		
		// If the middle index is less than the target index, set the left index to the middle index + 1
		if (arr[m] < x) {
			l = m + 1;
		} else {
			// Otherwise, set the right index to the middle index - 1
			r = m - 1;
		}
	}
	
	// If the left index is greater than the right index, return the right index + 1
	return l;
}

// Function to find the number of unique integers in an array
int countUnique(int* arr, int arrSize) {
	// Initialize a slice to hold the unique sorted integers
	int* xs = malloc(arrSize * sizeof(int));
	xs[0] = arr[0];
	int xsSize = 1;
	
	// Iterate through the input integers starting from the second element
	for (int j = 1; j < arrSize; j++) {
		// Use binary search to find the position to insert the current integer
		int idx = binarySearch(xs, xsSize, arr[j]);
		
		// If the index is equal to the length of xs, append the integer
		if (idx == xsSize) {
			xs[xsSize] = arr[j];
			xsSize++;
		} else {
			// Otherwise, replace the existing integer at the found index
			xs[idx] = arr[j];
		}
	}
	
	// Return the number of unique integers found
	return xsSize;
}

// Main function
int main(int argc, char* argv[]) {
	// Set the scanner to split input by whitespace
	setbuf(stdin, NULL);
	
	// Read the number of elements
	int n = intScanner();
	
	// Initialize a slice to hold the integers
	int* as = malloc(n * sizeof(int));
	
	// Read n integers from input
	for (int i = 0; i < n; i++) {
		as[i] = intScanner();
	}
	
	// Find the number of unique integers in the array
	int xsSize = countUnique(as, n);
	
	// Print the number of unique integers found
	printf("%d\n", xsSize);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// Initialize a new scanner to read input from standard input
char* input = NULL;
size_t inputSize = 0;

// Scanner function reads a line of input and returns it as a string
char* Scanner() {
	if (getline(&input, &inputSize, stdin) == -1) {
		return NULL;
	}
	return input;
}

// intScanner function reads an integer from input and returns it
int intScanner() {
	char* s = Scanner();
	return atoi(s);
}

// floatScanner function reads a float64 from input and returns it
double floatScanner() {
	char* s = Scanner();
	return atof(s);
}

// stringToInt converts a string to an integer
int stringToInt(char* s) {
	return atoi(s);
}

// Declare a variable for the modulus value
int mod = 1000000007;

// Function to find the position to insert an integer in a sorted array
int binarySearch(int* arr, int arrSize, int x) {
	int l = 0;
	int r = arrSize - 1;
	int m = 0;
	
	// Iterate while the left index is less than the right index
	while (l <= r) {
		// Find the middle index
		m = l + (r - l) / 2;
		
		// If the middle index is equal to the target index, return it
		if (arr[m] == x) {
			return m;
		}
		
		// If the middle index is less than the target index, set the left index to the middle index + 1
		if (arr[m] < x) {
			l = m + 1;
		} else {
			// Otherwise, set the right index to the middle index - 1
			r = m - 1;
		}
	}
	
	// If the left index is greater than the right index, return the right index + 1
	return l;
}

// Function to find the number of unique integers in an array
int countUnique(int* arr, int arrSize) {
	// Initialize a slice to hold the unique sorted integers
	int* xs = malloc(arrSize * sizeof(int));
	xs[0] = arr[0];
	int xsSize = 1;
	
	// Iterate through the input integers starting from the second element
	for (int j = 1; j < arrSize; j++) {
		// Use binary search to find the position to insert the current integer
		int idx = binarySearch(xs, xsSize, arr[j]);
		
		// If the index is equal to the length of xs, append the integer
		if (idx == xsSize) {
			xs[xsSize] = arr[j];
			xsSize++;
		} else {
			// Otherwise, replace the existing integer at the found index
			xs[idx] = arr[j];
		}
	}
	
	// Return the number of unique integers found
	return xsSize;
}

// Main function
int main(int argc, char* argv[]) {
	// Set the scanner to split input by whitespace
	setbuf(stdin, NULL);
	
	// Read the number of elements
	int n = intScanner();
	
	// Initialize a slice to hold the integers
	int* as = malloc(n * sizeof(int));
	
	// Read n integers from input
	for (int i = 0; i < n; i++) {
		as[i] = intScanner();
	}
	
	// Find the number of unique integers in the array
	int xsSize = countUnique(as, n);
	
	// Print the number of unique integers found
	printf("%d\n", xsSize);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// Initialize a new scanner to read input from standard input
char* input = NULL;
size_t inputSize = 0;

// Scanner function reads a line of input and returns it as a string
char* Scanner() {
	if (getline(&input, &inputSize, stdin) == -1) {
		return NULL;
	}
	return input;
}

// intScanner function reads an integer from input and returns it
int intScanner() {
	char* s = Scanner();
	return atoi(s);
}

// floatScanner function reads a float64 from input and returns it
double floatScanner() {
	char* s = Scanner();
	return atof(s);
}

// stringToInt converts a string to an integer
int stringToInt(char* s) {
	return atoi(s);
}

// Declare a variable for the modulus value
int mod = 1000000007;

// Function to find the position to insert an integer in a sorted array
int binarySearch(int* arr, int arrSize, int x) {
	int l = 0;
	int r = arrSize - 1;
	int m = 0;
	
	// Iterate while the left index is less than the right index
	while (l <= r) {
		// Find the middle index
		m = l + (r - l) / 2;
		
		// If the middle index is equal to the target index, return it
		if (arr[m] == x) {
			return m;
		}
		
		// If the middle index is less than the target index, set the left index to the middle index + 1
		if (arr[m] < x) {
			l = m + 1;
		} else {
			// Otherwise, set the right index to the middle index - 1
			r = m - 1;
		}
	}
	
	// If the left index is greater than the right index, return the right index + 1
	return l;
}

// Function to find t