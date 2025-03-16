#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Importing necessary packages

int main() {
	// Initializing an io object for input/output handling
	io *io = newIo();

	// Reading the number of test cases
	int n = io->nextInt();

	// Initializing an empty map to store the frequency of each character
	int *dic = (int *)malloc(sizeof(int) * 5);
	memset(dic, 0, sizeof(int) * 5);

	// Reading strings and updating the map
	for (int i = 0; i < n; i++) {
		char c = io->nextString()[0];
		switch (c) {
		case 'M':
			dic[0]++;
			break;
		case 'A':
			dic[1]++;
			break;
		case 'R':
			dic[2]++;
			break;
		case 'C':
			dic[3]++;
			break;
		case 'H':
			dic[4]++;
			break;
		}
	}

	// Converting map values to integers and appending them to the 'a' slice
	int a[5];
	for (int i = 0; i < 5; i++) {
		a[i] = dic[i];
	}

	// Initializing variables
	int ans = 0;
	int left = 3;
	int i = 0;
	int res = 1;

	// Calling the 'dfs' function with initial arguments
	dfs(left, i, res, a, &ans);

	// Printing the answer
	printf("%d\n", ans);
}

// Struct definition for input/output handling
typedef struct {
	char *buffer;
	int nextToken;
	char **tokens;
	int nTokens;
	FILE *reader;
} io;

// Function to initialize the io object
io *newIo() {
	io *io = (io *)malloc(sizeof(io));
	io->reader = fopen("input.txt", "r");
	io->buffer = (char *)malloc(sizeof(char) * 10000);
	io->nextToken = 0;
	io->tokens = (char **)malloc(sizeof(char *) * 10000);
	io->nTokens = 0;
	return io;
}

// Function to read a line from the standard input
char *readLine(io *io) {
	char *buffer = io->buffer;
	int bufferLength = 10000;
	int bufferPos = 0;
	int c;
	while (1) {
		c = fgetc(io->reader);
		if (c == EOF) {
			if (bufferPos == 0) {
				return NULL;
			}
			break;
		}
		if (bufferPos == bufferLength) {
			bufferLength += 10000;
			buffer = (char *)realloc(buffer, sizeof(char) * bufferLength);
		}
		buffer[bufferPos] = c;
		bufferPos++;
		if (c == '\n') {
			break;
		}
	}
	buffer[bufferPos] = 0;
	return buffer;
}

// Function to read a token (a word) from the standard input
char *nextString(io *io) {
	while (io->nextToken >= io->nTokens) {
		char *line = readLine(io);
		if (line == NULL) {
			return NULL;
		}
		char **tokens = io->tokens;
		int nTokens = io->nTokens;
		int nTokensLength = 10000;
		int nTokensPos = 0;
		char *token;
		int i;
		for (i = 0; i < strlen(line); i++) {
			if (line[i] =='' || line[i] == '\t' || line[i] == '\n') {
				if (nTokensPos == nTokensLength) {
					nTokensLength += 10000;
					tokens = (char **)realloc(tokens, sizeof(char *) * nTokensLength);
				}
				tokens[nTokensPos] = (char *)malloc(sizeof(char) * (i - nTokensPos + 1));
				strncpy(tokens[nTokensPos], line + nTokensPos, i - nTokensPos);
				tokens[nTokensPos][i - nTokensPos] = 0;
				nTokensPos = i + 1;
				nTokens++;
			}
		}
		if (nTokensPos < strlen(line)) {
			if (nTokensPos == nTokensLength) {
				nTokensLength += 10000;
				tokens = (char **)realloc(tokens, sizeof(char *) * nTokensLength);
			}
			tokens[nTokensPos] = (char *)malloc(sizeof(char) * (strlen(line) - nTokensPos + 1));
			strncpy(tokens[nTokensPos], line + nTokensPos, strlen(line) - nTokensPos);
			tokens[nTokensPos][strlen(line) - nTokensPos] = 0;
			nTokens++;
		}
		io->tokens = tokens;
		io->nTokens = nTokens;
	}
	char *r = io->tokens[io->nextToken];
	io->nextToken++;
	return r;
}

// Function to convert a token (a string) to an integer
int nextInt(io *io) {
	char *s = nextString(io);
	int r;
	sscanf(s, "%d", &r);
	return r;
}

// Function to perform Depth First Search (DFS) algorithm
void dfs(int left, int i, int res, int *a, int *ans) {
	// Base case
	if (left == 0) {
		*ans += res;
		return;
	}

	// Recursive case
	for (int j = i; j < 5; j++) {
		dfs(left - 1, j + 1, res * a[j], a, ans);
	}
}

// 

