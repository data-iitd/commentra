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
	struct io io;
	io.reader = stdin;
	io.tokens = NULL;
	io.nextToken = 0;

	// Read the number of characters
	int n = io.nextInt();
	// Map to count occurrences of specific characters
	int dic[5];
	for (int i = 0; i < 5; i++) {
		dic[i] = 0;
	}

	// Read n characters and count occurrences of 'M', 'A', 'R', 'C', 'H'
	for (int i = 0; i < n; i++) {
		char c = io.nextString()[0]; // Read the first character of the string
		switch (c) {
		case 'M':
		case 'A':
		case 'R':
		case 'C':
		case 'H':
			dic[c-'A']++; // Increment count for the character if it's one of the specified
		}
	}

	// Populate the slice a with the counts from the dictionary
	for (int i = 0; i < 5; i++) {
		a[i] = dic[i];
	}

	// Start the DFS to calculate the product of combinations of 3 characters
	dfs(3, 0, 1);
	// Print the final result
	printf("%d\n", ans);
	return 0;
}

// Struct to handle input operations
struct io {
	FILE *reader; // Buffered reader for input
	char **tokens; // Slice to hold split input tokens
	int nextToken; // Index for the next token to read
};

// Function to create a new io instance
struct io newIo() {
	struct io io;
	io.reader = stdin;
	io.tokens = NULL;
	io.nextToken = 0;
	return io;
}

// Method to read the next line of input
char *ioNextLine(struct io *io) {
	char *buffer = NULL;
	size_t bufferSize = 0;
	ssize_t lineLength;
	while ((lineLength = getline(&buffer, &bufferSize, io->reader)) != -1) {
		if (lineLength > 0 && buffer[lineLength-1] == '\n') {
			buffer[lineLength-1] = '\0';
			lineLength--;
		}
		return buffer;
	}
	return NULL;
}

// Method to read the next string token from input
char *ioNextString(struct io *io) {
	// Load more tokens if the current index exceeds the available tokens
	if (io->nextToken >= io->tokensSize) {
		char *line = ioNextLine(io);
		if (line == NULL) {
			return NULL;
		}
		io->tokensSize = 0;
		io->tokens = malloc(sizeof(char*) * 100);
		char *token = strtok(line, " ");
		while (token != NULL) {
			io->tokens[io->tokensSize++] = token;
			token = strtok(NULL, " ");
		}
		io->nextToken = 0;
	}
	char *r = io->tokens[io->nextToken];
	io->nextToken++;
	return r;
}

// Method to read the next integer from input
int ioNextInt(struct io *io) {
	char *token = ioNextString(io);
	int i = atoi(token);
	return i;
}

