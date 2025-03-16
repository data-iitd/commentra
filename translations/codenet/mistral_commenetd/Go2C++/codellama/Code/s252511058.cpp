
#include <bits/stdc++.h>
using namespace std;

// Defining a custom type 'point' for storing x-coordinate, left-endpoint, and right-endpoint of a segment
struct point {
    int x, l, r;
};

// Defining a vector 'points' of type 'point' for storing all segments in sorted order based on their right-endpoints
vector<point> points;

// Defining a function 'nextInt' for reading input from standard input
int nextInt(istream& sc) {
    int t;
    sc >> t;
    return t;
}

// Defining a function 'sortPoints' for sorting 'points' vector based on their right-endpoints
bool sortPoints(point a, point b) {
    return a.r < b.r;
}

// Defining a function 'main' for the program
int main() {
    // Initializing scanner for reading input from standard input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Reading the number of segments N from the input
    int N = nextInt(cin);
    // Reading x-coordinate, left-endpoint, and right-endpoint of each segment from the input and storing it in 'points' vector
    for (int i = 0; i < N; i++) {
        point p;
        p.x = nextInt(cin);
        int L = nextInt(cin);
        p.l = p.x - L;
        p.r = p.x + L;
        points.push_back(p);
    }
    // Sorting 'points' vector based on their right-endpoints
    sort(points.begin(), points.end(), sortPoints);
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

// Adding a comment at the end of the code


