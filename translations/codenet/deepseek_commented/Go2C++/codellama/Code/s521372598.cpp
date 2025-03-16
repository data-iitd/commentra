
#include <bits/stdc++.h>

using namespace std;

// The solve function reads an integer n and a slice of integers as.
// It then creates a new slice xs where each element is calculated as a - i + 1.
// The slice xs is sorted.
// The median of the sorted xs is chosen as b.
// The function calculates the sum of absolute differences between each element in xs and b.
// The result is printed.
void solve() {
	int n = getInt();
	vector<int> as = getIntSlice(n);

	vector<int> xs(n);
	for (int i = 0; i < n; i++) {
		xs[i] = as[i] - i + 1;
	}
	sort(xs.begin(), xs.end()); // Sort the slice xs

	int b = xs[n / 2]; // Choose the median as b
	int ans = 0;
	for (int x : xs) {
		ans += abs(x - b);
	}
	cout << ans << endl;
}

// The abs function returns the absolute value of an integer n.
int abs(int n) {
	if (n < 0) {
		return -n;
	}
	return n;
}

// -----------------------------------------

// The getInt function reads a single integer from the standard input.
int getInt() {
	int ret;
	cin >> ret;
	return ret;
}

// The getIntSlice function reads n integers from the standard input and returns them as a slice.
vector<int> getIntSlice(int n) {
	vector<int> ret;
	for (int i = 0; i < n; i++) {
		ret.push_back(getInt());
	}
	return ret;
}

// The getString function reads a single string from the standard input.
string getString() {
	string ret;
	cin >> ret;
	return ret;
}

// The getRunes function reads a single string from the standard input and returns it as a slice of runes.
vector<rune> getRunes() {
	string ret = getString();
	vector<rune> ret_rune;
	for (int i = 0; i < ret.size(); i++) {
		ret_rune.push_back(ret[i]);
	}
	return ret_rune;
}

int main() {
	solve();
	return 0;
}

