#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Scanner {
	FILE *r;
	char *buf;
	int p;
} Scanner;

Scanner *NewScanner() {
	Scanner *sc = (Scanner *)malloc(sizeof(Scanner));
	sc->r = stdin;
	sc->buf = (char *)malloc(1000);
	sc->p = 0;
	return sc;
}

void pre(Scanner *sc) {
	if (sc->p >= strlen(sc->buf)) {
		sc->readLine(sc);
		sc->p = 0;
	}
}

void readLine(Scanner *sc) {
	sc->buf = (char *)realloc(sc->buf, 1000);
	fgets(sc->buf, 1000, sc->r);
}

char *Next(Scanner *sc) {
	pre(sc);
	int start = sc->p;
	for (; sc->p < strlen(sc->buf); sc->p++) {
		if (sc->buf[sc->p] == ' ') {
			break;
		}
	}
	char *result = (char *)malloc(sc->p - start + 1);
	strncpy(result, sc->buf + start, sc->p - start);
	result[sc->p - start] = '\0';
	sc->p++;
	return result;
}

char *NextLine(Scanner *sc) {
	pre(sc);
	int start = sc->p;
	sc->p = strlen(sc->buf);
	char *result = (char *)malloc(sc->p - start + 1);
	strncpy(result, sc->buf + start, sc->p - start);
	result[sc->p - start] = '\0';
	return result;
}

int NextInt(Scanner *sc) {
	char *str = Next(sc);
	int result = atoi(str);
	free(str);
	return result;
}

int *NextIntArray(Scanner *sc) {
	pre(sc);
	int start = sc->p;
	int *result = (int *)malloc(sizeof(int) * 1000);
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

int *NextMap(Scanner *sc) {
	pre(sc);
	int start = sc->p;
	int *result = (int *)malloc(sizeof(int) * 1000);
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

int main() {
	Scanner *sc = NewScanner();

	int n = NextInt(sc);
	double *arr = (double *)malloc(sizeof(double) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = (double)NextInt(sc);
	}
	qsort(arr, n, sizeof(double), cmp);
	double prev = arr[0];
	for (int i = 1; i < n; i++) {
		prev = (prev + arr[i]) / 2;
	}

	printf("%f\n", prev);
}

int cmp(const void *a, const void *b) {
	return *(double *)a - *(double *)b;
}

