#include <iostream> // Importing header for input/output operations
#include <vector>   // Importing header for using vectors
#include <cmath>    // Importing header for mathematical functions

using namespace std;

int main() {
    int n; // Variable to store the size of the array
    cin >> n; // Read the size of the array
    vector<int> arr(n); // Initialize a vector of size n

    // Read n integers into the vector
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Initialize ans with the value of the first element plus 1
    int ans = arr[0] + 1;

    // Iterate through the vector and update ans
    for (int i = 1; i < n; i++) {
        ans += abs(arr[i] - arr[i - 1]) + 2;
    }

    // Print the final value of ans
    cout << ans << endl;

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
