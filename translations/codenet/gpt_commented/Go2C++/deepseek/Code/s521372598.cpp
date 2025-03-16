#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

// Function to read an integer from input
int getInt() {
    int ret;
    cin >> ret;
    return ret;
}

// Function to read a vector of integers from input
vector<int> getIntVector(int n) {
    vector<int> ret(n);
    for (int i = 0; i < n; ++i) {
        cin >> ret[i];
    }
    return ret;
}

// Function to compute the minimum total distance to a median value
void solve() {
    // Read the number of elements
    int n = getInt();
    // Read the integer vector of size n
    vector<int> as = getIntVector(n);

    // Create a new vector to store adjusted values
    vector<int> xs(n);
    for (int i = 0; i < n; ++i) {
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

int main() {
    // Call the solve function to perform the main logic
    solve();
    return 0;
}

