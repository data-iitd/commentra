
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<double> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }
    for (int i = 0; i < N; i++) {
        vector<double> D(N - 1);
        for (int j = 0, k = 0; j < N; j++) {
            if (j == i) continue;
            D[k++] = atan2(Y[j] - Y[i], X[j] - X[i]);
        }
        sort(D.begin(), D.end());
        D.push_back(D[0] + 2 * M_PI);
        double ans = 0;
        for (int j = 0; j < N - 1; j++) {
            if (D[j + 1] - D[j] >= M_PI) {
                ans = max(ans, D[j + 1] - D[j] - M_PI);
            }
        }
        cout << ans / (2 * M_PI) << endl;
    }
    return 0;
}

