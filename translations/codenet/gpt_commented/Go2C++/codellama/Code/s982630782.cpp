
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// Initialize a map to count occurrences of integers
	map<int, int> m;

	// Read the number of initial integers (N) and the number of operations (M)
	int N, M;
	cin >> N >> M;

	// Read N integers and count their occurrences in the map
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		m[x]++;
	}

	// Process M operations, where each operation adds B occurrences of integer C
	for (int i = 0; i < M; i++) {
		int B, C;
		cin >> B >> C;
		m[C] += B;
	}

	// Create a vector to hold the unique integers from the map
	vector<int> ints;
	for (auto i : m) {
		ints.push_back(i.first);
	}

	// Sort the integers in descending order
	sort(ints.begin(), ints.end(), greater<int>());

	// Initialize variables to keep track of remaining integers and the total sum
	int rest = N;
	int sum = 0;

	// Calculate the maximum sum based on the sorted integers
	for (auto i : ints) {
		int num = m[i];
		// If the number of occurrences is greater than or equal to the remaining count
		if (num >= rest) {
			sum += rest * i; // Add the product of remaining count and the integer
			break; // Exit the loop as we have used all remaining integers
		}
		sum += num * i; // Add the product of occurrences and the integer to the sum
		rest -= num; // Decrease the remaining count by the number of occurrences
	}

	// Output the final calculated sum
	cout << sum << endl;

	return 0;
}

