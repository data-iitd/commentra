

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Create a new scanner to read input
	scanner *sc = newScanner();
	
	// Read a string from the input
	char *S = sc->next();
	
	// Check if the string starts with "YAKI" and print the corresponding response
	if (strncmp(S, "YAKI", 4) == 0) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
}

// min returns the smaller of two integers
int min(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

// max returns the larger of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// scanner struct to handle buffered input reading
typedef struct {
	FILE *r; // Buffered reader
	char *buf; // Buffer to hold the input data
	int p; // Current position in the buffer
} scanner;

// newScanner initializes a new scanner with a specified buffer size
scanner *newScanner() {
	scanner *s = malloc(sizeof(scanner)); // Allocate memory for the scanner
	s->r = fopen("stdin", "r"); // Open the input file
	s->buf = malloc(1000); // Allocate memory for the buffer
	return s; // Return the new scanner
}

// next reads the next word from the input
char *next(scanner *s) {
	pre(s); // Ensure the buffer is filled
	int start = s->p; // Mark the start of the word
	// Iterate through the buffer until a space is found
	for (; s->p < strlen(s->buf); s->p++) {
		if (s->buf[s->p] =='') {
			break;
		}
	}
	char *result = malloc(s->p - start + 1); // Allocate memory for the word
	strncpy(result, s->buf + start, s->p - start); // Copy the word into the result
	result[s->p - start] = '\0'; // Terminate the string
	s->p++; // Move past the space
	return result; // Return the word
}

// nextLine reads the next line from the input
char *nextLine(scanner *s) {
	pre(s); // Ensure the buffer is filled
	int start = s->p; // Mark the start of the line
	s->p = strlen(s->buf); // Move to the end of the buffer
	char *result = malloc(s->p - start + 1); // Allocate memory for the line
	strncpy(result, s->buf + start, s->p - start); // Copy the line into the result
	result[s->p - start] = '\0'; // Terminate the string
	return result; // Return the line
}

// nextInt reads the next integer from the input
int nextInt(scanner *s) {
	return atoi(next(s)); // Convert the next word to an integer
}

// nextIntArray reads a space-separated array of integers from the input
int *nextIntArray(scanner *s) {
	pre(s); // Ensure the buffer is filled
	int start = s->p; // Mark the start of the array
	int *result = malloc(sizeof(int) * 100); // Allocate memory for the result
	int i = 0; // Initialize the result index
	// Iterate through the buffer to extract integers
	for (; s->p < strlen(s->buf) + 1; s->p++) {
		if (s->p == strlen(s->buf) || s->buf[s->p] =='') {
			result[i++] = atoi(s->buf + start); // Parse the integer
			start = s->p + 1; // Update the start position for the next integer
		}
	}
	return result; // Return the slice of integers
}

// pre checks if the buffer needs to be filled
void pre(scanner *s) {
	if (s->p >= strlen(s->buf)) { // If the current position is at or beyond the buffer length
		readLine(s); // Read a new line into the buffer
		s->p = 0; // Reset the position to the start of the buffer
	}
}

// readLine reads a line from the input and fills the buffer
void readLine(scanner *s) {
	free(s->buf); // Reset the buffer
	s->buf = malloc(1000); // Allocate memory for the buffer
	while (1) {
		char *l = fgets(s->buf, 1000, s->r); // Read a line from the buffered reader
		if (l == NULL) {
			free(s->buf); // Free the buffer
			s->buf = NULL; // Set the buffer to NULL
			return; // Exit the loop
		}
		if (l[strlen(l) - 1] == '\n') { // If the line is complete
			return; // Exit the loop
		}
	}
}

