#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// I/O
typedef struct {
	char *s;
	int len;
	int pos;
} Reader;

Reader newReader(char *s) {
	Reader r;
	r.s = s;
	r.len = strlen(s);
	r.pos = 0;
	return r;
}

char nextChar(Reader *r) {
	if (r->pos >= r->len) {
		return 0;
	}
	char c = r->s[r->pos];
	r->pos++;
	return c;
}

int nextInt(Reader *r) {
	int x = 0;
	bool neg = false;
	char c;
	for (c = nextChar(r); c < '0' || c > '9'; c = nextChar(r)) {
		if (c == '-') {
			neg = true;
		}
	}
	for (c = nextChar(r); c >= '0' && c <= '9'; c = nextChar(r)) {
		x = x * 10 + c - '0';
	}
	if (neg) {
		x = -x;
	}
	return x;
}

// Arithmetic
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

int abs(int x) {
	if (x > 0) {
		return x;
	}
	return -x;
}

int pow(int x, int y) {
	int res = 1;
	for (int i = 0; i < y; i++) {
		res *= x;
	}
	return res;
}

// Sort
typedef struct {
	int id;
	int num;
} Val;

int cmp(const void *a, const void *b) {
	Val *va = (Val *) a;
	Val *vb = (Val *) b;
	if (va->num < vb->num) {
		return -1;
	}
	if (va->num > vb->num) {
		return 1;
	}
	return 0;
}

// Main
int main() {
	Reader r = newReader(getenv("INPUT"));
	int A = nextInt(&r);
	int B = nextInt(&r);
	int C = nextInt(&r);
	int K = nextInt(&r);
	
	int ma = max(A, B, C);
	
	int rest = 0;
	if (ma == A) {
		rest += B + C;
	} else if (ma == B) {
		rest += A + C;
	} else {
		rest += A + B;
	}
	
	for (int i = 1; i <= K; i++) {
		ma *= 2;
	}
	
	printf("%d\n", ma + rest);
	return 0;
}

