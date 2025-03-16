#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	map<int, int> m;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		m[x]++;
	}
	for (int i = 0; i < M; i++) {
		int B, C;
		cin >> B >> C;
		m[C] += B;
	}
	vector<int> ints;
	for (auto it = m.begin(); it!= m.end(); it++) {
		ints.push_back(it->first);
	}
	sort(ints.begin(), ints.end(), greater<int>());
	int rest = N;
	int sum = 0;
	for (int i = 0; i < ints.size(); i++) {
		int num = m[ints[i]];
		if (num >= rest) {
			sum += rest * ints[i];
			break;
		}
		sum += num * ints[i];
		rest -= num;
	}
	cout << sum << endl;
}

