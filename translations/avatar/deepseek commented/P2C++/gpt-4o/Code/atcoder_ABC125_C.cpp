#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the greatest common divisor (GCD) of a and b
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to compute prefix and suffix GCD arrays
void ruiseki_lr(const vector<int>& array, vector<int>& left, vector<int>& right) {
    int n = array.size();
    left.resize(n + 1, 0);
    right.resize(n + 1, 0);
    
    // Compute prefix GCD array
    for (int i = 0; i < n; ++i) {
        left[i + 1] = gcd(left[i], array[i]);
    }
    
    // Compute suffix GCD array
    for (int i = n - 1; i >= 0; --i) {
        right[i] = gcd(right[i + 1], array[i]);
    }
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
    vector<int> left, right;
    ruiseki_lr(a, left, right);
    
    // Initialize the answer variable
    int ans = 0;
    
    // Iterate through the array to find the maximum GCD
    for (int i = 0; i < n; ++i) {
        ans = max(gcd(left[i], right[i + 1]), ans);
    }
    
    // Print the result
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
