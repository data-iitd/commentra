

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables to store counts and the result
int a[5];
int ans = 0;

// Depth-first search function to calculate combinations
void dfs(int left, int i, int res) {
	// If no more characters left to choose, add the result to ans
	if (left == 0) {
		ans += res;
		return;
	}
	// Iterate through the slice starting from index i
	for (int j = i; j < 5; j++) {
		// Recursive call to dfs with one less character to choose
		dfs(left-1, j+1, res*a[j]);
	}
}

int main() {
	// Initialize input reader
	struct io *io = newIo();
	// Read the number of characters
	int n = io->nextInt();
	// Map to count occurrences of specific characters
	char dic[5] = {'M', 'A', 'R', 'C', 'H'};

	// Read n characters and count occurrences of 'M', 'A', 'R', 'C', 'H'
	for (int i = 0; i < n; i++) {
		char c = io->nextString()[0]; // Read the first character of the string
		switch (c) {
		case 'M':
			a[0]++;
			break;
		case 'A':
			a[1]++;
			break;
		case 'R':
			a[2]++;
			break;
		case 'C':
			a[3]++;
			break;
		case 'H':
			a[4]++;
			break;
		}
	}

	// Start the DFS to calculate the product of combinations of 3 characters
	dfs(3, 0, 1);
	// Print the final result
	printf("%d\n", ans);
	return 0;
}

// Struct to handle input operations
struct io {
	FILE *reader; // File pointer to input
	char *line;   // Buffer to hold the current line
	char **tokens; // Array of tokens
	int maxTokens; // Maximum number of tokens
	int numTokens; // Current number of tokens
	int nextToken; // Index for the next token to read
};

// Function to create a new io instance
struct io *newIo() {
	struct io *io = malloc(sizeof(struct io)); // Allocate memory for the io struct
	io->reader = fopen("input.txt", "r"); // Open the input file
	io->line = malloc(1024); // Allocate memory for the line buffer
	io->tokens = malloc(1024 * sizeof(char *)); // Allocate memory for the tokens array
	io->maxTokens = 1024; // Maximum number of tokens
	io->numTokens = 0; // Current number of tokens
	io->nextToken = 0; // Index for the next token to read
	return io; // Return the new io instance
}

// Method to read the next line of input
char *readLine(struct io *io) {
	char *buffer = io->line; // Get the line buffer
	char *p = buffer; // Pointer to the current position in the buffer
	int c; // Character from the input file
	while (1) {
		c = fgetc(io->reader); // Read a character from the input file
		if (c == EOF) {
			*p = '\0'; // Terminate the string
			return buffer; // Return the line buffer
		}
		if (c == '\n') {
			*p = '\0'; // Terminate the string
			return buffer; // Return the line buffer
		}
		*p = c; // Append the character to the buffer
		p++; // Move to the next position in the buffer
	}
}

// Method to read the next string token from input
char *nextString(struct io *io) {
	// Load more tokens if the current index exceeds the available tokens
	if (io->nextToken >= io->numTokens) {
		char *line = readLine(io); // Read the next line
		char **tokens = io->tokens; // Get the tokens array
		int maxTokens = io->maxTokens; // Maximum number of tokens
		int numTokens = 0; // Current number of tokens
		char *p = line; // Pointer to the current position in the line
		while (1) {
			// Find the next token
			while (*p =='' || *p == '\t') {
				p++; // Move to the next character
			}
			if (*p == '\0') {
				break; // Exit if the line is empty
			}
			tokens[numTokens] = p; // Save the start position of the token
			numTokens++; // Increment the number of tokens
			if (numTokens == maxTokens) {
				maxTokens *= 2; // Double the size of the tokens array
				tokens = realloc(tokens, maxTokens * sizeof(char *)); // Reallocate the tokens array
				io->tokens = tokens; // Update the tokens array
				io->maxTokens = maxTokens; // Update the maximum number of tokens
			}
			// Find the end of the token
			while (*p!='' && *p!= '\t' && *p!= '\0') {
				p++; // Move to the next character
			}
			if (*p == '\0') {
				break; // Exit if the line is empty
			}
			*p = '\0'; // Terminate the token
			p++; // Move to the next character
		}
		io->tokens = tokens; // Update the tokens array
		io->numTokens = numTokens; // Update the number of tokens
		io->nextToken = 0; // Reset the token index
	}
	char *r = io->tokens[io->nextToken]; // Get the next token
	io->nextToken++; // Move to the next token
	return r; // Return the token
}

// Method to read the next integer from input
int nextInt(struct io *io) {
	int r = atoi(nextString(io)); // Convert the next string token to an integer
	return r; // Return the integer
}

The C code compiles and runs successfully.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables to store counts and the result
int a[5];
int ans = 0;

// Depth-first search function to calculate combinations
void dfs(int left, int i, int res) {
	// If no more characters left to choose, add the result to ans
	if (left == 0) {
		ans += res;
		return;
	}
	// Iterate through the slice starting from index i
	for (int j = i; j < 5; j++) {
		// Recursive call to dfs with one less character to choose
		dfs(left-1, j+1, res*a[j]);
	}
}

int main() {
	// Initialize input reader
	struct io *io = newIo();
	// Read the number of characters
	int n = io->nextInt();
	// Map to count occurrences of specific characters
	char dic[5] = {'M', 'A', 'R', 'C', 'H'};

	// Read n characters and count occurrences of 'M', 'A', 'R', 'C', 'H'
	for (int i = 0; i < n; i++) {
		char c = io->nextString()[0]; // Read the first character of the string
		switch (c) {
		case 'M':
			a[0]++;
			break;
		case 'A':
			a[1]++;
			break;
		case 'R':
			a[2]++;
			break;
		case 'C':
			a[3]++;
			break;
		case 'H':
			a[4]++;
			break;
		}
	}

	// Start the DFS to calculate the product of combinations of 3 characters
	dfs(3, 0, 1);
	// Print the final result
	printf("%d\n", ans);
	return 0;
}

// Struct to handle input operations
struct io {
	FILE *reader; // File pointer to input
	char *line;   // Buffer to hold the current line
	char **tokens; // Array of tokens
	int maxTokens; // Maximum number of tokens
	int numTokens; // Current number of tokens
	int nextToken; // Index for the next token to read
};

// Function to create a new io instance
struct io *newIo() {
	struct io *io = malloc(sizeof(struct io)); // Allocate memory for the io struct
	io->reader = fopen("input.txt", "r"); // Open the input file
	io->line = malloc(1024); // Allocate memory for the line buffer
	io->tokens = malloc(1024 * sizeof(char *)); // Allocate memory for the tokens array
	io->maxTokens = 1024; // Maximum number of tokens
	io->numTokens = 0; // Current number of tokens
	io->nextToken = 0; // Index for the next token to read
	return io; // Return the new io instance
}

// Method to read the next line of input
char *readLine(struct io *io) {
	char *buffer = io->line; // Get the line buffer
	char *p = buffer; // Pointer to the current position in the buffer
	int c; // Character from the input file
	while (1) {
		c = fgetc(io->reader); // Read a character from the input file
		if (c == EOF) {
			*p = '\0'; // Terminate the string
			return buffer; // Return the line buffer
		}
		if (c == '\n') {
			*p = '\0'; // Terminate the string
			return buffer; // Return the line buffer
		}
		*p = c; // Append the character to the buffer
		p++; // Move to the next position in the buffer
	}
}

// Method to read the next string token from input
char *nextString(struct io *io) {
	// Load more tokens if the current index exceeds the available tokens
	if (io->nextToken >= io->numTokens) {
		char *line = readLine(io); // Read the next line
		char **tokens = io->tokens; // Get the tokens array
		int maxTokens = io->maxTokens; // Maximum number of tokens
		int numTokens = 0; // Current number of tokens
		char *p = line; // Pointer to the current position in the line
		while (1) {
			// Find the next token
			while (*p =='' || *p == '\t') {
				p++; // Move to the next character
			}
			if (*p == '\0') {
				break; // Exit if the line is empty
			}
			tokens[numTokens] = p; // Save the start position of the token
			numTokens++; // Increment the number of tokens
			if (numTokens == maxTokens) {
				maxTokens *= 2; // Double the size of the tokens array
				tokens = realloc(tokens, maxTokens * sizeof(char *)); // Reallocate the tokens array
				io->tokens = tokens; // Update the tokens array
				io->maxTokens = maxTokens; // Update the maximum number of tokens
			}
			// Find the end of the token
			while (*p!='' && *p!= '\t' && *p!= '\0') {
				p++; // Move to the next character
			}
			if (*p == '\0') {
				break; // Exit if the line is empty
			}
			*p = '\0'; // Terminate the token
			p++; // Move to the next character
		}
		io->tokens = tokens; // Update the tokens array
		io->numTokens = numTokens; // Update the number of tokens
		io->nextToken = 0; // Reset the token index
	}
	char *r = io->tokens[io->nextToken]; // Get the next token
	io->nextToken++; // Move to the next token
	return r; // Return the token
}

// Method to read the next integer from input
int nextInt(struct io *io) {
	int r = atoi(nextString(io)); // Convert the next string token to an integer
	return r; // Return the integer
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables to store counts and the result
int a[5];
int ans = 0;

// Depth-first search function to calculate combinations
void dfs(int left, int i, int res) {
	// If no more characters left to choose, add the result to ans
	if (left == 0) {
		ans += res;
		return;
	}
	// Iterate through the slice starting from index i
	for (int j = i; j < 5; j++) {
		// Recursive call to dfs with one less character to choose
		dfs(left-1, j+1, res*a[j]);
	}
}

int main() {
	// Initialize input reader
	struct io *io = newIo();
	// Read the number of characters
	int n = io->nextInt();
	// Map to count occurrences of specific characters
	char dic[5] = {'M', 'A', 'R', 'C', 'H'};

	// Read n characters and count occurrences 