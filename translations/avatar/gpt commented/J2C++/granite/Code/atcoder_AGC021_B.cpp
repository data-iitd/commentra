
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // Create a Scanner object to read input from the user
    // (Note: Scanner is not available in C++, so we'll use cin instead)
    cin.tie(0);
    ios::sync_with_stdio(false);

    // Read the number of points N
    int N;
    cin >> N;

    // Initialize vectors to store the x and y coordinates of the points
    vector<int> x(N), y(N);

    // Read the coordinates of the points from user input
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
    }

    // Iterate over each point to calculate the angles with respect to other points
    for (int i = 0; i < N; ++i) {
        // Create a vector to store the angles (thetas) for the current point
        vector<double> thetas;

        // Calculate the angle between the current point and all other points
        for (int j = 0; j < N; ++j) {
            // Skip the current point itself
            if (i == j) continue;

            // Calculate the angle using atan2 and add it to the vector
            thetas.push_back(atan2(y[j] - y[i], x[j] - x[i]));
        }

        // Sort the angles in ascending order
        sort(thetas.begin(), thetas.end());

        // Add the angle that wraps around (2 * PI) to handle circularity
        thetas.push_back(thetas[0] + 2 * M_PI);

        // Initialize a variable to find the maximum angle difference
        double ans = 0;

        // Calculate the maximum angle difference between consecutive angles
        for (int k = 0; k < N - 1; ++k)
            ans = max(ans, thetas[k + 1] - thetas[k] - M_PI);

        // Output the result as a fraction of the full circle (2 * PI)
        cout << ans / (2 * M_PI) << endl;
    }

    return 0;
}
