
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] -= int(arr[i]);
    }
    sort(arr.begin(), arr.end());
    int o = 2 * n - count(arr.begin(), arr.end(), 0);
    double arr_sum = accumulate(arr.begin(), arr.end(), 0.0);
    double res = 2e9;
    for (int i = 0; i <= n; i++) {
        if (i + o >= n) {
            res = min(res, abs(i - arr_sum));
        }
    }
    cout << fixed << setprecision(3) << res << endl;
    return 0;
}

