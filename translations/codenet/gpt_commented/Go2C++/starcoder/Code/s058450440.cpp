#include <bits/stdc++.h>

using namespace std;

// Global variables to store counts and the result
int a[5];
int ans = 0;

// Depth-first search function to calculate combinations
void dfs(int left, int i, int res) {
	// If no more characters left to choose, add the result to ans
	if (left == 0) {
		ans += res;
		return;
	}
	// Iterate through the array starting from index i
	for (int j = i; j < 5; j++) {
		// Recursive call to dfs with one less character to choose
		dfs(left - 1, j + 1, res * a[j]);
	}
}

int main() {
	// Initialize input reader
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	auto io = new ios();
	// Read the number of characters
	int n = io->nextInt();
	// Map to count occurrences of specific characters
	map<char, int> dic;

	// Read n characters and count occurrences of 'M', 'A', 'R', 'C', 'H'
	for (int i = 0; i < n; i++) {
		char c = io->nextString()[0]; // Read the first character of the string
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

	// Populate the array a with the counts from the dictionary
	for (auto it = dic.begin(); it!= dic.end(); it++) {
		a[it->first - 'M'] = it->second;
	}

	// Start the DFS to calculate the product of combinations of 3 characters
	dfs(3, 0, 1);
	// Print the final result
	cout << ans << endl;
	return 0;
}

// Struct to handle input operations
struct ios {
	std::istream *stream;
	std::istream *save;
	ios() {
		stream = &std::cin;
		save = stream;
	}
	~ios() {
		stream = save;
	}
	int nextInt() {
		int ret;
		*stream >> ret;
		return ret;
	}
	string nextString() {
		string ret;
		*stream >> ret;
		return ret;
	}
};

