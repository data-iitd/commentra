#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// point struct represents a point with its position and its left and right bounds.
struct point {
    int x, l, r; // x is the position, l is the left bound, r is the right bound
};

// Comparator to sort points by their right bound
bool compare(const point &a, const point &b) {
    return a.r < b.r; // Sort by the right bound
}

int main() {
    int N;
    cin >> N; // Read the number of points
    vector<point> points(N); // Create a vector to hold the points

    // Read each point's position and calculate its left and right bounds
    for (int i = 0; i < N; i++) {
        cin >> points[i].x; // Read the position of the point
        int L;
        cin >> L; // Read the length to calculate bounds
        points[i].l = points[i].x - L; // Calculate the left bound
        points[i].r = points[i].x + L; // Calculate the right bound
    }

    // Sort the points based on their right bounds
    sort(points.begin(), points.end(), compare);

    // Initialize the scheduling process for the interval scheduling problem
    int start = points[0].r; // Start with the right bound of the first point
    int ans = 1; // Initialize the count of non-overlapping intervals

    // Iterate through the sorted points to count non-overlapping intervals
    for (int i = 0; i < points.size(); i++) {
        if (points[i].l < start) { // If the left bound overlaps with the current start
            continue; // Skip to the next point
        }
        start = points[i].r; // Update the start to the right bound of the current point
        ans++; // Increment the count of non-overlapping intervals
    }

    // Output the total number of non-overlapping intervals
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
