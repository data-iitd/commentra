package main

import (
	"fmt"
)

const MAXN = 3000

var mat [MAXN][MAXN]int
var dp [MAXN][MAXN][4]int64
var dpl [MAXN]int64

func main() {
	var rr, cc, k int

	// Read input values for rows, columns, and number of non-zero elements
	fmt.Scan(&rr, &cc, &k)

	// Read each non-zero element's row, column, and value, and store in the matrix
	for i := 0; i < k; i++ {
		var r, c, v int
		fmt.Scan(&r, &c, &v)
		mat[r-1][c-1] = v
	}

	// Initialize the DP table for the starting cell
	dp[0][0][1] = int64(mat[0][0])

	// Fill the DP table
	for y := 0; y < rr; y++ {
		for x := 0; x < cc; x++ {
			for c := 0; c < 4; c++ {
				v := mat[y][x]
				var q int64
				// Update the DP table based on the current cell's value and previous values
				if c == 0 || v == 0 {
					if x == 0 {
						q = dpl[x]
					} else {
						q = max(dpl[x], dp[y][x-1][c])
					}
				} else {
					if x == 0 {
						q = dpl[x] + int64(v)
					} else {
						q = max(dpl[x]+int64(v), max(dp[y][x-1][c], dp[y][x-1][c-1]+int64(v)))
					}
				}
				dp[y][x][c] = q
			}
		}
		// Update the maximum values for each column after processing the current row
		for x := 0; x < cc; x++ {
			dpl[x] = max(max(dp[y][x][0], dp[y][x][1]), max(dp[y][x][2], dp[y][x][3]))
		}
	}

	// Output the maximum value in the last column of the last row
	fmt.Println(dpl[cc-1])
}

// max function to return the maximum of two int64 values
func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

// max function to return the maximum of three int64 values
func max3(a, b, c int64) int64 {
	return max(max(a, b), c)
}

// max function to return the maximum of four int64 values
func max4(a, b, c, d int64) int64 {
	return max(max3(a, b, c), d)
}

// <END-OF-CODE>
