#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 1000

typedef struct {
	FILE *r;
	char *buf;
	int p;
} scanner;

scanner *newScanner() {
	scanner *s = (scanner *)malloc(sizeof(scanner));
	s->r = fopen("stdin", "r");
	s->buf = (char *)malloc(MAX_BUF * sizeof(char));
	s->p = 0;
	return s;
}

void pre(scanner *s) {
	if (s->p >= MAX_BUF) {
		readLine(s);
		s->p = 0;
	}
}

void readLine(scanner *s) {
	s->buf = (char *)realloc(s->buf, MAX_BUF * sizeof(char));
	int i = 0;
	while (1) {
		char c = fgetc(s->r);
		if (c == EOF) {
			break;
		}
		s->buf[i++] = c;
		if (c == '\n') {
			break;
		}
	}
}

char *next(scanner *s) {
	pre(s);
	int start = s->p;
	for (; s->p < MAX_BUF; s->p++) {
		if (s->buf[s->p] == ' ') {
			break;
		}
	}
	char *result = (char *)malloc((s->p - start + 1) * sizeof(char));
	strncpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	s->p++;
	return result;
}

char *nextLine(scanner *s) {
	pre(s);
	int start = s->p;
	s->p = MAX_BUF;
	char *result = (char *)malloc((MAX_BUF - start + 1) * sizeof(char));
	strncpy(result, s->buf + start, MAX_BUF - start);
	result[MAX_BUF - start] = '\0';
	return result;
}

int nextInt(scanner *s) {
	char *str = next(s);
	int result = atoi(str);
	free(str);
	return result;
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int main() {
	scanner *sc = newScanner();
	int x = nextInt(sc);
	int y = nextInt(sc);
	int xt, yt;
	int a[3][7] = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 7; j++) {
			// printf("%d\n", a[i][j]);
			if (x == a[i][j]) {
				xt = i;
			}
			if (y == a[i][j]) {
				yt = i;
			}
		}
	}
	if (xt == yt) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
