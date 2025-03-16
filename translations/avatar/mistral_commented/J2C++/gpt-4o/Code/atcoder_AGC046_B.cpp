#include <iostream> // Including iostream for input and output
#include <vector>   // Including vector for dynamic programming table
using namespace std;

const long long MOD = 998244353LL; // Modulus value for modular arithmetic

class Main {
public:
    void solve() { // Function to solve the problem
        int A, B, C, D; // Declaring variables for input
        cin >> A >> B >> C >> D; // Reading the four numbers A, B, C, D from input

        vector<vector<long long>> dp(3001, vector<long long>(3001, 0)); // Initializing the dynamic programming table with zeros

        dp[A][B] = 1; // Setting the base case as dp[A][B] = 1

        for (int c = A; c <= C; c++) { // Iterating over all possible values of c from A to C
            for (int d = B; d <= D; d++) { // Iterating over all possible values of d from B to D
                if (c == A && d == B) { // Skipping the base case as it has already been calculated
                    continue;
                }

                long long ans = 0; // Initializing the answer as zero

                if (c > A) { // If c is greater than A
                    long long part = dp[c - 1][d]; // Calculating the sub-answer for the previous value of c and the same value of d
                    ans = (part * d) % MOD; // Multiplying the sub-answer with the current value of d
                }

                if (d > B) { // If d is greater than B
                    long long part = dp[c][d - 1]; // Calculating the sub-answer for the same value of c and the previous value of d
                    ans = (ans + (part * c) % MOD) % MOD; // Adding the sub-answer multiplied by the current value of c to the answer
                }

                if (c > A && d > B) { // If both c and d are greater than their respective initial values
                    ans = (ans - (dp[c - 1][d - 1] * (c - 1) % MOD * (d - 1) % MOD) + MOD) % MOD; // Subtracting the answer for the previous values of c and d multiplied by their difference
                }

                dp[c][d] = (ans + MOD) % MOD; // Updating the answer for the current values of c and d
            }
        }

        cout << dp[C][D] << endl; // Printing the final answer
    }
};

int main() { // Main function to run the program
    Main().solve(); // Calling the solve function to solve the problem
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
