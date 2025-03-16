#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initializes a new Scanner instance to read from standard input.
void main() {
	Scanner sc = NewScanner();
	
	// Reads three integers H, W, and N from the standard input.
	int H, W, N;
	scanf("%d %d %d", &H, &W, &N);
	
	// Determines the maximum of H and W and assigns it to A.
	int A = max(H, W);
	
	// Calculates the result by dividing N by A and rounding up.
	// This is done by adding N-1 to the division result and then performing integer division by A.
	printf("%d\n", (N + A - 1) / A);
}

// Returns the maximum of two integers.
int max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

// Scanner struct to read input efficiently.
typedef struct {
	char *buf;
	int p;
} Scanner;

// Initializes a new Scanner instance with a buffer size of 1000 bytes.
Scanner NewScanner() {
	Scanner sc;
	sc.buf = (char *)malloc(1000 * sizeof(char));
	sc.p = 0;
	return sc;
}

// Reads the next token from the input buffer.
char *Next(Scanner *sc) {
	sc->pre();
	int start = sc->p;
	for (; sc->p < strlen(sc->buf); sc->p++) {
		if (sc->buf[sc->p] == ' ') {
			break;
		}
	}
	char *result = (char *)malloc((sc->p - start + 1) * sizeof(char));
	strncpy(result, sc->buf + start, sc->p - start);
	result[sc->p - start] = '\0';
	sc->p++;
	return result;
}

// Reads the next line from the input buffer.
char *NextLine(Scanner *sc) {
	sc->pre();
	int start = sc->p;
	sc->p = strlen(sc->buf);
	char *result = (char *)malloc((sc->p - start + 1) * sizeof(char));
	strncpy(result, sc->buf + start, sc->p - start);
	result[sc->p - start] = '\0';
	return result;
}

// Reads the next integer from the input buffer.
int NextInt(Scanner *sc) {
	char *str = Next(sc);
	int result = atoi(str);
	free(str);
	return result;
}

// Reads the next 64-bit integer from the input buffer.
long long NextInt64(Scanner *sc) {
	char *str = Next(sc);
	long long result = atoll(str);
	free(str);
	return result;
}

// Reads the next float from the input buffer.
float NextFloat(Scanner *sc) {
	char *str = Next(sc);
	float result = atof(str);
	free(str);
	return result;
}

// Reads the next array of integers from the input buffer.
int *NextIntArray(Scanner *sc) {
	sc->pre();
	int start = sc->p;
	int *result = (int *)malloc(1000 * sizeof(int));
	int i = 0;
	for (; sc->p < strlen(sc->buf); sc->p++) {
		if (sc->buf[sc->p] == ' ' || sc->p == strlen(sc->buf)) {
			char *str = (char *)malloc((sc->p - start + 1) * sizeof(char));
			strncpy(str, sc->buf + start, sc->p - start);
			str[sc->p - start] = '\0';
			result[i++] = atoi(str);
			free(str);
			start = sc->p + 1;
		}
	}
	return result;
}

// Reads the next array of 64-bit integers from the input buffer.
long long *NextInt64Array(Scanner *sc) {
	sc->pre();
	int start = sc->p;
	long long *result = (long long *)malloc(1000 * sizeof(long long));
	int i = 0;
	for (; sc->p < strlen(sc->buf); sc->p++) {
		if (sc->buf[sc->p] == ' ' || sc->p == strlen(sc->buf)) {
			char *str = (char *)malloc((sc->p - start + 1) * sizeof(char));
			strncpy(str, sc->buf + start, sc->p - start);
			str[sc->p - start] = '\0';
			result[i++] = atoll(str);
			free(str);
			start = sc->p + 1;
		}
	}
	return result;
}

// Reads the next map of integers from the input buffer.
int *NextMap(Scanner *sc) {
	sc->pre();
	int start = sc->p;
	int *result = (int *)malloc(1000 * sizeof(int));
	int i = 0;
	for (; sc->p < strlen(sc->buf); sc->p++) {
		if (sc->buf[sc->p] == ' ' || sc->p == strlen(sc->buf)) {
			char *str = (char *)malloc((sc->p - start + 1) * sizeof(char));
			strncpy(str, sc->buf + start, sc->p - start);
			str[sc->p - start] = '\0';
			result[i++] = atoi(str);
			free(str);
			start = sc->p + 1;
		}
	}
	return result;
}

// Ensures that the buffer has data before reading.
void pre(Scanner *sc) {
	if (sc->p >= strlen(sc->buf)) {
		sc->readLine();
		sc->p = 0;
	}
}

// Reads the entire line from the input buffer.
void readLine(Scanner *sc) {
	sc->buf = (char *)realloc(sc->buf, 1000 * sizeof(char));
	fgets(sc->buf, 1000, stdin);
}

