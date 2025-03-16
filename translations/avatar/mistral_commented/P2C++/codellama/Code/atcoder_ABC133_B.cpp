#include <iostream>
#include <cmath>

using namespace std;

// Defining a function 'dist' to calculate the Euclidean distance between two points
double dist(int x[], int y[]) {
    // Initializing a variable 'tmp' to store the sum of squared differences between corresponding elements of 'x' and 'y'
    double tmp = 0.0;

    // Iterating through each dimension 'i' from 0 to 'd'
    for (int i = 0; i < d; i++) {
        // Adding the square of the difference between the 'i'th elements of 'x' and 'y' to 'tmp'
        tmp += (x[i] - y[i]) * (x[i] - y[i]);
    }

    // Returning the square root of 'tmp' as the Euclidean distance between 'x' and 'y'
    return sqrt(tmp);
}

int main() {
    // Taking the number of points, n, and the number of dimensions, d, as input
    int n, d;
    cin >> n >> d;

    // Initializing a list 'points' of size 'n' to store the coordinates of each point
    int points[n][d];

    // Iterating through each point 'i' in 'points'
    for (int i = 0; i < n; i++) {
        // Iterating through each dimension 'j' from 0 to 'd'
        for (int j = 0; j < d; j++) {
            // Taking the 'j'th coordinate of the 'i'th point as input
            cin >> points[i][j];
        }
    }

    // Initializing a variable 'count' to store the number of distinct pairs of points with integer distance
    int count = 0;

    // Iterating through each point 'i' in 'points'
    for (int i = 0; i < n; i++) {
        // Iterating through each point 'j' from 'i+1' to the last point in 'points'
        for (int j = i + 1; j < n; j++) {
            // Checking if the Euclidean distance between 'points[i]' and 'points[j]' is an integer
            if (dist(points[i], points[j]) == (int) dist(points[i], points[j])) {
                // Incrementing the 'count' variable if the condition is true
                count++;
            }
        }
    }

    // Printing the final value of 'count'
    cout << count << endl;

    return 0;
}

