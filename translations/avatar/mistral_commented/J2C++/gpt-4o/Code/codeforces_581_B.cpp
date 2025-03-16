#include <iostream>  // Including the input/output stream library
#include <vector>    // Including the vector library
#include <algorithm> // Including the algorithm library for max function
#include <set>       // Including the set library for unique elements
#include <iomanip>   // Including the iomanip library for output formatting

using namespace std;

int main() {
    ios::sync_with_stdio(false); // Optimize input/output performance
    cin.tie(nullptr); // Untie cin from cout

    int n; // Variable to store the number of elements in the array
    cin >> n; // Reading the number of elements

    vector<long long> a(n); // Creating a vector of size n to store the elements
    for (int i = 0; i < n; i++) { // Loop to read the elements of the array from the input
        cin >> a[i]; // Reading each element
    }

    vector<long long> dp(n + 1, -1); // Creating a vector of size n+1 to store the maximum subarray sum ending at each index
    dp[n - 1] = a[n - 1]; // Setting the last element of the dp vector with the last element of the array

    for (int i = n - 1; i >= 0; i--) { // Loop to calculate the maximum subarray sum ending at each index
        dp[i] = max(dp[i + 1], a[i]); // Update dp[i] with the maximum of dp[i + 1] and a[i]
    }

    for (int i = 0; i < n; i++) { // Loop to print the answer for each test case
        if (a[i] > dp[i + 1]) { // If the current element is greater than the maximum subarray sum ending at next index
            cout << 0 << " "; // Print 0 as the answer
        } else {
            cout << (dp[i + 1] - a[i] + 1) << " "; // Else print the length of the subarray ending at current index
        }
    }

    cout << endl; // Printing a newline character at the end of the output

    set<long long> uniqueSet; // Initializing the set to store unique elements

    // Debugging the array elements (if needed)
    // for (const auto& elem : a) {
    //     cerr << elem << " "; // Print each element to stderr for debugging
    // }
    // cerr << endl;

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
