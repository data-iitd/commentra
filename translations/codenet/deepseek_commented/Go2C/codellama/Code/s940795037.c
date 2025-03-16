
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Scanner {
	char *buf;
	int p;
} Scanner;

Scanner *NewScanner() {
	Scanner *sc = (Scanner *)malloc(sizeof(Scanner));
	sc->buf = (char *)malloc(1000 * sizeof(char));
	sc->p = 0;
	return sc;
}

void pre(Scanner *sc) {
	if (sc->p >= strlen(sc->buf)) {
		readLine(sc);
		sc->p = 0;
	}
}

void readLine(Scanner *sc) {
	sc->buf = (char *)realloc(sc->buf, 1000 * sizeof(char));
	fgets(sc->buf, 1000, stdin);
}

char *Next(Scanner *sc) {
	pre(sc);
	int start = sc->p;
	for (; sc->p < strlen(sc->buf); sc->p++) {
		if (sc->buf[sc->p] == ' ') {
			break;
		}
	}
	char *result = (char *)malloc((sc->p - start + 1) * sizeof(char));
	strncpy(result, sc->buf + start, sc->p - start);
	result[sc->p - start] = '\0';
	sc->p++;
	return result;
}

char *NextLine(Scanner *sc) {
	pre(sc);
	int start = sc->p;
	sc->p = strlen(sc->buf);
	char *result = (char *)malloc((sc->p - start + 1) * sizeof(char));
	strncpy(result, sc->buf + start, sc->p - start);
	result[sc->p - start] = '\0';
	return result;
}

int NextInt(Scanner *sc) {
	char *tmp = Next(sc);
	int result = atoi(tmp);
	free(tmp);
	return result;
}

int *NextIntArray(Scanner *sc) {
	pre(sc);
	int start = sc->p;
	int *result = (int *)malloc(1000 * sizeof(int));
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
	int *result = (int *)malloc(1000 * sizeof(int));
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
	float ans = 0.0;
	for (int i = 0; i < n; i++) {
		float tmp = 1 / (float)NextInt(sc);
		ans += tmp;
	}
	printf("%f\n", 1 / ans);
	return 0;
}

