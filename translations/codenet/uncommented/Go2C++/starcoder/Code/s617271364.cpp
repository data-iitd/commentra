#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, A, B, C;
	cin >> N >> A >> B >> C;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int ans = 10000;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				int cost = 0;
				int aa = 0, bb = 0, cc = 0;
				for (int l = 0; l < N; l++) {
					if (i == 0) {
						aa += arr[l];
					} else if (i == 1) {
						bb += arr[l];
					} else if (i == 2) {
						cc += arr[l];
					}
					cost += abs(arr[l] - (aa + bb + cc));
				}
				cost += abs(A-aa) + abs(B-bb) + abs(C-cc);
				ans = min(ans, cost);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}

