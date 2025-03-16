
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

// scanner struct to handle buffered input reading
typedef struct {
	char *buf; // Buffer to hold the input data
	int p; // Current position in the buffer
	int len; // Length of the buffer
} scanner;

// newScanner initializes a new scanner with a specified buffer size
scanner newScanner() {
	scanner s;
	s.buf = (char *) malloc(BUFFER_SIZE * sizeof(char));
	s.p = 0;
	s.len = 0;
	return s;
}

// next reads the next word from the input
char *next(scanner *s) {
	s->pre(); // Ensure the buffer is filled
	int start = s->p; // Mark the start of the word
	// Iterate through the buffer until a space is found
	while (s->p < s->len) {
		if (s->buf[s->p] == ' ') {
			break;
		}
		s->p++;
	}
	char *result = (char *) malloc((s->p - start + 1) * sizeof(char));
	strncpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	s->p++; // Move past the space
	return result;
}

// nextLine reads the next line from the input
char *nextLine(scanner *s) {
	s->pre(); // Ensure the buffer is filled
	int start = s->p; // Mark the start of the line
	s->p = s->len; // Move to the end of the buffer
	char *result = (char *) malloc((s->p - start + 1) * sizeof(char));
	strncpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	return result;
}

// nextInt reads the next integer from the input
int nextInt(scanner *s) {
	char *word = next(s);
	int result = atoi(word);
	free(word);
	return result;
}

// nextIntArray reads a space-separated array of integers from the input
int *nextIntArray(scanner *s) {
	s->pre(); // Ensure the buffer is filled
	int start = s->p; // Mark the start of the array
	int *result = (int *) malloc(BUFFER_SIZE * sizeof(int));
	int i = 0;
	// Iterate through the buffer to extract integers
	while (s->p < s->len) {
		if (s->p == s->len || s->buf[s->p] == ' ') {
			char *word = (char *) malloc((s->p - start + 1) * sizeof(char));
			strncpy(word, s->buf + start, s->p - start);
			word[s->p - start] = '\0';
			result[i++] = atoi(word);
			free(word);
			start = s->p + 1; // Update the start position for the next integer
		}
		s->p++;
	}
	return result;
}

// pre checks if the buffer needs to be filled
void pre(scanner *s) {
	if (s->p >= s->len) { // If the current position is at or beyond the buffer length
		s->readLine(); // Read a new line into the buffer
		s->p = 0; // Reset the position to the start of the buffer
	}
}

// readLine reads a line from the input and fills the buffer
void readLine(scanner *s) {
	s->buf = (char *) realloc(s->buf, BUFFER_SIZE * sizeof(char));
	s->len = 0;
	while (1) {
		int l = getline(&s->buf, &s->len, stdin);
		if (l == -1) {
			break;
		}
		if (l < BUFFER_SIZE) {
			break;
		}
	}
}

int main() {
	scanner s = newScanner();
	char *S = next(s);
	if (strncmp(S, "YAKI", 4) == 0) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	free(S);
	return 0;
}

