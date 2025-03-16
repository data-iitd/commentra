
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<double> frac;
    for (int i = 0; i < n; i++) {
        double f = arr[i] - floor(arr[i]);
        if (f!= 0) {
            frac.push_back(f);
        }
    }

    sort(frac.begin(), frac.end());

    int o = 2 * n - frac.size();

    double sum = 0;
    for (int i = 0; i < frac.size(); i++) {
        sum += frac[i];
    }

    double res = 1e9;
    for (int i = 0; i <= n; i++) {
        if (i + o >= n) {
            res = min(res, abs(i - sum));
        }
    }

    cout << fixed << setprecision(3) << res << endl;

    return 0;
}
