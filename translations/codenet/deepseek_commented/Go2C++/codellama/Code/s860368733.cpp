
#include <iostream>
#include <map>

using namespace std;

int main() {
	int n, m; // Declare variables to store the number of elements and comparisons
	cin >> n >> m; // Read the number of elements and comparisons from standard input
	int h[n]; // Create an array to store the heights of the elements
	for (int i = 0; i < n; i++) {
		cin >> h[i]; // Read the heights of the elements from standard input
	}
	int a, b; // Declare variables to store the indices of the elements being compared
	map<int, int> counter; // Create a map to keep track of elements that cannot be the highest
	for (int i = 0; i < m; i++) {
		cin >> a >> b; // Read each comparison from standard input
		if (h[a-1] < h[b-1]) { // Check if the height of the first element is less than the second
			counter[a] = 1; // Mark the first element as not being the highest
		} else if (h[a-1] > h[b-1]) { // Check if the height of the first element is greater than the second
			counter[b] = 1; // Mark the second element as not being the highest
		} else if (h[a-1] == h[b-1]) { // Check if the heights of the two elements are equal
			counter[a] = 1; // Mark both elements as not being the highest
			counter[b] = 1;
		}
	}
	cout << n - counter.size() << endl; // Print the number of elements that cannot be the highest
	return 0;
}

