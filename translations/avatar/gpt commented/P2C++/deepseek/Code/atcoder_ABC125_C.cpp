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

// Function to compute cumulative GCD from the left and right
vector<int> ruiseki_lr(const vector<int>& array) {
    int n = array.size();
    vector<int> left(n + 1, 0);
    vector<int> right(n + 1, 0);

    // Calculate cumulative GCD from the left
    for (int i = 0; i < n; ++i) {
        left[i + 1] = gcd(left[i], array[i]);
    }

    // Calculate cumulative GCD from the right
    for (int i = n - 1; i >= 0; --i) {
        right[i] = gcd(right[i + 1], array[i]);
    }

    return right;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Compute the cumulative GCD from the left and right
    vector<int> right = ruiseki_lr(a);

    // Initialize the answer variable to store the maximum GCD found
    int ans = 0;

    // Iterate through the array to find the maximum GCD of left and right parts
    for (int i = 0; i < n; ++i) {
        ans = max(gcd(a[i], right[i + 1]), ans);
    }

    // Print the maximum GCD found
    cout << ans << endl;

    return 0;
}
