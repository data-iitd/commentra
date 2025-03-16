#include <bits/stdc++.h>

using namespace std;

int main() {
	// Code for B - Traveling AtCoDeer Problem
	int N;
	cin >> N;

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	int ans = 0;
	for (int i = 1; i < N; i++) {
		ans += A[i] - A[i-1];
	}

	cout << ans << endl;
}

