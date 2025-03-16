
#include <bits/stdc++.h>

using namespace std;

//=====I/O=====

// Initialize scanner and writer
std::istream& cin = std::cin;
std::ostream& cout = std::cout;
std::ostream& cerr = std::cerr;

// Function to read an integer from standard input
int scanInt() {
	int a;
	cin >> a;
	return a;
}

// Function to read an integer64 from standard input
int64_t scanInt64() {
	int64_t a;
	cin >> a;
	return a;
}

// Function to read n integers from standard input
vector<int> scanInts(int n) {
	vector<int> res(n);
	// Read n integers and store them in slice res
	for (int i = 0; i < n; i++) { cin >> res[i]; }
	return res;
}

// Function to print integers to standard output
void printInts(vector<int> a) {
	// Iterate through slice a and print each integer followed by a space
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
		if (i!= a.size()-1) { cout << " "; }
	}
	// Print newline character and flush writer buffer
	cout << endl;
}

//=====main=====

// Set scanner to scan words
void scan() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	std::ios_base::sync_with_stdio(false);
}

// Constants
const int mod = 1000000007;

// Function to calculate modular exponentiation
int modpow(int a, int n) {
	// Initialize result to 1
	int res = 1;

	// If n is 0, return result
	if (n == 0) { return res; }

	// If n is 1, return a
	if (n == 1) { return a; }

	// If n is odd, multiply result with a multiplied by itself recursively
	if (n&1 == 1) {
		res = res*a%mod;
		a = a*a%mod;
		n = n>>1;
		res = res*modpow(a,n)%mod;
	}

	// If n is even, square result and recursively call function for n/2
	else {
		a = a*a%mod;
		n = n>>1;
		res = modpow(a,n)%mod;
	}

	// Return result
	return res;
}

//=====main=====

int main() {
	// Set scanner to scan words
	scan();

	// Read an integer n from standard input
	int n = scanInt();

	// Read n integers c from standard input and store them in a slice
	vector<int> c = scanInts(n);

	// Initialize answer variable to 0
	int ans = 0;

	// Sort slice c in ascending order
	sort(c.begin(), c.end());

	// Iterate through slice c and calculate answer
	for (int i = 0; i < n; i++) {
		// Calculate contribution of current integer to answer
		ans = (ans + (n+1-i)*c[i]%mod)%mod;
	}

	// Calculate final answer by multiplying answer with (4^(n-1)) modulo mod
	cout << ans*modpow(4,n-1)%mod << endl;
}

