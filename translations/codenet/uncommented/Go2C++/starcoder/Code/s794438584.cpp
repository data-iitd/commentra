#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int max(int lhs, int rhs) {
	return lhs > rhs? lhs : rhs;
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> values(N);
	vector<int> weights(N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &weights[i], &values[i]);
	}
	//cout << N << " " << M << endl;
	//cout << values << " " << weights << endl;
	vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			dp[i][j] = dp[i-1][j];
			if (j >= weights[i-1]) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-weights[i-1]]+values[i-1]);
			}
		}
	}
	cout << dp[N][M] << endl;
}

