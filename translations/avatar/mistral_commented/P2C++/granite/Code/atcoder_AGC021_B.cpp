
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<double, double>> XY(N);
    for (int i = 0; i < N; i++) {
        cin >> XY[i].first >> XY[i].second;
    }

    vector<double> D(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            D[i] = atan2(XY[j].first - XY[i].first, XY[j].second - XY[i].second);
        }
        sort(D.begin(), D.end());
        D.push_back(D[0] + 2 * M_PI);
    }

    double ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (D[j + 1] - D[j] >= M_PI) {
                ans += D[j + 1] - D[j] - M_PI;
            }
        }
    }

    cout << ans / (2 * M_PI) << endl;

    return 0;
}
