
```cpp
#include <bits/stdc++.h>
using namespace std;

// solve function computes the minimum total distance to a median value
void solve() {
    // Read the number of elements
    int n;
    cin >> n;
    // Read the integer vector of size n
    vector<int> as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }

    // Create a new vector to store adjusted values
    vector<int> xs(n);
    for (int i = 0; i < n; i++) {
        // Adjust each element by subtracting its index and adding 1
        xs[i] = as[i] - i + 1;
    }
    // Sort the adjusted values
    sort(xs.begin(), xs.end());

    // Find the median value from the sorted vector
    int b = xs[n / 2];
    int ans = 0;
    // Calculate the total distance from each element to the median
    for (int x : xs) {
        ans += abs(x - b);
    }
    // Output the result
    cout << ans << endl;
}

// abs function returns the absolute value of an integer
int abs(int n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

int main() {
    // Call the solve function to perform the main logic
    solve();
    return 0;
}

