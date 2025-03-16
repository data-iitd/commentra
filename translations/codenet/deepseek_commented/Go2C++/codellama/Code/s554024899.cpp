
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to return the maximum of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// Custom scanner struct to read input
struct scanner {
	vector<string> buf;
	int p;
	
	// Function to create a new scanner
	scanner() {
		string line;
		while (getline(cin, line)) {
			buf.push_back(line);
		}
		p = 0;
	}
	
	// Function to read the next word
	string next() {
		pre();
		int start = p;
		for (; p < buf[0].size(); p++) {
			if (buf[0][p] == ' ') {
				break;
			}
		}
		string result = buf[0].substr(start, p - start);
		p++;
		return result;
	}
	
	// Function to read the next line
	string nextLine() {
		pre();
		int start = p;
		p = buf[0].size();
		return buf[0].substr(start);
	}
	
	// Function to read the next integer
	int nextInt() {
		return stoi(next());
	}
	
	// Function to preprocess the buffer
	void pre() {
		if (p >= buf[0].size()) {
			buf.erase(buf.begin());
			p = 0;
		}
	}
};

// Function to determine if two integers belong to the same group
bool sameGroup(int x, int y) {
	// Define an array containing three slices, each representing a group of months with the same number of days
	vector<vector<int>> a = {
		{1, 3, 5, 7, 8, 10, 12},
		{4, 6, 9, 11},
		{2}
	};
	
	// Iterate over the array to determine which group each of the integers belongs to
	int xt, yt;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[i].size(); j++) {
			if (x == a[i][j]) {
				xt = i;
			}
			if (y == a[i][j]) {
				yt = i;
			}
		}
	}
	
	// Compare the groups of x and y to determine if they belong to the same group
	if (xt == yt) {
		return true;
	}
	return false;
}

// Main function
int main() {
	// Create a new scanner to read input
	scanner sc;
	
	// Read two integers from the input
	int x = sc.nextInt();
	int y = sc.nextInt();
	
	// Determine if x and y belong to the same group
	bool same = sameGroup(x, y);
	
	// Print the result
	if (same) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	
	return 0;
}

