
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

// FastScanner struct: Efficiently reads input.
struct FastScanner {
	char *buf;
	int p;
	int len;
	FastScanner() {
		buf = new char[1024];
		p = 0;
		len = 0;
	}
	void readLine() {
		p = 0;
		len = 0;
		while (true) {
			char c = getchar();
			if (c == '\n') {
				break;
			}
			buf[len++] = c;
		}
		buf[len] = '\0';
	}
	void pre() {
		if (p >= len) {
			readLine();
			p = 0;
		}
	}
	char next() {
		pre();
		return buf[p++];
	}
	int nextInt() {
		pre();
		int v = 0;
		while (buf[p] != ' ') {
			v = v * 10 + buf[p] - '0';
			p++;
		}
		p++;
		return v;
	}
	int64_t nextInt64() {
		pre();
		int64_t v = 0;
		while (buf[p] != ' ') {
			v = v * 10 + buf[p] - '0';
			p++;
		}
		p++;
		return v;
	}
	double nextDouble() {
		pre();
		double v = 0;
		while (buf[p] != ' ') {
			v = v * 10 + buf[p] - '0';
			p++;
		}
		p++;
		return v;
	}
};

// Main function: Entry point of the program.
// Initializes a FastScanner, reads three integers A, B, and C,
// and checks if the difference between consecutive integers is the same.
// If the difference is the same, it prints "YES"; otherwise, it prints "NO".
int main() {
	FastScanner fsc;
	int A, B, C;
	A = fsc.nextInt();
	B = fsc.nextInt();
	C = fsc.nextInt();
	if (B - A == C - B) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}

// Max, Min, Gcd, Abs functions: Utility functions for various operations.
int IntMax(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

int64_t Int64Max(int64_t a, int64_t b) {
	if (a < b) {
		return b;
	}
	return a;
}

double Float64Max(double a, double b) {
	if (a < b) {
		return b;
	}
	return a;
}

int IntMin(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

int64_t Int64Min(int64_t a, int64_t b) {
	if (a > b) {
		return b;
	}
	return a;
}

double Float64Min(double a, double b) {
	if (a > b) {
		return b;
	}
	return a;
}

int IntGcd(int a, int b) {
	if (a < b) {
		b = a;
	}
	if (b == 0) {
		return a;
	}
	return IntGcd(b, a % b);
}

int64_t Int64Gcd(int64_t a, int64_t b) {
	if (a < b) {
		b = a;
	}
	if (b == 0) {
		return a;
	}
	return Int64Gcd(b, a % b);
}

int IntAbs(int a) {
	if (a < 0) {
		a *= -1;
	}
	return a;
}

int64_t Int64Abs(int64_t a) {
	if (a < 0) {
		a *= -1;
	}
	return a;
}

