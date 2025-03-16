#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm> // for std::move
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;

// Function to solve the problem
void solve(long long N, // Number of elements in T
           std::vector<long long> T, // Input vector T
           long long M, // Number of queries
           std::vector<long long> P, // Position of each query
           std::vector<long long> X // Value of each query
         ) {
    // Initialize a variable to store the answer for each query
    long long ans = 0;

    // Iterate through each query
    REP(i, M) {
        // Initialize the answer variable to zero
        ans = 0;

        // Iterate through each element in T up to the position of the current query
        REP(j, N) {
            // If the current index j is equal to the position of the current query - 1
            if (j == P[i] - 1) {
                // Add the value of X[i] to the answer variable
                ans += X[i];
            }
            // Otherwise, add the value of the current element in T to the answer variable
            else {
                ans += T[j];
            }
        }

        // Print the answer for the current query
        cout << ans << '\n';
    }
}

// Main function
int main() {
    // Initialize iostream objects
    cin.tie(0);
    ios::sync_with_stdio(false);

    // Read the number of elements in T from the standard input
    long long N;
    cin >> N;

    // Initialize a vector T of size N
    std::vector<long long> T(N);

    // Read the elements of T from the standard input
    REP(i, N) cin >> T[i];

    // Read the number of queries from the standard input
    long long M;
    cin >> M;

    // Initialize vectors P and X of size M
    std::vector<long long> P(M), X(M);

    // Read the positions and values of the queries from the standard input
    REP(i, M) cin >> P[i] >> X[i];

    // Call the solve function with the given arguments
    solve(N, std::move(T), M, std::move(P), std::move(X));

    // Return 0 to indicate successful execution
    return 0;
}

