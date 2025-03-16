#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	FILE *r;
	char *buf;
	int p;
} FastScanner;

FastScanner *NewFastScanner() {
	FastScanner *fsc = (FastScanner *)malloc(sizeof(FastScanner));
	fsc->r = stdin;
	fsc->buf = (char *)malloc(1024);
	fsc->p = 0;
	return fsc;
}

void pre(FastScanner *fsc) {
	if (fsc->p >= strlen(fsc->buf)) {
		fsc->readLine(fsc);
		fsc->p = 0;
	}
}

void readLine(FastScanner *fsc) {
	fsc->buf = (char *)realloc(fsc->buf, 1024);
	fsc->buf[0] = '\0';
	fsc->p = 0;
	while (1) {
		fgets(fsc->buf + fsc->p, 1024 - fsc->p, fsc->r);
		fsc->p = strlen(fsc->buf);
		if (fsc->buf[fsc->p - 1] == '\n') {
			fsc->buf[fsc->p - 1] = '\0';
			break;
		}
		fsc->buf = (char *)realloc(fsc->buf, fsc->p + 1024);
	}
}

char *next(FastScanner *fsc) {
	pre(fsc);
	int start = fsc->p;
	for (; fsc->p < strlen(fsc->buf); fsc->p++) {
		if (fsc->buf[fsc->p] == ' ') {
			break;
		}
	}
	char *result = (char *)malloc(fsc->p - start + 1);
	strncpy(result, fsc->buf + start, fsc->p - start);
	result[fsc->p - start] = '\0';
	fsc->p++;
	return result;
}

char *nextLine(FastScanner *fsc) {
	pre(fsc);
	int start = fsc->p;
	fsc->p = strlen(fsc->buf);
	char *result = (char *)malloc(fsc->p - start + 1);
	strncpy(result, fsc->buf + start, fsc->p - start);
	result[fsc->p - start] = '\0';
	return result;
}

int nextInt(FastScanner *fsc) {
	char *str = next(fsc);
	int result = atoi(str);
	free(str);
	return result;
}

int64_t nextInt64(FastScanner *fsc) {
	char *str = next(fsc);
	int64_t result = atoll(str);
	free(str);
	return result;
}

int max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

int64_t max64(int64_t a, int64_t b) {
	if (a < b) {
		return b;
	}
	return a;
}

int min(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

int64_t min64(int64_t a, int64_t b) {
	if (a > b) {
		return b;
	}
	return a;
}

int abs(int a) {
	if (a < 0) {
		a *= -1;
	}
	return a;
}

int64_t abs64(int64_t a) {
	if (a < 0) {
		a *= -1;
	}
	return a;
}

int gcd(int a, int b) {
	if (a < b) {
		b = a;
	}
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int64_t gcd64(int64_t a, int64_t b) {
	if (a < b) {
		b = a;
	}
	if (b == 0) {
		return a;
	}
	return gcd64(b, a % b);
}

int main() {
	FastScanner *fsc = NewFastScanner();
	int A, B, C;
	A = fsc->nextInt(fsc);
	B = fsc->nextInt(fsc);
	C = fsc->nextInt(fsc);
	if (B - A == C - B) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}

