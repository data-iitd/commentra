
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Scanner struct to handle input reading efficiently
typedef struct {
	char *buf; // Buffer to hold the input line
	int p; // Current position in the buffer
} Scanner;

// NewScanner initializes a new Scanner instance
Scanner NewScanner() {
	Scanner s;
	s.buf = (char *) malloc(1000 * sizeof(char)); // Create a buffered reader with a specified size
	s.p = 0; // Reset the position to the start of the new line
	return s; // Return a new Scanner with the reader
}

// Next reads the next token from the input
char *Next(Scanner *s) {
	s->pre(); // Ensure there is data to read
	int start = s->p; // Mark the start position
	// Iterate through the buffer to find the next space
	for (; s->p < strlen(s->buf); s->p++) {
		if (s->buf[s->p] == ' ') {
			break; // Stop at the first space
		}
	}
	char *result = (char *) malloc((s->p - start + 1) * sizeof(char)); // Extract the token
	strncpy(result, s->buf + start, s->p - start); // Copy the token to the result
	result[s->p - start] = '\0'; // Null-terminate the result
	s->p++; // Move past the space
	return result; // Return the token
}

// NextLine reads the next full line from the input
char *NextLine(Scanner *s) {
	s->pre(); // Ensure there is data to read
	int start = s->p; // Mark the start position
	s->p = strlen(s->buf); // Move to the end of the buffer
	char *result = (char *) malloc((s->p - start + 1) * sizeof(char)); // Extract the line
	strncpy(result, s->buf + start, s->p - start); // Copy the line to the result
	result[s->p - start] = '\0'; // Null-terminate the result
	return result; // Return the line
}

// NextInt reads the next integer from the input
int NextInt(Scanner *s) {
	char *tmp = Next(s); // Convert the next token to an integer
	int v = atoi(tmp); // Extract the integer
	free(tmp); // Free the token
	return v; // Return the integer
}

// NextIntArray reads a space-separated array of integers from the input
int *NextIntArray(Scanner *s, int *size) {
	s->pre(); // Ensure there is data to read
	int start = s->p; // Mark the start position
	int *result = (int *) malloc(1000 * sizeof(int)); // Initialize an empty slice for the results
	int i = 0; // Initialize the result index
	// Iterate through the buffer to find integers separated by spaces
	for (; s->p < strlen(s->buf); s->p++) {
		if (s->buf[s->p] == ' ') {
			char *tmp = (char *) malloc((s->p - start + 1) * sizeof(char)); // Convert the token to an integer
			strncpy(tmp, s->buf + start, s->p - start); // Copy the token to the result
			tmp[s->p - start] = '\0'; // Null-terminate the result
			result[i++] = atoi(tmp); // Add the integer to the result slice
			free(tmp); // Free the token
			start = s->p + 1; // Update the start position
		}
	}
	char *tmp = (char *) malloc((s->p - start + 1) * sizeof(char)); // Convert the last token to an integer
	strncpy(tmp, s->buf + start, s->p - start); // Copy the token to the result
	tmp[s->p - start] = '\0'; // Null-terminate the result
	result[i++] = atoi(tmp); // Add the last integer to the result slice
	free(tmp); // Free the token
	*size = i; // Update the size of the result slice
	return result; // Return the slice of integers
}

// NextMap reads a space-separated list of integers into a map
int *NextMap(Scanner *s, int *size) {
	s->pre(); // Ensure there is data to read
	int start = s->p; // Mark the start position
	int *mp = (int *) malloc(1000 * sizeof(int)); // Initialize an empty map
	int i = 0; // Initialize the result index
	// Iterate through the buffer to find integers separated by spaces
	for (; s->p < strlen(s->buf); s->p++) {
		if (s->buf[s->p] == ' ') {
			char *tmp = (char *) malloc((s->p - start + 1) * sizeof(char)); // Convert the token to an integer
			strncpy(tmp, s->buf + start, s->p - start); // Copy the token to the result
			tmp[s->p - start] = '\0'; // Null-terminate the result
			mp[atoi(tmp)] = 1; // Add the integer to the map
			free(tmp); // Free the token
			start = s->p + 1; // Update the start position
		}
	}
	char *tmp = (char *) malloc((s->p - start + 1) * sizeof(char)); // Convert the last token to an integer
	strncpy(tmp, s->buf + start, s->p - start); // Copy the token to the result
	tmp[s->p - start] = '\0'; // Null-terminate the result
	mp[atoi(tmp)] = 1; // Add the last integer to the map
	free(tmp); // Free the token
	*size = i; // Update the size of the result slice
	return mp; // Return the map of integers
}

// pre checks if there is data to read and reads a new line if necessary
void pre(Scanner *s) {
	if (s->p >= strlen(s->buf)) { // If the current position is at the end of the buffer
		s->readLine(); // Read a new line
		s->p = 0; // Reset the position to the start of the new line
	}
}

// readLine reads a full line from the input and stores it in the buffer
void readLine(Scanner *s) {
	s->buf = (char *) realloc(s->buf, 1000 * sizeof(char)); // Reset the buffer
	for (; ; ) {
		char *l = (char *) malloc(1000 * sizeof(char)); // Read a line from the buffered reader
		int p = 0; // Mark the start position
		for (; ; ) {
			int c = getchar(); // Read a character from the input
			if (c == EOF) {
				break; // Exit the loop if there is no more input
			}
			l[p++] = c; // Add the character to the line
			if (c == '\n') {
				break; // Exit the loop if the character is a newline
			}
		}
		l[p] = '\0'; // Null-terminate the line
		strcat(s->buf, l); // Append the line to the buffer
		free(l); // Free the line
		if (p < 1000) {
			break; // Exit the loop if the line is not a continuation
		}
	}
}

int main() {
	Scanner s = NewScanner(); // Create a new scanner
	int n = NextInt(&s); // Read the number of integers to process
	float ans = 0.0; // Initialize the sum
	// Loop through each integer, calculate the reciprocal, and accumulate the sum
	for (int i = 0; i < n; i++) {
		float tmp = 1 / (float) NextInt(&s); // Calculate the reciprocal
		ans += tmp; // Accumulate the sum
	}
	// Print the harmonic mean of the input integers
	printf("%f\n", 1 / ans);
	return 0;
}

