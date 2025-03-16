
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//=====I/O=====

// Declare scanner and writer for input and output
ios_base::sync_with_stdio(false);
cin.tie(NULL);

// Function to scan an integer from input
int scanInt() {
	int a;
	cin >> a;
	return a;
}

// Function to scan a 64-bit integer from input
long long scanInt64() {
	long long a;
	cin >> a;
	return a;
}

// Function to scan multiple integers from input
int* scanInts(int n) {
	int* res = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> res[i];
	}
	return res;
}

// Function to scan a single line of text from input
string scanText() {
	string a;
	cin >> a;
	return a;
}

// Function to print integers to output
void printInts(int n, int* a) {
	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i != n - 1) {
			cout << " ";
		}
	}
	cout << endl;
}

//=====main=====

// Main function where execution starts
int main() {
	int n = scanInt(); // Read the number of integers

	int* c = scanInts(n); // Read n integers into array c

	int ans = 0; // Initialize answer variable
	sort(c, c + n); // Sort the array of integers

	// Calculate the answer based on the sorted integers
	for (int i = 0; i < n; i++) {
		ans = (ans + (n + 1 - i) * c[i] % mod) % mod; // Update the answer using the formula
	}

	// Print the final result after applying modular exponentiation
	cout << ans * modpow(4, n - 1) % mod << endl;

	return 0;
}

// Function to perform modular exponentiation
int modpow(int a, int n) {
	int res = 1; // Initialize result
	while (n > 0) {
		if (n & 1) { // If n is odd
			res = res * a % mod; // Update result
		}
		a = a * a % mod; // Square the base
		n = n >> 1; // Divide n by 2
	}
	return res; // Return the final result
}

const int mod = 1000000007; // Define a constant for the modulus

//=====END-OF-CODE=====
