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

    for (int i = 0; i < N; i++) {
        double ans = 0;
        vector<double> D(N);
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            D[j] = atan2(XY[j].first - XY[i].first, XY[j].second - XY[i].second);
        }
        sort(D.begin(), D.end());
        D.push_back(D[0] + 2 * M_PI);
        for (int j = 0; j < N; j++) {
            if (j == N - 1) break;
            ans += (D[j + 1] - D[j] >= M_PI)? (D[j + 1] - D[j] - M_PI) : 0;
        }
        cout << ans / (2 * M_PI) << '\n';
    }

    return 0;
}

