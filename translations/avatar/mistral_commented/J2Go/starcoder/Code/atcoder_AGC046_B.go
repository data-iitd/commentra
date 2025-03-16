
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Global variables
var MOD int64 = 998244353

// Function to solve the problem
func solve(A, B, C, D int64) int64 {
	// Initializing the dynamic programming table with zeros
	dp := make([][]int64, 3001)
	for i := range dp {
		dp[i] = make([]int64, 3001)
	}

	dp[A][B] = 1

	// Iterating over all possible values of c from A to C
	for c := A; c <= C; c++ {
		// Iterating over all possible values of d from B to D
		for d := B; d <= D; d++ {
			// Skipping the base case as it has already been calculated
			if c == A && d == B {
				continue
			}

			ans := int64(0)

			// If c is greater than A
			if c > A {
				part := dp[c-1][d]
				ans = (part * d)
			}

			// If d is greater than B
			if d > B {
				part := dp[c][d-1]
				ans = (ans + (part * c))
			}

			// If both c and d are greater than their respective initial values
			if c > A && d > B {
				ans = (ans - (dp[c-1][d-1] * (c-1) * (d-1)))
			}

			dp[c][d] = (ans % MOD + MOD) % MOD
		}
	}

	return dp[C][D]
}

// Main function to run the program
func main() {
	// Reading input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Reading the first line of input
	line, _ := reader.ReadString('\n')
	// Splitting the input line into individual space-separated integers
	line = strings.TrimSpace(line)
	lineArray := strings.Split(line, " ")
	A, _ := strconv.ParseInt(lineArray[0], 10, 64)
	B, _ := strconv.ParseInt(lineArray[1], 10, 64)
	C, _ := strconv.ParseInt(lineArray[2], 10, 64)
	D, _ := strconv.ParseInt(lineArray[3], 10, 64)

	// Printing the final answer to stdout
	fmt.Println(solve(A, B, C, D))
}

