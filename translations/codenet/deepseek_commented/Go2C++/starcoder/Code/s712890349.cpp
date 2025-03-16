
#include <bits/stdc++.h>

using namespace std;

// Block represents a run-length encoded block of characters
struct Block {
	string Value;
	int Len;
};

// RunLength performs run-length encoding on the input string
vector<Block> RunLength(string s) {
	vector<Block> r;
	if (s.empty()) {
		return r;
	}
	Block t = {s[0], 1};
	for (int i = 1; i < s.length(); i++) {
		if (t.Value == s[i]) {
			t.Len++;
		} else {
			r.push_back(t);
			t = {s[i], 1};
		}
	}
	r.push_back(t);
	return r;
}

// Max returns the maximum of two integers
int Max(int a, int b) {
	if (b > a) {
		return b;
	}
	return a;
}

int main() {
	int N, K, ans = 0, zero = 0, l = 0, sum = 0;
	cin >> N >> K;
	string S;
	cin >> S;
	vector<Block> blocks = RunLength(S);
	for (int r = 0; r < blocks.size(); r++) {
		sum += blocks[r].Len;
		if (blocks[r].Value == "0") {
			zero++;
		}
		// Adjust the window size if the number of '0' blocks exceeds K
		for (int k = K; k < zero; k++) {
			sum -= blocks[l].Len;
			if (blocks[l].Value == "0") {
				zero--;
			}
			l++;
		}
		ans = Max(ans, sum);
	}
	cout << ans << endl;
	return 0;
}

