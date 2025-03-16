#include <bits/stdc++.h>

using namespace std;

int main() {
	// Create a new scanner to read input
	Scanner sc;
	// Read two integers from input
	int A, B = sc.NextInt(), sc.NextInt();

	// Calculate the maximum of A+B, A-B, and A*B
	int mx = max(A+B, A-B);
	mx = max(mx, A*B);
	// Print the maximum value
	cout << mx << endl;
}

// Function to return the maximum of two integers
int max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

// Scanner struct to handle input reading
struct Scanner {
	int p;
	char buf[1000];
	istream *in;
	Scanner() {
		in = &cin;
	}
	void pre() {
		if (p >= strlen(buf)) {
			readLine();
			p = 0;
		}
	}
	void readLine() {
		in->getline(buf, 1000);
	}
	int NextInt() {
		pre();
		int v = 0;
		while (p < strlen(buf) && buf[p] =='') {
			p++;
		}
		bool neg = false;
		if (p < strlen(buf) && buf[p] == '-') {
			neg = true;
			p++;
		}
		while (p < strlen(buf) && buf[p] >= '0' && buf[p] <= '9') {
			v = v*10 + (buf[p] - '0');
			p++;
		}
		if (neg) {
			return -v;
		}
		return v;
	}
};

