#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K; // Declare N and K to store the number of elements and the number of days respectively
	int d, a; // Declare d and a to store the number of elements chosen on a day and an element respectively
	cin >> N >> K; // Read the values of N and K
	map<int, int> as; // Create a map to keep track of the occurrences of each element
	for (int i = 1; i <= N; i++) {
		as[i] = 0; // Initialize all elements to zero in the map
	}
	for (int i = 0; i < K; i++) {
		cin >> d; // Read the number of elements chosen on the i-th day
		for (int j = 0; j < d; j++) {
			cin >> a; // Read the elements chosen on the i-th day
			as[a]++; // Increment the count of the chosen element in the map
		}
	}
	int ans = 0; // Initialize the answer variable to count unchosen elements
	for (auto it = as.begin(); it!= as.end(); it++) {
		if (it->second == 0) {
			ans++; // Increment the answer if an element was not chosen
		}
	}
	cout << ans << endl; // Print the number of unchosen elements
	return 0;
}

