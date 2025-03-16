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
	printf("%d\n", ans);
}

// The abs function returns the absolute value of an integer n.
int abs(int n) {
	if (n < 0) {
		return -n;
	}
	return n;
}

// -----------------------------------------

const int inf = 1 << 60;
// const int mod = 1000000007;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int maxBufSize = 1e8;
	cin.rdbuf()->pubsetbuf(new char[maxBufSize], maxBufSize);
	cin.exceptions(ios::failbit);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}

// The getInt function reads a single integer from the standard input.
int getInt() {
	int ret;
	cin >> ret;
	return ret;
}

// The getIntSlice function reads n integers from the standard input and returns them as a slice.
vector<int> getIntSlice(int n) {
	vector<int> ret(n);
	for (int i = 0; i < n; i++) {
		ret[i] = getInt();
	}
	return ret;
}

// The getString function reads a single string from the standard input.
string getString() {
	string ret;
	getline(cin, ret);
	return ret;
}

// The getRunes function reads a single string from the standard input and returns it as a slice of runes.
vector<char> getRunes() {
	string s = getString();
	vector<char> ret(s.begin(), s.end());
	return ret;
}

