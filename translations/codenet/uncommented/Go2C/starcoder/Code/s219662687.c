#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define FOR(i, a, b) for(int i=(a); i<(b); ++i)
#define REP(i, n) FOR(i, 0, (n))

int main() {
	int A = nextInt();
	int B = nextInt();
	int Q = nextInt();
	int s[A+2];
	s[0] = -1000000000;
	s[A+1] = 1000000000;
	REP(i, A) {
		s[i+1] = nextInt();
	}

	int t[B+2];
	t[0] = -1000000000;
	t[B+1] = 1000000000;
	REP(i, B) {
		t[i+1] = nextInt();
	}

	for(int i=0; i<Q; ++i) {
		int x = nextInt();
		int b = 0, d = 0;
		while(b < A && s[b] < x) ++b;
		while(d < B && t[d] < x) ++d;
		int res = 1000000000;
		REP(i, 2) {
			int S = s[b-1+i];
			int T = t[d-1+i];
			int d1 = abs(S-x) + abs(T-S);
			int d2 = abs(T-x) + abs(S-T);
			res = min(res, min(d1, d2));
		}
		printf("%d\n", res);
	}
}

// Input. ----------

#define BUFSIZE 65536

char buf[BUFSIZE];
int curChar;
int numChars;

void initBuf() {
	numChars = fread(buf, 1, BUFSIZE, stdin);
	if (numChars == 0) {
		numChars = 0;
		return;
	}

	curChar = 0;
}

char nextChar() {
	if (numChars == 0) {
		initBuf();
	}

	if (curChar >= numChars) {
		return 0;
	}

	char c = buf[curChar++];
	if (c == '\n') {
		numChars = 0;
		curChar = 0;
	}

	return c;
}

int nextInt() {
	int c = nextChar();
	int sgn = 1;

	while (c =='' || c == '\n' || c == '\t' || c == '\r') {
		c = nextChar();
	}

	if (c == '-') {
		sgn = -1;
		c = nextChar();
	}

	int res = 0;

	while ('0' <= c && c <= '9') {
		res *= 10;
		res += c - '0';
		c = nextChar();
	}

	return res * sgn;
}

// ---------- Input.

// Util. ----------

int min(int a, int b) {
	return a < b? a : b;
}

// ---------- Util.

