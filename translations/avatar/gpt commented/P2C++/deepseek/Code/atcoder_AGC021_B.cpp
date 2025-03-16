#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<double, double>> XY;
    for (int i = 0; i < N; ++i) {
        double x, y;
        cin >> x >> y;
        XY.emplace_back(x, y);
    }

    const double pi = acos(-1.0);

    for (int i = 0; i < N; ++i) {
        vector<double> D;
        for (int j = 0; j < N; ++j) {
            if (i != j) {
                double dx = XY[j].first - XY[i].first;
                double dy = XY[j].second - XY[i].second;
                D.push_back(atan2(dy, dx));
            }
        }
        sort(D.begin(), D.end());
        D.push_back(D[0] + 2 * pi);

        double ans = 0;
        for (int k = 0; k < D.size() - 1; ++k) {
            double a = D[k];
            double b = D[k + 1];
            if (b - a >= pi) {
                ans = max(ans, (b - a) - pi);
            }
        }
        cout << fixed << setprecision(12) << ans / (2 * pi) << endl;
    }

    return 0;
}

