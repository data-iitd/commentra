

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    // Recursively calculates the greatest common divisor (GCD) of a and b
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void ruiseki_lr(vector<int>& array) {
    // Defines a lambda function to compute GCD
    auto op = [](int a, int b) { return gcd(a, b); };
    // Length of the input array
    int n = array.size();
    // Initialize prefix and suffix GCD arrays
    vector<int> left(n + 1), right(n + 1);
    // Compute prefix GCD array
    for (int i = 0; i < n; i++) {
        left[i + 1] = op(left[i], array[i]);
    }
    // Compute suffix GCD array
    for (int i = n - 1; i >= 0; i--) {
        right[i] = op(right[i + 1], array[i]);
    }
    // Copy the GCD arrays to the original array
    copy(left.begin(), left.end(), array.begin());
    copy(right.begin(), right.end(), array.begin() + n);
}

int main() {
    // Read the number of elements
    int n;
    cin >> n;
    // Read the list of elements
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // Compute prefix and suffix GCD arrays
    ruiseki_lr(a);
    // Initialize the answer variable
    int ans = 0;
    // Iterate through the array to find the maximum GCD
    for (int i = 0; i < n; i++) {
        ans = max(gcd(a[i], a[n + i]), ans);
    }
    // Print the result
    cout << ans << endl;
    return 0;
}

