
#include <bits/stdc++.h>

using namespace std;

int main() {
	// Initialize variables and read input
	// Code for A - Initialize variables and read input
	int N;
	cin >> N;

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	// Sort the array in ascending order
	// Code for C - Sort the array
	sort(A.begin(), A.end());

	// Calculate the answer
	// Code for D - Calculate the answer
	int ans = 0;
	for (int i = 1; i < N; i++) {
		ans += A[i] - A[i-1];
	}

	// Print the answer
	// Code for E - Print the answer
	cout << "The answer is: " << ans << endl;
}

