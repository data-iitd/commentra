

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#include <cctype>
#include <utility>
#include <numeric>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <typeinfo>
#include <valarray>
#include <complex>
#include <regex>
#include <locale>
#include <cfloat>
#include <ciso646>
#include <cstdarg>
#include <cstdint>
#include <cinttypes>
#include <ctgmath>
#include <cassert>
#include <random>
#include <memory>

using namespace std;

// Function to read a single word as a string from the input
string next() {
	string s;
	cin >> s;
	return s;
}

// Function to read an integer from the input
int nextInt() {
	int n;
	cin >> n;
	return n;
}

// Function to read a float64 from the input
double nextFloat64() {
	double d;
	cin >> d;
	return d;
}

// Function to read n integers from the input and return as a vector
vector<int> nextInts(int n) {
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = nextInt();
	}
	return v;
}

// Main function
int main() {
	// Read the first three integers from the input
	int a = nextInt();
	int b = nextInt();
	int c = nextInt();

	// Check if the condition is true
	if (a + b >= c) {
		// If true, print "Yes" to the output
		cout << "Yes" << endl;
	} else {
		// If false, print "No" to the output
		cout << "No" << endl;
	}

	// End of code
	
