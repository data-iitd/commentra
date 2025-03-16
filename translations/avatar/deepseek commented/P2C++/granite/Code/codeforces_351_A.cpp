
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;  // Input the number of elements (n)

    vector<double> arr(n);  // Input the array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Extract fractional parts and sort them
    vector<double> temp;
    for (int i = 0; i < n; i++) {
        double f = arr[i] - floor(arr[i]);
        if (f!= 0) {
            temp.push_back(f);
        }
    }
    sort(temp.begin(), temp.end());

    // Calculate the number of elements to be added to make the total number of elements equal to 2 * n
    int o = 2 * n - temp.size();

    // Sum of the sorted fractional parts
    double arr_sum = 0;
    for (int i = 0; i < temp.size(); i++) {
        arr_sum += temp[i];
    }

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
