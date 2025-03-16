

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> arr(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> arr[i];
    }
    double sum_before = 0, sum = 0;
    int non_int = 0;
    for (int i = 0; i < 2 * n; i++) {
        sum_before += arr[i];
        if (arr[i]!= floor(arr[i])) {
            non_int++;
        }
        sum += floor(arr[i]);
    }
    double max_sum = min(n, non_int) + sum;
    double min_sum = max(0, non_int - n) + sum;
    double ans;
    if (min_sum > sum_before) {
        ans = min_sum - sum_before;
    } else if (max_sum < sum_before) {
        ans = sum_before - max_sum;
    } else {
        double x = sum_before - floor(sum_before);
        ans = min(1 - x, x);
    }
    cout << fixed << setprecision(3) << ans << endl;
    return 0;
}
