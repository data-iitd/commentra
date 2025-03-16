#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    // Read the input from standard input
    int N;
    cin >> N;

    // Read the coordinates into a vector of pairs
    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Initialize a variable to store the answer
    double ans = 0;

    // Iterate through each point in points
    for (int i = 0; i < N; ++i) {
        vector<double> D;

        // Calculate the angles between the current point and all other points
        for (int j = 0; j < N; ++j) {
            if (j != i) {
                double angle = atan2(points[j].first - points[i].first, points[j].second - points[i].second);
                D.push_back(angle);
            }
        }

        // Sort the angles
        sort(D.begin(), D.end());

        // Append the angle between the current point and the first point (wrapped around if it's greater than pi)
        D.push_back(D[0] + 2 * M_PI);

        // Iterate through each pair of consecutive angles
        for (size_t k = 0; k < D.size() - 1; ++k) {
            double a = D[k];
            double b = D[k + 1];

            // If the angle between two consecutive points is greater than pi, subtract pi from it and add it to the answer
            if (b - a >= M_PI) {
                ans += (b - a) - M_PI;
            }
        }
    }

    // Print the answer, which is the total area of the sectors divided by the total possible area (2π)
    cout << ans / (2 * M_PI) << endl;

    return 0;
}

// <END-OF-CODE>
