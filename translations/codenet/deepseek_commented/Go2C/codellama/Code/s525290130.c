#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// nextInt reads the next word from the scanner, converts it to an integer, and returns it.
int nextInt(FILE *sc) {
	char *t;
	int i;
	t = malloc(sizeof(char) * 100);
	fscanf(sc, "%s", t);
	i = atoi(t);
	free(t);
	return i;
}

// reva takes a slice of integers and reverses it in place.
void reva(int *b, int n) {
	int i;
	for (i = 0; i < n/2; i++) {
		b[i] = b[n-1-i];
		b[n-1-i] = b[i];
	}
}

// main is the entry point of the program.
int main() {
	FILE *sc = stdin;
	int n, q, i, j, b, e;
	int *a;
	a = malloc(sizeof(int) * 1000000);
	n = nextInt(sc);
	for (i = 0; i < n; i++) {
		a[i] = nextInt(sc);
	}
	q = nextInt(sc);
	for (i = 0; i < q; i++) {
		b = nextInt(sc);
		e = nextInt(sc);
		reva(a+b, e-b);
	}
	for (i = 0; i < n; i++) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d", a[i]);
	}
	printf("\n");
	free(a);
	return 0;
}

