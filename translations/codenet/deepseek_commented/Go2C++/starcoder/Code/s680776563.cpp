
#include <bits/stdc++.h>

using namespace std;

// FastScanner struct: Efficiently reads input.
struct FastScanner {
	std::istream& stream;
	std::vector<char> buf;
	char curChar;
	int bufPos, bufSize;

	FastScanner(std::istream& stream) : stream(stream), bufPos(0), bufSize(0) {
		refillBuffer();
	}

	void refillBuffer() {
		bufPos = 0;
		bufSize = stream.rdbuf()->sgetn(&buf[0], 1024);
		if (bufSize == 0) {
			curChar = EOF;
		} else {
			curChar = buf[0];
		}
	}

	char getChar() {
		if (bufPos == bufSize) {
			refillBuffer();
		}
		char c = curChar;
		bufPos++;
		if (bufPos == bufSize) {
			refillBuffer();
		}
		curChar = buf[bufPos];
		return c;
	}

	void skipWhitespace() {
		while (isspace(curChar)) {
			getChar();
		}
	}

	std::string next() {
		std::string str;
		while (isspace(curChar)) {
			getChar();
		}
		while (!isspace(curChar)) {
			str.push_back(curChar);
			getChar();
		}
		return str;
	}

	int nextInt() {
		int x;
		std::stringstream ss;
		ss << next();
		ss >> x;
		return x;
	}
};

// Main function: Entry point of the program.
// Initializes a FastScanner, reads three integers A, B, and C,
// and checks if the difference between consecutive integers is the same.
// If the difference is the same, it prints "YES"; otherwise, it prints "NO".
int main() {
	FastScanner fs(cin);
	int A, B, C;
	A = fs.nextInt();
	B = fs.nextInt();
	C = fs.nextInt();
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

int IntMin(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

int IntGcd(int a, int b) {
	if (a < b) {
		b, a = a, b;
	}
	if (b == 0) {
		return a;
	}
	return IntGcd(b, a % b);
}

int IntAbs(int a) {
	if (a < 0) {
		a *= -1;
	}
	return a;
}

