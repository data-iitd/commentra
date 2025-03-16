#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int sqrtN = (int)sqrt(N);

	int min = N;
	for (int i = 1; i <= sqrtN; i++) {
		if (N % i!= 0) {
			continue;
		}

		int num = i + (N / i) - 2;
		if (num < min) {
			min = num;
		}
	}

	cout << min << "\n";
}

