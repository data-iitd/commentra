
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the scanner type
typedef struct Scanner {
	// Defining the reader instance
	FILE *r;
	// Defining the input buffer
	char *buf;
	// Defining the position of the input buffer pointer
	int p;
} Scanner;

// Defining the NewScanner function
Scanner NewScanner() {
	// Creating a new buffered reader instance
	FILE *rdr = fopen(stdin, "r");
	// Initializing the scanner instance with the reader instance
	Scanner sc = { r: rdr };
	// Returning the scanner instance
	return sc;
}

// Defining the Next function
char *Next(Scanner *s) {
	// Preprocessing the input buffer
	s->pre();
	// Reading the next token from the input buffer
	int start = s->p;
	for (; s->p < strlen(s->buf); s->p++) {
		// Checking if the current character is a whitespace character
		if (s->buf[s->p] == ' ') {
			// If yes, then setting the end position of the token
			break;
		}
	}
	// Reading the token from the input buffer
	char *result = (char *)malloc(sizeof(char) * (s->p - start + 1));
	strncpy(result, s->buf + start, s->p - start);
	// Incrementing the position of the input buffer pointer
	s->p++;
	// Returning the token
	return result;
}

// Defining the NextLine function
char *NextLine(Scanner *s) {
	// Preprocessing the input buffer
	s->pre();
	// Reading the next line from the input buffer
	int start = s->p;
	s->p = strlen(s->buf);
	// Reading the rest of the line if available
	s->readLine();
	// Creating a slice from the current position to the end of the input buffer
	char *result = (char *)malloc(sizeof(char) * (strlen(s->buf) - start + 1));
	strncpy(result, s->buf + start, strlen(s->buf) - start);
	// Returning the line
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
	// Initializing an empty slice
	int *result = (int *)malloc(sizeof(int) * 1000);
	// Reading each integer from the standard input and appending it to the slice
	int i = 0;
	for (; i < 1000; i++) {
		// Checking if the current token is an integer
		if (strlen(token) > 0 && token[strlen(token) - 1] >= '0' && token[strlen(token) - 1] <= '9') {
			// If yes, then converting the token to an integer and appending it to the slice
			int v = atoi(token);
			result[i] = v;
			// Reading the next token
			token = Next(s);
			// If the current token is not a space character, then there is an error in the input
			if (token[0] != ' ') {
				panic("Invalid input");
			}
		} else {
			// If the current token is not an integer, then the input is invalid
			panic("Invalid input");
		}
	}
	// Returning the slice
	return result;
}

// Defining the NextMap function
int *NextMap(Scanner *s) {
	// Reading the next token as a string
	char *token = Next(s);
	// Initializing an empty map
	int *mp = (int *)malloc(sizeof(int) * 1000);
	// Reading each key-value pair from the standard input and adding it to the map
	int i = 0;
	for (; i < 1000; i++) {
		// Checking if the current token is an integer
		if (strlen(token) > 0 && token[strlen(token) - 1] >= '0' && token[strlen(token) - 1] <= '9') {
			// If yes, then converting the token to an integer and adding it as a key to the map
			int k = atoi(token);
			mp[k] = 1;
			// Reading the next token
			token = Next(s);
			// If the current token is not a colon character, then there is an error in the input
			if (token[0] != ':') {
				panic("Invalid input");
			}
			// Reading the next token as a boolean value
			char *v = Next(s);
			// Adding the value to the map
			mp[k] = (v[0] == 't') ? 1 : 0;
			// If the current token is not a space character, then there is an error in the input
			if (token[0] != ' ') {
				panic("Invalid input");
			}
		} else {
			// If the current token is not an integer, then the input is invalid
			panic("Invalid input");
		}
		// Checking if the next token is the end of the input
		if (strlen(token) == 0) {
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
		s->readLine();
		s->p = 0;
	}
}

// Defining the readLine function
void readLine(Scanner *s) {
	// Reading a line from the standard input
	char *l = (char *)malloc(sizeof(char) * 1000);
	fgets(l, 1000, s->r);
	// Appending the line to the input buffer
	s->buf = (char *)realloc(s->buf, sizeof(char) * (strlen(s->buf) + strlen(l) + 1));
	strcat(s->buf, l);
	// Setting the position of the input buffer pointer to the end of the line
	s->p = strlen(s->buf);
}

// Defining the panic function
void panic(char *msg) {
	// Printing the error message
	printf("%s\n", msg);
	// Exiting the program
	exit(1);
}

// Defining the main function
int main() {
	// Creating a new scanner instance
	Scanner sc = NewScanner();

	// Reading the first integer from the standard input
	int n = NextInt(&sc);
	// Initializing the answer variable
	double ans = 0.0;

	// Iterating through the given number of integers
	for (int i = 0; i < n; i++) {
		// Reading the next integer from the standard input
		double tmp = 1 / NextInt(&sc);
		// Adding the reciprocal of the current integer to the answer
		ans += tmp;
	}

	// Printing the final answer
	printf("%f\n", 1 / ans);

	// Returning 0
	return 0;
}

