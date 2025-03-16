

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to scan an array of integers from standard input
int* scanArrayInt(int* ret) {
	// Read a line from standard input
	char* line = NULL;
	size_t len = 0;
	getline(&line, &len, stdin);
	// Split the input line into strings and convert each to an integer
	char* token = strtok(line, " ");
	int i = 0;
	while (token!= NULL) {
		ret[i] = atoi(token);
		i++;
		token = strtok(NULL, " ");
	}
	// Return the array of integers
	return ret;
}

// Function to print an array of integers to standard output
void printArrayInt(int* arr, int len) {
	// Loop through the array and print each element
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	// Print a newline
	printf("\n");
}

// Function to calculate the number of taps needed to get to a certain number
int calculateTaps(int a, int b) {
	// Initialize the number of taps needed to 0
	int tap = 0;
	// Initialize the consent variable to 1 (the starting point)
	int consent = 1;
	
	// Loop until the consent value is less than b
	while (consent < b) {
		// Update consent by adding (a - 1) to it
		consent = consent + a - 1;
		// Increment the tap count
		tap++;
	}
	
	// Return the total number of taps needed
	return tap;
}

// Main function
int main(int argc, char** argv) {
	// Declare an array to hold the integers
	int arr[2];
	// Scan the array of integers from standard input
	scanArrayInt(arr);
	// Assign the first two elements of the array to variables a and b
	int a = arr[0];
	int b = arr[1];
	// Calculate the number of taps needed to get to b
	int tap = calculateTaps(a, b);
	// Print the total number of taps needed
	printf("%d\n", tap);
	// Return from main
	return 0;
}

The C code above is a complete solution to the problem.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to scan an array of integers from standard input
int* scanArrayInt(int* ret) {
	// Read a line from standard input
	char* line = NULL;
	size_t len = 0;
	getline(&line, &len, stdin);
	// Split the input line into strings and convert each to an integer
	char* token = strtok(line, " ");
	int i = 0;
	while (token!= NULL) {
		ret[i] = atoi(token);
		i++;
		token = strtok(NULL, " ");
	}
	// Return the array of integers
	return ret;
}

// Function to print an array of integers to standard output
void printArrayInt(int* arr, int len) {
	// Loop through the array and print each element
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	// Print a newline
	printf("\n");
}

// Function to calculate the number of taps needed to get to a certain number
int calculateTaps(int a, int b) {
	// Initialize the number of taps needed to 0
	int tap = 0;
	// Initialize the consent variable to 1 (the starting point)
	int consent = 1;
	
	// Loop until the consent value is less than b
	while (consent < b) {
		// Update consent by adding (a - 1) to it
		consent = consent + a - 1;
		// Increment the tap count
		tap++;
	}
	
	// Return the total number of taps needed
	return tap;
}

// Main function
int main(int argc, char** argv) {
	// Declare an array to hold the integers
	int arr[2];
	// Scan the array of integers from standard input
	scanArrayInt(arr);
	// Assign the first two elements of the array to variables a and b
	int a = arr[0];
	int b = arr[1];
	// Calculate the number of taps needed to get to b
	int tap = calculateTaps(a, b);
	// Print the total number of taps needed
	printf("%d\n", tap);
	// Return from main
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to scan an array of integers from standard input
int* scanArrayInt(int* ret) {
	// Read a line from standard input
	char* line = NULL;
	size_t len = 0;
	getline(&line, &len, stdin);
	// Split the input line into strings and convert each to an integer
	char* token = strtok(line, " ");
	int i = 0;
	while (token!= NULL) {
		ret[i] = atoi(token);
		i++;
		token = strtok(NULL, " ");
	}
	// Return the array of integers
	return ret;
}

// Function to print an array of integers to standard output
void printArrayInt(int* arr, int len) {
	// Loop through the array and print each element
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	// Print a newline
	printf("\n");
}

// Function to calculate the number of taps needed to get to a certain number
int calculateTaps(int a, int b) {
	// Initialize the number of taps needed to 0
	int tap = 0;
	// Initialize the consent variable to 1 (the starting point)
	int consent = 1;
	
	// Loop until the consent value is less than b
	while (consent < b) {
		// Update consent by adding (a - 1) to it
		consent = consent + a - 1;
		// Increment the tap count
		tap++;
	}
	
	// Return the total number of taps needed
	return tap;
}

// Main function
int main(int argc, char** argv) {
	// Declare an array to hold the integers
	int arr[2];
	// Scan the array of integers from standard input
	scanArrayInt(arr);
	// Assign the first two elements of the array to variables a and b
	int a = arr[0];
	int b = arr[1];
	// Calculate the number of taps needed to get to b
	int tap = calculateTaps(a, b);
	// Print the total number of taps needed
	printf("%d\n", tap);
	// Return from main
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to scan an array of integers from standard input
int* scanArrayInt(int* ret) {
	// Read a line from standard input
	char* line = NULL;
	size_t len = 0;
	getline(&line, &len, stdin);
	// Split the input line into strings and convert each to an integer
	char* token = strtok(line, " ");
	int i = 0;
	while (token!= NULL) {
		ret[i] = atoi(token);
		i++;
		token = strtok(NULL, " ");
	}
	// Return the array of integers
	return ret;
}

// Function to print an array of integers to standard output
void printArrayInt(int* arr, int len) {
	// Loop through the array and print each element
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	// Print a newline
	printf("\n");
}

// Function to calculate the number of taps needed to get to a certain number
int calculateTaps(int a, int b) {
	// Initialize the number of taps needed to 0
	int tap = 0;
	// Initialize the consent variable to 1 (the starting point)
	int consent = 1;
	
	// Loop until the consent value is less than b
	while (consent < b) {
		// Update consent by adding (a - 1) to it
		consent = consent + a - 1;
		// Increment the tap count
		tap++;
	}
	
	// Return the total number of taps needed
	return tap;
}

// Main function
int main(int argc, char** argv) {
	// Declare an array to hold the integers
	int arr[2];
	// Scan the array of integers from standard input
	scanArrayInt(arr);
	// Assign the first two elements of the array to variables a and b
	int a = arr[0];
	int b = arr[1];
	// Calculate the number of taps needed to get to b
	int tap = calculateTaps(a, b);
	// Print the total number of taps needed
	printf("%d\n", tap);
	// Return from main
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to scan an array of integers from standard input
int* scanArrayInt(int* ret) {
	// Read a line from standard input
	char* line = NULL;
	size_t len = 0;
	getline(&line, &len, stdin);
	// Split the input line into strings and convert each to an integer
	char* token = strtok(line, " ");
	int i = 0;
	while (token!= NULL) {
		ret[i] = atoi(token);
		i++;
		token = strtok(NULL, " ");
	}
	// Return the array of integers
	return ret;
}

// Function to print an array of integers to standard output
void printArrayInt(int* arr, int len) {
	// Loop through the array and print each element
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	// Print a newline
	printf("\n");
}

// Function to calculate the number of taps needed to get to a certain number
int calculateTaps(int a, int b) {
	// Initialize the number of taps needed to 0
	int tap = 0;
	// Initialize the consent variable to 1 (the starting point)
	int consent = 1;
	
	// Loop until the consent value is less than b
	while (consent < b) {
		// Update consent by adding (a - 1) to it
		consent = consent + a - 1;
		// Increment the tap count
		tap++;
	}
	
	// Return the total number of taps needed
	return tap;
}

// Main function
int main(int argc, char** argv) {
	// Declare an array to hold the integers
	int arr[2];
	// Scan the array of integers from standard input
	scanArrayInt(arr);
	// Assign the first two elements of the array to variables a and b
	int a = arr[0];
	int b = arr[1];
	// Calculate the number of taps needed to get to b
	int tap = calculateTaps(a, b);
	// Print the total number of taps needed
	printf("%d\n", tap);
	// Return from main
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to scan an array of integers from standard input
int* scanArrayInt(int* ret) {
	// Read a line from standard input
	char* line = NULL;
	size_t len = 0;
	getline(&line, &len, stdin);
	// Split the input line into strings and convert each to an integer
	char* token = strtok(line, " ");
	int i = 0;
	while (token!= NULL) {
		ret[i] = atoi(token);
		i++;
		token = strtok(NULL, " ");
	}
	// Return the array of integers
	return ret;
}

// Function to print an array of integers to standard output
void printArrayInt(int* arr, int len) {
	// Loop through the array and print each element
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	// Print a newline
	printf("\n");
}

// Function to calculate the number of taps needed to get to a certain number
int calculateTaps(int a, int b) {
	// Initialize the number of taps needed to 0
	int tap = 0;
	// Initialize the consent variable to 1 (the starting point)
	int consent = 1;
	
	// Loop until the consent value is less than b
	while (consent < b) {
		// Update consent by adding (a - 1) to it
		consent = consent + a - 1;
		// Increment the tap count
		tap++;
	}
	
	// Return the total number of taps needed
	return tap;
}

// Main function
int main(int argc, char** argv) {
	// Declare an array to hold the integers
	int arr