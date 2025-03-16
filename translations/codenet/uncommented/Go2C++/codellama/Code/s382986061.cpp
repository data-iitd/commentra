#include <iostream>
#include <map>

using namespace std;

int main() {
	int N, K;
	int d, a;
	map<int, int> as;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		as[i] = 0;
	}
	for (int i = 0; i < K; i++) {
		cin >> d;
		for (int j = 0; j < d; j++) {
			cin >> a;
			as[a]++;
		}
	}
	int ans = 0;
	for (auto v : as) {
		if (v.second == 0) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}

