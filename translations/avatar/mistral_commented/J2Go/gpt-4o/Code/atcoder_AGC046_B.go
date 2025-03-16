package main

import (
	"fmt"
)

const MOD = 998244353 // Modulus value for modular arithmetic

var dp [3001][3001]int64 // 2D dynamic programming table for storing intermediate results

func solve(A, B, C, D int) int64 { // Function to solve the problem
	dp[A][B] = 1 // Setting the base case as dp[A][B] = 1

	for c := A; c <= C; c++ { // Iterating over all possible values of c from A to C
		for d := B; d <= D; d++ { // Iterating over all possible values of d from B to D
			if c == A && d == B { // Skipping the base case as it has already been calculated
				continue
			}

			ans := int64(0) // Initializing the answer as zero

			if c > A { // If c is greater than A
				part := dp[c-1][d] // Calculating the sub-answer for the previous value of c and the same value of d
				ans = (part * int64(d)) % MOD // Multiplying the sub-answer with the current value of d
			}

			if d > B { // If d is greater than B
				part := dp[c][d-1] // Calculating the sub-answer for the same value of c and the previous value of d
				ans = (ans + (part * int64(c)) % MOD) % MOD // Adding the sub-answer multiplied by the current value of c to the answer
			}

			if c > A && d > B { // If both c and d are greater than their respective initial values
				ans = (ans - (dp[c-1][d-1] * int64(c-1) * int64(d-1)) % MOD + MOD) % MOD // Subtracting the answer for the previous values of c and d multiplied by their difference
			}

			dp[c][d] = (ans + MOD) % MOD // Updating the answer for the current values of c and d
		}
	}

	return dp[C][D] // Returning the final answer
}

func main() { // Main function to run the program
	var A, B, C, D int
	fmt.Scan(&A, &B, &C, &D) // Reading the input values A, B, C, D
	result := solve(A, B, C, D) // Calling the solve function to solve the problem
	fmt.Println(result) // Printing the final answer
}

// <END-OF-CODE>
