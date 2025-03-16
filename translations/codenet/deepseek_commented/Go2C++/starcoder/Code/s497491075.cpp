#include <bits/stdc++.h>

using namespace std;

// Run function reads input from the reader, processes it, and writes the output to the writer.
void Run(std::istream& r, std::ostream& w) {
	// Read the first line which contains two integers N and D.
	int N, D;
	r >> N >> D;

	// Read the next N lines which contain pairs of integers representing points.
	vector<vector<int>> lines(N);
	for (int i = 0; i < N; i++) {
		int x, y;
		r >> x >> y;
		lines[i] = {x, y};
	}

	// Initialize a counter to keep track of points within the given distance.
	int count = 0;

	// Iterate over each point and calculate the distance from the origin.
	for (auto line : lines) {
		// Calculate the Euclidean distance of the point from the origin.
		double d = sqrt(pow(line[0], 2) + pow(line[1], 2));
		// Check if the distance is within the given limit.
		if (D >= d) {
			count++;
		}
	}

	// Write the count of points within the distance to the writer.
	w << count << endl;
}

// main function initializes the Run function with cin and cout.
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	Run(std::cin, std::cout);
}

