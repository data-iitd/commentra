#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	FILE *r;
	char *buf;
	int i;
} bufReader;

bufReader reader = {
	stdin,
	NULL,
	0,
};

void readLine(bufReader *r) {
	if (r->i < strlen(r->buf)) {
		return;
	}
	free(r->buf);
	r->buf = NULL;
	r->i = 0;
	for (;;) {
		char *line = NULL;
		size_t size = 0;
		int isPrefix = getline(&line, &size, r->r);
		if (line == NULL) {
			panic(NULL);
		}
		if (r->buf == NULL) {
			r->buf = malloc(size);
		} else {
			r->buf = realloc(r->buf, strlen(r->buf) + size);
		}
		strcat(r->buf, line);
		free(line);
		if (!isPrefix) {
			break;
		}
	}
}

char *next(bufReader *r) {
	readLine(r);
	int from = r->i;
	for (; r->i < strlen(r->buf); r->i++) {
		if (r->buf[r->i] == ' ') {
			break;
		}
	}
	char *s = malloc(r->i - from + 1);
	strncpy(s, r->buf + from, r->i - from);
	s[r->i - from] = '\0';
	r->i++;
	return s;
}

char *nextLine(bufReader *r) {
	readLine(r);
	char *s = malloc(strlen(r->buf) - r->i + 1);
	strncpy(s, r->buf + r->i, strlen(r->buf) - r->i);
	s[strlen(r->buf) - r->i] = '\0';
	r->i = strlen(r->buf);
	return s;
}

FILE *writer = stdout;

void out(char *a, ...) {
	va_list args;
	va_start(args, a);
	vfprintf(writer, a, args);
	va_end(args);
	fprintf(writer, "\n");
}

long long max(long long x, long long y) {
	if (x > y) {
		return x;
	}
	return y;
}

long long min(long long x, long long y) {
	if (x < y) {
		return x;
	}
	return y;
}

char *joinInts(long long *a, int n, char *sep) {
	char *b = malloc(n * 20);
	int i;
	for (i = 0; i < n; i++) {
		sprintf(b + i * 20, "%lld", a[i]);
		if (i != n - 1) {
			strcat(b, sep);
		}
	}
	return b;
}

long long divUp(long long x, long long y) {
	return (x + y - 1) / y;
}

void solve() {
	long long N = atoll(next());
	long long *T, *A;
	T = malloc(N * sizeof(long long));
	A = malloc(N * sizeof(long long));
	for (int i = 0; i < N; i++) {
		T[i] = atoll(next());
		A[i] = atoll(next());
	}
	long long t, a;
	t = T[0];
	a = A[0];
	for (int i = 1; i < N; i++) {
		long long r = max(divUp(t, T[i]), divUp(a, A[i]));
		t = T[i] * r;
		a = A[i] * r;
	}
	out("%lld", t + a);
}

int main() {
	solve();
	return 0;
}

