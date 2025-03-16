
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Run function reads input from the reader, processes it, and writes the output to the writer.
void Run(istream& reader, ostream& writer) {
	// Read the first line which contains two integers N and D.
	int N, D;
	reader >> N >> D;

	// Read the next N lines which contain pairs of integers representing points.
	vector<pair<int, int>> points;
	for (int i = 0; i < N; i++) {
		int x, y;
		reader >> x >> y;
		points.push_back(make_pair(x, y));
	}

	// Initialize a counter to keep track of points within the given distance.
	int count = 0;

	// Iterate over each point and calculate the distance from the origin.
	for (auto point : points) {
		// Calculate the Euclidean distance of the point from the origin.
		double d = sqrt(point.first * point.first + point.second * point.second);
		// Check if the distance is within the given limit.
		if (D >= d) {
			count++;
		}
	}

	// Write the count of points within the distance to the writer.
	writer << count << endl;
}

// main function initializes the Run function with cin and cout.
int main() {
	Run(cin, cout);
	return 0;
}

