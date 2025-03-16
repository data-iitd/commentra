#include <bits/stdc++.h>

using namespace std;

int main() {
	// Initializing necessary variables
	int n, ans = 0;
	vector<int> a;
	map<char, int> dic;

	// Reading the number of test cases
	cin >> n;

	// Reading strings and updating the map
	for (int i = 0; i < n; i++) {
		char c = cin.get();
		switch (c) {
		case 'M':
			dic['M']++;
			break;
		case 'A':
			dic['A']++;
			break;
		case 'R':
			dic['R']++;
			break;
		case 'C':
			dic['C']++;
			break;
		case 'H':
			dic['H']++;
			break;
		}
	}

	// Converting map values to integers and appending them to the 'a' vector
	for (auto it = dic.begin(); it!= dic.end(); it++) {
		a.push_back(it->second);
	}

	// Calling the 'dfs' function with initial arguments
	dfs(3, 0, 1, a, ans);

	// Printing the answer
	cout << ans << endl;
}

// Function to perform Depth First Search (DFS) algorithm
void dfs(int left, int i, int res, vector<int> a, int &ans) {
	// Base case
	if (left == 0) {
		ans += res;
		return;
	}

	// Recursive case
	for (int j = i; j < a.size(); j++) {
		dfs(left - 1, j + 1, res * a[j], a, ans);
	}
}

// 

Translate the above C++ code to Python and end with comment "