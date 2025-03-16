package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Constants to represent indices for time and value
const (
	TIME = 0
	VAL  = 1
)

// Read input from standard input
func readInput() (int, int, [][2]int) {
	// Read the number of items (N) and the maximum time (T)
	N, T := readTwoInts()

	// Initialize a list to store time and value pairs, starting with a dummy entry
	time_value := make([][2]int, N+1)
	time_value[0] = [2]int{-1, -1}

	// Read the time and value pairs for each item
	for i := 1; i <= N; i++ {
		time_value[i] = readTwoInts()
	}

	return N, T, time_value
}

// Read two integers from standard input
func readTwoInts() (int, int) {
	// Read two integers from standard input
	var a, b int
	fmt.Scanf("%d %d", &a, &b)
	return a, b
}

// Read a string from standard input
func readString() string {
	// Read a string from standard input
	var s string
	fmt.Scanf("%s", &s)
	return s
}

// Print the maximum value achievable within the given time
func printMaxVal(max_val int) {
	fmt.Printf("%d\n", max_val)
}

// Fill the dynamic programming table
func fillDPTable(N int, T int, time_value [][2]int) (dp [][]int) {
	// Initialize a 2D list for dynamic programming, with -1 as default values
	dp = make([][]int, N+1)
	for i := range dp {
		dp[i] = make([]int, T)
		for j := range dp[i] {
			dp[i][j] = -1
	}

	// Base case: If time is 0, the maximum value is 0 for all items
	for t := 0; t < T; t++ {
		dp[0][t] = 0
	}

	// Fill the dynamic programming table
	for n := 1; n <= N; n++ {
		// Base case: If no time is available, the maximum value is 0
		dp[n][0] = 0
		for t := 1; t < T; t++ {
			// If the current item's time exceeds the available time, skip the item
			if time_value[n][TIME] > t {
				dp[n][t] = dp[n-1][t]
			} else {
				// Choose the maximum between not taking the item and taking it
				dp[n][t] = max(dp[n-1][t], time_value[n][VAL]+dp[n-1][t-time_value[n][TIME]])
		}
	}

	return dp
}

// Backtrack to find the maximum value considering previous items
func backtrack(N int, T int, time_value [][2]int, dp [][]int) int {
	// Initialize the maximum value with the last item's value
	val_acum := time_value[N][VAL]
	t := T - 1
	max_val := val_acum + dp[N-1][t]

	// Backtrack to find the maximum value considering previous items
	for n := N - 1; n > 0; n-- {
		val_acum += time_value[n][VAL]
		t -= time_value[n+1][TIME]

		// If time goes negative, break the loop
		if t < 0 {
			break
		} else {
			// Update the maximum value if a better option is found
			max_val = max(max_val, val_acum+dp[n-1][t])
	}

	return max_val
}

// Find the maximum value between two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Main function
func main() {
	// Read the number of items (N) and the maximum time (T)
	N, T, time_value := readInput()

	// Fill the dynamic programming table
	dp := fillDPTable(N, T, time_value)

	// Find the maximum value considering previous items
	max_val := backtrack(N, T, time_value, dp)

	// Print the maximum value achievable within the given time
	printMaxVal(max_val)
}

