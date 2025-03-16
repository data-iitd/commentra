#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read an integer input for the number of elements
    int n;
    cin >> n;

    // Read a line of space-separated floats and convert them to a list of floats
    vector<float> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Calculate the fractional parts of the elements, excluding whole numbers
    vector<float> arr_frac;
    for (float x : arr) {
        if (x - int(x)!= 0) {
            arr_frac.push_back(x - int(x));
        }
    }

    // Calculate the number of whole numbers that can be added to the fractional parts
    int o = 2 * n - arr_frac.size();

    // Calculate the sum of the fractional parts
    float arr_sum = 0;
    for (float x : arr_frac) {
        arr_sum += x;
    }

    // Initialize the result with a large number
    int res = 2e9;

    // Iterate through possible counts of fractional parts used
    for (int i = 0; i <= n; i++) {
        // Check if the current count of fractional parts plus whole numbers is sufficient
        if (i + o >= n) {
            // Update the result with the minimum difference found
            res = min(res, abs(i - arr_sum));
        }
    }

    // Print the result formatted to three decimal places
    cout << fixed << setprecision(3) << res << endl;

    return 0;
}

