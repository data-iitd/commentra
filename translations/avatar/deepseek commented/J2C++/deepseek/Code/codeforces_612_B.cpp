#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(200001, 0);

    // Storing positions of the integers in the array dp
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        dp[num] = i;
    }

    long long ans = 0; // Initializing the answer variable to 0

    // Calculating the sum of absolute differences between consecutive positions
    for (int i = 2; i <= n; i++) {
        ans += abs(dp[i] - dp[i - 1]);
    }

    cout << ans << endl; // Printing the final answer

    return 0;
}
