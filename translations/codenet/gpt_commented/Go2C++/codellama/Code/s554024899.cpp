
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define a 2D array where each sub-array represents a category of numbers
vector<vector<int>> a = {
	{1, 3, 5, 7, 8, 10, 12},
	{4, 6, 9, 11},
	{2}
};

int main() {
	// Read two integers from input
	int x, y;
	cin >> x >> y;

	// Initialize variables to store the category indices of x and y
	int xt, yt;

	// Iterate through the categories to find the indices of x and y
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[i].size(); j++) {
			// Check if the current number matches x
			if (a[i][j] == x) {
				xt = i; // Store the category index for x
			}
			// Check if the current number matches y
			if (a[i][j] == y) {
				yt = i; // Store the category index for y
			}
		}
	}

	// Compare the category indices of x and y and print the result
	if (xt == yt) {
		cout << "Yes" << endl; // x and y belong to the same category
	} else {
		cout << "No" << endl; // x and y belong to different categories
	}

	return 0;
}

