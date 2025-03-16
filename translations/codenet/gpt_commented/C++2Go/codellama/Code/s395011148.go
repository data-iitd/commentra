package main

import (
	"fmt"
	"math"
)

// Declare global variables
var N int // N is the number of elements
var A []int // A is the array to hold the elements
var dp [][][]int // dp array for dynamic programming

func main() {
	// Read the number of elements
	fmt.Scan(&N)

	// Initialize the dp array with a very small value
	dp = make([][][]int, N + 1)
	for i := 0; i <= N; i++ {
		dp[i] = make([][]int, 2)
		for j := 0; j < 2; j++ {
			dp[i][j] = make([]int, 20)
			for k := 0; k < 20; k++ {
				dp[i][j][k] = math.MinInt64
			}
		}
	}

	// Read the elements into the array A
	A = make([]int, N + 1)
	for i := 1; i <= N; i++ {
		fmt.Scan(&A[i])
	}

	// Base case: when no elements are considered, the value at dp[0][0][10] is 0
	dp[0][0][10] = 0

	// Fill the dp array based on previous states
	for i := 1; i <= N; i++ {
		for j := 6; j <= 14; j++ {
			// If the previous state in dp[i-1][0][j] is valid
			if dp[i - 1][0][j] != math.MinInt64 {
				// Update the state dp[i][1][j + 1] by adding the current element A[i]
				dp[i][1][j + 1] = max(dp[i][1][j + 1], dp[i - 1][0][j] + A[i])
				// Update the state dp[i][0][j - 1] without adding the current element
				dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][0][j])
			}
			// If the previous state in dp[i-1][1][j] is valid
			if dp[i - 1][1][j] != math.MinInt64 {
				// Update the state dp[i][0][j - 1] without adding the current element
				dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][1][j])
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

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// 