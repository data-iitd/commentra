#include <bits/stdc++.h>

using namespace std;

int main() {
	// Initialize variables R, G, B, and N with next integers
	int R = nextInt();
	int G = nextInt();
	int B = nextInt();
	int N = nextInt();

	// Initialize variable ans with zero
	int ans = 0;

	// Nested for loops to iterate through all possible combinations of x and y within the range of N
	for (int x = 0; x <= N; x++) {
		for (int y = 0; y <= N; y++) {
			// Calculate temporary variable tmp
			int tmp = N - R*x - G*y;

			// Check if tmp is non-negative and the remainder of tmp when divided by B is zero
			if (tmp >= 0 && tmp%B == 0) {
				// Increment the value of ans if the condition is true
				ans++;
			}
		}
	}

	// Print the value of ans
	cout << ans << endl;
}

// Input related functions
int nextInt() {
	// Read next word as string, convert it to integer, and return
	string s;
	cin >> s;
	int x;
	istringstream iss(s);
	iss >> x;
	return x;
}

// Utility functions
int abs(int x) {
	// Return absolute value of x
	return x < 0? -x : x;
}

int min(int x, int y) {
	// Return minimum value of x and y
	return x < y? x : y;
}

int max(int x, int y) {
	// Return maximum value of x and y
	return x > y? x : y;
}

