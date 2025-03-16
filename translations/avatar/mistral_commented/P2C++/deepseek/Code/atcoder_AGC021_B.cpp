#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<double, double>> XY(N);
    for (auto& p : XY) {
        cin >> p.first >> p.second;
    }

    double ans = 0.0;
    for (int i = 0; i < N; ++i) {
        vector<double> angles;
        for (int j = 0; j < N; ++j) {
            if (i != j) {
                double dx = XY[j].first - XY[i].first;
                double dy = XY[j].second - XY[i].second;
                angles.push_back(atan2(dy, dx));
            }
        }
        sort(angles.begin(), angles.end());
        for (int k = 0; k < angles.size(); ++k) {
            angles.push_back(angles[k] + 2 * M_PI);
        }
        for (int k = 0; k < angles.size(); ++k) {
            auto it = lower_bound(angles.begin(), angles.end(), angles[k] + M_PI);
            double angle = *it - angles[k];
            if (angle > M_PI) {
                angle = 2 * M_PI - angle;
            }
            ans += angle;
        }
    }
    cout << fixed << setprecision(10) << ans / (2 * M_PI) << endl;
    return 0;
}

