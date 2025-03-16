package main

import (
	"fmt"
	"os"
	"strconv"
)

// Define a constant for the modulo operation
const MOD = 998244353

// Create a 2D array for dynamic programming
var dp [3001][3001]int64

// Method to solve the problem
func solve(sc *os.File, pw *os.File) {
	// Read input values A, B, C, D from the scanner
	A, _ := strconv.Atoi(nextLine(sc))
	B, _ := strconv.Atoi(nextLine(sc))
	C, _ := strconv.Atoi(nextLine(sc))
	D, _ := strconv.Atoi(nextLine(sc))

	// Initialize the starting point in the dp array
	dp[A][B] = 1

	// Iterate over the range from A to C and B to D
	for c := A; c <= C; c++ {
		for d := B; d <= D; d++ {
			// Skip the initial point
			if c == A && d == B {
				continue
			}

			// Variable to store the current answer
			ans := int64(0)

			// If moving down (increasing c)
			if c > A {
				part := dp[c-1][d]
				ans = (part * int64(d)) // Calculate contribution from the previous row
			}

			// If moving right (increasing d)
			if d > B {
				part := dp[c][d-1]
				ans = (ans + (part * int64(c))) // Calculate contribution from the previous column
			}

			// If moving diagonally (increasing both c and d)
			if c > A && d > B {
				ans = (ans - (dp[c-1][d-1] * int64(c-1) * int64(d-1))) // Adjust for double counting
			}

			// Store the result in the dp array with modulo adjustment
			dp[c][d] = ((ans % MOD) + MOD) % MOD
		}
	}

	// Output the final result for dp[C][D]
	fmt.Fprintln(pw, dp[C][D])
}

// Method to read a line of input from the scanner
func nextLine(sc *os.File) string {
	sc.Scan()
	return sc.Text()
}

// Main method to execute the program
func main() {
	sc := os.Stdin
	pw := os.Stdout
	solve(sc, pw) // Create an instance of Main and call solve method
	pw.Flush()    // Flush the output
	pw.Close()    // Close the PrintWriter
	sc.Close()    // Close the scanner
}

