#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    double result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double distance = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
            result += distance;
        }
    }
    result /= N * (N - 1) / 2;
    cout << fixed << setprecision(10) << result << endl;
    return 0;
}
