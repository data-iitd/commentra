
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Reads a single line of input from the standard input.
string next() {
	string s;
	getline(cin, s);
	return s;
}

// Reads the next input as an integer.
int nextInt() {
	string s = next();
	stringstream ss(s);
	int i;
	ss >> i;
	return i;
}

// Reads the next input as a float64.
double nextFloat64() {
	string s = next();
	stringstream ss(s);
	double f;
	ss >> f;
	return f;
}

// Reads `n` integers from input and returns them as a vector.
vector<int> nextInts(int n) {
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = nextInt();
	}
	return a;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a = nextInts(n);
	// Set the first element of `a` to 0 to avoid unused variable error.
	a[0] = 0;

	int sum = k;
	int ans = 1;
	// Loop to increment `sum` and `ans` until `sum` is less than `n`.
	while (sum < n) {
		sum = sum - 1 + k;
		ans++;
	}
	cout << ans << endl;
	return 0;
}

