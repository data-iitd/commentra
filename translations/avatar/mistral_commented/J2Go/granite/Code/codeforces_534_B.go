
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Reading input variables from the user
	v1, _ := strconv.Atoi(reader.ReadLine()[2:]) // Reading the first integer value
	v2, _ := strconv.Atoi(reader.ReadLine()[2:]) // Reading the second integer value
	t, _ := strconv.Atoi(reader.ReadLine()[2:]) // Reading the number of time steps
	d, _ := strconv.Atoi(reader.ReadLine()[2:]) // Reading the maximum difference between two consecutive values

	dp := make([][]int64, t-1) // Creating a 2D array dp of size (t-1) x 1150 for dynamic programming table

	// Initializing the first row of the dp table with the given value
	for i := 0; i < t-1; i++ {
		dp[i] = make([]int64, 1150) // Initializing a new row of the dp table with 1150 elements
		for j := 0; j < 1150; j++ {
			dp[i][j] = -999999999999999999 // Initializing all elements of the current row with a very small value
		}
		dp[i][v1] = int64(v1) // Setting the value of the cell (i, v1) to v1
	}

	sum := int64(0) // Initializing a variable sum to 0

	// Filling the dp table using dynamic programming
	for i := 1; i < t-1; i++ {
		for j := 0; j < 1150; j++ {
			for x := 0; x <= d; x++ {
				dp[i][j] = max(dp[i][j], dp[i-1][j+x]+int64(j)) // Filling the current cell with the maximum value of itself and the sum of the previous cell and the current element plus the jump
			}
			for x := d; x >= 0; x-- {
				dp[i][j] = max(dp[i][j], dp[i-1][j-x]+int64(j)) // Filling the current cell with the maximum value of itself and the sum of the previous cell and the current element minus the jump
			}
		}
		sum += dp[i][1149] // Adding the value of the last cell of the current row to the sum
	}

	ans := int64(-999999999999999999) // Initializing a variable ans with a very small value

	// Finding the maximum value that can be obtained by jumping from any cell in the last but one row to the last row and adding the value of the last cell of the last row
	for i := t - 2; i < t - 1; i++ {
		for j := 0; j < 1150; j++ {
			if abs(int64(j)-int64(v2)) <= int64(d) { // Checking if the absolute difference between j and v2 is less than or equal to d
				ans = max(ans, dp[i][j]+int64(v2)) // Updating the value of ans with the maximum of itself and the sum of the current cell and v2
			}
		}
	}

	fmt.Println(ans) // Printing the final answer
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func abs(a int64) int64 {
	if a < 0 {
		return -a
	}
	return a
}

// Translate the above Go code to C++ and end with comment "