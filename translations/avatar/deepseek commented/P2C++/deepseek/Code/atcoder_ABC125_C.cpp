#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to compute the greatest common divisor (GCD)
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to compute prefix and suffix GCD arrays
vector<int> ruiseki_lr(const vector<int>& array) {
    // Length of the input array
    int n = array.size();
    // Initialize prefix and suffix GCD arrays
    vector<int> left(n + 1, 0);
    vector<int> right(n + 1, 0);
    // Compute prefix GCD array
    for (int i = 0; i < n; ++i) {
        left[i + 1] = gcd(left[i], array[i]);
    }
    // Compute suffix GCD array
    for (int i = n - 1; i >= 0; --i) {
        right[i] = gcd(right[i + 1], array[i]);
    }
    return right;
}

int main() {
    // Read the number of elements
    int n;
    cin >> n;
    // Read the list of elements
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // Compute prefix and suffix GCD arrays
    vector<int> right = ruiseki_lr(a);
    // Initialize the answer variable
    int ans = 0;
    // Iterate through the array to find the maximum GCD
    for (int i = 0; i < n; ++i) {
        ans = max(gcd(a[i], right[i + 1]), ans);
    }
    // Print the result
    cout << ans << endl;
    return 0;
}
