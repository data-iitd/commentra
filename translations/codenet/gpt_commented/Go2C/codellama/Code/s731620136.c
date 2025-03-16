
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Scanner struct for handling input
typedef struct {
	char *str;
	int pos;
} Scanner;

// NewScanner initializes a new Scanner for reading input
Scanner NewScanner() {
	Scanner sc;
	sc.str = (char *) malloc(sizeof(char) * 10240);
	sc.pos = 0;
	return sc;
}

// nextStr reads the next string from input
char *nextStr(Scanner *sc) {
	char *res = (char *) malloc(sizeof(char) * 10240);
	int i = 0;
	while (sc->str[sc->pos] != ' ' && sc->str[sc->pos] != '\0') {
		res[i] = sc->str[sc->pos];
		i++;
		sc->pos++;
	}
	res[i] = '\0';
	sc->pos++;
	return res;
}

// nextInt reads the next integer from input
int nextInt(Scanner *sc) {
	int res = atoi(nextStr(sc));
	return res;
}

// nextFloat reads the next float from input
float nextFloat(Scanner *sc) {
	float res = atof(nextStr(sc));
	return res;
}

// nextRuneSlice reads the next string and converts it to a byte slice
char *nextRuneSlice(Scanner *sc) {
	return nextStr(sc);
}

// nextIntSlice reads a slice of integers from input
int *nextIntSlice(Scanner *sc, int n) {
	int *res = (int *) malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		res[i] = nextInt(sc);
	}
	return res;
}

// nextFloatSlice reads a slice of floats from input
float *nextFloatSlice(Scanner *sc, int n) {
	float *res = (float *) malloc(sizeof(float) * n);
	for (int i = 0; i < n; i++) {
		res[i] = nextFloat(sc);
	}
	return res;
}

// run processes the input and produces output
int run(FILE *input, FILE *output) {
	Scanner sc = NewScanner(); // Create a new scanner instance
	int N = nextInt(&sc); // Read the number of elements
	char *S = nextStr(&sc); // Read the string of colors

	// Handle case where there are no elements
	if (N == 0) {
		return 0;
	}

	// If there are fewer than 4 elements, output 0
	if (N < 4) {
		fprintf(output, "0\n");
		return 0;
	}

	// Count occurrences of each color
	int nr = 0, nb = 0, ng = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == 'R') {
			nr++;
		}
		if (S[i] == 'B') {
			nb++;
		}
		if (S[i] == 'G') {
			ng++;
		}
	}

	int same = 0; // Counter for same color combinations

	// Iterate through possible combinations of indices
	for (int a = 1; a < N; a++) {
		int i = 0;
		int j = 1 * a;
		int k = 2 * a;
		if (k >= N) {
			break; // Exit if index exceeds string length
		}
		for (; k < N; k++) {
			// Check if the colors at the indices are different
			if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) {
				same++; // Increment same color combination counter
			}
			i++;
			j++;
			k++;
		}
	}

	// Calculate total combinations of different colors
	int tot = nr * nb * ng;

	// Output the result by subtracting same combinations from total
	fprintf(output, "%d\n", tot - same);

	return 0; // Return success
}

int main() {
	run(stdin, stdout); // Run the program and exit
	return 0;
}

