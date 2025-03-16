#include <iostream>
#include <cmath>

using namespace std;

int max(int lhs, int rhs) {
	return int(max(lhs, rhs));
}

int main() {
	int N, M;
	cin >> N >> M;
	int values[N];
	int weights[N];
	for (int i = 0; i < N; i++) {
		cin >> weights[i] >> values[i];
	}
	//fmt.Println(N, M)
	//fmt.Println(values, weights)
	int dp[N+1][M+1];
	for (int i = 0; i < N+1; i++) {
		for (int j = 0; j < M+1; j++) {
			dp[i][j] = dp[i-1][j];
			if (j >= weights[i-1]) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-weights[i-1]]+values[i-1]);
			}
		}
	}
	cout << dp[N][M] << endl;
	return 0;
}

