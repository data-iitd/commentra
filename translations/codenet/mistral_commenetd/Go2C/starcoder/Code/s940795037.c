#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the Scanner structure
typedef struct {
	// Defining the reader instance
	FILE *r;
	// Defining the input buffer
	char *buf;
	// Defining the position of the input buffer pointer
	int p;
} Scanner;

// Defining the NewScanner function
Scanner *NewScanner() {
	// Creating a new scanner instance
	Scanner *s = malloc(sizeof(Scanner));
	// Creating a new buffered reader instance
	s->r = freopen(NULL, "r", stdin);
	// Initializing the input buffer
	s->buf = malloc(1000);
	// Initializing the position of the input buffer pointer
	s->p = 0;
	// Returning the scanner instance
	return s;
}

// Defining the Next function
char *Next(Scanner *s) {
	// Preprocessing the input buffer
	pre(s);
	// Initializing the start position of the token
	int start = s->p;
	// Iterating through the input buffer
	for (; s->p < strlen(s->buf); s->p++) {
		// Checking if the current character is a whitespace character
		if (s->buf[s->p] =='') {
			// If yes, then setting the end position of the token
			break;
		}
	}
	// Creating a new string from the input buffer
	char *result = malloc(s->p - start + 1);
	// Copying the token from the input buffer to the new string
	for (int i = start; i < s->p; i++) {
		result[i - start] = s->buf[i];
	}
	// Incrementing the position of the input buffer pointer
	s->p++;
	// Returning the new string
	return result;
}

// Defining the NextLine function
char *NextLine(Scanner *s) {
	// Preprocessing the input buffer
	pre(s);
	// Initializing the start position of the line
	int start = s->p;
	// Setting the position of the input buffer pointer to the end of the line
	s->p = strlen(s->buf);
	// Reading the rest of the line if available
	readLine(s);
	// Creating a new string from the input buffer
	char *result = malloc(s->p - start + 1);
	// Copying the line from the input buffer to the new string
	for (int i = start; i < s->p; i++) {
		result[i - start] = s->buf[i];
	}
	// Returning the new string
	return result;
}

// Defining the NextInt function
int NextInt(Scanner *s) {
	// Reading the next token as a string
	char *token = Next(s);
	// Converting the token to an integer
	int v = atoi(token);
	// Returning the integer
	return v;
}

// Defining the NextIntArray function
int *NextIntArray(Scanner *s) {
	// Reading the next token as a string
	char *token = Next(s);
	// Initializing an empty array
	int *result = malloc(sizeof(int));
	// Reading each integer from the standard input and appending it to the array
	for (int i = 0; ; i++) {
		// Checking if the current token is an integer
		if (strlen(token) > 0 && token[strlen(token) - 1] >= '0' && token[strlen(token) - 1] <= '9') {
			// If yes, then converting the token to an integer and appending it to the array
			int v = atoi(token);
			result = realloc(result, sizeof(int) * (i + 1));
			result[i] = v;
			// Reading the next token
			token = Next(s);
			// If the current token is not a space character, then there is an error in the input
			if (token[0]!='') {
				free(result);
				free(token);
				fprintf(stderr, "Invalid input\n");
				exit(1);
			}
		} else {
			// If the current token is not an integer, then the input is invalid
			free(result);
			free(token);
			fprintf(stderr, "Invalid input\n");
			exit(1);
		}
	}
	// Returning the array
	return result;
}

// Defining the NextMap function
int *NextMap(Scanner *s) {
	// Reading the next token as a string
	char *token = Next(s);
	// Initializing an empty map
	int *mp = malloc(sizeof(int));
	// Reading each key-value pair from the standard input and adding it to the map
	for (int i = 0; ; i++) {
		// Checking if the current token is an integer
		if (strlen(token) > 0 && token[strlen(token) - 1] >= '0' && token[strlen(token) - 1] <= '9') {
			// If yes, then converting the token to an integer and adding it as a key to the map
			int k = atoi(token);
			mp = realloc(mp, sizeof(int) * (i + 1));
			mp[i] = k;
			// Reading the next token
			token = Next(s);
			// If the current token is not a colon character, then there is an error in the input
			if (token[0]!= ':') {
				free(mp);
				free(token);
				fprintf(stderr, "Invalid input\n");
				exit(1);
			}
			// Reading the next token as a boolean value
			char *v = Next(s);
			// Adding the value to the map
			mp = realloc(mp, sizeof(int) * (i + 1));
			mp[i] = v;
			// If the current token is not a space character, then there is an error in the input
			if (token[0]!='') {
				free(mp);
				free(token);
				free(v);
				fprintf(stderr, "Invalid input\n");
				exit(1);
			}
		} else {
			// If the current token is not an integer, then the input is invalid
			free(mp);
			free(token);
			fprintf(stderr, "Invalid input\n");
			exit(1);
		}
		// Checking if the next token is the end of the input
		if (token[0] == '\0') {
			break;
		}
	}
	// Returning the map
	return mp;
}

// Defining the pre function
void pre(Scanner *s) {
	// If the position of the input buffer pointer is at the end of the buffer, then reading the next line from the standard input
	if (s->p >= strlen(s->buf)) {
		readLine(s);
		s->p = 0;
	}
}

// Defining the readLine function
void readLine(Scanner *s) {
	// Reading a line from the standard input
	char *l = malloc(1000);
	int p = 0;
	while (1) {
		int c = fgetc(s->r);
		if (c == '\n' || c == EOF) {
			break;
		}
		l[p++] = c;
	}
	l[p] = '\0';
	// Appending the line to the input buffer
	s->buf = realloc(s->buf, strlen(s->buf) + strlen(l) + 1);
	strcat(s->buf, l);
	// Setting the position of the input buffer pointer to the end of the line
	s->p = strlen(s->buf);
	// Freeing the line
	free(l);
}

// Defining the main function
int main() {
	// Creating a new scanner instance
	Scanner *s = NewScanner();
	// Reading the first integer from the standard input
	int n = NextInt(s);
	// Initializing the answer variable
	double ans = 0.0;
	// Iterating through the given number of integers
	for (int i = 0; i < n; i++) {
		// Reading the next integer from the standard input
		int tmp = 1 / NextInt(s);
		// Adding the reciprocal of the current integer to the answer
		ans += tmp;
	}
	// Printing the final answer
	printf("%.10f\n", 1 / ans);
	// Freeing the scanner instance
	free(s);
	return 0;
}

