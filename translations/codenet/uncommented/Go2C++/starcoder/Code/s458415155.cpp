
#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> heights) {
	vector<int> t(n+1, numeric_limits<int>::max());
	t[0] = 0;
	for (int i = 1; i < n; i++) {
		if (int v = t[i-1] + abs(heights[i]-heights[i-1]); v < t[i]) {
			t[i] = v;
		}
		if (1 < i) {
			if (int v = t[i-2] + abs(heights[i]-heights[i-2]); v < t[i]) {
				t[i] = v;
			}
		}
	}
	return t[n-1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<int> heights(n);
	for (int i = 0; i < n; i++) {
		cin >> heights[i];
	}
	cout << solve(n, heights) << '\n';
}

