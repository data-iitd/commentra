
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<double> filtered;
    for (double num : arr) {
        if (num - int(num)!= 0) {
            filtered.push_back(num - int(num));
        }
    }

    sort(filtered.begin(), filtered.end());

    int o = 2 * n - filtered.size();
    double arr_sum = accumulate(filtered.begin(), filtered.end(), 0.0);

    int res = 2e9;
    for (int i = 0; i <= n; i++) {
        if (i + o >= n) {
            res = min(res, abs(i - arr_sum));
        }
    }

    cout << fixed << setprecision(3) << res << endl;

    return 0;
}
