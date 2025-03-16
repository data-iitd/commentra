#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// nextInt reads the next integer from the scanner and returns it.
int nextInt(FILE *sc) {
	char *t;
	int i;
	fscanf(sc, "%d", &i);
	return i;
}

// reva reverses a slice of integers in place.
void reva(int *b, int n) {
	int i;
	for (i = 0; i < n/2; i++) {
		int t = b[i];
		b[i] = b[n-1-i];
		b[n-1-i] = t;
	}
}

int main() {
	FILE *sc = stdin;
	int n = nextInt(sc);
	int *a = malloc(n * sizeof(int));
	int i;
	for (i = 0; i < n; i++) {
		a[i] = nextInt(sc);
	}
	int q = nextInt(sc);
	for (i = 0; i < q; i++) {
		int b = nextInt(sc);
		int e = nextInt(sc);
		reva(a + b, e - b);
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

