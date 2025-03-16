#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate the Euclidean distance between two points
double dist(const vector<int>& x, const vector<int>& y) {
    double tmp = 0.0;
    for (size_t i = 0; i < x.size(); ++i) {
        tmp += (x[i] - y[i]) * (x[i] - y[i]);
    }
    return sqrt(tmp);
}

int main() {
    // Read the number of points and the dimension from the input
    int n, d;
    cin >> n >> d;

    // Read n points, each with d coordinates, and store them in a vector called points
    vector<vector<int>> points(n, vector<int>(d));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cin >> points[i][j];
        }
    }

    // Initialize a counter to keep track of pairs with integer distances
    int count = 0;

    // Iterate over all pairs of points
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // Check if the distance between the two points is an integer
            if (dist(points[i], points[j]) == floor(dist(points[i], points[j]))) {
                count++;
            }
        }
    }

    // Print the total count of pairs with integer distances
    cout << count << endl;

    return 0;
}

// <END-OF-CODE>
