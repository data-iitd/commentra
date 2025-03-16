package main

import (
	"fmt"
	"math"
)

// Declare global variables
var N int
var A [1 << 18]int64
var dp [1 << 18][2][20]int64

func main() {
	// Read the number of elements
	fmt.Scan(&N)

	// Read the elements into the array A
	for i := 1; i <= N; i++ {
		fmt.Scan(&A[i])
	}

	// Initialize the dp array with a very small value
	for i := 0; i <= N; i++ {
		for j := 0; j < 20; j++ {
			dp[i][0][j] = -int64(math.Pow(2, 60)) // Initialize dp for state 0
			dp[i][1][j] = -int64(math.Pow(2, 60)) // Initialize dp for state 1
		}
	}

	// Base case: when no elements are considered, the value at dp[0][0][10] is 0
	dp[0][0][10] = 0

	// Fill the dp array based on previous states
	for i := 1; i <= N; i++ {
		for j := 6; j <= 14; j++ {
			// If the previous state in dp[i-1][0][j] is valid
			if dp[i-1][0][j] != -int64(math.Pow(2, 60)) {
				// Update the state dp[i][1][j + 1] by adding the current element A[i]
				dp[i][1][j+1] = max(dp[i][1][j+1], dp[i-1][0][j]+A[i])
				// Update the state dp[i][0][j - 1] without adding the current element
				dp[i][0][j-1] = max(dp[i][0][j-1], dp[i-1][0][j])
			}
			// If the previous state in dp[i-1][1][j] is valid
			if dp[i-1][1][j] != -int64(math.Pow(2, 60)) {
				// Update the state dp[i][0][j - 1] without adding the current element
				dp[i][0][j-1] = max(dp[i][0][j-1], dp[i-1][1][j])
			}
		}
	}

	// Calculate the target value V based on the number of elements
	V := 10 + (N / 2) - (N - (N / 2))

	// Retrieve the maximum values from the last state of dp
	T1 := dp[N][0][V]
	T2 := dp[N][1][V]

	// Output the maximum value obtained from the two states
	fmt.Println(max(T1, T2))
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
