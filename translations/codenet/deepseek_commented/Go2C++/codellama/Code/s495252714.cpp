
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cctype>
#include <fstream>
#include <numeric>
#include <iterator>
#include <sstream>
#include <cassert>
using namespace std;

//=====I/O=====

// Initialize buffered reader and writer for efficient I/O operations.
ifstream sc("input.txt");
ofstream wr("output.txt");

// Function to scan an integer from input.
int scanInt() {
	int a;
	sc >> a;
	return a;
}

// Function to scan a 64-bit integer from input.
long long scanInt64() {
	long long a;
	sc >> a;
	return a;
}

// Function to scan a list of integers from input.
vector<int> scanInts(int n) {
	vector<int> res;
	for (int i = 0; i < n; i++) {
		int e;
		sc >> e;
		res.push_back(e);
	}
	return res;
}

// Function to scan a single line of text from input.
string scanText() {
	string res;
	getline(sc, res);
	return res;
}

// Function to print a list of integers, separated by spaces.
void printInts(vector<int> a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
		if (i != a.size() - 1) {
			cout << " ";
		}
	}
	cout << endl;
}

//=====main=====

// The main function of the program.
int main() {
	// Set the split function for the scanner to scan words.
	sc.sync_with_stdio(false);
	sc.tie(0);

	// Read the number of elements.
	int n = scanInt();

	// Read n integers into a vector.
	vector<int> c = scanInts(n);

	// Initialize the answer variable.
	int ans = 0;

	// Sort the vector of integers.
	sort(c.begin(), c.end());

	// Calculate the answer based on the sorted vector.
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
	for (; n > 0; a = a * a % mod, n >>= 1) {
		if (n & 1) {
			res = res * a % mod;
		}
	}
	return res;
}

