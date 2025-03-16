
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> as(n);
	for (int i = 0; i < n; i++) {
		cin >> as[i];
	}
	
	// Initialize xs with the first element of as
	vector<int> xs;
	xs.push_back(as[0]);
	for (int j = 1; j < n; j++) {
		// Use lower_bound to find the position to insert the current element
		int idx = lower_bound(xs.begin(), xs.end(), as[j]) - xs.begin();
		if (idx == xs.size()) {
			// If the element is larger than all elements in xs, append it
			xs.push_back(as[j]);
		} else {
			// Otherwise, replace the existing element at the found position
			xs[idx] = as[j];
		}
	}
	
	// Print the length of the longest increasing subsequence found
	cout << xs.size() << endl;
	return 0;
}

