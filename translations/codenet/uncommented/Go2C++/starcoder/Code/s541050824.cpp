#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<int> T(N), A(N);
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> A[i];
	}
	int t = T[0], a = A[0];
	for (int i = 1; i < N; i++) {
		int r = max(t / T[i], a / A[i]);
		t = T[i] * r;
		a = A[i] * r;
	}
	cout << t + a << "\n";
}

