
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// Global variables for the problem.
int a, b, c, k;

// Generate all possible patterns of length k where each element is one of 0, 1, 2, or 3.
vector<vector<int>> DuplicatePatterns(vector<int> elems, int k) {
	vector<vector<int>> res;
	if (k == 0) {
		res.push_back(vector<int>());
		return res;
	}

	for (int i = 0; i < elems.size(); i++) {
		vector<vector<int>> tmp = DuplicatePatterns(elems, k - 1);
		for (int j = 0; j < tmp.size(); j++) {
			tmp[j].push_back(elems[i]);
		}
		res.insert(res.end(), tmp.begin(), tmp.end());
	}
	return res;
}

// Iterate through each pattern to check the condition.
void main() {
	cin >> a >> b >> c >> k;

	vector<int> elems = {0, 1, 2, 3};
	vector<vector<int>> patterns = DuplicatePatterns(elems, k);

	for (int i = 0; i < patterns.size(); i++) {
		int r, g, b;
		r = a;
		g = b = c;
		for (int j = 0; j < patterns[i].size(); j++) {
			if (patterns[i][j] == 0) {
				continue;
			} else if (patterns[i][j] == 1) {
				r *= 2;
			} else if (patterns[i][j] == 2) {
				g *= 2;
			} else if (patterns[i][j] == 3) {
				b *= 2;
			}
		}

		if (g > r && b > g) {
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
}

