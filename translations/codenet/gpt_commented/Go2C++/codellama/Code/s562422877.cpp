#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	// Read the number of elements N from input
	int N;
	cin >> N;

	// Initialize a vector A to hold N integers
	vector<int> A(N);
	
	// Read N integers from input into the vector A
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	// Sort the vector A in ascending order
	sort(A.begin(), A.end());

	// Initialize a variable to hold the total difference sum
	int ans = 0;
	
	// Calculate the sum of differences between consecutive elements in the sorted vector
	for (int i = 1; i < N; i++) {
		ans += A[i] - A[i-1];
	}

	// Output the total sum of differences
	cout << ans << endl;

	return 0;
}

