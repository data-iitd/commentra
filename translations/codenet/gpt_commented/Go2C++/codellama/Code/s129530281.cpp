
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Segment structure to hold the segment data and operations
struct Segment {
	int n, h, i, chunk;
	vector<int> unit;
	vector<vector<int>> bucket;

	// Initialize the segment structure with the given size n
	void init(int n) {
		this->n = n;
		unit.push_back(1);
		bucket.push_back(vector<int>(n));

		chunk = 8;
		for (int i = 0; n > 1; i++) {
			n = (n - 1) / chunk + 1;
			bucket.push_back(vector<int>(n));
			unit.push_back(unit[i] * chunk);
		}
		h = unit.size();
	}

	// Update the segment at a given index with a new value
	void maximize(int index, int value) {
		bucket[0][index] = value;
		for (i = 0; i < h - 1; i++) {
			int s = index - index % chunk;
			int t = s + chunk;
			if (t > bucket[i].size()) {
				t = bucket[i].size();
			}
			int parent = index / chunk;
			int max = 0;
			for (int i = s; i < t; i++) {
				if (max < bucket[i][i]) {
					max = bucket[i][i];
				}
			}
			bucket[i + 1][parent] = max;
			index /= chunk;
		}
	}

	// Retrieve the index of the top value in the segment
	int top() {
		int index = 0;
		for (i = h - 2; i >= 0; i--) {
			int s = index * chunk;
			int t = s + chunk;
			if (t > bucket[i].size()) {
				t = bucket[i].size();
			}
			for (int i = s; i < t; i++) {
				if (bucket[i][i] == bucket[i + 1][index]) {
					index = i;
					break;
				}
			}
		}

		return index;
	}
};

// Read the number of elements and operations
int n, m;
cin >> n >> m;

// Initialize the Segment structure
Segment seg;
seg.init(n);

// Populate the segment with initial values
for (int i = 0; i < n; i++) {
	int value;
	cin >> value;
	seg.maximize(i, value);
}

// Perform m operations to maximize the segment
for (int i = 0; i < m; i++) {
	seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] >> 1);
}

// Calculate the final answer by summing up the values in the first bucket
int64_t ans = 0;
for (int i = 0; i < n; i++) {
	ans += seg.bucket[0][i];
}

// Output the final result
cout << ans << endl;

