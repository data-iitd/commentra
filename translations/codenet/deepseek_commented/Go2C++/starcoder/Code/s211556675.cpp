#include <bits/stdc++.h>

using namespace std;

// I/O
struct Reader {
	FILE* in;
	int b;
	char buf[1000000];
	int cur;
	int max;
	Reader() {
		in = fopen("input.txt", "r");
		max = 1000000;
		b = 0;
		cur = 0;
	}
	int read() {
		if (b == 0) {
			cur = 0;
			b = fread(buf, 1, max, in);
		}
		if (b == 0) {
			return -1;
		}
		b--;
		return buf[cur++];
	}
	void close() {
		fclose(in);
	}
};

struct Writer {
	FILE* out;
	Writer() {
		out = fopen("output.txt", "w");
	}
	void write(int x) {
		fprintf(out, "%d\n", x);
	}
	void close() {
		fclose(out);
	}
};

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
	if (x < 0) {
		return -x;
	}
	return x;
}

int pow(int x, int y) {
	int res = 1;
	for (int i = 0; i < y; i++) {
		res *= x;
	}
	return res;
}

// Sort
struct Val {
	int id, num;
};

bool operator<(const Val& a, const Val& b) {
	return a.num < b.num;
}

// Main
int main() {
	Reader sc;
	Writer wtr;
	
	// Read input values
	int A, B, C, K;
	A = sc.read();
	B = sc.read();
	C = sc.read();
	K = sc.read();
	
	// Determine the maximum value among A, B, and C
	int ma = max(A, B, C);
	
	// Calculate the sum of the other two values
	int rest = 0;
	if (ma == A) {
		rest += B + C;
	} else if (ma == B) {
		rest += A + C;
	} else {
		rest += A + B;
	}
	
	// Double the maximum value K times
	for (int i = 1; i <= K; i++) {
		ma *= 2;
	}
	
	// Print the final result
	wtr.write(ma + rest);
	wtr.close();
	return 0;
}

