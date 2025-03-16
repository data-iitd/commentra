#include <bits/stdc++.h>

using namespace std;

// Defining a custom type 'point' for storing x-coordinate, left-endpoint, and right-endpoint of a segment
struct point {
	int x, l, r;
};

// Defining a vector 'ps' of type 'point' for storing all segments in sorted order based on their right-endpoints
vector<point> ps;

// Function for reading input from standard input
int nextInt(int sc) {
	sc = getchar();
	int t = 0;
	while (sc!= EOF && sc!= '\n') {
		t = t*10 + sc - '0';
		sc = getchar();
	}
	return t;
}

// Main function starts here
int main() {
	// Reading the number of segments N from the input
	int N = nextInt(getchar());
	// Reading x-coordinate, left-endpoint, and right-endpoint of each segment from the input and storing it in 'ps' vector
	for (int i = 0; i < N; i++) {
		int x = nextInt(getchar());
		int L = nextInt(getchar());
		point p;
		p.x = x;
		p.l = x - L;
		p.r = x + L;
		ps.push_back(p);
	}
	// Sorting 'ps' vector based on their right-endpoints
	sort(ps.begin(), ps.end(), [](point &p1, point &p2) {
		return p1.r < p2.r;
	});
	// Initializing variables for result calculation
	int start = ps[0].r;
	int ans = 1;
	// Iterating through all segments in sorted order and updating result accordingly
	for (int i = 0; i < ps.size(); i++) {
		// If the start of current segment is less than the end of previous segment, then skip it
		if (ps[i].l < start) {
			continue;
		}
		// Updating start to the end of current segment
		start = ps[i].r;
		// Incrementing answer by 1
		ans++;
	}
	// Printing the final answer
	printf("%d\n", ans);
	return 0;
}

// Adding a comment at the end of the code

