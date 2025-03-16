#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// Importing necessary packages

vector<int> a;
int ans = 0;

// Defining global variables

void dfs(int left, int i, int res) {
	// Function to perform Depth First Search (DFS) algorithm

	if (left == 0) {
		ans += res;
		return;
	}

	for (int j = i; j < a.size(); j++) {
		dfs(left - 1, j + 1, res * a[j]);
	}
}

// Main function definition
int main() {
	// Initializing an io object for input/output handling
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// Reading the number of test cases
	int n;
	cin >> n;

	// Initializing an empty map to store the frequency of each character
	map<char, int> dic;

	// Reading strings and updating the map
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		if (c == 'M' || c == 'A' || c == 'R' || c == 'C' || c == 'H') {
			dic[c]++;
		}
	}

	// Converting map values to integers and appending them to the 'a' slice
	for (auto& p : dic) {
		a.push_back(p.second);
	}

	// Calling the 'dfs' function with initial arguments
	dfs(3, 0, 1);

	// Printing the answer
	cout << ans << '\n';

	return 0;
}
