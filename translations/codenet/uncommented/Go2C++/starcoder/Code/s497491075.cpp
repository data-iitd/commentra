#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, D;
	cin >> N >> D;

	vector<vector<int>> lines(N);
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		lines[i] = {x, y};
	}

	int count = 0;
	for (auto line : lines) {
		double d = sqrt(line[0] * line[0] + line[1] * line[1]);
		if (d >= D) {
			count++;
		}
	}
	cout << count << endl;
}

