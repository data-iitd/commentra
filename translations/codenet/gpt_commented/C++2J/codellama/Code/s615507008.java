#include <iostream>
#include <map>
#include <set>
#include <vector>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;

// Function to solve the problem based on the given parameters
void solve(long long N, std::vector<long long> T, long long M, std::vector<long long> P, std::vector<long long> X) {
    // Iterate over each modification request
    REP(i, M) {
        long long ans = 0; // Initialize the answer for the current modification
        // Calculate the total time considering the current modification
        REP(j, N) {
            // If the current index matches the modified position, add the new time value
            if (j == P[i] - 1) ans += X[i];
            // Otherwise, add the original time value
            else ans += T[j];
        }
        // Output the result for the current modification
        cout << ans << '\n';
    }
}

int main() {
    cin.tie(0); // Untie cin from cout for faster input
    ios::sync_with_stdio(false); // Disable synchronization with C I/O for performance

    long long N; // Number of original time values
    cin >> N; // Read the number of time values
    std::vector<long long> T(N); // Vector to store the original time values
    REP(i, N) cin >> T[i]; // Read the original time values into the vector

    long long M; // Number of modifications
    cin >> M; // Read the number of modifications
    std::vector<long long> P(M); // Vector to store the positions of modifications
    std::vector<long long> X(M); // Vector to store the new time values for modifications
    REP(i, M) cin >> P[i] >> X[i]; // Read the modification positions and new time values

    // Call the solve function to process the modifications and output results
    solve(N, std::move(T), M, std::move(P), std::move(X));
    return 0; // Indicate successful completion of the program
}

