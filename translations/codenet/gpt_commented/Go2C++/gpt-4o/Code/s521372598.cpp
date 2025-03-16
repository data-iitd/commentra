#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

// Function to compute the minimum total distance to a median value
void solve() {
    int n;
    cin >> n; // Read the number of elements
    vector<int> as(n);
    
    // Read the integer vector of size n
    for (int i = 0; i < n; ++i) {
        cin >> as[i];
    }

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
    long long ans = 0; // Use long long to avoid overflow

    // Calculate the total distance from each element to the median
    for (int x : xs) {
        ans += abs(x - b);
    }

    // Output the result
    cout << ans << endl;
}

// Main function initializes input/output and calls the solve function
int main() {
    solve(); // Call the solve function to perform the main logic
    return 0;
}

// <END-OF-CODE>
