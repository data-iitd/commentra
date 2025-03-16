#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for using vectors
using namespace std; // Using the standard namespace

int main() { // Starting the main function
    long mod = 1e9 + 7; // Assigning the value of 1e9 + 7 to a long variable named mod
    int n, k; // Declaring variables n and k
    cin >> n >> k; // Reading the first two integer inputs

    vector<int> len; // Creating a vector named len to store the lengths of subsequences
    int l = 1; // Initializing the variable l to 1

    while (l <= n) { // Starting a while loop that runs as long as l is less than or equal to n
        int r = n / (n / l); // Calculating the right end of the current subsequence
        len.push_back(r - l + 1); // Adding the length of the current subsequence to the vector len
        l = r + 1; // Incrementing the variable l to consider the next subsequence
    }

    int q = len.size(); // Assigning the size of the vector len to the variable q
    vector<long> dp(k * (q + 1)); // Creating a vector named dp of size k * (q + 1) to store the dynamic programming results

    for (int j = 1; j <= q; j++) { // Starting a for loop that runs from 1 to q
        dp[j] = len[j - 1] + dp[j - 1]; // Calculating the dp value for the current subsequence length using the previous dp value and the length of the current subsequence
    }

    for (int i = 1; i < k; i++) { // Starting a nested for loop that runs from 1 to k - 1 for the number of overlapping subsequences
        for (int j = 1; j <= q; j++) { // Starting an inner for loop that runs from 1 to q for the length of the current subsequence
            dp[i * (q + 1) + j] = dp[i * (q + 1) + j - 1] + dp[(i - 1) * (q + 1) + q - j + 1] * len[j - 1]; // Calculating the dp value for the current combination of subsequence length and number of overlapping subsequences
            dp[i * (q + 1) + j] %= mod; // Taking the modulo of the dp value to ensure it doesn't exceed the value of mod
        }
    }

    cout << dp[k * (q + 1) - 1] << endl; // Printing the final result, which is the dp value for the combination of subsequence length and number of overlapping subsequences that matches the given input
    return 0; // Returning 0 to indicate successful completion
}

// <END-OF-CODE>
