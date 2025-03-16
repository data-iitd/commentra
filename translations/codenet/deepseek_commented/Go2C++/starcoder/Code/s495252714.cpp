#include <bits/stdc++.h>

using namespace std;

//=====I/O=====

// Initialize buffered reader and writer for efficient I/O operations.
ios_base::sync_with_stdio(false);
cin.tie(NULL);

// Function to scan an integer from input.
int scanInt() {
	int a;
	cin >> a;
	return a;
}

// Function to scan a 64-bit integer from input.
int64_t scanInt64() {
	int64_t a;
	cin >> a;
	return a;
}

// Function to scan a list of integers from input.
vector<int> scanInts(int n) {
	vector<int> res(n);
	for (int i = 0; i < n; i++) { cin >> res[i]; }
	return res;
}

// Function to scan a single line of text from input.
string scanText() {
	string a;
	getline(cin, a);
	return a;
}

// Function to print a list of integers, separated by spaces.
void printInts(vector<int> a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
		if (i!= a.size() - 1) { cout << " "; }
	}
	cout << endl;
}

//=====main=====

// The main function of the program.
int main() {
	// Set the split function for the scanner to scan words.
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Read the number of elements.
	int n = scanInt();

	// Read n integers into a slice.
	vector<int> c = scanInts(n);

	// Initialize the answer variable.
	int ans = 0;

	// Sort the slice of integers.
	sort(c.begin(), c.end());

	// Calculate the answer based on the sorted slice.
	for (int i = 0; i < n; i++) {
		ans = (ans + (n + 1 - i) * c[i] % mod) % mod;
	}

	// Print the final answer, multiplied by 4^(n-1) modulo mod.
	cout << ans * modpow(4, n - 1) % mod << endl;
}

// Define the constant for modular arithmetic.
const int mod = 1000000007;

// Function to perform modular exponentiation.
int modpow(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n & 1 == 1) {
			res = res * a % mod;
		}
		a = a * a % mod;
		n = n >> 1;
	}
	return res;
}

