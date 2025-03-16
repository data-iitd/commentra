#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> x(N);
    vector<int> y(N);

    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
    }

    vector<double> thetas;

    for (int i = 0; i < N; ++i) {
        thetas.clear();

        for (int j = 0; j < N; ++j) {
            if (i == j) continue;

            double angle = atan2(y[j] - y[i], x[j] - x[i]);
            thetas.push_back(angle);
        }

        sort(thetas.begin(), thetas.end());

        for (int k = 0; k < thetas.size(); ++k) {
            thetas.push_back(thetas[k] + 2 * M_PI);
        }

        double ans = 0;
        for (int k = 0; k < thetas.size() - 1; ++k) {
            ans = max(ans, thetas[k + 1] - thetas[k] - M_PI);
        }

        cout << fixed << setprecision(10) << ans / (M_PI * 2) << endl;
    }

    return 0;
}
