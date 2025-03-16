package main

import (
	"fmt"
	"math"
)

func main() {
	var v1, v2, t, d int
	fmt.Scan(&v1, &v2, &t, &d) // Reading input variables from the user

	dp := make([][]int64, t-1) // Creating a 2D slice dp of size (t-1) for dynamic programming table
	for i := range dp {
		dp[i] = make([]int64, 1150) // Initializing each row with a slice of size 1150
		for j := range dp[i] {
			dp[i][j] = math.MinInt64 // Initializing all elements of the current row with minimum int64 value
		}
		dp[i][v1] = int64(v1) // Setting the value of the cell (i, v1) to v1
	}

	var sum int64 = 0 // Initializing a variable sum to 0

	// Filling the dp table using dynamic programming
	for i := 1; i < t-1; i++ {
		for j := 0; j < 1150; j++ {
			for x := 0; x <= d; x++ {
				if j+x < 1150 {
					dp[i][j] = max(dp[i][j], dp[i-1][j+x]+int64(j)) // Filling the current cell with the maximum value
				}
			}
			for x := d; x >= 0; x-- {
				if j-x >= 0 {
					dp[i][j] = max(dp[i][j], dp[i-1][j-x]+int64(j)) // Filling the current cell with the maximum value
				}
			}
		}
		sum += dp[i][1149] // Adding the value of the last cell of the current row to the sum
	}

	var ans int64 = math.MinInt64 // Initializing a variable ans with minimum int64 value

	// Finding the maximum value that can be obtained by jumping from any cell in the last but one row to the last row
	for i := t - 2; i < t-1; i++ {
		for j := 0; j < 1150; j++ {
			if abs(j-v2) <= d { // Checking if the absolute difference between j and v2 is less than or equal to d
				ans = max(ans, dp[i][j]+int64(v2)) // Updating the value of ans
			}
		}
	}

	fmt.Println(ans) // Printing the final answer
}

// max function to return the maximum of two int64 values
func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

// abs function to return the absolute value of an integer
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
