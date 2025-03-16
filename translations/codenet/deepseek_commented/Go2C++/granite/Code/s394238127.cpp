
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// Create a vector to store the input values
	vector<vector<int>> c(3, vector<int>(3));
	vector<int> a(3), b(3);
	
	// Read values into the 3x3 array `c`
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> c[i][j];
		}
	}

	// Calculate the values of `b` based on the initial assumption that `a[0]` is zero
	b[0] = c[0][0] - a[0];
	b[1] = c[0][1] - a[0];
	b[2] = c[0][2] - a[0];
	
	// Calculate the values of `a` based on the values in `c`
	a[1] = c[1][0] - c[0][0];
	a[2] = c[2][0] - c[0][0];
	
	// Check if the calculated values of `a` and `c` are consistent with the given relationships
	if (a[1] == c[1][1] - c[0][1] && a[1] == c[1][2] - c[0][2] &&
		a[2] == c[2][1] - c[0][1] && a[2] == c[2][2] - c[0][2]) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

