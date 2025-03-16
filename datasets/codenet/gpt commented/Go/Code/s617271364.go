package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Initialize scanner for input and writer for output
var sc = bufio.NewScanner(os.Stdin)
var wtr = bufio.NewWriter(os.Stdout)

// Declare global variables
var N, ss, ans, A, B, C int

func main() {
	// Read input values and split them into a slice of strings
	X := strings.Split(nextLine(), " ")

	// Parse the first four values from the input
	N, _ = strconv.Atoi(X[0]) // Number of elements
	A, _ = strconv.Atoi(X[1]) // Target value A
	B, _ = strconv.Atoi(X[2]) // Target value B
	C, _ = strconv.Atoi(X[3]) // Target value C

	// Initialize arrays for dynamic programming and results
	arr := make([]int, N) // Array to hold input values
	dp := make([]int, N)  // DP array to store current state
	ans = 10000           // Initialize answer with a large value
	ss = A + B + C        // Sum of target values

	// Read N integers from input and populate the array
	for i := 0; i < N; i++ {
		Y := strings.Split(nextLine(), " ")
		a, _ := strconv.Atoi(Y[0])
		arr[i] = a // Store the integer in the array
	}

	// Perform depth-first search to find the optimal distribution
	dfs(dp, 0, arr)

	// Output the final answer
	fmt.Fprintln(wtr, ans)

	// Flush the writer to ensure all output is written
	_ = wtr.Flush()
}

// Recursive function to explore all distributions of items
func dfs(dp []int, times int, arr []int) {
	// Base case: if all items have been considered
	if times >= N {
		ans = min(ans, calc(dp, arr)) // Calculate cost and update answer
		return
	}

	// Explore all possible distributions (0 to 3)
	for i := 0; i < 4; i++ {
		dp[times] = i // Assign current item to one of the four groups
		dfs(dp, times+1, arr) // Recur for the next item
	}
}

// Calculate the cost of the current distribution
func calc(dp, arr []int) int {
	var cost, AA, BB, CC int // Initialize cost and group sums

	// Count items in each group and calculate their sums
	memo := make([]int, 4)
	for i := 0; i < len(dp); i++ {
		memo[dp[i]]++ // Count items in each group
		if dp[i] == 1 {
			AA += arr[i] // Sum for group A
		} else if dp[i] == 2 {
			BB += arr[i] // Sum for group B
		} else if dp[i] == 3 {
			CC += arr[i] // Sum for group C
		}
	}

	// Calculate the cost based on the differences from target values
	cost += abs(A - AA) + abs(B - BB) + abs(C - CC)

	// Penalize for missing groups and excess items
	for i := 1; i < 4; i++ {
		a := memo[i]
		if a < 1 {
			cost += 10000 // High penalty for missing group
		} else {
			cost += (a - 1) * 10 // Penalty for excess items
		}
	}

	return cost // Return the calculated cost
}

// Helper function to read the next line of input
func nextLine() string {
	sc.Scan() // Scan the next line
	return sc.Text() // Return the text of the line
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Helper function to find the absolute value of an integer
func abs(a int) int {
	if a < 0 {
		return a * -1
	}
	return a
}

// Additional utility functions and types can be defined below
