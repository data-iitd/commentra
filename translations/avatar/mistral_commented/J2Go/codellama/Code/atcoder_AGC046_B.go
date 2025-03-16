
package main

import (
	"fmt"
	"math"
)

const MOD = 998244353 // Modulus value for modular arithmetic

func solve(sc *Scanner, pw *PrintWriter) { // Function to solve the problem

	A := sc.nextInt() // Reading the first number A from input
	B := sc.nextInt() // Reading the second number B from input
	C := sc.nextInt() // Reading the third number C from input
	D := sc.nextInt() // Reading the fourth number D from input

	dp := make([][]int, 3001) // Initializing the dynamic programming table with zeros

	for i := 0; i < 3001; i++ {
		dp[i] = make([]int, 3001)
	}

	dp[A][B] = 1 // Setting the base case as dp[A][B] = 1

	for c := A; c <= C; c++ { // Iterating over all possible values of c from A to C
		for d := B; d <= D; d++ { // Iterating over all possible values of d from B to D
			if c == A && d == B { // Skipping the base case as it has already been calculated
				continue
			}

			ans := 0 // Initializing the answer as zero

			if c > A { // If c is greater than A
				part := dp[c-1][d] // Calculating the sub-answer for the previous value of c and the same value of d
				ans = (part * d) // Multiplying the sub-answer with the current value of d
			}

			if d > B { // If d is greater than B
				part := dp[c][d-1] // Calculating the sub-answer for the same value of c and the previous value of d
				ans = (ans + (part * c)) // Adding the sub-answer multiplied by the current value of c to the answer
			}

			if c > A && d > B { // If both c and d are greater than their respective initial values
				ans = (ans - (dp[c-1][d-1] * (c-1) * (d-1))) // Subtracting the answer for the previous values of c and d multiplied by their difference
			}

			dp[c][d] = (ans % MOD + MOD) % MOD // Updating the answer for the current values of c and d
		}
	}

	pw.println(dp[C][D]) // Printing the final answer
}

func main() { // Main function to run the program
	sc := newScanner(os.Stdin) // Creating a Scanner object for reading input
	pw := newPrintWriter(os.Stdout) // Creating a PrintWriter object for writing output
	solve(sc, pw) // Calling the solve function to solve the problem
	pw.flush() // Flushing the output buffer
	pw.close() // Closing the output stream
	sc.close() // Closing the input stream
}

