
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

vector<int> ruiseki_lr(vector<int> array) {
    // Defines a lambda function to compute GCD
    auto op = [](int a, int b) { return gcd(a, b); };
    // Initial GCD value
    int e = 0;
    // Length of the input array
    int n = array.size();
    // Initialize prefix and suffix GCD arrays
    vector<int> left(n + 1, e);
    vector<int> right(n + 1, e);
    // Compute prefix GCD array
    for (int i = 0; i < n; i++) {
        left[i + 1] = op(left[i], array[i]);
    }
    // Compute suffix GCD array
    for (int i = n - 1; i >= 0; i--) {
        right[i] = op(right[i + 1], array[i]);
    }
    return left;
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
    vector<int> left = ruiseki_lr(a);
    // Initialize the answer variable
    int ans = 0;
    // Iterate through the array to find the maximum GCD
    for (int i = 0; i < n; i++) {
        ans = max(gcd(left[i], left[i + 1]), ans);
    }
    // Print the result
    cout << ans << endl;
    return 0;
}

