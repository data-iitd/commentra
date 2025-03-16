#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int maxn = 4010;

    // Reading the three integers representing the array elements
    int a, b, c;
    cin >> a >> b >> c;

    // Defining an array to store the array elements
    vector<int> arr = {a, b, c};

    // Defining a dynamic programming array of size maxn
    vector<int> dp(maxn, INT_MIN);

    // Initializing the dynamic programming array with minimum values
    dp[0] = 0;

    // Filling the dynamic programming array using two nested loops
    for (int i = 0; i < 3; i++) {
        for (int j = arr[i]; j < maxn; j++) {
            dp[j] = max(dp[j], dp[j - arr[i]] + 1);
        }
    }

    // Printing the result, which is the maximum length ending at the nth index
    cout << dp[n] << endl;

    return 0;
}
