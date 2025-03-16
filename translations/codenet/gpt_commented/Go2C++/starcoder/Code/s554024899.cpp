#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

// Define a 2D array where each sub-array represents a category of numbers
int a[3][7] = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};

// Function to find the index of a number in a category
int find(int x, int y) {
	// Iterate through the categories to find the indices of x and y
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 7; j++) {
			// Check if the current number matches x
			if (x == a[i][j]) {
				return i; // Return the category index for x
			}
			// Check if the current number matches y
			if (y == a[i][j]) {
				return i; // Return the category index for y
			}
		}
	}
	return -1; // Return -1 if x and y don't belong to any category
}

int main() {
	// Read two integers from input
	int x, y;
	cin >> x >> y;

	// Find the indices of x and y
	int xt = find(x, y);
	int yt = find(y, x);

	// Compare the category indices of x and y and print the result
	if (xt == yt) {
		cout << "Yes" << endl; // x and y belong to the same category
	} else {
		cout << "No" << endl;  // x and y belong to different categories
	}
	return 0;
}

