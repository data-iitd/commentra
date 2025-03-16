#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // Read the number of points (n) and the dimension (d) from input
    int n, d;
    cin >> n >> d;

    // Read the coordinates of the points into a list
    vector<vector<int>> points(n, vector<int>(d));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> points[i][j];
        }
    }

    // Define a function to calculate the Euclidean distance between two points
    double dist(vector<int> x, vector<int> y) {
        double tmp = 0.0;
        // Calculate the squared differences for each dimension
        for (int i = 0; i < d; i++) {
            tmp += pow(x[i] - y[i], 2);
        }
        // Return the square root of the sum of squared differences
        return sqrt(tmp);
    }

    // Initialize a counter for pairs of points with integer distances
    int count = 0;

    // Iterate through each point and compare it with every other point
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if the distance between the two points is an integer
            if (dist(points[i], points[j]).is_integer()) {
                count++;  // Increment the count if the distance is an integer
            }
        }
    }

    // Print the total count of pairs with integer distances
    cout << count << endl;

    return 0;
}

