#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    for (int i = 0; i < N; ++i) {
        double x = points[i].first;
        double y = points[i].second;

        vector<double> angles;
        for (int j = 0; j < N; ++j) {
            if (j != i) {
                double angle = atan2(points[j].second - y, points[j].first - x);
                angles.push_back(angle);
            }
        }

        // Sort the angles
        sort(angles.begin(), angles.end());

        // Append the angle that wraps around (2*pi)
        angles.push_back(angles[0] + 2 * M_PI);

        double ans = 0;

        // Calculate the gaps between consecutive angles
        for (size_t k = 0; k < angles.size() - 1; ++k) {
            double gap = angles[k + 1] - angles[k];
            if (gap >= M_PI) {
                ans = max(ans, gap - M_PI);
            }
        }

        // Print the normalized answer (as a fraction of 2*pi)
        cout << ans / (2 * M_PI) << endl;
    }

    return 0;
}

// <END-OF-CODE>
