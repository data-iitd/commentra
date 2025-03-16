#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Extract fractional parts and sort them
    sort(arr.begin(), arr.end(), [](double x, double y) { return x - int(x) < y - int(y); });

    // Calculate the number of elements to be added to make the total number of elements equal to 2 * n
    int o = 2 * n - arr.size();

    // Sum of the sorted fractional parts
    double arr_sum = accumulate(arr.begin(), arr.end(), 0.0);

    // Initialize the result variable to a very large number
    double res = 1e9;

    // Iterate to find the best position
    for (int i = 0; i <= n; i++) {
        if (i + o >= n) {
            res = min(res, abs(i - arr_sum));
        }
    }

    // Print the result with three decimal places
    cout << fixed << setprecision(3) << res << endl;

    return 0;
}

