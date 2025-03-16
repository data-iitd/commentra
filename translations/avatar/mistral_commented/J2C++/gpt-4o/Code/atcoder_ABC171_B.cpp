#include <iostream>     // Include iostream for input and output
#include <vector>      // Include vector for dynamic arrays
#include <algorithm>   // Include algorithm for sorting
#include <numeric>     // Include numeric for accumulate

using namespace std;    // Use the standard namespace

// Main function to start the program
int main() {
    // Read input: number of elements n and the number of summands k
    int n, k;
    cin >> n >> k;

    // Read input array a of size n
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; // Read next element of array a
    }

    // Sort the array a
    sort(a.begin(), a.end());

    // Calculate the answer: sum of first k elements of sorted array a
    int ans = accumulate(a.begin(), a.begin() + k, 0);

    // Write the answer to the output stream
    cout << ans << endl;

    return 0; // Return success
}

// <END-OF-CODE>
