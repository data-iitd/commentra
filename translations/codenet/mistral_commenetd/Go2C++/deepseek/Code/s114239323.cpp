#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

// Helper function to read input from standard input as a single string
string nextString() {
    string s;
    getline(cin, s);
    return s;
}

// Helper function to read a single integer from standard input
int nextInt() {
    int x;
    cin >> x;
    return x;
}

// Helper function to read an array of N integers from standard input
vector<int> nextInts(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return arr;
}

// Main function
int main() {
    // Read the number of test cases N from standard input
    int N = nextInt();

    // Read an array h of N integers from standard input
    vector<int> h = nextInts(N);

    // Initialize a dp array of size N with zeros
    vector<int> dp(N, 0);

    // Set the first element of dp to the absolute difference between the first and second elements of h
    dp[1] = abs(h[0] - h[1]);

    // Iterate over the array h from the second element to the last
    for (int i = 2; i < N; i++) {
        // Set the current element of dp to the minimum of the previous and previous-previous elements plus the absolute difference between the current and previous/previous elements
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    // Print the last element of dp, which is the minimum number of jumps required to reach the last index of h
    cout << dp[N - 1] << endl;

    return 0;
}
