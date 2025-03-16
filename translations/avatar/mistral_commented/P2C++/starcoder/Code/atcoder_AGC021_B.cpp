#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> XY(N);
    for (int i = 0; i < N; i++) {
        cin >> XY[i].first >> XY[i].second;
    }

    vector<double> D(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            D[i] += atan2(XY[j].first - XY[i].first, XY[j].second - XY[i].second);
        }
        D[i] = fmod(D[i], 2 * M_PI);
    }

    double ans = 0;
    for (int i = 0; i < N; i++) {
        ans += (D[i] - D[(i + 1) % N] + M_PI) % (2 * M_PI) - M_PI;
    }

    cout << ans / (2 * M_PI) << "\n";

    return 0;
}

