#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <list>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip> // Required for using setprecision to display floating-point numbers
using namespace std;

// Macro definitions for convenience
#define REPD(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) REPD(i, 0, n)
typedef long long ll; // Define ll as a shorthand for long long
#define fin(ans) cout << (ans) << '\n' // Macro to print the answer followed by a newline

int main()
{
    ll N, K; // Declare variables for number of elements and steps
    ll A[200100]; // Array to store the input values
    ll B[200100] = {-1}; // Array to track the first visit time to each position, initialized to -1
    int now = 1; // Current position, starting at 1
    ll cnt = 0; // Counter for the number of steps taken

    // Read the number of elements (N) and the number of steps (K)
    cin >> N >> K;

    // Read the elements into array A
    REP(i, N) {
        cin >> A[i + 1]; // Store input values in A, starting from index 1
    }

    // Initialize array B to -1 to indicate unvisited positions
    REP(i, 200100) {
        B[i] = -1;
    }

    // Mark the starting position as visited at step 0
    ll j;
    B[1] = 0; // Starting point is visited at step 0

    // Traverse the positions based on the values in A
    for (j = 1; j <= K; j++) {
        now = A[now]; // Move to the next position based on the current position

        // Check if the current position has been visited before
        if (B[now] == -1) {
            B[now] = j; // Mark the position with the current step count
        } else {
            // If the position has been visited, calculate the cycle length
            cnt = j; // Store the current step count
            break; // Exit the loop as we found a cycle
        }
    }

    // If we did not reach the maximum steps K
    if (j < K) {
        ll tmp;
        // Calculate how many additional steps to take within the cycle
        tmp = (K - B[now]) % (cnt - B[now]);
        
        // Move to the final position after the calculated additional steps
        for (ll j = 0; j < tmp; j++) {
            now = A[now]; // Continue moving to the next position
        }
    }

    // Output the final position after all movements
    fin(now);
    return 0; // End of the program
}

