
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	map<int, int> m;
	int N, M;
	cin >> N >> M;
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
	for (auto it = m.begin(); it != m.end(); it++) {
		ints.push_back(it->first);
	}
	sort(ints.begin(), ints.end(), greater<int>());
	int rest = N;
	int sum = 0;
	for (auto i : ints) {
		int num = m[i];
		if (num >= rest) {
			sum += rest * i;
			break;
		}
		sum += num * i;
		rest -= num;
	}
	cout << sum << endl;
	return 0;
}

