#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// I/O
// The Scanner struct is defined to read input efficiently.
typedef struct {
	char *s;
	int len;
	int pos;
} Scanner;

// NewScanner initializes a new Scanner instance with appropriate buffer sizes and word-based scanning.
Scanner *NewScanner() {
	Scanner *sc = malloc(sizeof(Scanner));
	sc->s = malloc(10240);
	sc->len = 10240;
	sc->pos = 0;
	return sc;
}

// Reads the next word from the input and returns it as a string.
char *nextStr(Scanner *sc) {
	while (sc->s[sc->pos] =='' || sc->s[sc->pos] == '\n' || sc->s[sc->pos] == '\t') {
		sc->pos++;
	}
	char *res = malloc(10240);
	int i = 0;
	while (sc->s[sc->pos]!='' && sc->s[sc->pos]!= '\n' && sc->s[sc->pos]!= '\t' && sc->pos < sc->len) {
		res[i] = sc->s[sc->pos];
		sc->pos++;
		i++;
	}
	res[i] = '\0';
	return res;
}

// Reads the next word, converts it to an integer, and returns it.
int nextInt(Scanner *sc) {
	char *res = nextStr(sc);
	int i = atoi(res);
	free(res);
	return i;
}

// Reads the next word, converts it to a float64, and returns it.
double nextFloat(Scanner *sc) {
	char *res = nextStr(sc);
	double i = atof(res);
	free(res);
	return i;
}

// Reads the next word and returns it as a byte slice.
char *nextRuneSlice(Scanner *sc) {
	char *res = nextStr(sc);
	return res;
}

// Reads `n` integers from the input and returns them as a slice.
int *nextIntSlice(Scanner *sc, int n) {
	int *res = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		res[i] = nextInt(sc);
	}
	return res;
}

// Reads `n` floats from the input and returns them as a slice.
double *nextFloatSlice(Scanner *sc, int n) {
	double *res = malloc(sizeof(double) * n);
	for (int i = 0; i < n; i++) {
		res[i] = nextFloat(sc);
	}
	return res;
}

// The run function reads the input, processes it, and prints the result.
int run(Scanner *sc, FILE *f) {
	// Reads the number of elements N and the string S.
	int N = nextInt(sc);
	char *S = nextStr(sc);

	if (N == 0) {
	}

	if (N < 4) {
		fprintf(f, "0\n");
		return 0;
	}

	// Counts the number of 'R', 'B', and 'G' characters in S.
	int nr = 0;
	int nb = 0;
	int ng = 0;
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

	// Calculates the number of triplets where the characters are all different.
	int same = 0;
	for (int a = 1; a < N; a++) {
		int i = 0;
		int j = 1 * a;
		int k = 2 * a;
		if (k >= N) {
			break;
		}
		for (k = 2 * a; k < N; k++) {
			if (S[i]!= S[j] && S[i]!= S[k] && S[j]!= S[k]) {
				same++;
			}
			i++;
			j++;
			k++;
		}
	}

	// Calculates the total number of possible triplets.
	int tot = nr * nb * ng;

	// Prints the difference between the total number of possible triplets and the number of triplets with all different characters.
	fprintf(f, "%d\n", tot - same);

	return 0;
}

// The main function calls the run function with standard input and output, and exits with the return value of run.
int main() {
	Scanner *sc = NewScanner();
	FILE *f = stdout;
	return run(sc, f);
}

