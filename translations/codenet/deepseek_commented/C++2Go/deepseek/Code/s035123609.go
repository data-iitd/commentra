package main

import (
	"fmt"
	"math"
)

func main() {
	var rr, cc, k int

	// Read input values for rows, columns, and number of non-zero elements
	fmt.Scan(&rr, &cc, &k)

	// Define the matrix and DP arrays
	mat := make([][]int, rr)
	for i := range mat {
		mat[i] = make([]int, cc)
	}
	dp := make([][][]float64, rr)
	for i := range dp {
		dp[i] = make([][]float64, cc)
		for j := range dp[i] {
			dp[i][j] = make([]float64, 4)
		}
	}
	dpl := make([]float64, cc)

	// Read each non-zero element's row, column, and value, and store in the matrix
	for i := 0; i < k; i++ {
		var r, c, v int
		fmt.Scan(&r, &c, &v)
		mat[r-1][c-1] = v
	}

	// Initialize the DP table for the starting cell
	dp[0][0][1] = float64(mat[0][0])

	// Fill the DP table
	for y := 0; y < rr; y++ {
		for x := 0; x < cc; x++ {
			for c := 0; c < 4; c++ {
				v := float64(mat[y][x])
				var q float64
				// Update the DP table based on the current cell's value and previous values
				if c == 0 || v == 0 {
					if x == 0 {
						q = dpl[x]
					} else {
						q = math.Max(dpl[x], dp[y][x-1][c])
					}
				} else {
					if x == 0 {
						q = dpl[x] + v
					} else {
						q = math.Max(dpl[x]+v, math.Max(dp[y][x-1][c], dp[y][x-1][c-1]+v))
					}
				}
				dp[y][x][c] = q
			}
		}
		// Update the maximum values for each column after processing the current row
		for x := 0; x < cc; x++ {
			dpl[x] = math.Max(math.Max(dp[y][x][0], dp[y][x][1]), math.Max(dp[y][x][2], dp[y][x][3]))
		}
	}

	// Output the maximum value in the last column of the last row
	fmt.Println(dpl[cc-1])
}

