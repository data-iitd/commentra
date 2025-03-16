// Importing necessary C++ standard library headers
#include <iostream>  // For input and output
#include <vector>   // For using vectors
#include <algorithm> // For sorting the vector
#include <cmath>    // For mathematical functions

using namespace std; // To avoid using std:: prefix

// Main function where the program starts
int main() {
    // Creating a variable for reading input from the console
    int N;
    cin >> N; // Reading the number of points (N)

    // Creating two vectors, x and y, for storing the x and y coordinates of the points respectively
    vector<int> x(N);
    vector<int> y(N);

    // Reading the x and y coordinates of each point and storing them in the respective vectors
    for (int i = 0; i < N; ++i) {
        cin >> x[i]; // Reading the x coordinate
        cin >> y[i]; // Reading the y coordinate
    }

    // Finding the maximum angle between consecutive angles
    double ans = 0;

    // Calculating the angles between each pair of points
    for (int i = 0; i < N; ++i) {
        vector<double> thetas; // Creating a vector for storing the angles

        // Calculating the angles between the current point and all other points
        for (int j = 0; j < N; ++j) {
            if (i == j) continue; // Skip if the current point is the same as the other point

            // Calculating the angle using the atan2 function
            thetas.push_back(atan2(y[j] - y[i], x[j] - x[i]));
        }

        // Sorting the vector of angles in ascending order
        sort(thetas.begin(), thetas.end());

        // Adding the angle between the last point and the first point (wrapped around 2π) to the vector
        thetas.push_back(thetas[0] + 2 * M_PI);

        // Finding the maximum angle between consecutive angles
        for (size_t k = 0; k < thetas.size() - 1; ++k) {
            ans = max(ans, thetas[k + 1] - thetas[k] - M_PI);
        }
    }

    // Printing the answer
    cout << ans / (M_PI * 2) << endl;

    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
