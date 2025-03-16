
#include <bits/stdc++.h>

using namespace std;

// Constants
const int mod = 998244353;
const int facNum = 300001;

// Main function
int main() {
	// Initialize a new scanner
	auto sc = newScanner(cin);

	// Read an integer N from the standard input
	int N = sc->i();

	// Initialize a variable sum to 0
	int sum = 0;

	// Loop through numbers from 1 to N
	for (int i = 1; i <= N; i++) {
		// If the number is not divisible by 3 or 5, add it to the sum
		if (i%3!= 0 && i%5!= 0) {
			sum += i;
		}
	}

	// Print the result to the standard output
	cout << sum << endl;
}

// I/O
class scanner {
public:
	// Constructor
	scanner(istream& input) :
		sc(new istream(input)) {
		// Set the scanner to split input on words
		sc->word_boundary = true;
	}

	// Helper methods for scanner
	string s() {
		// Scan the next token and return it as a string
		sc->ignore();
		string s;
		*sc >> s;
		return s;
	}

	int i() {
		// Convert the next token to an integer and return it
		return atoi(s().c_str());
	}

	float f() {
		// Convert the next token to a float64 and return it
		return atof(s().c_str());
	}

	bool b() {
		// Convert the next token to a boolean and return it
		return atoi(s().c_str());
	}

	vector<int> is(int n) {
		// Read n integers from the standard input and return them as a vector
		vector<int> res(n);
		for (int i = 0; i < n; i++) {
			res[i] = i();
		}
		return res;
	}

	vector<float> fs(int n) {
		// Read n floating-point numbers from the standard input and return them as a vector
		vector<float> res(n);
		for (int i = 0; i < n; i++) {
			res[i] = f();
		}
		return res;
	}

private:
	// Scanner
	istream* sc;
};

// Math functions
int Pow(int a, int n) {
	// Calculate a^n modulo mod
	int ans = 1;
	while (n > 0) {
		if (n & 1) {
			ans = ans * a % mod;
		}
		a = a * a % mod;
		n = n >> 1;
	}
	return ans;
}

int Gcd(int a, int b) {
	// Calculate the greatest common divisor of a and b
	if (a < b) {
		return Gcd(b, a);
	}
	while (b!= 0) {
		a, b = b, a%b;
	}
	return a;
}

int min(int a, int b) {
	// Return the minimum of a and b
	if (a < b) {
		return a;
	}
	return b;
}

// Combination function
int combination(int n, int k, vector<int>& fac, vector<int>& ifac) {
	// Calculate the binomial coefficient (n choose k) modulo mod
	if (n < k || n < 0) {
		return 0;
	}
	if (k == 0) {
		return 1;
	}
	// While n is not 0
	int ans = ifac[k] * ifac[n-k] % mod;
	return ans * fac[n] % mod;
}

// Factorial function
vector<int> factorial() {
	// Calculate and return the factorial of all numbers from 0 to facNum-1
	vector<int> fac(facNum);
	fac[0] = 1;
	vector<int> ifac(facNum);
	ifac[0] = 1;
	for (int i = 1; i < facNum; i++) {
		fac[i] = fac[i-1] * i % mod;
		ifac[i] = ifac[i-1] * Pow(i, mod-2) % mod;
	}
	return fac;
}

// Lower bound function
int lowerBound(vector<int>& vs, int v) {
	// Calculate the index of the first element in vs that is greater than or equal to v
	int n = vs.size() / 2;
	int m = vs.size();
	while (m!= n) {
		if (vs[n] < v) {
			n = (m-n+1)/2 + n;
			//m = m;
		} else {
			m = n;
			n = n / 2;
		}
	}
	return n;
}

// IntSlice function
vector<int> IntSlice(int n, int init) {
	// Create and initialize a slice of length n with the given initial value
	vector<int> r(n);
	for (int i = 0; i < n; i++) {
		r[i] = init;
	}
	return r;
}

// 