#include <bits/stdc++.h>

using namespace std;

class Segment {
public:
	int n, h, i, chunk;
	vector<int> unit;
	vector<vector<int>> bucket;

	void init(int n) {
		this->n = n;
		unit.push_back(1);
		bucket.push_back(vector<int>(n));

		chunk = 8;
		for (int i = 0; n > 1; i++) {
			n = (n-1)/chunk + 1;
			bucket.push_back(vector<int>(n));
			unit.push_back(unit[i]*chunk);
		}
		h = unit.size();
		chunk = 8;
	}

	void maximize(int index, int value) {
		bucket[0][index] = value;
		for (i = 0; i < h-1; i++) {
			int s = index - index%chunk;
			int t = s + chunk;
			if (t > bucket[i].size()) {
				t = bucket[i].size();
			}
			int parent = index / chunk;
			int max = 0;
			for (int i = s; i < t; i++) {
				if (max < bucket[i]) {
					max = bucket[i];
				}
			}
			bucket[i+1][parent] = max;
			index /= chunk;
		}
	}

	int top() {
		int index = 0;
		for (i = h - 2; i >= 0; i--) {
			int s = index * chunk;
			int t = s + chunk;
			if (t > bucket[i].size()) {
				t = bucket[i].size();
			}
			for (int i = s; i < t; i++) {
				if (bucket[i] == bucket[i+1][index]) {
					index = i;
					break;
				}
			}
		}

		return index;
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;
	Segment seg;
	seg.init(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		seg.maximize(i, x);
	}
	for (int i = 0; i < m; i++) {
		seg.maximize(seg.top(), seg.bucket[seg.h-1][0]>>1);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += seg.bucket[0][i];
	}

	cout << ans << endl;
	return 0;
}

