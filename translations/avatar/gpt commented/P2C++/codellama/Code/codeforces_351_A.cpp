#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<float> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<float> arr_fractional;
    for (int i = 0; i < n; i++) {
        if (arr[i] - floor(arr[i]) != 0) {
            arr_fractional.push_back(arr[i] - floor(arr[i]));
        }
    }

    int o = 2 * n - arr_fractional.size();
    float arr_sum = accumulate(arr_fractional.begin(), arr_fractional.end(), 0.0);

    int res = 2e9;
    for (int i = 0; i <= n; i++) {
        if (i + o >= n) {
            res = min(res, abs(i - arr_sum));
        }
    }

    cout << fixed << setprecision(3) << res << endl;

    return 0;
}

