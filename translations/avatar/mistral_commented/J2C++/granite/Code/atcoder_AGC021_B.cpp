
// Importing necessary C++ utility classes
#include <iostream>  // For reading input from the console
#include <algorithm>  // For sorting the list of thetas
#include <vector>  // For creating and manipulating vectors
#include <cmath>  // For calculating the angle using the atan2 function

// Main method where the program starts
int main() {
    // Creating a Scanner object for reading input from the console
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cin.exceptions(std::ios::badbit);

    // Reading the number of points (N) from the input
    int N;
    std::cin >> N;

    // Creating two vectors, x and y, of size N for storing the x and y coordinates of the points respectively
    std::vector<int> x(N);
    std::vector<int> y(N);

    // Reading the x and y coordinates of each point and storing them in the respective vectors
    for (int i = 0; i < N; ++i) {
        std::cin >> x[i] >> y[i];  // Reading the x and y coordinates
    }

    // Calculating the angles between each pair of points and storing them in a vector called thetas
    std::vector<double> thetas;
    for (int i = 0; i < N; ++i) {
        thetas.clear();  // Clearing the list of angles for the current point

        // Calculating the angles between the current point and all other points
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;  // Skip if the current point is the same as the other point

            // Calculating the angle using the atan2 function
            thetas.push_back(std::atan2(y[j] - y[i], x[j] - x[i]));
        }

        // Sorting the list of angles in ascending order
        std::sort(thetas.begin(), thetas.end());

        // Adding the angle between the last point and the first point (wrapped around 2π) to the list
        thetas.push_back(thetas[0] + 2 * M_PI);
    }

    // Finding the maximum angle between consecutive angles and calculating the answer
    double ans = 0;
    for (int k = 0; k < N - 1; ++k) {
        ans = std::max(ans, thetas[k + 1] - thetas[k] - M_PI);
    }

    // Printing the answer
    std::cout << std::fixed << std::setprecision(10) << ans / (2 * M_PI) << '\n';

    return 0;
}
