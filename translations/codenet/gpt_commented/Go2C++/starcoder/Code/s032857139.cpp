#include <bits/stdc++.h>

using namespace std;

// Constants for the program
const int MOD = 1000000000 + 7;
const int ALPHABET_NUM = 26;

int n, x;
int A[100000 + 1];

// main function where the program execution starts
int main() {
	// Read input values for n and x
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	// Sort the array A
	sort(A, A + n);

	// Initialize answer variable
	int ans = 0;
	// Count how many elements can be taken from A without exceeding x
	for (int i = 0; i < n; i++) {
		if (x >= A[i]) {
			ans++;
			x -= A[i];
		} else {
			break;
		}
	}
	// Adjust answer if all elements are taken and there is still remaining x
	if (ans == n && x > 0) {
		ans--;
	}
	// Print the final answer
	cout << ans << endl;
	return 0;
}

