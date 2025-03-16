#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to compute the GCD of two numbers
int gcd(int a, int b) {
    // Base case: if b is 0, return a as the GCD
    if (b == 0) {
        return a;
    }
    // Recursive case: call gcd with b and the remainder of a divided by b
    return gcd(b, a % b);
}

// Function to compute cumulative GCD from left and right
pair<vector<int>, vector<int>> ruiseki_lr(const vector<int>& array) {
    // Define the operation to find the GCD of two numbers
    auto op = [](int a, int b) { return gcd(a, b); };
    
    // Initialize the identity element for GCD
    int e = 0;
    int n = array.size();
    
    // Create vectors to store cumulative GCD from the left and right
    vector<int> left(n + 1, e);
    vector<int> right(n + 1, e);
    
    // Calculate cumulative GCD from the left
    for (int i = 0; i < n; ++i) {
        left[i + 1] = op(left[i], array[i]);
    }
    
    // Calculate cumulative GCD from the right
    for (int i = n - 1; i >= 0; --i) {
        right[i] = op(right[i + 1], array[i]);
    }
    
    // Return both cumulative GCD vectors
    return {left, right};
}

int main() {
    // Read the number of elements in the array
    int n;
    cin >> n;
    
    // Read the array elements from input
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Compute the cumulative GCD from the left and right
    auto [left, right] = ruiseki_lr(a);

    // Initialize the answer variable to store the maximum GCD found
    int ans = 0;

    // Iterate through the array to find the maximum GCD of left and right parts
    for (int i = 0; i < n; ++i) {
        ans = max(gcd(left[i], right[i + 1]), ans);
    }

    // Print the maximum GCD found
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
