#include <bits/stdc++.h>

using namespace std;

int main() {
    // Reading the number of points (N) from the input
    int N;
    cin >> N;

    // Creating two arrays, x and y, of size N for storing the x and y coordinates of the points respectively
    int x[N], y[N];

    // Reading the x and y coordinates of each point and storing them in the respective arrays
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
    }

    // Calculating the angles between each pair of points and storing them in a list called thetas
    for (int i = 0; i < N; ++i) {
        vector<double> thetas;  // Creating a new vector for storing the angles

        // Calculating the angles between the current point and all other points
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;  // Skip if the current point is the same as the other point

            // Calculating the angle using the atan2 function
            thetas.push_back(atan2(y[j] - y[i], x[j] - x[i]));
        }

        // Sorting the list of angles in ascending order
        sort(thetas.begin(), thetas.end());

        // Adding the angle between the last point and the first point (wrapped around 2π) to the list
        thetas.push_back(thetas.front() + 2 * M_PI);
    }

    // Finding the maximum angle between consecutive angles and calculating the answer
    double ans = 0;
    for (int k = 0; k < N - 1; ++k) {
        ans = max(ans, thetas[k + 1] - thetas[k] - M_PI);
    }

    // Printing the answer
    cout << ans / (M_PI * 2) << endl;
}

