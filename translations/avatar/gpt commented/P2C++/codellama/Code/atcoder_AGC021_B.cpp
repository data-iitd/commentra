#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> XY(N);
    for (int i = 0; i < N; i++) {
        cin >> XY[i].first >> XY[i].second;
    }
    for (int i = 0; i < N; i++) {
        vector<double> D;
        for (int j = 0; j < N; j++) {
            if (i != j) {
                D.push_back(atan2(XY[j].first - XY[i].first, XY[j].second - XY[i].second));
            }
        }
        sort(D.begin(), D.end());
        D.push_back(D[0] + 2 * M_PI);
        double ans = 0;
        for (int j = 0; j < D.size() - 1; j++) {
            if (D[j + 1] - D[j] >= M_PI) {
                ans = D[j + 1] - D[j] - M_PI;
            }
        }
        cout << ans / (2 * M_PI) << endl;
    }
    return 0;
}

