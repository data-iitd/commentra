

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	// Read an integer input from the user
	int n = nextInt();
	
	// Calculate the integer square root of n
	int rt = (int) sqrt(n);
	
	// Initialize a variable to keep track of the minimum number of digits found
	int minf = 100;
	
	// Loop through all integers from 1 to the square root of n
	for (int i = 1; i < rt+1; i++) {
		// Check if i is a divisor of n
		if (n % i == 0) {
			// Calculate the corresponding divisor b
			int b = n / i;
			
			// Initialize a counter for the number of digits in b
			int ndigit = 0;
			
			// Count the number of digits in b
			while (b > 0) {
				b /= 10;
				ndigit++;
			}
			
			// Update minf with the minimum number of digits found
			minf = min(minf, ndigit);
		}
	}
	
	// Print the minimum number of digits found among the divisors
	printf("%d\n", minf);
}

// Define a constant for the buffer size
#define SIZE 1000000

// Function to read a full line of input
char* nextLine() {
	char* line = NULL;
	size_t len = 0;
	getline(&line, &len, stdin);
	return line;
}

// Function to read a line of input and split it into a string array
char** nextStringArray() {
	char* line = nextLine();
	return split(line, " ");
}

// Function to read an integer from input
int nextInt() {
	char* line = nextLine();
	int n = atoi(line);
	free(line);
	return n;
}

// Function to read a line of input and convert it into an array of integers
int* nextIntArray() {
	char** strings = nextStringArray();
	int n = 0;
	int* a = NULL;
	
	// Count the number of strings in the array
	while (strings[n]!= NULL) {
		n++;
	}
	
	// Convert each string in the array to an integer
	a = (int*) malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		a[i] = atoi(strings[i]);
	}
	
	// Free the array of strings
	free(strings);
	
	// Return the array
	return a;
}

// Function to return the minimum of two integers
int min(int i, int j) {
	if (i > j) {
		return j;
	}
	return i;
}

// Function to split a string into a string array
char** split(char* a, char* delim) {
	char** tokens = NULL;
	char* token = NULL;
	char* saveptr = NULL;
	char* line = strdup(a);
	
	// Split the string into tokens
	tokens = (char**) malloc(sizeof(char*) * 100);
	token = strtok_r(line, delim, &saveptr);
	int i = 0;
	while (token!= NULL) {
		tokens[i] = strdup(token);
		token = strtok_r(NULL, delim, &saveptr);
		i++;
	}
	tokens[i] = NULL;
	
	// Free the line
	free(line);
	
	// Return the array of tokens
	return tokens;
}

// Function to free an array of strings
void freeStringArray(char** a) {
	for (int i = 0; a[i]!= NULL; i++) {
		free(a[i]);
	}
	free(a);
}

// Function to free an array of integers
void freeIntArray(int* a) {
	free(a);
}

// Function to free a 2D array of integers
void free2DIntArray(int** a, int n) {
	for (int i = 0; i < n; i++) {
		free(a[i]);
	}
	free(a);
}

// Function to free a 2D array of strings
void free2DStringArray(char** a, int n) {
	for (int i = 0; i < n; i++) {
		freeStringArray(a[i]);
	}
	free(a);
}

// Function to print a 2D array of integers
void print2DIntArray(int** a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; a[i][j]!= -1; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

// Function to print a 2D array of strings
void print2DStringArray(char** a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; a[i][j]!= NULL; j++) {
			printf("%s ", a[i][j]);
		}
		printf("\n");
	}
}

// Function to print a 1D array of integers
void printIntArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

// Function to print a 1D array of strings
void printStringArray(char** a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s ", a[i]);
	}
	printf("\n");
}

// Function to print an integer
void printInt(int a) {
	printf("%d\n", a);
}

// Function to print a string
void printString(char* a) {
	printf("%s\n", a);
}

// Function to print a newline
void printNewline() {
	printf("\n");
}

// Function to print a tab
void printTab() {
	printf("\t");
}

// Function to print a null character
void printNull() {
	printf("\0");
}

// Function to print a space
void printSpace() {
	printf(" ");
}

// Function to print a newline character
void printNewlineChar() {
	printf("\n");
}

// Function to print a tab character
void printTabChar() {
	printf("\t");
}

// Function to print a null character
void printNullChar() {
	printf("\0");
}

// Function to print a space character
void printSpaceChar() {
	printf(" ");
}

// Function to print a boolean
void printBool(int a) {
	if (a) {
		printf("true");
	} else {
		printf("false");
	}
	printf("\n");
}

// Function to print a boolean character
void printBoolChar(int a) {
	if (a) {
		printf("t");
	} else {
		printf("f");
	}
	printf("\n");
}

// Function to print a newline character
void printNewlineChar() {
	printf("\n");
}

// Function to print a tab character
void printTabChar() {
	printf("\t");
}

// Function to print a null character
void printNullChar() {
	printf("\0");
}

// Function to print a space character
void printSpaceChar() {
	printf(" ");
}

// Function to print a newline
void printNewline() {
	printf("\n");
}

// Function to print a tab
void printTab() {
	printf("\t");
}

// Function to print a null
void printNull() {
	printf("\0");
}

// Function to print a space
void printSpace() {
	printf(" ");
}

// Function to print a newline character
void printNewlineChar() {
	printf("\n");
}

// Function to print a tab character
void printTabChar() {
	printf("\t");
}

// Function to print a null character
void printNullChar() {
	printf("\0");
}

// Function to print a space character
void printSpaceChar() {
	printf(" ");
}

// Function to print a boolean
void printBool(int a) {
	if (a) {
		printf("true");
	} else {
		printf("false");
	}
	printf("\n");
}

// Function to print a boolean character
void printBoolChar(int a) {
	if (a) {
		printf("t");
	} else {
		printf("f");
	}
	printf("\n");
}

// Function to print a newline character
void printNewlineChar() {
	printf("\n");
}

// Function to print a tab character
void printTabChar() {
	printf("\t");
}

// Function to print a null character
void printNullChar() {
	printf("\0");
}

// Function to print a space character
void printSpaceChar() {
	printf(" ");
}

// Function to print a newline
void printNewline() {
	printf("\n");
}

// Function to print a tab
void printTab() {
	printf("\t");
}

// Function to print a null
void printNull() {
	printf("\0");
}

// Function to print a space
void printSpace() {
	printf(" ");
}

// Function to print a newline character
void printNewlineChar() {
	printf("\n");
}

// Function to print a tab character
void printTabChar() {
	printf("\t");
}

// Function to print a null character
void printNullChar() {
	printf("\0");
}

// Function to print a space character
void printSpaceChar() {
	printf(" ");
}

// Function to print a boolean
void printBool(int a) {
	if (a) {
		printf("true");
	} else {
		printf("false");
	}
	printf("\n");
}

// Function to print a boolean character
void printBoolChar(int a) {
	if (a) {
		printf("t");
	} else {
		printf("f");
	}
	printf("\n");
}

// Function to print a newline character
void printNewlineChar() {
	printf("\n");
}

// Function to print a tab character
void printTabChar() {
	printf("\t");
}

// Function to print a null character
void printNullChar() {
	printf("\0");
}

// Function to print a space character
void printSpaceChar() {
	printf(" ");
}

// Function to print a newline
void printNewline() {
	printf("\n");
}

// Function to print a tab
void printTab() {
	printf("\t");
}

// Function to print a null
void printNull() {
	printf("\0");
}

// Function to print a space
void printSpace() {
	printf(" ");
}

// Function to print a newline character
void printNewlineChar() {
	printf("\n");
}

// Function to print a tab character
void printTabChar() {
	printf("\t");
}

// Function to print a null character
void printNullChar() {
	printf("\0");
}

// Function to print a space character
void printSpaceChar() {
	printf(" ");
}

// Function to print a boolean
void printBool(int a) {
	if (a) {
		printf("true");
	} else {
		printf("false");
	}
	printf("\n");
}

// Function to print a boolean character
void printBoolChar(int a) {
	if (a) {
		printf("t");
	} else {
		printf("f");
	}
	printf("\n");
}

// Function to print a newline character
void printNewlineChar() {
	printf("\n");
}

// Function to print a tab character
void printTabChar() {
	printf("\t");
}

// Function to print a null character
void printNullChar() {
	printf("\0");
}

// Function to print a space character
void printSpaceChar() {
	printf(" ");
}

// Function to print a newline
void printNewline() {
	printf("\n");
}

// Function to print a tab
void printTab() {
	printf("\t");
}

// Function to print a null
void printNull() {
	printf("\0");
}

// Function to print a space
void printSpace() {
	printf(" ");
}

// Function to print a newline character
void printNewlineChar() {
	printf("\n");
}

// Function to print a tab character
void printTabChar() {
	printf("\t");
}

// Function to print a null character
void printNullChar() {
	printf("\0");
}

// Function to print a space character
void printSpaceChar() {
	printf(" ");
}

// Function to print a boolean
void printBool(int a) {
	if (a) {
		printf("true");
	} else {
		printf("false");
	}
	printf("\n");
}

// Function to print a boolean character
void printBoolChar(int a) {
	if (a) {
		printf("t");
	} else {
		printf("f");
	}
	printf("\n");
}

// Function to print a newline character
void printNewlineChar() {
	printf("\n");
}

// Function to print a tab character
void printTabChar() {
	printf("\t");
}

// Function to print a null character
void printNullChar() {
	printf("\0");
}

// Function to print a space character
void printSpaceChar() {
	printf(" ");
}

// Function to print a newline
void printNewline() {
	printf("\n");
}

// Function to print a tab
void printTab() {
	printf("\t");
}

// Function to print a null
voi