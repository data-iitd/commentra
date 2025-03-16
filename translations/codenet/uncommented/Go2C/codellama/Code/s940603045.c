#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_BUF 10000

// const abcd = "abcdefghijklmnopqrstuvwxyz"
// const ABCD = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};

int inf = 2147483647;

// var mod = 1000000007

typedef struct {
	int a, b;
} Pair;

typedef struct {
	Pair *p;
	int n;
} Pairs;

int in(int c, int a, int z) {
	return c >= a && c < z;
}
int out(int c, int a, int z) {
	return !in(c, a, z);
}
int btoi(int b) {
	if (b) {
		return 1;
	}
	return 0;
}
int itob(int a) {
	return a != 0;
}
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}
int sum(int *a, int n) {
	int r = 0;
	for (int i = 0; i < n; i++) {
		r += a[i];
	}
	return r;
}
int pro(int *a, int n) {
	int r = a[0];
	for (int i = 1; i < n; i++) {
		r *= a[i];
	}
	return r;
}

int *fill(int *a, int n, int m) {
	for (int i = 0; i < n; i++) {
		a[i] = m;
	}
	return a;
}
int minmax(int a, int b) {
	if (a > b) {
		return b, a;
	}
	return a, b;
}

int abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

//
//int abs(int a) {
//	int mask = a >> 63;
//	return (a ^ mask) - mask;
//}

int ceil(int a, int b) {
	if (a % b != 0) {
		return 1;
	}
	return 0;
}

void printStrings(char **out, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s", out[i]);
		if (i != n - 1) {
			printf(" ");
		}
	}
	printf("\n");
}
void printInts(int *out, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d", out[i]);
		if (i != n - 1) {
			printf(" ");
		}
	}
	printf("\n");
}

// ---------- buffered scanner -----------------------------------------
typedef struct {
	FILE *r;
	char *buf;
	int p;
} scanner;

scanner *newScanner() {
	scanner *s = malloc(sizeof(scanner));
	s->r = stdin;
	s->buf = malloc(MAX_BUF);
	s->p = 0;
	return s;
}
char *next(scanner *s) {
	s->pre();
	int start = s->p;
	for (; s->p < strlen(s->buf); s->p++) {
		if (s->buf[s->p] == ' ') {
			break;
		}
	}
	char *result = malloc(s->p - start + 1);
	strncpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	s->p++;
	return result;
}
char *Line(scanner *s) {
	s->pre();
	int start = s->p;
	s->p = strlen(s->buf);
	char *result = malloc(s->p - start + 1);
	strncpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	return result;
}
char *String(scanner *s) {
	return next(s);
}
int Int(scanner *s) {
	char *str = next(s);
	int v = atoi(str);
	free(str);
	return v;
}
int *Ints(scanner *s, int n) {
	int *r = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		r[i] = Int(s);
	}
	return r;
}
int Int64(scanner *s) {
	char *str = next(s);
	int v = atoi(str);
	free(str);
	return v;
}
int Uint64(scanner *s) {
	char *str = next(s);
	int v = atoi(str);
	free(str);
	return v;
}
int Float64(scanner *s) {
	char *str = next(s);
	int v = atoi(str);
	free(str);
	return v;
}
void pre(scanner *s) {
	if (s->p >= strlen(s->buf)) {
		s->readLine();
		s->p = 0;
	}
}
void readLine(scanner *s) {
	s->buf = malloc(MAX_BUF);
	for (;;) {
		char *l = fgets(s->buf, MAX_BUF, s->r);
		if (l == NULL) {
			log(NULL, "fgets error");
		}
		if (strlen(l) < MAX_BUF - 1) {
			break;
		}
	}
}

int main() {
	scanner *next = newScanner();
	char *N = next->String();
	int n = 0;

	for (int i = 0; i < strlen(N); i++) {
		n += N[i] - '0';
	}
	int m = atoi(N);
	if (m % n == 0) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
}

