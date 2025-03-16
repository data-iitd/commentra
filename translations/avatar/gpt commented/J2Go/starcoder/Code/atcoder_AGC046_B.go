package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a constant for the modulo operation
const MOD = 998244353

// Create a 2D array for dynamic programming
var dp [3001][3001]int64

// Method to solve the problem
func solve(sc *bufio.Scanner, pw *bufio.Writer) {
	// Read input values A, B, C, D from the scanner
	A, _ := strconv.Atoi(sc.Text())
	B, _ := strconv.Atoi(sc.Text())
	C, _ := strconv.Atoi(sc.Text())
	D, _ := strconv.Atoi(sc.Text())

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
				ans = (ans - (dp[c-1][d-1] * (int64(c-1) * (int64(d-1))))) // Adjust for double counting
			}

			// Store the result in the dp array with modulo adjustment
			dp[c][d] = ((ans % MOD) + MOD) % MOD
		}
	}

	// Output the final result for dp[C][D]
	fmt.Fprintln(pw, dp[C][D])
}

// Main method to execute the program
func main() {
	sc := bufio.NewScanner(os.Stdin) // Initialize scanner for input
	pw := bufio.NewWriter(os.Stdout) // Initialize PrintWriter for output
	solve(sc, pw)                    // Create an instance of Main and call solve method
	pw.Flush()                        // Flush the output
	pw.Close()                        // Close the PrintWriter
	sc.Close()                        // Close the scanner
}

