
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main function starts here
int main() {
	// Initialize a new scanner to read input
	scanner *sc = newScanner();
	// Read the next string from the scanner
	char *S = sc->next();
	// Check if the string S starts with the prefix "YAKI"
	if (strncmp(S, "YAKI", 4) == 0) {
		// If it does, print "Yes"
		printf("Yes\n");
	} else {
		// Otherwise, print "No"
		printf("No\n");
	}
}

// Helper function to find the minimum of two integers
int min(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

// Helper function to find the maximum of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// Custom scanner type to handle input reading
typedef struct {
	FILE *r;
	char *buf;
	int p;
} scanner;

// Function to create a new scanner instance
scanner *newScanner() {
	scanner *sc = (scanner *)malloc(sizeof(scanner));
	sc->r = fopen("input.txt", "r");
	sc->buf = (char *)malloc(1000);
	sc->p = 0;
	return sc;
}

// Method to read the next word from the input
char *next(scanner *sc) {
	pre(sc);
	int start = sc->p;
	while (sc->p < strlen(sc->buf)) {
		if (sc->buf[sc->p] =='') {
			break;
		}
		sc->p++;
	}
	char *result = (char *)malloc(sc->p - start + 1);
	strncpy(result, sc->buf + start, sc->p - start);
	result[sc->p - start] = '\0';
	sc->p++;
	return result;
}

// Method to read the next line from the input
char *nextLine(scanner *sc) {
	pre(sc);
	int start = sc->p;
	sc->p = strlen(sc->buf);
	char *result = (char *)malloc(sc->p - start + 1);
	strncpy(result, sc->buf + start, sc->p - start);
	result[sc->p - start] = '\0';
	return result;
}

// Method to read the next integer from the input
int nextInt(scanner *sc) {
	char *v = next(sc);
	return atoi(v);
}

// Method to read the next array of integers from the input
int *nextIntArray(scanner *sc) {
	pre(sc);
	int start = sc->p;
	int *result = (int *)malloc(1000 * sizeof(int));
	int i = 0;
	while (sc->p < strlen(sc->buf) + 1) {
		if (sc->p == strlen(sc->buf) || sc->buf[sc->p] =='') {
			char *v = (char *)malloc(sc->p - start + 1);
			strncpy(v, sc->buf + start, sc->p - start);
			v[sc->p - start] = '\0';
			result[i] = atoi(v);
			free(v);
			i++;
			start = sc->p + 1;
		}
		sc->p++;
	}
	return result;
}

// Method to preprocess the buffer before reading
void pre(scanner *sc) {
	if (sc->p >= strlen(sc->buf)) {
		readLine(sc);
		sc->p = 0;
	}
}

// Method to read a line from the input and update the buffer
void readLine(scanner *sc) {
	sc->buf = (char *)malloc(1000);
	while (1) {
		char *l = (char *)malloc(1000);
		int p = fgets(l, 1000, sc->r);
		if (p == NULL) {
			free(l);
			break;
		}
		sc->buf = (char *)realloc(sc->buf, strlen(sc->buf) + strlen(l) + 1);
		strcat(sc->buf, l);
		free(l);
		if (p == 0) {
			break;
		}
	}
}

