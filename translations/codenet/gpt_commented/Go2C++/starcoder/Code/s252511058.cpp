#include <bits/stdc++.h>

using namespace std;

// nextInt reads the next integer from the scanner and returns it.
int nextInt(istream& is) {
	int t;
	is >> t;
	return t;
}

// point struct represents a point with its position and its left and right bounds.
struct point {
	int x, l, r; // x is the position, l is the left bound, r is the right bound
};

// ps is a slice of point, implementing sort.Interface.
struct ps {
	vector<point> p;
	int Len() {
		return p.size();
	}
	void Swap(int i, int j) {
		point t = p[i];
		p[i] = p[j];
		p[j] = t;
	}
	bool Less(int i, int j) {
		return p[i].r < p[j].r; // Sort by the right bound
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	ps points(N);

	// Read each point's position and calculate its left and right bounds
	for (int i = 0; i < N; i++) {
		cin >> points.p[i].x;
		int L;
		cin >> L;
		points.p[i].l = points.p[i].x - L; // Calculate the left bound
		points.p[i].r = points.p[i].x + L; // Calculate the right bound
	}

	// Sort the points based on their right bounds
	sort(points.p.begin(), points.p.end(), [](point a, point b) {
		return a.r < b.r; // Sort by the right bound
	});

	// Initialize the scheduling process for the interval scheduling problem
	int start = points.p[0].r; // Start with the right bound of the first point
	int ans = 1; // Initialize the count of non-overlapping intervals

	// Iterate through the sorted points to count non-overlapping intervals
	for (int i = 0; i < N; i++) {
		if (points.p[i].l < start) { // If the left bound overlaps with the current start
			continue; // Skip to the next point
		}
		start = points.p[i].r; // Update the start to the right bound of the current point
		ans++; // Increment the count of non-overlapping intervals
	}

	// Output the total number of non-overlapping intervals
	cout << ans << endl;
}

