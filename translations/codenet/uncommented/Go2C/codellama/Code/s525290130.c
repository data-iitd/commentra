
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nextInt(FILE *f) {
	int t;
	fscanf(f, "%d", &t);
	return t;
}

void reva(int *b, int n) {
	for (int i = 0; i < n/2; i++) {
		b[i] ^= b[n-1-i];
		b[n-1-i] ^= b[i];
		b[i] ^= b[n-1-i];
	}
}

int main() {
	FILE *f = fopen("input.txt", "r");
	int n = nextInt(f);
	int *a = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		a[i] = nextInt(f);
	}
	int q = nextInt(f);
	for (int i = 0; i < q; i++) {
		int b = nextInt(f);
		int e = nextInt(f);
		reva(a+b, e-b);
	}
	for (int i = 0; i < n; i++) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d", a[i]);
	}
	printf("\n");
	free(a);
	return 0;
}

