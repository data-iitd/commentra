
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of rows (rr), columns (cc), and the number of values (k)
	var rr, cc, k int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d %d\n", &rr, &cc, &k)

	// Declare a matrix to store values
	mat := make([][]int, rr)
	for i := 0; i < rr; i++ {
		mat[i] = make([]int, cc)
	}

	// Input the values into the matrix
	for i := 0; i < k; i++ {
		var r, c, v int
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d %d\n", &r, &c, &v)
		// Store the value in the matrix (adjusting for 0-based indexing)
		mat[r-1][c-1] = v
	}

	// Initialize the dynamic programming array with the value at the starting position
	dp := make([][][]int64, rr)
	for i := 0; i < rr; i++ {
		dp[i] = make([][]int64, cc)
		for j := 0; j < cc; j++ {
			dp[i][j] = make([]int64, 4)
			dp[i][j][1] = int64(mat[i][j])
		}
	}

	// Iterate through each cell in the matrix
	for y := 0; y < rr; y++ {
		for x := 0; x < cc; x++ {
			// Iterate through the four possible states (c)
			for c := 0; c < 4; c++ {
				v := int64(mat[y][x]) // Get the current cell value
				var q int64 // Variable to store the computed maximum value

				// Check if we are at the first column or if the current value is zero
				if c == 0 || v == 0 {
					// If at the first column, take the value from dpl, else take the maximum from previous states
					q = (x == 0)? dpl[x] : max(dpl[x], dp[y][x-1][c])
				} else {
					// If not at the first column, calculate the maximum considering the current value
					q = (x == 0)? dpl[x] + v : max(dpl[x] + v, max(dp[y][x-1][c], dp[y][x-1][c-1] + v))
				}
				// Store the computed maximum value in the dp array
				dp[y][x][c] = q
			}
		}
		// Update the dpl array with the maximum values from the current row
		for x := 0; x < cc; x++ {
			dpl[x] = max(max(dp[y][x][0], dp[y][x][1]), max(dp[y][x][2], dp[y][x][3]))
		}
	}

	// Output the maximum value found in the last column
	fmt.Println(dpl[cc-1])
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

// Translate the above Go code to Rust and end with comment "