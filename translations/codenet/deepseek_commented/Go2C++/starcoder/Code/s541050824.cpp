#include <bits/stdc++.h>

using namespace std;

// bufReader struct definition
// This struct is designed to efficiently read lines from standard input.
// It uses a buffer to minimize the number of system calls.
struct bufReader {
	FILE *stream;
	char buf[1024];
	int curChar, numChars;
};

// bufReader initialization
bufReader reader;

// readLine reads a line from the input and stores it in the buffer.
void readLine() {
	reader.curChar = 0;
	reader.numChars = 0;
	if (fgets(reader.buf, 1024, reader.stream) == NULL) {
		reader.stream = NULL;
	} else {
		reader.numChars = strlen(reader.buf);
		if (reader.buf[reader.numChars - 1] == '\n') {
			reader.numChars--;
			if (reader.numChars > 0 && reader.buf[reader.numChars - 1] == '\r') {
				reader.numChars--;
			}
		}
	}
}

// next returns the next space-separated word from the buffer.
string next() {
	while (reader.curChar >= reader.numChars) {
		readLine();
	}
	char c = reader.buf[reader.curChar++];
	while (isspace(c)) {
		c = reader.buf[reader.curChar++];
	}
	string s;
	while (!isspace(c)) {
		s += c;
		c = reader.buf[reader.curChar++];
	}
	return s;
}

// nextInt reads the next token as an integer.
int64_t nextInt() {
	string s = next();
	int64_t x;
	istringstream ss(s);
	ss >> x;
	return x;
}

// nextLine wraps the reader.nextLine() function.
string nextLine() {
	string s = "";
	while (reader.curChar >= reader.numChars) {
		readLine();
	}
	char c = reader.buf[reader.curChar++];
	while (isspace(c)) {
		c = reader.buf[reader.curChar++];
	}
	while (!isspace(c) && reader.curChar < reader.numChars) {
		s += c;
		c = reader.buf[reader.curChar++];
	}
	return s;
}

// out prints the arguments to the output with a newline.
void out(string s) {
	cout << s << endl;
}

// max returns the maximum of two integers.
int64_t max(int64_t x, int64_t y) {
	if (x > y) {
		return x;
	}
	return y;
}

// min returns the minimum of two integers.
int64_t min(int64_t x, int64_t y) {
	if (x < y) {
		return x;
	}
	return y;
}

// joinInts joins an array of integers into a string with a separator.
string joinInts(vector<int64_t> a, string sep) {
	string s = "";
	for (int i = 0; i < a.size(); i++) {
		s += to_string(a[i]);
		if (i < a.size() - 1) {
			s += sep;
		}
	}
	return s;
}

// divUp returns the ceiling of the division of x by y.
int64_t divUp(int64_t x, int64_t y) {
	return (x + y - 1) / y;
}

// Main function
int main() {
	solve();
}

// Solve function
// Reads the number of elements N.
// Reads N pairs of integers T and A.
// Iteratively adjusts t and a to ensure the ratios are maintained.
// Outputs the sum of t and a after all adjustments.
void solve() {
	int64_t N = nextInt();
	vector<int64_t> T(N), A(N);
	for (int i = 0; i < int(N); i++) {
		T[i], A[i] = nextInt(), nextInt();
	}
	int64_t t = T[0], a = A[0];
	for (int i = 1; i < int(N); i++) {
		int64_t r = max(divUp(t, T[i]), divUp(a, A[i]));
		t, a = T[i] * r, A[i] * r;
	}
	out(t + a);
}

