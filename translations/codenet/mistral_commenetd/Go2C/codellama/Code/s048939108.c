
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a new scanner
void main() {
	scanner sc = newScanner();

	// Read the first string from the standard input
	char *S = sc.next();

	// Check if the string starts with "YAKI"
	if (strncmp(S, "YAKI", 4) == 0) {
		printf("Yes\n"); // Print "Yes" if the condition is true
	} else {
		printf("No\n"); // Print "No" if the condition is false
	}
}

// Minimum function
int min(int a, int b) {
	// Determine the minimum of two integers
	if (a > b) {
		return b;
	}
	return a;
}

// Maximum function
int max(int a, int b) {
	// Determine the maximum of two integers
	if (a > b) {
		return a;
	}
	return b;
}

// Scanner structure definition
typedef struct {
	char *buf;
	int p;
} scanner;

// Initialize a new scanner instance
scanner newScanner() {
	scanner sc;
	sc.buf = (char *)malloc(1000 * sizeof(char));
	sc.p = 0;
	return sc;
}

// Next function to read the next token as a string
char *next(scanner *sc) {
	sc->p++;
	while (sc->buf[sc->p] != ' ' && sc->buf[sc->p] != '\0') {
		sc->p++;
	}
	return sc->buf;
}

// NextLine function to read the next line as a string
char *nextLine(scanner *sc) {
	sc->p = strlen(sc->buf);
	return sc->buf;
}

// NextInt function to read the next integer from the standard input
int nextInt(scanner *sc) {
	char *token = next(sc);
	int v = atoi(token);
	return v;
}

// NextIntArray function to read an array of integers from the standard input
int *nextIntArray(scanner *sc) {
	int *result = (int *)malloc(1000 * sizeof(int));
	int i = 0;
	while (sc->buf[sc->p] != '\0') {
		char *token = next(sc);
		int v = atoi(token);
		result[i] = v;
		i++;
	}
	return result;
}

// Pre function to prepare the scanner for reading the next token
void pre(scanner *sc) {
	if (sc->p >= strlen(sc->buf)) {
		sc->buf = (char *)realloc(sc->buf, 1000 * sizeof(char));
		fgets(sc->buf, 1000, stdin);
		sc->p = 0;
	}
}

// ReadLine function to read a line from the standard input
void readLine(scanner *sc) {
	sc->buf = (char *)realloc(sc->buf, 1000 * sizeof(char));
	fgets(sc->buf, 1000, stdin);
	sc->p = 0;
}

