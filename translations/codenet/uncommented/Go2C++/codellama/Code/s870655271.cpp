
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int N, M;
	int ans = 0;
	cin >> N >> M;
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		ans += (N - 2) * (M - 2);
	} else {
		ans += (N * M) - 2;
	}

	cout << ans << endl;

	return 0;
}

