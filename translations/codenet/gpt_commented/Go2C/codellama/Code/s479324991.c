
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1000

typedef struct {
	char *buf;
	int p;
	int len;
} Scanner;

void pre(Scanner *s) {
	if (s->p >= s->len) {
		s->buf = realloc(s->buf, MAX_BUFFER_SIZE);
		s->len = fread(s->buf, 1, MAX_BUFFER_SIZE, stdin);
		s->p = 0;
	}
}

char *next(Scanner *s) {
	pre(s);
	int start = s->p;
	while (s->buf[s->p] != ' ') {
		s->p++;
	}
	char *result = malloc(s->p - start + 1);
	memcpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	s->p++;
	return result;
}

char *nextLine(Scanner *s) {
	pre(s);
	int start = s->p;
	while (s->buf[s->p] != '\n') {
		s->p++;
	}
	char *result = malloc(s->p - start + 1);
	memcpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	s->p++;
	return result;
}

int nextInt(Scanner *s) {
	char *token = next(s);
	int result = atoi(token);
	free(token);
	return result;
}

int *nextIntArray(Scanner *s) {
	pre(s);
	int start = s->p;
	int *result = malloc(sizeof(int) * 1000);
	int i = 0;
	while (s->buf[s->p] != '\n') {
		while (s->buf[s->p] != ' ') {
			s->p++;
		}
		result[i] = atoi(s->buf + start);
		start = s->p + 1;
		i++;
	}
	result[i] = atoi(s->buf + start);
	return result;
}

int *nextMap(Scanner *s) {
	pre(s);
	int start = s->p;
	int *result = malloc(sizeof(int) * 1000);
	int i = 0;
	while (s->buf[s->p] != '\n') {
		while (s->buf[s->p] != ' ') {
			s->p++;
		}
		result[i] = atoi(s->buf + start);
		start = s->p + 1;
		i++;
	}
	result[i] = atoi(s->buf + start);
	return result;
}

int main() {
	Scanner *sc = malloc(sizeof(Scanner));
	sc->buf = malloc(MAX_BUFFER_SIZE);
	sc->len = fread(sc->buf, 1, MAX_BUFFER_SIZE, stdin);
	sc->p = 0;

	int n = nextInt(sc);
	float *arr = malloc(sizeof(float) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextInt(sc);
	}

	qsort(arr, n, sizeof(float), compare);

	float prev = arr[0];
	for (int i = 1; i < n; i++) {
		prev = (prev + arr[i]) / 2;
	}

	printf("%f\n", prev);

	return 0;
}

int compare(const void *a, const void *b) {
	return *(float *)a - *(float *)b;
}

