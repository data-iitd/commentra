#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// nextInt reads the next word from the scanner, converts it to an integer, and returns it.
int nextInt(char **input) {
	char *token = strtok(*input, " ");
	*input = NULL;
	return atoi(token);
}

// reva takes a slice of integers and reverses it in place.
void reva(int *b, int n) {
	for (int i = 0; i < n/2; i++) {
		int t = b[i];
		b[i] = b[n-1-i];
		b[n-1-i] = t;
	}
}

// main is the entry point of the program.
int main(int argc, char **argv) {
	char *input = NULL;
	size_t len = 0;
	ssize_t read;
	char *line = NULL;
	getline(&input, &len, stdin);
	int n = nextInt(&input);
	int *a = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		a[i] = nextInt(&input);
	}
	int q = nextInt(&input);
	for (int i = 0; i < q; i++) {
		int b = nextInt(&input);
		int e = nextInt(&input);
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
	free(input);
	return EXIT_SUCCESS;
}

