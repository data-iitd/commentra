
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//=====I/O=====

// Function to read an integer from standard input
int scanInt() {
	int a;
	scanf("%d",&a);
	return a;
}

// Function to read an integer64 from standard input
long long scanInt64() {
	long long a;
	scanf("%lld",&a);
	return a;
}

// Function to read n integers from standard input
int* scanInts(int n) {
	int* res = new int[n];
	// Read n integers and store them in slice res
	for (int i = 0; i < n; i++) { res[i] = scanInt(); }
	return res;
}

// Function to print integers to standard output
void printInts(int n, int* a) {
	// Iterate through slice a and print each integer followed by a space
	for (int i = 0; i < n; i++) {
		printf("%d",a[i]);
		if (i != n-1) { printf(" "); }
	}
	// Print newline character and flush writer buffer
	printf("\n");
	fflush(stdout);
}

//=====main=====

// Set scanner to scan words
int main() {
	// Read an integer n from standard input
	int n = scanInt();

	// Read n integers c from standard input and store them in a slice
	int* c = scanInts(n);

	// Initialize answer variable to 0
	int ans = 0;

	// Sort slice c in ascending order
	sort(c,c+n);

	// Iterate through slice c and calculate answer
	for (int i = 0; i < n; i++) {
		// Calculate contribution of current integer to answer
		ans = (ans + (n+1-i)*c[i]%mod)%mod;
	}

	// Calculate final answer by multiplying answer with (4^(n-1)) modulo mod
	printf("%d\n",ans*modpow(4,n-1)%mod);

	// Free memory allocated for slice c
	delete[] c;

	return 0;
}

// Constants
const int mod = 1000000007;

// Function to calculate modular exponentiation
int modpow(int a,int n) {
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

