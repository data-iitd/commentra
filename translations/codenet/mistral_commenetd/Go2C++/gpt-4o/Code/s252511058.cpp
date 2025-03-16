#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Defining a structure 'point' for storing x-coordinate, left-endpoint, and right-endpoint of a segment
struct point {
    int x, l, r;
};

// Custom comparator for sorting points based on their right-endpoints
bool compare(const point &a, const point &b) {
    return a.r < b.r;
}

int main() {
    // Reading the number of segments N from the input
    int N;
    cin >> N;
    // Creating a vector 'points' of type 'point' to store all segments
    vector<point> points(N);
    // Reading x-coordinate, left-endpoint, and right-endpoint of each segment from the input and storing it in 'points' vector
    for (int i = 0; i < N; i++) {
        cin >> points[i].x;
        int L;
        cin >> L;
        // Calculating left and right endpoints of the segment based on x-coordinate and left-endpoint
        points[i].l = points[i].x - L;
        points[i].r = points[i].x + L;
    }
    // Sorting 'points' vector based on their right-endpoints
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

    return 0;
}

// <END-OF-CODE>
