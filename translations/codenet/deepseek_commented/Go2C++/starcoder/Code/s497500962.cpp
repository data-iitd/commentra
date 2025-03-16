
#include <bits/stdc++.h>

using namespace std;

// <START-OF-CODE>

int main() {
	int R, G, B, N;
	cin >> R >> G >> B >> N;

	int ans = 0;
	// Iterate over all possible values of x and y
	for (int x = 0; x <= N; x++) {
		for (int y = 0; y <= N; y++) {
			// Calculate the remaining value after subtracting x*R and y*G
			int tmp = N - x*R - y*G;
			// Check if the remaining value is non-negative and a multiple of B
			if (tmp >= 0 && tmp%B == 0) {
				ans++;
			}
		}
	}

	cout << ans << endl;
}

// 