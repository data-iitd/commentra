#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int N; cin >> N;
    vector<pair<int, int>> XY(N);
    for (int i = 0; i < N; i++) cin >> XY[i].first >> XY[i].second;

    for (int i = 0; i < N; i++) {
        vector<double> D(N);
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            int x = XY[i].first, y = XY[i].second;
            int X = XY[j].first, Y = XY[j].second;
            D[j] = atan2(X - x, Y - y);
        }
        sort(D.begin(), D.end());
        D.push_back(D[0] + 2 * M_PI);
        double ans = 0;
        for (int j = 0; j < N; j++) {
            double a = D[j], b = D[(j + 1) % N];
            if (b - a >= M_PI) ans += (b - a) - M_PI;
        }
        cout << ans / (2 * M_PI) << '\n';
    }

    return 0;
}

