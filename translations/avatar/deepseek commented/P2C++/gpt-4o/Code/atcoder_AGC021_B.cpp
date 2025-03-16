#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    // Step 1: Reading Input
    int N;
    cin >> N;
    vector<int> XY(2 * N);
    for (int i = 0; i < 2 * N; ++i) {
        cin >> XY[i];
    }

    // Step 2: Processing Coordinates
    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; ++i) {
        points[i] = {XY[2 * i], XY[2 * i + 1]};
    }

    // Step 3: Calculating Angles
    for (int i = 0; i < N; ++i) {
        double x = points[i].first;
        double y = points[i].second;
        vector<double> D;

        for (int j = 0; j < N; ++j) {
            if (j != i) {
                double angle = atan2(points[j].first - x, points[j].second - y);
                D.push_back(angle);
            }
        }

        // Step 4: Handling Circular Angles
        sort(D.begin(), D.end());
        D.push_back(D[0] + 2 * M_PI);

        // Step 5: Finding the Maximum Gap
        double ans = 0;
        for (size_t k = 0; k < D.size() - 1; ++k) {
            if (D[k + 1] - D[k] >= M_PI) {
                ans = max(ans, (D[k + 1] - D[k]) - M_PI);
            }
        }

        // Step 6: Calculating the Fraction
        cout << ans / (2 * M_PI) << endl;
    }

    return 0;
}

// <END-OF-CODE>
