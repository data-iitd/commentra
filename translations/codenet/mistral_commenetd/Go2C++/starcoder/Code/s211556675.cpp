
#include <bits/stdc++.h>

using namespace std;

// I/O
class Scanner {
public:
	Scanner() : buf(new char[BUFSIZ]), sc(new istringstream(buf)) {}
	~Scanner() { delete[] buf; delete sc; }
	bool eof() { return sc->eof(); }
	void read() { sc->read(buf, BUFSIZ); }
	string nextStr() {
		while (isspace(*sc->peek())) sc->ignore(); // Ignore leading whitespace
		string s;
		if (*sc->peek() == EOF) return s; // Check for EOF
		while (!isspace(*sc->peek())) { // Read until next whitespace
			s += *sc->get();
		}
		while (isspace(*sc->peek())) sc->ignore(); // Ignore trailing whitespace
		return s;
	}
	int nextInt() {
		string s = nextStr();
		if (s.length() == 0) return 0; // Check for EOF
		return atoi(s.c_str());
	}
	double nextFloat() {
		string s = nextStr();
		if (s.length() == 0) return 0; // Check for EOF
		return atof(s.c_str());
	}
	char nextRune() {
		string s = nextStr();
		if (s.length() == 0) return EOF; // Check for EOF
		return s[0];
	}
	vector<int> nextIntSlice(int n) {
		vector<int> res(n);
		for (int i = 0; i < n; i++) res[i] = nextInt();
		return res;
	}
	vector<float> nextFloatSlice(int n) {
		vector<float> res(n);
		for (int i = 0; i < n; i++) res[i] = nextFloat();
		return res;
	}
	vector<string> nextStrSlice(int n) {
		vector<string> res(n);
		for (int i = 0; i < n; i++) res[i] = nextStr();
		return res;
	}
private:
	char* buf;
	istringstream* sc;
	const int BUFSIZ = 1000000;
};

// Arithmetic
int max(int a, int b) {
	return a > b? a : b;
}

int min(int a, int b) {
	return a < b? a : b;
}

int abs(int x) {
	return x < 0? -x : x;
}

int pow(int x, int y) {
	int res = 1;
	for (int i = 0; i < y; i++) res *= x;
	return res;
}

// Sort
struct Val {
	int id, num;
};

bool operator<(const Val& a, const Val& b) {
	return a.num < b.num;
}

// Main function
int main() {
	Scanner sc;
	ostream& out = cout;
	int A, B, C, K;
	sc.read();
	A = sc.nextInt();
	B = sc.nextInt();
	C = sc.nextInt();
	K = sc.nextInt();

	// Find the maximum value among A, B, and C
	int ma = max(A, B, C);

	// Calculate the rest of the numbers that need to be multiplied by 2 to reach or exceed K
	int rest = 0;
	if (ma == A) {
		rest += B + C;
	} else if (ma == B) {
		rest += A + C;
	} else {
		rest += A + B;
	}

	// Calculate the final answer
	int answer = pow(ma, K) + rest;

	// Write the answer to the output
	out << answer << endl;
	return 0;
}

// 