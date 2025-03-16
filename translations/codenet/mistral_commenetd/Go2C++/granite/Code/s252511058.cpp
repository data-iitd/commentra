
#include <bits/stdc++.h>
using namespace std;

// Initializing scanner for reading input from standard input
int nextInt(Scanner &sc) {
	sc.nextLine();
	// Scanning the next word as a string
	string t = sc.next();
	// Converting the string to integer and returning it
	return stoi(t);
}

// Defining a custom type 'point' for storing x-coordinate, left-endpoint, and right-endpoint of a segment
struct point {
	int x, l, r;
};

// Defining a vector 'ps' of type 'point' for storing all segments in sorted order based on their right-endpoints
typedef vector<point> ps;

// Implementing comparison function for sorting 'ps' vector based on their right-endpoints
bool compare(point p1, point p2) {
	return p1.r < p2.r;
}

// Main function starts here
int main() {
	// Initializing scanner for reading input from standard input
	Scanner sc;
	// Reading the number of segments N from the input
	int N = nextInt(sc);
	// Creating a vector 'points' of type 'point' to store all segments
	vector<point> points(N);
	// Reading x-coordinate, left-endpoint, and right-endpoint of each segment from the input and storing it in 'points' vector
	for (int i = 0; i < N; i++) {
		points[i].x = nextInt(sc);
		// Reading left-endpoint L of the segment
		int L = nextInt(sc);
		// Calculating left and right endpoints of the segment based on x-coordinate and left-endpoint
		points[i].l = points[i].x - L;
		points[i].r = points[i].x + L;
	}
	// Sorting 'points' vector based on their right-endpoints using comparison function
	sort(points.begin(), points.end(), compare);
	// Initializing variables for result calculation
	int start = points[0].r;
	int ans = 1;
	// Iterating through all segments in sorted order and updating result accordingly
	for (int i = 0; i < points.size(); i++) {
		// If the start of current segment is less than the end of previous segment, then skip it
		if (points[i].l < start) {
			continue;
		}
		// Updating start to the end of current segment
		start = points[i].r;
		// Incrementing answer by 1
		ans++;
	}
	// Printing the final answer
	cout << ans << endl;
}

// Adding a comment at the end of the code
