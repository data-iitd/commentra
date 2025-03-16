
#include <iostream>
#include <cmath>

using namespace std;

const int inf = 10000000000;

int main() {
    int n;
    cin >> n; // Reading the size of the array

    int arrA[n];
    for (int i = 0; i < n; i++) {
        cin >> arrA[i]; // Reading the elements of the array
    }

    int cumSumA[n+1];
    cumSumA[0] = 0; // Initialize the cumulative sum array
    for (int i = 0; i < n; i++) {
        cumSumA[i+1] = cumSumA[i] + arrA[i]; // Calculate cumulative sums
    }

    int ans = inf; // Initialize the answer with a large number
    for (int i = 1; i < n; i++) {
        if (abs(cumSumA[n]-(cumSumA[i]*2)) < ans) {
            ans = abs(cumSumA[n] - cumSumA[i]*2); // Update the answer if a smaller difference is found
        }
    }

    cout << ans << endl; // Output the minimum difference

    return 0;
}

