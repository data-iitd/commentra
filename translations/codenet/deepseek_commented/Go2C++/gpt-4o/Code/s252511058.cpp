#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// point represents a point with x, l (left boundary), and r (right boundary).
struct point {
    int x, l, r;
};

// Comparator to sort points by their right boundary.
bool compare(const point &a, const point &b) {
    return a.r < b.r;
}

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
    
    sort(points.begin(), points.end(), compare); // Sort the points by their right boundary.
    
    // Now we have a list of intervals. We need to select the maximum number of non-overlapping intervals.
    int start = points[0].r; // Initialize the start of the first interval.
    int ans = 1; // Initialize the answer (at least one interval is selected).
    
    for (int i = 1; i < points.size(); i++) {
        if (points[i].l < start) { // If the current interval overlaps with the previous one, skip it.
            continue;
        }
        start = points[i].r; // Move to the next interval.
        ans++; // Increment the count of selected intervals.
    }
    
    cout << ans << endl; // Print the number of selected intervals.
    return 0;
}

// <END-OF-CODE>
