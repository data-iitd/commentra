#include <bits/stdc++.h>

using namespace std;

// nextInt reads the next word from the scanner, converts it to an integer, and returns it.
int nextInt(istream& is) {
	int t;
	is >> t;
	return t;
}

// point represents a point with x, l (left boundary), and r (right boundary).
struct point {
	int x, l, r;
};

// ps is a slice of point and implements sort.Interface to sort by r.
struct ps {
	vector<point> p;
	ps(int n) : p(n) {}
	bool operator()(int i, int j) {
		return p[i].r < p[j].r;
	}
};

int main() {
	int N;
	cin >> N; // Read the number of points.
	vector<point> points(N);
	for (int i = 0; i < N; i++) {
		cin >> points[i].x; // Read the x-coordinate of the point.
		int L;
		cin >> L; // Read the length L.
		points[i].l = points[i].x - L; // Calculate the left boundary.
		points[i].r = points[i].x + L; // Calculate the right boundary.
	}
	sort(points.begin(), points.end(), ps(N)); // Sort the points by their right boundary.
	// Now we have a list of intervals. We need to select the maximum number of non-overlapping intervals.
	int start = points[0].r; // Initialize the start of the first interval.
	int ans = 1; // Initialize the answer (at least one interval is selected).
	for (int i = 0; i < N; i++) {
		if (points[i].l < start) { // If the current interval overlaps with the previous one, skip it.
			continue;
		}
		start = points[i].r; // Move to the next interval.
		ans++; // Increment the count of selected intervals.
	}
	cout << ans << endl; // Print the number of selected intervals.
}

