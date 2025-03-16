#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    double arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int o = 2 * n - count_if(arr, arr + n, [](double x) { return x - int(x) != 0; });
    double arr_sum = accumulate(arr, arr + n, 0.0);
    double res = 2e9;
    for (int i = 0; i < n + 1; i++) {
        if (i + o >= n) {
            res = min(res, abs(i - arr_sum));
        }
    }
    cout << fixed << setprecision(3) << res << endl;
    return 0;
}

