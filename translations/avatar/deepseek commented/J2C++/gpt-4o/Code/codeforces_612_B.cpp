#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for dynamic arrays
#include <cmath>    // Including the cmath library for mathematical functions

using namespace std;

int main() {
    int n;
    cin >> n; // Reading the integer n from the input
    vector<int> dp(200001); // Initializing a vector to store positions

    // Storing positions of the integers in the vector dp
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x; // Reading the integer from the input
        dp[x] = i; // Storing the position of x
    }

    long long ans = 0; // Initializing the answer variable to 0

    // Calculating the sum of absolute differences between consecutive positions
    for (int i = 2; i <= n; i++) {
        ans += abs(dp[i] - dp[i - 1]);
    }

    cout << ans << endl; // Printing the final answer
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
