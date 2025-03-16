#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read the input from standard input and parse it into two variables: N (number of points) and XY (a vector of pairs representing the coordinates of N points)
    int N;
    cin >> N;
    vector<pair<int, int>> XY(N);
    for (int i = 0; i < N; i++) {
        cin >> XY[i].first >> XY[i].second;
    }

    // Transpose the XY vector so that it becomes a vector of vectors, where each inner vector contains the x and y coordinates of a point
    vector<vector<int>> XY_transposed(2, vector<int>(N));
    for (int i = 0; i < N; i++) {
        XY_transposed[0][i] = XY[i].first;
        XY_transposed[1][i] = XY[i].second;
    }

    // Iterate through each point in XY and calculate the angles between it and all other points
    for (int i = 0; i < N; i++) {
        // Calculate the differences between the x and y coordinates of the current point and all other points
        vector<double> D(N);
        for (int j = 0; j < N; j++) {
            if (i != j) {
                D[j] = atan2(XY_transposed[0][j] - XY_transposed[0][i], XY_transposed[1][j] - XY_transposed[1][i]);
            }
        }

        // Append the angle between the current point and the first point (wrapped around if it's greater than pi)
        D.push_back(D[0] + 2 * M_PI);

        // Sort the angles in ascending order
        sort(D.begin(), D.end());

        // Iterate through each pair of consecutive angles and calculate the area of the corresponding sector
        for (int j = 0; j < N; j++) {
            // If the angle between two consecutive points is greater than pi, subtract pi from it and add it to the answer
            if (D[j + 1] - D[j] >= M_PI) {
                ans += (D[j + 1] - D[j]) - M_PI;
            }
        }
    }

    // Print the answer, which is the total area of the sectors divided by the total possible area (2π)
    cout << fixed << setprecision(10) << ans / (2 * M_PI) << endl;

    return 0;
}

