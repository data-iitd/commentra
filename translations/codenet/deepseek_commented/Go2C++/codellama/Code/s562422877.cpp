#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	// Read the number of elements N
	int N;
	cin >> N;

	// Create a vector A to store N integers
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		// Read each integer and store it in vector A
		cin >> A[i];
	}

	// Sort the vector A in ascending order
	sort(A.begin(), A.end());

	// Initialize the answer variable to store the result
	int ans = 0;
	for (int i = 1; i < N; i++) {
		// Calculate the sum of differences between consecutive elements
		ans += A[i] - A[i-1];
	}

	// Print the result
	cout << ans << endl;

	return 0;
}

