#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate the Euclidean distance between two points
double dist(const vector<int>& x, const vector<int>& y) {
    double tmp = 0.0;

    // Iterating through each dimension
    for (size_t i = 0; i < x.size(); ++i) {
        // Adding the square of the difference between the corresponding elements
        tmp += (x[i] - y[i]) * (x[i] - y[i]);
    }

    // Returning the square root of the sum of squared differences
    return sqrt(tmp);
}

int main() {
    // Taking the number of points, n, and the number of dimensions, d, as input
    int n, d;
    cin >> n >> d;

    // Initializing a vector 'points' to store the coordinates of each point
    vector<vector<int>> points(n, vector<int>(d));

    // Taking the coordinates of each point as input
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cin >> points[i][j];
        }
    }

    // Initializing a variable 'count' to store the number of distinct pairs of points with integer distance
    int count = 0;

    // Iterating through each point
    for (int i = 0; i < n; ++i) {
        // Iterating through each point from i+1 to the last point
        for (int j = i + 1; j < n; ++j) {
            // Checking if the Euclidean distance between points[i] and points[j] is an integer
            if (dist(points[i], points[j]) == floor(dist(points[i], points[j]))) {
                // Incrementing the count variable if the condition is true
                count++;
            }
        }
    }

    // Printing the final value of count
    cout << count << endl;

    return 0;
}

// <END-OF-CODE>
