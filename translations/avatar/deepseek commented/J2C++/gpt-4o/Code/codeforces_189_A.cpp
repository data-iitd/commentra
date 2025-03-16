#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Initialize input variables
    int n;
    cin >> n;
    int maxn = 4010;
    int a, b, c;
    cin >> a >> b >> c;

    // Store the coin values in a vector
    vector<int> arr = {a, b, c};

    // Initialize a dp array with all elements set to INT_MIN
    vector<int> dp(maxn, INT_MIN);

    // Set the base case where dp[0] is 0
    dp[0] = 0;

    // Iterate over the coin values and update the dp array
    for (int i = 0; i < 3; i++) {
        for (int j = arr[i]; j < dp.size(); j++) {
            dp[j] = max(dp[j], dp[j - arr[i]] + 1);
        }
    }

    // Print the value of dp[n]
    cout << dp[n] << endl;

    return 0;
}

// <END-OF-CODE>
