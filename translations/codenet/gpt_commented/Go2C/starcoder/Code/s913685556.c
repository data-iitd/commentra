

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to return the maximum of two integers
int max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

// Scanner struct to handle input reading
typedef struct {
	char *buf; // Buffer to hold the input data
	int p; // Current position in the buffer
} Scanner;

// Function to initialize and return a new Scanner
Scanner *NewScanner() {
	Scanner *s = (Scanner *)malloc(sizeof(Scanner)); // Allocate memory for the Scanner
	s->buf = (char *)malloc(1000); // Allocate memory for the buffer
	s->p = 0; // Initialize the current position
	return s; // Return the Scanner
}

// Function to read the next token from the input
char *Next(Scanner *s) {
	s->pre(); // Ensure there is data to read
	int start = s->p; // Mark the start of the token
	// Iterate through the buffer to find the next space
	for (; s->p < strlen(s->buf); s->p++) {
		if (s->buf[s->p] =='') {
			break;
		}
	}
	char *result = (char *)malloc(s->p - start + 1); // Allocate memory for the token
	strncpy(result, s->buf + start, s->p - start); // Copy the token to the result
	result[s->p - start] = '\0'; // Add a null terminator
	s->p++; // Move past the space
	return result; // Return the token
}

// Function to read the next line from the input
char *NextLine(Scanner *s) {
	s->pre(); // Ensure there is data to read
	int start = s->p; // Mark the start of the line
	s->p = strlen(s->buf); // Move to the end of the buffer
	char *result = (char *)malloc(s->p - start + 1); // Allocate memory for the line
	strncpy(result, s->buf + start, s->p - start); // Copy the line to the result
	result[s->p - start] = '\0'; // Add a null terminator
	return result; // Return the line
}

// Function to read the next integer from the input
int NextInt(Scanner *s) {
	char *token = Next(s); // Read the next token
	int result = atoi(token); // Convert the token to an integer
	free(token); // Free the token
	return result; // Return the integer
}

// Function to read the next int64 from the input
int64_t NextInt64(Scanner *s) {
	char *token = Next(s); // Read the next token
	int64_t result = atoll(token); // Convert the token to an int64
	free(token); // Free the token
	return result; // Return the int64
}

// Function to read the next float64 from the input
double NextFloat(Scanner *s) {
	char *token = Next(s); // Read the next token
	double result = atof(token); // Convert the token to a float64
	free(token); // Free the token
	return result; // Return the float64
}

// Function to read a space-separated array of integers from the input
int *NextIntArray(Scanner *s) {
	s->pre(); // Ensure there is data to read
	int start = s->p; // Mark the start of the array
	int *result = (int *)malloc(sizeof(int)); // Allocate memory for the array
	int i = 0; // Initialize the index
	// Iterate through the buffer to read integers
	for (; s->p < strlen(s->buf) + 1; s->p++) {
		if (s->p == strlen(s->buf) || s->buf[s->p] =='') {
			int v = atoi(s->buf + start); // Parse the integer
			result = (int *)realloc(result, sizeof(int) * (i + 1)); // Reallocate the array
			result[i] = v; // Append the integer to the result array
			i++; // Increment the index
			start = s->p + 1; // Update the start position for the next integer
		}
	}
	return result; // Return the array
}

// Function to read a space-separated array of int64 from the input
int64_t *NextInt64Array(Scanner *s) {
	s->pre(); // Ensure there is data to read
	int start = s->p; // Mark the start of the array
	int64_t *result = (int64_t *)malloc(sizeof(int64_t)); // Allocate memory for the array
	int i = 0; // Initialize the index
	// Iterate through the buffer to read int64 values
	for (; s->p < strlen(s->buf) + 1; s->p++) {
		if (s->p == strlen(s->buf) || s->buf[s->p] =='') {
			int64_t v = atoll(s->buf + start); // Parse the int64
			result = (int64_t *)realloc(result, sizeof(int64_t) * (i + 1)); // Reallocate the array
			result[i] = v; // Append the int64 to the result array
			i++; // Increment the index
			start = s->p + 1; // Update the start position for the next int64
		}
	}
	return result; // Return the array
}

// Function to read a space-separated map of integers to booleans from the input
int *NextMap(Scanner *s) {
	s->pre(); // Ensure there is data to read
	int start = s->p; // Mark the start of the map
	int *result = (int *)malloc(sizeof(int)); // Allocate memory for the map
	int i = 0; // Initialize the index
	// Iterate through the buffer to read integers
	for (; s->p < strlen(s->buf); s->p++) {
		if (s->buf[s->p] =='') {
			int v = atoi(s->buf + start); // Parse the integer
			result = (int *)realloc(result, sizeof(int) * (i + 1)); // Reallocate the map
			result[i] = v; // Append the integer to the result map
			i++; // Increment the index
			start = s->p + 1; // Update the start position for the next integer
		}
	}
	int v = atoi(s->buf + start); // Parse the last integer
	result = (int *)realloc(result, sizeof(int) * (i + 1)); // Reallocate the map
	result[i] = v; // Append the last integer to the result map
	i++; // Increment the index
	result = (int *)realloc(result, sizeof(int) * (i + 1)); // Reallocate the map
	result[i] = -1; // Set the last map entry to -1
	return result; // Return the map
}

// Function to check if more data needs to be read into the buffer
void pre(Scanner *s) {
	if (s->p >= strlen(s->buf)) {
		readLine(s); // Read a new line if the current position is at the end of the buffer
		s->p = 0; // Reset the position to the start of the new buffer
	}
}

// Function to read a full line from the input and store it in the buffer
void readLine(Scanner *s) {
	free(s->buf); // Free the old buffer
	s->buf = (char *)malloc(1000); // Allocate memory for the new buffer
	s->p = 0; // Reset the current position
	while (1) {
		char *l = (char *)malloc(1000); // Allocate memory for the line
		int p = 0; // Initialize the current position
		while (1) {
			l[p] = getchar(); // Read a character from the input
			if (l[p] == '\n') { // Check if the character is a newline
				break; // Break if the character is a newline
			}
			p++; // Increment the current position
		}
		l[p] = '\0'; // Add a null terminator
		s->buf = (char *)realloc(s->buf, strlen(s->buf) + strlen(l) + 1); // Reallocate the buffer
		strcat(s->buf, l); // Append the line to the buffer
		free(l); // Free the line
		if (p == 0) { // Check if the line is complete
			break; // Break if the line is complete
		}
	}
}

// Main function
int main() {
	// Create a new scanner to read input
	Scanner *s = NewScanner();
	// Read two integers from input
	int A = NextInt(s);
	int B = NextInt(s);

	// Calculate the maximum of A+B, A-B, and A*B
	int mx = max(A + B, A - B);
	mx = max(mx, A * B);
	// Print the maximum value
	printf("%d\n", mx);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to return the maximum of two integers
int max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

// Scanner struct to handle input reading
typedef struct {
	char *buf; // Buffer to hold the input data
	int p; // Current position in the buffer
} Scanner;

// Function to initialize and return a new Scanner
Scanner *NewScanner() {
	Scanner *s = (Scanner *)malloc(sizeof(Scanner)); // Allocate memory for the Scanner
	s->buf = (char *)malloc(1000); // Allocate memory for the buffer
	s->p = 0; // Initialize the current position
	return s; // Return the Scanner
}

// Function to read the next token from the input
char *Next(Scanner *s) {
	s->pre(); // Ensure there is data to read
	int start = s->p; // Mark the start of the token
	// Iterate through the buffer to find the next space
	for (; s->p < strlen(s->buf); s->p++) {
		if (s->buf[s->p] =='') {
			break;
		}
	}
	char *result = (char *)malloc(s->p - start + 1); // Allocate memory for the token
	strncpy(result, s->buf + start, s->p - start); // Copy the token to the result
	result[s->p - start] = '\0'; // Add a null terminator
	s->p++; // Move past the space
	return result; // Return the token
}

// Function to read the next line from the input
char *NextLine(Scanner *s) {
	s->pre(); // Ensure there is data to read
	int start = s->p; // Mark the start of the line
	s->p = strlen(s->buf); // Move to the end of the buffer
	char *result = (char *)malloc(s->p - start + 1); // Allocate memory for the line
	strncpy(result, s->buf + start, s->p - start); // Copy the line to the result
	result[s->p - start] = '\0'; // Add a null terminator
	return result; // Return the line
}

// Function to read the next integer from the input
int NextInt(Scanner *s) {
	char *token = Next(s); // Read the next token
	int result = atoi(token); // Convert the token to an integer
	free(token); // Free the token
	return result; // Return the integer
}

// Function to read the next int64 from the input
int64_t NextInt64(Scanner *s) {
	char *token = Next(s); // Read the next token
	int64_t result = atoll(token); // Convert the token to an int64
	free(token); // Free the token
	return result; // Return the int64
}

// Function to read the next float64 from the input
double NextFloat(Scanner *s) {
	char *token = Next(s); // Read the next token
	double result = atof(token); // Convert the token to a float64
	free(token); // Free the token
	return result; // Return the float64
}

// Function to read a space-separated array of integers from the input
int *NextIntArray(Scanner *s) {
	s->pre(); // Ensure there is data to read
	int start = s->p; // Mark the start of the array
	int *result = (int *)malloc(sizeof(int)); // Allocate memory for the array
	int i = 0; // Initialize the index
	// Iterate through the buffer to read integers
	for (; s->p < strlen(s->buf) + 1; s->p++) {
		if (s->p == strlen(s->buf) || s->buf[s->p] =='') {
			int v = atoi(s->buf + start); // Parse the integer
			result = (int *)realloc(result, sizeof(int) * (i + 1)); // Reallocate the array
			result[i] = v; // Append the integer to the result array
			i++; // Increment the index
			start = s->p + 1; 