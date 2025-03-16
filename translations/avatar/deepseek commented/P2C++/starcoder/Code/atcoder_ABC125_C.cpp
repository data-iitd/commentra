
#include <bits/stdc++.h>
using namespace std;

// Function to compute GCD
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to compute prefix and suffix GCD arrays
void ruiseki_lr(vector<int> &array, vector<int> &left, vector<int> &right) {
    // Initial GCD value
    int e = 0;
    // Length of the input array
    int n = array.size();
    // Initialize prefix and suffix GCD arrays
    left[0] = e;
    right[n] = e;
    // Compute prefix GCD array
    for (int i = 0; i < n; i++) {
        left[i + 1] = gcd(left[i], array[i]);
    }
    // Compute suffix GCD array
    for (int i = n - 1; i >= 0; i--) {
        right[i] = gcd(right[i + 1], array[i]);
    }
}

// Function to find the maximum GCD
int max_gcd(vector<int> &left, vector<int> &right, int n) {
    // Initialize the answer variable
    int ans = 0;
    // Iterate through the array to find the maximum GCD
    for (int i = 0; i < n; i++) {
        ans = max(gcd(left[i], right[i + 1]), ans);
    }
    // Return the result
    return ans;
}

// Driver code
int main() {
    // Read the number of elements
    int n;
    cin >> n;
    // Read the list of elements
    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    // Initialize prefix and suffix GCD arrays
    vector<int> left(n + 1), right(n + 1);
    // Compute prefix and suffix GCD arrays
    ruiseki_lr(array, left, right);
    // Find the maximum GCD
    cout << max_gcd(left, right, n) << endl;
    return 0;
}

