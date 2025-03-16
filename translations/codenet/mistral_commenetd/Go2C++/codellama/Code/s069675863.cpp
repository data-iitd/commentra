
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <array>
#include <boost/rational.hpp>

using namespace std;
using boost::rational;

// <START-OF-CODE>

// helper function to initialize a 2D boolean array
void make2DBooleanArray(vector<vector<bool>> &dpx, vector<vector<bool>> &dpy, int rows, int cols) {
	dpx.resize(rows);
	dpy.resize(rows);
	for (int i = 0; i < rows; i++) {
		dpx[i].resize(cols);
		dpy[i].resize(cols);
	}
}

// helper function to update dpx array
void updateDPX(vector<vector<bool>> &dpx, int index, int val) {
	for (int j = 2000; j <= 18000; j++) {
		if (j + val <= 18000) {
			dpx[index + 1][j + val] = dpx[index + 1][j + val] || dpx[index][j];
		}
		if (j - val >= 2000 && index != 0) {
			dpx[index + 1][j - val] = dpx[index + 1][j - val] || dpx[index][j];
		}
	}
}

// helper function to update dpy array
void updateDPY(vector<vector<bool>> &dpy, int index, int val) {
	for (int j = 2000; j <= 18000; j++) {
		if (j + val <= 18000) {
			dpy[index + 1][j + val] = dpy[index + 1][j + val] || dpy[index][j];
		}
		if (j - val >= 2000) {
			dpy[index + 1][j - val] = dpy[index + 1][j - val] || dpy[index][j];
		}
	}
}

int main() {
	// Read a string from the standard input
	string S;
	cin >> S;

	// Parse two integers from the string and assign them to the variables x and y
	int x, y;
	cin >> x >> y;

	// Initialize a 2D boolean array dpx and dpy with the size of 8000 x 20000
	vector<vector<bool>> dpx, dpy;
	make2DBooleanArray(dpx, dpy, 8000, 20000);

	// Iterate through the even indices of the F slice and update the dpx array accordingly
	for (int i = 0; i < S.size(); i++) {
		if (i % 2 == 0) {
			updateDPX(dpx, i, S[i] - '0');
		}
	}

	// Iterate through the odd indices of the F slice and update the dpy array accordingly
	for (int i = 0; i < S.size(); i++) {
		if (i % 2 == 1) {
			updateDPY(dpy, i, S[i] - '0');
		}
	}

	// Check if the boolean values at the indices (len(evens) + 1) and (len(odds) + 1) corresponding to x and y are both true
	if (dpx[S.size()][x + 10000] && dpy[S.size()][y + 10000]) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}

// 