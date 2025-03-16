#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // Step 1: Read the number of points N from the input.
    int N;
    cin >> N;

    // Step 2: Read the coordinates of each point and store them in vectors x and y.
    vector<int> x(N), y(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
    }

    // Step 3: For each point, calculate the angles between this point and all other points.
    for (int i = 0; i < N; ++i) {
        vector<double> thetas;
        for (int j = 0; j < N; ++j) {
            if (i == j) continue; // Skip the point itself
            // Calculate the angle using atan2
            thetas.push_back(atan2(y[j] - y[i], x[j] - x[i]));
        }

        // Step 4: Sort the angles and add 2π to the last angle to handle the wrap-around.
        sort(thetas.begin(), thetas.end());
        thetas.push_back(thetas[0] + 2 * M_PI);

        // Step 5: Find the maximum difference between consecutive angles, subtract π, and divide by 2π to get the fraction of the circle.
        double ans = 0;
        for (int k = 0; k < N - 1; ++k) {
            ans = max(ans, thetas[k + 1] - thetas[k] - M_PI);
        }

        // Step 6: Print the result.
        cout << ans / (M_PI * 2) << endl;
    }

    return 0;
}

// <END-OF-CODE>
