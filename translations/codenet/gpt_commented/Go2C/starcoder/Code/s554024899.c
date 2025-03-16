

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// max returns the maximum of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// scanner struct to handle buffered input reading
typedef struct {
	FILE *r; // Buffered reader
	char *buf; // Buffer to hold read data
	int p; // Current position in the buffer
} scanner;

// newScanner initializes a new scanner with a specified buffer size
scanner *newScanner() {
	scanner *s = malloc(sizeof(scanner)); // Allocate memory for the scanner
	s->r = fopen("input.txt", "r"); // Open the input file
	s->buf = malloc(1000); // Allocate memory for the buffer
	s->p = 0; // Set the current position in the buffer to 0
	return s; // Return the new scanner
}

// next reads the next token from the input
char *next(scanner *s) {
	pre(s); // Ensure there's data to read
	int start = s->p; // Mark the start position
	while (s->p < strlen(s->buf)) {
		if (s->buf[s->p] =='') { // Stop at space
			break;
		}
		s->p++;
	}
	char *result = malloc(s->p - start + 1); // Allocate memory for the token
	strncpy(result, s->buf + start, s->p - start); // Copy the token to the result
	result[s->p - start] = '\0'; // Terminate the token
	s->p++; // Move past the space
	return result; // Return the token
}

// nextLine reads the next line from the input
char *nextLine(scanner *s) {
	pre(s); // Ensure there's data to read
	int start = s->p; // Mark the start position
	s->p = strlen(s->buf); // Move to the end of the buffer
	char *result = malloc(s->p - start + 1); // Allocate memory for the line
	strncpy(result, s->buf + start, s->p - start); // Copy the line to the result
	result[s->p - start] = '\0'; // Terminate the line
	return result; // Return the line
}

// nextInt reads the next integer from the input
int nextInt(scanner *s) {
	return atoi(next(s)); // Convert the next token to an integer
}

// pre checks if more data needs to be read into the buffer
void pre(scanner *s) {
	if (s->p >= strlen(s->buf)) { // If the current position is at or beyond the buffer length
		readLine(s); // Read a new line into the buffer
		s->p = 0; // Reset the position to the start of the buffer
	}
}

// readLine reads a full line from the input into the buffer
void readLine(scanner *s) {
	free(s->buf); // Free the old buffer
	s->buf = malloc(1000); // Allocate memory for the new buffer
	s->p = 0; // Set the current position in the buffer to 0
	while (1) {
		char *l = fgets(s->buf + s->p, 1000 - s->p, s->r); // Read a line
		if (l == NULL) { // If the line is NULL
			free(s->buf); // Free the buffer
			s->buf = NULL; // Set the buffer to NULL
			return; // Exit the function
		}
		s->p += strlen(l); // Increase the current position in the buffer by the length of the line
		if (l[strlen(l) - 1]!= '\n') { // If the line is not continued
			break; // Exit the loop
		}
	}
}

// main function
int main(int argc, char *argv[]) {
	scanner *sc = newScanner(); // Initialize a new scanner

	// Read two integers from input
	int x = nextInt(sc);
	int y = nextInt(sc);

	// Initialize variables to store the category indices of x and y
	int xt, yt;

	// Define a 2D array where each sub-array represents a category of numbers
	int a[3][7] = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};

	// Iterate through the categories to find the indices of x and y
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 7; j++) {
			// Check if the current number matches x
			if (x == a[i][j]) {
				xt = i; // Store the category index for x
			}
			// Check if the current number matches y
			if (y == a[i][j]) {
				yt = i; // Store the category index for y
			}
		}
	}

	// Compare the category indices of x and y and print the result
	if (xt == yt) {
		printf("Yes\n"); // x and y belong to the same category
	} else {
		printf("No\n"); // x and y belong to different categories
	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// max returns the maximum of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// scanner struct to handle buffered input reading
typedef struct {
	FILE *r; // Buffered reader
	char *buf; // Buffer to hold read data
	int p; // Current position in the buffer
} scanner;

// newScanner initializes a new scanner with a specified buffer size
scanner *newScanner() {
	scanner *s = malloc(sizeof(scanner)); // Allocate memory for the scanner
	s->r = fopen("input.txt", "r"); // Open the input file
	s->buf = malloc(1000); // Allocate memory for the buffer
	s->p = 0; // Set the current position in the buffer to 0
	return s; // Return the new scanner
}

// next reads the next token from the input
char *next(scanner *s) {
	pre(s); // Ensure there's data to read
	int start = s->p; // Mark the start position
	while (s->p < strlen(s->buf)) {
		if (s->buf[s->p] =='') { // Stop at space
			break;
		}
		s->p++;
	}
	char *result = malloc(s->p - start + 1); // Allocate memory for the token
	strncpy(result, s->buf + start, s->p - start); // Copy the token to the result
	result[s->p - start] = '\0'; // Terminate the token
	s->p++; // Move past the space
	return result; // Return the token
}

// nextLine reads the next line from the input
char *nextLine(scanner *s) {
	pre(s); // Ensure there's data to read
	int start = s->p; // Mark the start position
	s->p = strlen(s->buf); // Move to the end of the buffer
	char *result = malloc(s->p - start + 1); // Allocate memory for the line
	strncpy(result, s->buf + start, s->p - start); // Copy the line to the result
	result[s->p - start] = '\0'; // Terminate the line
	return result; // Return the line
}

// nextInt reads the next integer from the input
int nextInt(scanner *s) {
	return atoi(next(s)); // Convert the next token to an integer
}

// pre checks if more data needs to be read into the buffer
void pre(scanner *s) {
	if (s->p >= strlen(s->buf)) { // If the current position is at or beyond the buffer length
		readLine(s); // Read a new line into the buffer
		s->p = 0; // Reset the position to the start of the buffer
	}
}

// readLine reads a full line from the input into the buffer
void readLine(scanner *s) {
	free(s->buf); // Free the old buffer
	s->buf = malloc(1000); // Allocate memory for the new buffer
	s->p = 0; // Set the current position in the buffer to 0
	while (1) {
		char *l = fgets(s->buf + s->p, 1000 - s->p, s->r); // Read a line
		if (l == NULL) { // If the line is NULL
			free(s->buf); // Free the buffer
			s->buf = NULL; // Set the buffer to NULL
			return; // Exit the function
		}
		s->p += strlen(l); // Increase the current position in the buffer by the length of the line
		if (l[strlen(l) - 1]!= '\n') { // If the line is not continued
			break; // Exit the loop
		}
	}
}

// main function
int main(int argc, char *argv[]) {
	scanner *sc = newScanner(); // Initialize a new scanner

	// Read two integers from input
	int x = nextInt(sc);
	int y = nextInt(sc);

	// Initialize variables to store the category indices of x and y
	int xt, yt;

	// Define a 2D array where each sub-array represents a category of numbers
	int a[3][7] = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};

	// Iterate through the categories to find the indices of x and y
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 7; j++) {
			// Check if the current number matches x
			if (x == a[i][j]) {
				xt = i; // Store the category index for x
			}
			// Check if the current number matches y
			if (y == a[i][j]) {
				yt = i; // Store the category index for y
			}
		}
	}

	// Compare the category indices of x and y and print the result
	if (xt == yt) {
		printf("Yes\n"); // x and y belong to the same category
	} else {
		printf("No\n"); // x and y belong to different categories
	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// max returns the maximum of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// scanner struct to handle buffered input reading
typedef struct {
	FILE *r; // Buffered reader
	char *buf; // Buffer to hold read data
	int p; // Current position in the buffer
} scanner;

// newScanner initializes a new scanner with a specified buffer size
scanner *newScanner() {
	scanner *s = malloc(sizeof(scanner)); // Allocate memory for the scanner
	s->r = fopen("input.txt", "r"); // Open the input file
	s->buf = malloc(1000); // Allocate memory for the buffer
	s->p = 0; // Set the current position in the buffer to 0
	return s; // Return the new scanner
}

// next reads the next token from the input
char *next(scanner *s) {
	pre(s); // Ensure there's data to read
	int start = s->p; // Mark the start position
	while (s->p < strlen(s->buf)) {
		if (s->buf[s->p] =='') { // Stop at space
			break;
		}
		s->p++;
	}
	char *result = malloc(s->p - start + 1); // Allocate memory for the token
	strncpy(result, s->buf + start, s->p - start); // Copy the token to the result
	result[s->p - start] = '\0'; // Terminate the token
	s->p++; // Move past the space
	return result; // Return the token
}

// nextLine reads the next line from the input
char *nextLine(scanner *s) {
	pre(s); // Ensure there's data to read
	int start = s->p; // Mark the start position
	s->p = strlen(s->buf); // Move to the end of the buffer
	char *result = malloc(s->p - start + 1); // Allocate memory for the line
	strncpy(result, s->buf + start, s->p - start); // Copy the line to the result
	result[s->p - start] = '\0'; // Terminate the line
	return result; // Return the line
}

// nextInt reads the next integer from the input
int nextInt(scanner *s) {
	return atoi(next(s)); // Convert the next token to an integer
}

// pre checks if more data needs to be read into the buffer
void pre(scanner *s) {
	if (s->p >= strlen(s->buf)) { // If the current position is at or beyond the buffer length
		readLine(s); // Read a new line into the buffer
		s->p = 0; // Reset the position to the start of the buffer
	}
}

// readLine reads a full line from the input into the buffer
void readLine(scanner *s) {
	free(s->b