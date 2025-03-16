
#include <bits/stdc++.h>

using namespace std;

const long long int inf = 1e12; // Constants should be defined with clear names and values

int main() {
	// Initialize variables and read input
	int n;
	cin >> n;

	vector<int> arrA(n); // Create an array of size n to store input
	for (int i = 0; i < n; i++) {
		cin >> arrA[i]; // Read each element of the array
	}

	vector<int> cumSumA(n+1); // Create an array of size n+1 to store cumulative sum
	cumSumA[0] = 0;            // Initialize the first element of cumulative sum array
	for (int i = 0; i < n; i++) {
		cumSumA[i+1] = cumSumA[i] + arrA[i]; // Calculate cumulative sum
	}

	// Initialize variable to store the answer
	long long int ans = inf; // Initialize with a large value

	// Iterate through the array to find the answer
	for (int i = 1; i < n; i++) {
		long long int temp = cumSumA[n] - cumSumA[i]*2; // Calculate the difference
		if (abs(temp) < ans) { // If the difference is smaller than the current answer
			ans = temp; // Update the answer
		}
	}

	// Print the answer
	cout << ans << endl;

	// End of the code
}

