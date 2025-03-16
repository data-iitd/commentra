#include <bits/stdc++.h>

using namespace std;

struct Block {
	string Value;
	int Len;
};

int main() {
	int N, K, ans = 0, sum = 0, zero = 0, l = 0;
	cin >> N >> K;
	string S;
	cin >> S;
	vector<Block> blocks = RunLength(S);
	for (int r = 0; r < blocks.size(); r++) {
		sum += blocks[r].Len;
		if (blocks[r].Value == "0") {
			zero++;
		}
		for (int k = 0; k < K; k++) {
			if (K < zero) {
				sum -= blocks[l].Len;
				if (blocks[l].Value == "0") {
					zero--;
				}
				l++;
			}
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
}

vector<Block> RunLength(string s) {
	vector<Block> r;
	if (s.size() == 0) {
		return r;
	}
	Block t = {s[0], 1};
	for (int i = 1; i < s.size(); i++) {
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

int Max(int a, int b) {
	if (b > a) {
		return b;
	}
	return a;
}

