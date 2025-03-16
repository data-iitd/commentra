package main

import (
	"fmt"
)

const MAX = 3000

var mat [MAX][MAX]int
var dp [MAX][MAX][4]int64
var dpl [MAX]int64

func main() {
	var rr, cc, k int

	// Read the number of rows (rr), columns (cc), and the number of values (k)
	fmt.Scan(&rr, &cc, &k)

	// Input the values into the matrix
	for i := 0; i < k; i++ {
		var r, c, v int
		fmt.Scan(&r, &c, &v)
		// Store the value in the matrix (adjusting for 0-based indexing)
		mat[r-1][c-1] = v
	}

	// Initialize the dynamic programming array with the value at the starting position
	dp[0][0][1] = int64(mat[0][0])

	// Iterate through each cell in the matrix
	for y := 0; y < rr; y++ {
		for x := 0; x < cc; x++ {
			// Iterate through the four possible states (c)
			for c := 0; c < 4; c++ {
				v := mat[y][x] // Get the current cell value
				var q int64    // Variable to store the computed maximum value

				// Check if we are at the first column or if the current value is zero
				if c == 0 || v == 0 {
					// If at the first column, take the value from dpl, else take the maximum from previous states
					if x == 0 {
						q = dpl[x]
					} else {
						q = max(dpl[x], dp[y][x-1][c])
					}
				} else {
					// If not at the first column, calculate the maximum considering the current value
					if x == 0 {
						q = dpl[x] + int64(v)
					} else {
						q = max(dpl[x]+int64(v), max(dp[y][x-1][c], dp[y][x-1][c-1]+int64(v)))
					}
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

// Helper function to find the maximum of two int64 values
func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

// Helper function to find the maximum of two int values
func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
