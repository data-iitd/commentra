#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// max function returns the maximum value between two integers a and b.
int max(int a, int b) {
	// If a is smaller than b, return b.
	if (a < b) {
		return b;
	}
	// Otherwise, return a.
	return a;
}

// Scanner struct represents the input reader.
typedef struct {
	// buf char array buffer is used for storing the input line.
	char *buf;
	// p int p keeps track of the current position in the buffer.
	int p;
} Scanner;

// NewScanner function initializes a new Scanner object with the standard input stdin as the reader.
Scanner *NewScanner() {
	// Allocate a new Scanner object.
	Scanner *s = (Scanner *)malloc(sizeof(Scanner));
	// Initialize the buffer to NULL.
	s->buf = NULL;
	// Initialize the current position p to 0.
	s->p = 0;
	// Return the initialized Scanner object.
	return s;
}

// Next method reads the next token from the input, which can be a single word, number, or symbol.
// It skips leading whitespaces and returns the result as a string.
char *Next(Scanner *s) {
	// Set the current position p to the beginning of the buffer if it's at the end.
	pre(s);
	// Start index of the token in the buffer.
	int start = s->p;
	// Read the input until a non-whitespace character is found.
	for (; s->p < strlen(s->buf); s->p++) {
		// If the current character is a whitespace, break the loop.
		if (s->buf[s->p] =='') {
			break;
		}
	}
	// Allocate a new char array named result with the length of the token.
	char *result = (char *)malloc(sizeof(char) * (s->p - start + 1));
	// Copy the token from the buffer to the result.
	for (int i = start; i <= s->p; i++) {
		result[i - start] = s->buf[i];
	}
	// Increment the current position p.
	s->p++;
	// Return the result.
	return result;
}

// NextLine method reads the next line from the input and returns it as a string.
char *NextLine(Scanner *s) {
	// Set the current position p to the beginning of the buffer if it's at the end.
	pre(s);
	// Start index of the line in the buffer.
	int start = s->p;
	// Read the input until the end of the line is reached.
	for (; s->p < strlen(s->buf); s->p++) {
		// If the current character is a newline character, break the loop.
		if (s->buf[s->p] == '\n') {
			break;
		}
	}
	// Allocate a new char array named result with the length of the line.
	char *result = (char *)malloc(sizeof(char) * (s->p - start + 1));
	// Copy the line from the buffer to the result.
	for (int i = start; i <= s->p; i++) {
		result[i - start] = s->buf[i];
	}
	// Increment the current position p.
	s->p++;
	// Return the result.
	return result;
}

// NextInt method reads an integer from the input and returns it.
int NextInt(Scanner *s) {
	// Read the next token as a string.
	char *token = Next(s);
	// Parse the token as an integer and return the result.
	int v, _ = atoi(token);
	// Return the result.
	return v;
}

// NextInt64 method reads a 64-bit integer from the input and returns it.
int64_t NextInt64(Scanner *s) {
	// Read the next token as a string.
	char *token = Next(s);
	// Parse the token as a 64-bit integer and return the result.
	int64_t v, _ = atoll(token);
	// Return the result.
	return v;
}

// NextFloat method reads a floating-point number from the input and returns it.
double NextFloat(Scanner *s) {
	// Read the next token as a string.
	char *token = Next(s);
	// Parse the token as a floating-point number and return the result.
	double v, _ = atof(token);
	// Return the result.
	return v;
}

// NextIntArray method reads an array of integers from the input and returns it.
int *NextIntArray(Scanner *s) {
	// Read the next line as a string.
	char *line = NextLine(s);
	// Split the line into tokens using spaces as delimiters.
	char **tokens = (char **)malloc(sizeof(char *) * (strlen(line) + 1));
	int i = 0;
	for (char *p = strtok(line, " "); p; p = strtok(NULL, " ")) {
		tokens[i++] = p;
	}
	// Parse each token as an integer and append it to the result slice.
	int *result = (int *)malloc(sizeof(int) * i);
	for (int j = 0; j < i; j++) {
		result[j], _ = atoi(tokens[j]);
	}
	// Return the result.
	return result;
}

// NextInt64Array method reads an array of 64-bit integers from the input and returns it.
int64_t *NextInt64Array(Scanner *s) {
	// Read the next line as a string.
	char *line = NextLine(s);
	// Split the line into tokens using spaces as delimiters.
	char **tokens = (char **)malloc(sizeof(char *) * (strlen(line) + 1));
	int i = 0;
	for (char *p = strtok(line, " "); p; p = strtok(NULL, " ")) {
		tokens[i++] = p;
	}
	// Parse each token as a 64-bit integer and append it to the result slice.
	int64_t *result = (int64_t *)malloc(sizeof(int64_t) * i);
	for (int j = 0; j < i; j++) {
		result[j], _ = atoll(tokens[j]);
	}
	// Return the result.
	return result;
}

// NextMap method reads a map from the input and returns it.
int *NextMap(Scanner *s) {
	// Read the next line as a string.
	char *line = NextLine(s);
	// Split the line into tokens using spaces as delimiters.
	char **tokens = (char **)malloc(sizeof(char *) * (strlen(line) + 1));
	int i = 0;
	for (char *p = strtok(line, " "); p; p = strtok(NULL, " ")) {
		tokens[i++] = p;
	}
	// Parse each token as an integer and create a key-value pair.
	int *result = (int *)malloc(sizeof(int) * i);
	for (int j = 0; j < i; j++) {
		result[j], _ = atoi(tokens[j]);
	}
	// Return the result.
	return result;
}

// pre function sets the current position p to the beginning of the buffer if it's at the end.
void pre(Scanner *s) {
	// If the current position p is at the end of the buffer, read the next line.
	if (s->p >= strlen(s->buf)) {
		readLine(s);
		s->p = 0;
	}
}

// readLine function reads a line from the input and appends it to the buffer.
void readLine(Scanner *s) {
	// Allocate a new char array named line with the length of the input line.
	char *line = (char *)malloc(sizeof(char) * 1000);
	// Read a line from the input using the scanf function.
	scanf("%s", line);
	// If the buffer is NULL, allocate a new char array with the length of the input line.
	if (s->buf == NULL) {
		s->buf = (char *)malloc(sizeof(char) * (strlen(line) + 1));
	}
	// Otherwise, reallocate the buffer with the length of the input line.
	else {
		s->buf = (char *)realloc(s->buf, sizeof(char) * (strlen(line) + 1));
	}
	// Copy the input line to the buffer.
	strcpy(s->buf, line);
}

// 