
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

// Define a struct to handle buffered input reading
typedef struct {
	char *buf; // Buffer to hold read data
	int p; // Current position in the buffer
	int size; // Size of the buffer
} scanner;

// Initialize a new scanner with a specified buffer size
scanner newScanner(int size) {
	scanner s;
	s.buf = (char *)malloc(size * sizeof(char));
	s.p = 0;
	s.size = size;
	return s;
}

// Read the next token from the input
char *next(scanner *s) {
	s->pre(); // Ensure there's data to read
	int start = s->p; // Mark the start position
	for (; s->p < s->size; s->p++) {
		if (s->buf[s->p] == ' ') { // Stop at space
			break;
		}
	}
	char *result = (char *)malloc((s->p - start + 1) * sizeof(char));
	strncpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0'; // Null terminate the token
	s->p++; // Move past the space
	return result; // Return the token
}

// Read the next line from the input
char *nextLine(scanner *s) {
	s->pre(); // Ensure there's data to read
	int start = s->p; // Mark the start position
	s->p = s->size; // Move to the end of the buffer
	char *result = (char *)malloc((s->p - start + 1) * sizeof(char));
	strncpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0'; // Null terminate the line
	return result; // Return the line
}

// Read the next integer from the input
int nextInt(scanner *s) {
	char *token = next(s); // Get the next token
	int result = atoi(token); // Convert the token to an integer
	free(token); // Free the token
	return result; // Return the integer
}

// Check if more data needs to be read into the buffer
void pre(scanner *s) {
	if (s->p >= s->size) { // If the current position is at or beyond the buffer length
		s->readLine(); // Read a new line into the buffer
		s->p = 0; // Reset the position to the start of the buffer
	}
}

// Read a full line from the input into the buffer
void readLine(scanner *s) {
	s->buf = (char *)realloc(s->buf, s->size * sizeof(char));
	s->buf[0] = '\0'; // Clear the buffer
	for (;;) {
		char *l = (char *)malloc(MAX_BUFFER_SIZE * sizeof(char));
		int p = 0;
		int e = fgets(l, MAX_BUFFER_SIZE, stdin); // Read a line
		if (e == NULL) {
			free(l);
			break;
		}
		strcat(s->buf, l); // Append the line to the buffer
		free(l);
		if (strlen(s->buf) >= s->size) { // If the line is too long
			s->size *= 2; // Double the buffer size
			s->buf = (char *)realloc(s->buf, s->size * sizeof(char));
		}
		if (strlen(s->buf) > 0 && s->buf[strlen(s->buf) - 1] != '\n') { // If the line is continued
			continue; // Read another line
		}
		break; // Exit the loop
	}
}

// Compare the category indices of x and y and print the result
void compare(int xt, int yt) {
	if (xt == yt) {
		printf("Yes\n"); // x and y belong to the same category
	} else {
		printf("No\n"); // x and y belong to different categories
	}
}

// Find the category index of x
int findX(int x) {
	int xt = -1;
	int a[3][7] = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 7; j++) {
			if (x == a[i][j]) {
				xt = i; // Store the category index for x
			}
		}
	}
	return xt;
}

// Find the category index of y
int findY(int y) {
	int yt = -1;
	int a[3][7] = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 7; j++) {
			if (y == a[i][j]) {
				yt = i; // Store the category index for y
			}
		}
	}
	return yt;
}

int main() {
	// Set log flags to show the file name and line number for log messages
	// log.SetFlags(log.Lshortfile)

	// Initialize a new scanner to read input
	scanner sc = newScanner(MAX_BUFFER_SIZE);

	// Read two integers from input
	int x = nextInt(&sc);
	int y = nextInt(&sc);

	// Initialize variables to store the category indices of x and y
	int xt = -1;
	int yt = -1;

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
	compare(xt, yt);

	return 0;
}

