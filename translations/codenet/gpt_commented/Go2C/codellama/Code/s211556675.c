
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// I/O
// Scanner struct to facilitate reading input from standard input
typedef struct {
	char *str;
	int pos;
} Scanner;

// NewScanner initializes a new Scanner instance
Scanner NewScanner() {
	Scanner sc;
	sc.str = (char *) malloc(sizeof(char) * 1024);
	sc.pos = 0;
	return sc;
}

// nextStr reads the next string from input
char *nextStr(Scanner *sc) {
	char *res = (char *) malloc(sizeof(char) * 1024);
	int i = 0;
	while (sc->str[sc->pos] != ' ' && sc->str[sc->pos] != '\0') {
		res[i++] = sc->str[sc->pos++];
	}
	res[i] = '\0';
	sc->pos++;
	return res;
}

// nextInt reads the next integer from input
int nextInt(Scanner *sc) {
	char *str = nextStr(sc);
	int res = atoi(str);
	free(str);
	return res;
}

// nextFloat reads the next float from input
float nextFloat(Scanner *sc) {
	char *str = nextStr(sc);
	float res = atof(str);
	free(str);
	return res;
}

// nextRuneSlice reads the next string and converts it to a slice of runes
char *nextRuneSlice(Scanner *sc) {
	char *res = (char *) malloc(sizeof(char) * 1024);
	int i = 0;
	while (sc->str[sc->pos] != ' ' && sc->str[sc->pos] != '\0') {
		res[i++] = sc->str[sc->pos++];
	}
	res[i] = '\0';
	sc->pos++;
	return res;
}

// nextIntSlice reads n integers from input and returns them as a slice
int *nextIntSlice(Scanner *sc, int n) {
	int *res = (int *) malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		res[i] = nextInt(sc);
	}
	return res;
}

// nextFloatSlice reads n floats from input and returns them as a slice
float *nextFloatSlice(Scanner *sc, int n) {
	float *res = (float *) malloc(sizeof(float) * n);
	for (int i = 0; i < n; i++) {
		res[i] = nextFloat(sc);
	}
	return res;
}

// Arithmetic functions

// max returns the maximum value from a list of integers
int max(int n, ...) {
	va_list args;
	va_start(args, n);
	int m = va_arg(args, int);
	for (int i = 1; i < n; i++) {
		int x = va_arg(args, int);
		if (m < x) {
			m = x;
		}
	}
	va_end(args);
	return m;
}

// min returns the minimum value from a list of integers
int min(int n, ...) {
	va_list args;
	va_start(args, n);
	int m = va_arg(args, int);
	for (int i = 1; i < n; i++) {
		int x = va_arg(args, int);
		if (m > x) {
			m = x;
		}
	}
	va_end(args);
	return m;
}

// abs returns the absolute value of an integer
int abs(int x) {
	if (x > 0) {
		return x;
	}
	return -x;
}

// pow computes x raised to the power of y
int pow(int x, int y) {
	int res = 1;
	for (int i = 0; i < y; i++) {
		res *= x;
	}
	return res;
}

// Sort related types and methods

// Val struct to hold a value and its associated ID
typedef struct {
	int id, num;
} Val;

// ByNum is a type that implements sort.Interface based on the num field
typedef struct {
	Val *vals;
	int n;
} ByNum;

// Len returns the number of elements in the collection
int Len(ByNum *a) {
	return a->n;
}

// Less reports whether the element with index i should sort before the element with index j
int Less(ByNum *a, int i, int j) {
	return a->vals[i].num < a->vals[j].num;
}

// Swap exchanges the elements with indexes i and j
void Swap(ByNum *a, int i, int j) {
	Val tmp = a->vals[i];
	a->vals[i] = a->vals[j];
	a->vals[j] = tmp;
}

// Main function
int main() {
	Scanner sc = NewScanner(); // Create a new scanner for input
	// Read four integers from input
	int A, B, C, K = nextInt(&sc), nextInt(&sc), nextInt(&sc), nextInt(&sc);

	// Determine the maximum value among A, B, and C
	int ma = max(3, A, B, C);
	int rest = 0; // Initialize the rest variable to hold the sum of the other two values

	// Calculate the sum of the two smaller values
	if (ma == A) {
		rest += B + C;
	} else if (ma == B) {
		rest += A + C;
	} else {
		rest += A + B;
	}

	// Double the maximum value K times
	for (int i = 1; i <= K; i++) {
		ma *= 2;
	}

	// Output the final result: doubled max value plus the sum of the other two
	printf("%d\n", ma + rest);
	return 0;
}

