
#include <bits/stdc++.h> // Importing standard library
using namespace std; // Importing standard namespace

long MOD = 998244353; // Modulus value for modular arithmetic

long dp[3001][3001]; // 2D dynamic programming table for storing intermediate results

void solve(int A, int B, int C, int D) { // Function to solve the problem

  dp[A][B] = 1; // Setting the base case as dp[A][B] = 1

  for (int c = A; c <= C; c++) { // Iterating over all possible values of c from A to C
    for (int d = B; d <= D; d++) { // Iterating over all possible values of d from B to D
      if (c == A && d == B) { // Skipping the base case as it has already been calculated
        continue;
      }

      long ans = 0; // Initializing the answer as zero

      if (c > A) { // If c is greater than A
        long part = dp[c - 1][d]; // Calculating the sub-answer for the previous value of c and the same value of d
        ans = (part * d); // Multiplying the sub-answer with the current value of d
      }

      if (d > B) { // If d is greater than B
        long part = dp[c][d - 1]; // Calculating the sub-answer for the same value of c and the previous value of d
        ans = (ans + (part * c)); // Adding the sub-answer multiplied by the current value of c to the answer
      }

      if (c > A && d > B) { // If both c and d are greater than their respective initial values
        ans = (ans - (dp[c - 1][d - 1] * (c - 1) * (d - 1))); // Subtracting the answer for the previous values of c and d multiplied by their difference
      }

      dp[c][d] = (ans % MOD + MOD) % MOD; // Updating the answer for the current values of c and d
    }
  }
}

int main() { // Main function to run the program
  int A, B, C, D; // Declaring variables for input
  cin >> A >> B >> C >> D; // Reading input from stdin
  solve(A, B, C, D); // Calling the solve function to solve the problem
  return 0;
}

