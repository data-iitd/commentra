#include <bits/stdc++.h>
using namespace std;

int main() {
    // Take an integer input 'n' from the user
    int n;
    cin >> n;

    // Take 'n' floating point numbers as input and store them in a list 'arr'
    vector<float> arr;
    for (int i = 0; i < n; i++) {
        float x;
        cin >> x;
        arr.push_back(x);
    }

    // Filter out the integers from the list 'arr' and sort the remaining floating point numbers
    vector<float> arr_flt;
    for (float x : arr) {
        if (x - int(x)!= 0) {
            arr_flt.push_back(x - int(x));
        }
    }
    sort(arr_flt.begin(), arr_flt.end());

    // Calculate the length of the filtered list 'arr' and assign it to the variable 'o'
    int o = 2 * n - arr_flt.size();

    // Calculate the sum of all the floating point numbers in the list 'arr' and assign it to the variable 'arr_sum'
    float arr_sum = 0;
    for (float x : arr) {
        arr_sum += x;
    }

    // Initialize the variable'res' with a large integer value
    float res = 2e9;

    // Iterate through the range from 0 to n+1
    for (int i = 0; i <= n; i++) {
        // Check if the index 'i' plus the offset 'o' is greater than or equal to 'n'
        if (i + o >= n) {
            // Update the minimum value of'res' with the absolute difference between 'i' and 'arr_sum'
            res = min(res, abs(i - arr_sum));
        }
    }

    // Print the result with three decimal places
    cout << fixed << setprecision(3) << res << endl;

    return 0;
}

