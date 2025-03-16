#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n; // Reading the size of the array

    vector<int> arrA(n);
    for (int i = 0; i < n; i++) {
        cin >> arrA[i]; // Reading the elements of the array
    }

    vector<int> cumSumA(n + 1, 0); // Initialize the cumulative sum array with 0
    for (int i = 0; i < n; i++) {
        cumSumA[i + 1] = cumSumA[i] + arrA[i]; // Calculate cumulative sums
    }

    double ans = INT_MAX; // Initialize the answer with a large number
    for (int i = 1; i < n; i++) {
        double diff = abs(static_cast<double>(cumSumA[n] - 2 * cumSumA[i]));
        if (diff < ans) {
            ans = diff; // Update the answer if a smaller difference is found
        }
    }

    cout << static_cast<int>(ans) << endl; // Output the minimum difference

    return 0;
}
