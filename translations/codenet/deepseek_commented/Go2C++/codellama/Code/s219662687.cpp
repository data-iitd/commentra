
#include <bits/stdc++.h>

using namespace std;

int main() {
	int INF = 1e11; // Define a large constant for infinity
	int A = nextInt(); // Read the number of temples
	int B = nextInt(); // Read the number of shrines
	int Q = nextInt(); // Read the number of queries
	vector<int> s(A+2); // Create a vector for temples with extra space for boundaries
	s[0], s[A+1] = -INF, INF; // Set boundary values
	for (int i = 1; i <= A; i++) {
		s[i] = nextInt(); // Read temple locations
	}

	vector<int> t(B+2); // Create a vector for shrines with extra space for boundaries
	t[0], t[B+1] = -INF, INF; // Set boundary values
	for (int i = 1; i <= B; i++) {
		t[i] = nextInt(); // Read shrine locations
	}

	for (int i = 0; i < Q; i++) {
		int x = nextInt(); // Read the query point
		int b, d = lower_bound(s.begin(), s.end(), x) - s.begin(), upper_bound(t.begin(), t.end(), x) - t.begin(); // Find closest temples and shrines
		int res = INF; // Initialize result with infinity
		for (int S : {s[b-1], s[b]}) { // Check previous and current temple
			for (int T : {t[d-1], t[d]}) { // Check previous and current shrine
				int d1, d2 = abs(S-x)+abs(T-S), abs(T-x)+abs(S-T); // Calculate distances
				res = min(res, min(d1, d2)); // Update result with minimum distance
			}
		}

		cout << res << endl; // Print the minimum distance for the query
	}
}

// Input. ----------

int nextInt() {
	int x;
	cin >> x;
	return x;
}

float nextFloat() {
	float x;
	cin >> x;
	return x;
}

string nextString() {
	string x;
	cin >> x;
	return x;
}

// ---------- Input.

// Util. ----------

int abs(int x) {
	return x < 0 ? -x : x; // Return absolute value of x
}

int min(int x, int y) {
	return x < y ? x : y; // Return minimum of x and y
}

int max(int x, int y) {
	return x > y ? x : y; // Return maximum of x and y
}

// ---------- Util.

