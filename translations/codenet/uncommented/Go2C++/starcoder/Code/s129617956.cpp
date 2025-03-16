#include <bits/stdc++.h>

using namespace std;

int main() {
	int n = nextInt();
	int rt = (int)sqrt(n);
	int minf = 100;
	for (int i = 1; i <= rt; i++) {
		if (n % i == 0) {
			int b = n / i;
			int ndigit = 0;
			while (b > 0) {
				b /= 10;
				ndigit++;
			}
			minf = min(minf, ndigit);
		}
	}
	cout << minf << endl;
}

const int size = 1000000;

char buffer[size];
int position = 0;

inline char readChar() {
	if (position == size) {
		position = 0;
		fread(buffer, size, 1, stdin);
	}
	return buffer[position++];
}

inline int readInt() {
	int result = 0;
	bool negative = false;
	char c = readChar();
	for (; c < '0' || c > '9'; c = readChar()) {
		if (c == '-') {
			negative = true;
		}
	}
	for (; c >= '0' && c <= '9'; c = readChar()) {
		result = result * 10 + (c - '0');
	}
	if (negative) {
		return -result;
	}
	return result;
}

inline void writeInt(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) {
		writeInt(x / 10);
	}
	putchar(x % 10 + '0');
}

inline void writeIntLn(int x) {
	writeInt(x);
	putchar('\n');
}

inline void writeChar(char c) {
	putchar(c);
}

inline void writeString(const char* s) {
	while (*s) {
		putchar(*s);
		s++;
	}
}

inline void writeStringLn(const char* s) {
	writeString(s);
	putchar('\n');
}

int main() {
	int n = readInt();
	int rt = (int)sqrt(n);
	int minf = 100;
	for (int i = 1; i <= rt; i++) {
		if (n % i == 0) {
			int b = n / i;
			int ndigit = 0;
			while (b > 0) {
				b /= 10;
				ndigit++;
			}
			minf = min(minf, ndigit);
		}
	}
	writeIntLn(minf);
}

