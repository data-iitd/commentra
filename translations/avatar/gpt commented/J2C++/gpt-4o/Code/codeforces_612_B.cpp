#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // Create a variable to read input from the console
    int n;
    
    // Read the number of elements to be processed
    cin >> n;
    
    // Initialize a dp vector to store the indices of the input elements
    vector<int> dp(200001, 0);
    
    // Populate the dp vector with the indices of the input elements
    for (int i = 0; i < n; i++) {
        // Read the next integer and store its index in the dp vector
        int x;
        cin >> x;
        dp[x] = i;
    }
    
    // Initialize a variable to accumulate the result
    long long ans = 0;
    
    // Calculate the total distance between consecutive elements in the dp vector
    for (int i = 2; i <= n; i++) {
        // Add the absolute difference of indices of consecutive elements to ans
        ans += abs(dp[i] - dp[i - 1]);
    }
    
    // Output the final result
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
