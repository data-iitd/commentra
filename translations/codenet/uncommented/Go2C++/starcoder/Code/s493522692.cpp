#include <bits/stdc++.h>
using namespace std;

// Util
int nextInt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int N, M;
	cin >> N >> M;
	int tmp = min(N, M / 2);
	int ans = tmp;
	N -= tmp;
	M -= tmp * 2;
	//cout << ans << " " << N << " " << M << endl;
	cout << ans + M / 4 << endl;
	return 0;
}

