
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	// Read input values
	int N, C, K;
	cin >> N >> C >> K;

	// Array to store arrival times
	vector<int> t(N);
	for (int i = 0; i < N; i++) {
		cin >> t[i];
	}

	// Sort the arrival times
	sort(t.begin(), t.end());

	// Initialize variables for the number of buses and passengers in the current bus
	int ans = 1;
	int cnt = 1;
	int end = t[0] + K; // Time when the bus will be full or the time window expires

	// Iterate through the sorted arrival times
	for (int i = 1; i < N; i++) {
		if (cnt < C && t[i] <= end) {
			// The current passenger can fit in the bus
			cnt++;
		} else {
			// The current bus is full or the time window has expired
			// Increment the bus count, reset the count, and update the end time
			cnt = 1;
			end = t[i] + K;
			ans++;
		}
	}

	// Output the number of buses required
	cout << ans << endl;

	return 0;
}

