#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> XY(N);
    for (int i = 0; i < N; ++i) {
        cin >> XY[i].first >> XY[i].second;
    }

    for (int i = 0; i < N; ++i) {
        double x = XY[i].first;
        double y = XY[i].second;
        vector<double> D;

        for (int j = 0; j < N; ++j) {
            if (j != i) {
                double angle = atan2(XY[j].first - x, XY[j].second - y);
                D.push_back(angle);
            }
        }

        sort(D.begin(), D.end());
        D.push_back(D[0] + 2 * M_PI); // M_PI is the constant for π

        double ans = 0;
        for (size_t k = 0; k < D.size() - 1; ++k) {
            double a = D[k];
            double b = D[k + 1];
            if (b - a >= M_PI) {
                ans = (b - a) - M_PI;
            }
        }

        cout << ans / (2 * M_PI) << endl;
    }

    return 0;
}

// <END-OF-CODE>
