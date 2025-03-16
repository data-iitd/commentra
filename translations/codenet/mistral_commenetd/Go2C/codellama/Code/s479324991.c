#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Initialize a new scanner object
struct Scanner {
	char *buf;
	int p;
};

// Create a new scanner object
struct Scanner* NewScanner() {
	struct Scanner *sc = (struct Scanner*)malloc(sizeof(struct Scanner));
	sc->buf = (char*)malloc(1000 * sizeof(char));
	sc->p = 0;
	return sc;
}

// Read a single token from the standard input
char* Next(struct Scanner *sc) {
	sc->pre(sc);
	int start = sc->p;
	for (; sc->p < strlen(sc->buf); sc->p++) {
		if (sc->buf[sc->p] == ' ') {
			break;
		}
	}
	char *result = (char*)malloc((sc->p - start + 1) * sizeof(char));
	strncpy(result, sc->buf + start, sc->p - start);
	result[sc->p - start] = '\0';
	sc->p++;
	return result;
}

// Read a line from the standard input
char* NextLine(struct Scanner *sc) {
	sc->pre(sc);
	int start = sc->p;
	sc->p = strlen(sc->buf);
	char *result = (char*)malloc((sc->p - start + 1) * sizeof(char));
	strncpy(result, sc->buf + start, sc->p - start);
	result[sc->p - start] = '\0';
	return result;
}

// Read an integer from the standard input
int NextInt(struct Scanner *sc) {
	char *str = Next(sc);
	int result = atoi(str);
	free(str);
	return result;
}

// Read an array of integers from the standard input
int* NextIntArray(struct Scanner *sc) {
	sc->pre(sc);
	int start = sc->p;
	int *result = (int*)malloc(1000 * sizeof(int));
	int i = 0;
	for (; sc->p < strlen(sc->buf); sc->p++) {
		if (sc->buf[sc->p] == ' ') {
			result[i] = atoi(sc->buf + start);
			start = sc->p + 1;
			i++;
		}
	}
	result[i] = atoi(sc->buf + start);
	return result;
}

// Read a map from the standard input
int* NextMap(struct Scanner *sc) {
	sc->pre(sc);
	int start = sc->p;
	int *result = (int*)malloc(1000 * sizeof(int));
	int i = 0;
	for (; sc->p < strlen(sc->buf); sc->p++) {
		if (sc->buf[sc->p] == ' ') {
			result[i] = atoi(sc->buf + start);
			start = sc->p + 1;
			i++;
		}
	}
	result[i] = atoi(sc->buf + start);
	return result;
}

// Prepare the scanner for the next read operation
void pre(struct Scanner *sc) {
	if (sc->p >= strlen(sc->buf)) {
		sc->readLine(sc);
		sc->p = 0;
	}
}

// Read a line from the standard input
void readLine(struct Scanner *sc) {
	sc->buf = (char*)malloc(1000 * sizeof(char));
	for (; ; ) {
		int l = 0;
		int p = 0;
		int e = 0;
		l = fread(sc->buf, sizeof(char), 1000, stdin);
		p = feof(stdin);
		e = ferror(stdin);
		if (e != 0) {
			printf("Error reading from standard input\n");
			exit(1);
		}
		if (!p) {
			break;
		}
	}
}

// Initialize a new scanner object
struct Scanner* sc = NewScanner();

// Read the number of elements in the array from the standard input
int n = NextInt(sc);

// Allocate memory for the array of size n
double* arr = (double*)malloc(n * sizeof(double));

// Read n integers from the standard input and store them in the array
for (int i = 0; i < n; i++) {
	arr[i] = NextInt(sc);
}

// Sort the array in ascending order
qsort(arr, n, sizeof(double), compare);

// Initialize a variable prev to store the previous element in the sorted array
double prev = arr[0];

// Iterate through the sorted array from the second element to the last
for (int i = 1; i < n; i++) {
	// Calculate the average of the previous and current elements
	prev = (prev + arr[i]) / 2;
}

// Print the result to the standard output
printf("%f\n", prev);

// Free the memory allocated for the array
free(arr);

// Free the memory allocated for the scanner object
free(sc);

// End of code
