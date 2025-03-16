
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function to calculate the Euclidean distance between two points
double dist(vector<double> x, vector<double> y) {
    double tmp = 0.0;
    // Calculate the squared differences for each dimension
    for (int i = 0; i < x.size(); i++) {
        tmp += pow(x[i] - y[i], 2);
    }
    // Return the square root of the sum of squared differences
    return sqrt(tmp);
}

int main() {
    int n, d;
    cin >> n >> d;  // Read the number of points (n) and the dimension (d) from input

    vector<vector<double>> points(n, vector<double>(d));
    // Read the coordinates of the points into a vector of vectors
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> points[i][j];
        }
    }

    int count = 0;  // Initialize a counter for pairs of points with integer distances

    // Iterate through each point and compare it with every other point
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if the distance between the two points is an integer
            if (dist(points[i], points[j]) == (int)dist(points[i], points[j])) {
                count++;  // Increment the count if the distance is an integer
            }
        }
    }

    // Print the total count of pairs with integer distances
    cout << count << endl;

    return 0;
}
