#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate the Euclidean distance between two points
double dist(const vector<int>& x, const vector<int>& y) {
    double tmp = 0.0;
    // Calculate the squared differences for each dimension
    for (size_t i = 0; i < x.size(); ++i) {
        tmp += (x[i] - y[i]) * (x[i] - y[i]);
    }
    // Return the square root of the sum of squared differences
    return sqrt(tmp);
}

int main() {
    // Read the number of points (n) and the dimension (d) from input
    int n, d;
    cin >> n >> d;

    // Read the coordinates of the points into a vector
    vector<vector<int>> points(n, vector<int>(d));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cin >> points[i][j];
        }
    }

    // Initialize a counter for pairs of points with integer distances
    int count = 0;

    // Iterate through each point and compare it with every other point
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // Check if the distance between the two points is an integer
            if (dist(points[i], points[j]) == static_cast<int>(dist(points[i], points[j]))) {
                count++;  // Increment the count if the distance is an integer
            }
        }
    }

    // Print the total count of pairs with integer distances
    cout << count << endl;

    return 0;
}

// <END-OF-CODE>
