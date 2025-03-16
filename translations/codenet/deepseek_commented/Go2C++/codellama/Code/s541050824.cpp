
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// bufReader struct definition
// This struct is designed to efficiently read lines from standard input.
// It uses a buffer to minimize the number of system calls.
struct bufReader {
	char *buf;
	int i;
	int len;
	bufReader() {
		buf = new char[1 << 22];
		i = 0;
		len = 0;
	}
	void readLine() {
		if (i < len) {
			return;
		}
		i = 0;
		len = 0;
		while (true) {
			int c = getchar();
			if (c == EOF) {
				return;
			}
			if (c == '\n') {
				break;
			}
			buf[len++] = c;
		}
	}
	char next() {
		readLine();
		return buf[i++];
	}
	int nextInt() {
		readLine();
		int x = 0;
		while (buf[i] >= '0' && buf[i] <= '9') {
			x = x * 10 + buf[i] - '0';
			i++;
		}
		return x;
	}
	char *nextLine() {
		readLine();
		return buf + i;
	}
};

// bufio Writer initialization
struct bufWriter {
	char *buf;
	int i;
	int len;
	bufWriter() {
		buf = new char[1 << 22];
		i = 0;
		len = 0;
	}
	void flush() {
		fwrite(buf, 1, i, stdout);
		i = 0;
	}
	void out(char c) {
		buf[i++] = c;
		if (i == len) {
			flush();
		}
	}
	void out(char *s) {
		while (*s) {
			out(*s++);
		}
	}
	void out(int x) {
		char s[20];
		sprintf(s, "%d", x);
		out(s);
	}
	void out(char c, int n) {
		while (n--) {
			out(c);
		}
	}
};

// bufReader initialization
bufReader reader;

// bufio Writer initialization
bufWriter writer;

// next wraps the reader.next() function.
char next() {
	return reader.next();
}

// nextInt reads the next token as an integer.
int nextInt() {
	return reader.nextInt();
}

// nextLine wraps the reader.nextLine() function.
char *nextLine() {
	return reader.nextLine();
}

// max returns the maximum of two integers.
int max(int x, int y) {
	if (x > y) {
		return x;
	}
	return y;
}

// min returns the minimum of two integers.
int min(int x, int y) {
	if (x < y) {
		return x;
	}
	return y;
}

// joinInts joins an array of integers into a string with a separator.
char *joinInts(int *a, int n, char *sep) {
	char *s = new char[n * 20];
	char *p = s;
	for (int i = 0; i < n; i++) {
		sprintf(p, "%d", a[i]);
		p += strlen(p);
		if (i < n - 1) {
			strcpy(p, sep);
			p += strlen(p);
		}
	}
	return s;
}

// divUp returns the ceiling of the division of x by y.
int divUp(int x, int y) {
	return (x + y - 1) / y;
}

// solve function
// Reads the number of elements N.
// Reads N pairs of integers T and A.
// Iteratively adjusts t and a to ensure the ratios are maintained.
// Outputs the sum of t and a after all adjustments.
void solve() {
	int N = nextInt();
	int *T, *A;
	T = new int[N];
	A = new int[N];
	for (int i = 0; i < N; i++) {
		T[i] = nextInt();
		A[i] = nextInt();
	}
	int t, a;
	t = T[0];
	a = A[0];
	for (int i = 1; i < N; i++) {
		int r = max(divUp(t, T[i]), divUp(a, A[i]));
		t = T[i] * r;
		a = A[i] * r;
	}
	writer.out(t + a);
}

int main() {
	solve();
	writer.out('\n');
	writer.flush();
	return 0;
}

