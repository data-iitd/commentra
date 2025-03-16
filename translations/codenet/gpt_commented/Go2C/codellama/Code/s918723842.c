
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

typedef struct {
	char *buf;
	int p;
} Scanner;

void pre(Scanner *s) {
	if (s->p >= strlen(s->buf)) {
		s->buf = realloc(s->buf, MAX_BUFFER_SIZE);
		fgets(s->buf, MAX_BUFFER_SIZE, stdin);
		s->p = 0;
	}
}

char *next(Scanner *s) {
	pre(s);
	int start = s->p;
	while (s->buf[s->p] != ' ' && s->p < strlen(s->buf)) {
		s->p++;
	}
	char *result = malloc(s->p - start + 1);
	strncpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	s->p++;
	return result;
}

char *nextLine(Scanner *s) {
	pre(s);
	int start = s->p;
	while (s->p < strlen(s->buf)) {
		s->p++;
	}
	char *result = malloc(s->p - start + 1);
	strncpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	return result;
}

int nextInt(Scanner *s) {
	char *token = next(s);
	int result = atoi(token);
	free(token);
	return result;
}

int nextInt64(Scanner *s) {
	char *token = next(s);
	int64_t result = strtoll(token, NULL, 10);
	free(token);
	return result;
}

double nextFloat(Scanner *s) {
	char *token = next(s);
	double result = strtod(token, NULL);
	free(token);
	return result;
}

int *nextIntArray(Scanner *s) {
	pre(s);
	int start = s->p;
	int *result = malloc(sizeof(int) * 1000);
	int i = 0;
	while (s->p < strlen(s->buf) + 1) {
		if (s->p == strlen(s->buf) || s->buf[s->p] == ' ') {
			char *token = malloc(s->p - start + 1);
			strncpy(token, s->buf + start, s->p - start);
			token[s->p - start] = '\0';
			result[i++] = atoi(token);
			free(token);
			start = s->p + 1;
		}
	}
	char *token = malloc(s->p - start + 1);
	strncpy(token, s->buf + start, s->p - start);
	token[s->p - start] = '\0';
	result[i++] = atoi(token);
	free(token);
	return result;
}

int64_t *nextInt64Array(Scanner *s) {
	pre(s);
	int start = s->p;
	int64_t *result = malloc(sizeof(int64_t) * 1000);
	int i = 0;
	while (s->p < strlen(s->buf) + 1) {
		if (s->p == strlen(s->buf) || s->buf[s->p] == ' ') {
			char *token = malloc(s->p - start + 1);
			strncpy(token, s->buf + start, s->p - start);
			token[s->p - start] = '\0';
			result[i++] = strtoll(token, NULL, 10);
			free(token);
			start = s->p + 1;
		}
	}
	char *token = malloc(s->p - start + 1);
	strncpy(token, s->buf + start, s->p - start);
	token[s->p - start] = '\0';
	result[i++] = strtoll(token, NULL, 10);
	free(token);
	return result;
}

int *nextMap(Scanner *s) {
	pre(s);
	int start = s->p;
	int *result = malloc(sizeof(int) * 1000);
	int i = 0;
	while (s->p < strlen(s->buf)) {
		if (s->buf[s->p] == ' ') {
			char *token = malloc(s->p - start + 1);
			strncpy(token, s->buf + start, s->p - start);
			token[s->p - start] = '\0';
			result[i++] = atoi(token);
			free(token);
			start = s->p + 1;
		}
	}
	char *token = malloc(s->p - start + 1);
	strncpy(token, s->buf + start, s->p - start);
	token[s->p - start] = '\0';
	result[i++] = atoi(token);
	free(token);
	return result;
}

int main() {
	Scanner *sc = malloc(sizeof(Scanner));
	sc->buf = malloc(MAX_BUFFER_SIZE);
	fgets(sc->buf, MAX_BUFFER_SIZE, stdin);
	sc->p = 0;

	int H = nextInt(sc);
	int W = nextInt(sc);
	int N = nextInt(sc);

	int A = H > W ? H : W;

	int fullGroups = (N + A - 1) / A;

	printf("%d\n", fullGroups);

	return 0;
}

