#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    // Read the total number of items (n) to be processed
    int n;
    cin >> n;

    // Define the maximum size for the dp array
    const int maxn = 4010;

    // Read three integer values (a, b, c) which represent the sizes of items
    int a, b, c;
    cin >> a >> b >> c;

    // Store the sizes of items in an array for easier access
    int arr[] = { a, b, c };

    // Initialize a dp array to store the maximum number of items that can be formed
    vector<int> dp(maxn, numeric_limits<int>::min());

    // Base case: zero items can be formed with zero size
    dp[0] = 0;

    // Iterate through each item size (a, b, c)
    for (int i = 0; i < 3; i++) {
        // Update the dp array for each possible size from the current item size
        for (int j = arr[i]; j < dp.size(); j++) {
            // Calculate the maximum number of items that can be formed
            dp[j] = max(dp[j], dp[j - arr[i]] + 1);
        }
    }

    // Output the maximum number of items that can be formed with size n
    cout << dp[n] << endl;

    return 0;
}

// <END-OF-CODE>
