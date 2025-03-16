#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Read the number of pairs from user input
    int n;
    cin >> n;

    // Initialize a vector to store values, with a size of 1000010, filled with zeros
    vector<int> l(1000010, 0);

    // Initialize a dynamic programming vector to store results, also of size 1000010
    vector<int> dp(1000010, 0);

    // Read n pairs of integers and populate the vector l
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        l[a] = b;  // Set l[a] to b based on the input pairs
    }

    // If the first element in l is greater than 0, set dp[0] to 1
    if (l[0] > 0) {
        dp[0] = 1;
    }

    // Initialize a variable to keep track of the maximum value found in dp
    int mx = 0;

    // Iterate through the vector from index 1 to 1000009
    for (int i = 1; i < 1000010; i++) {
        // If l[i] is 0, carry forward the previous dp value
        if (l[i] == 0) {
            dp[i] = dp[i - 1];
        } else {
            // If l[i] is greater than or equal to i, set dp[i] to 1
            if (l[i] >= i) {
                dp[i] = 1;
            } else {
                // Otherwise, calculate dp[i] based on previous values
                dp[i] = dp[i - l[i] - 1] + 1;
            }
        }

        // Update the maximum value found in dp
        if (dp[i] > mx) {
            mx = dp[i];
        }
    }

    // Print the result, which is the difference between n and the maximum value found in dp
    cout << n - mx << endl;

    return 0;
}

// <END-OF-CODE>
