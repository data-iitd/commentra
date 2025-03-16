#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

const double pi = acos(-1.0);

int main() {
    int N;
    cin >> N;
    vector<pair<double, double>> XY;
    for (int i = 0; i < N; ++i) {
        double x, y;
        cin >> x >> y;
        XY.emplace_back(x, y);
    }

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
        angles.push_back(angles[0] + 2 * pi);

        double ans = 0;
        for (int k = 0; k < angles.size(); ++k) {
            double diff = angles[k + 1] - angles[k];
            if (diff >= M_PI) {
                ans = max(ans, diff - M_PI);
            }
        }
        cout << fixed << setprecision(10) << ans / (2 * pi) << endl;
    }

    return 0;
}

