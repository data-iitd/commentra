
#include <iostream> // Importing theiostream library for input/output

using namespace std; // Using the standard namespace

int main() {
    int n; // Declaring an integer variable n to store the size of the array
    cin >> n; // Reading the integer n from the input

    int dp[200001]; // Initializing an array to store positions

    // Storing positions of the integers in the array dp
    for (int i = 0; i < n; i++) {
        cin >> dp[i];
    }

    long long ans = 0; // Initializing the answer variable to 0

    // Calculating the sum of absolute differences between consecutive positions
    for (int i = 1; i < n; i++) {
        ans += abs(dp[i] - dp[i - 1]);
    }

    cout << ans << endl; // Printing the final answer

    return 0; // Returning 0 to indicate successful execution
}

