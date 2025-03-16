
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void out(int x) {
	cout << x << endl;
}

int getInt() {
	int x;
	cin >> x;
	return x;
}

int main() {
	int N, C, K;
	cin >> N >> C >> K;
	vector<int> t(N);
	for (int i = 0; i < N; i++) {
		cin >> t[i];
	}

	sort(t.begin(), t.end());
	// out(t)
	int ans = 1;
	int cnt = 1;
	int end = t[0] + K;
	for (int i = 1; i < N; i++) {
		if (cnt < C && t[i] <= end) {
			cnt++;
			// out(t[i])
		} else {
			// out("----")
			// out(t[i])
			cnt = 1;
			end = t[i] + K;
			ans++;
		}
	}
	out(ans);
}

