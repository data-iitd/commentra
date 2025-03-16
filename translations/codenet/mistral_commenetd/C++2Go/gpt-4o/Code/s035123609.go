package main

import (
	"fmt"
)

const MAXN = 3000

var mat [MAXN][MAXN]int64        // 2D matrix to store the given grid data
var dp [MAXN][MAXN][4]int64      // 3D dp array to store the maximum sum of submatrices with different conditions
var dpl [MAXN]int64               // 1D array to store the maximum sum of submatrices ending at the current column

func main() {
	var rr, cc, k int // rr: number of rows, cc: number of columns, k: number of given values

	fmt.Scan(&rr, &cc, &k) // reading input dimensions and number of given values

	for i := 0; i < k; i++ { // reading given values and updating the matrix
		var r, c int
		var v int64
		fmt.Scan(&r, &c, &v)
		mat[r-1][c-1] = v
	}

	dp[0][0][1] = mat[0][0] // base case for a 1x1 submatrix

	for y := 0; y < rr; y++ { // iterating through each row
		for x := 0; x < cc; x++ { // iterating through each column
			for c := 0; c < 4; c++ { // iterating through all conditions (top, left, diagonal, and bottom-left)
				v := mat[y][x] // current cell value
				var q int64
				if c == 0 || v == 0 { // if the current condition is top or the cell value is zero
					if x == 0 {
						q = dpl[x]
					} else {
						q = max(dpl[x], dp[y][x-1][c]) // the maximum sum of submatrices ending at the current column or the maximum sum of submatrices ending at the previous column with the same condition
					}
				} else { // if the current condition is left, diagonal, or bottom-left
					if x == 0 {
						q = dpl[x] + v
					} else {
						q = max(dpl[x]+v, max(dp[y][x-1][c], dp[y][x-1][c-1]+v)) // the maximum sum of submatrices ending at the current column or the maximum sum of submatrices with the same conditions at the previous cell and the current cell
					}
				}
				dp[y][x][c] = q // updating the dp array with the maximum sum of submatrices with the current condition
			}
		}
		for x := 0; x < cc; x++ { // updating the dpl array with the maximum sum of submatrices ending at the current column
			dpl[x] = max(max(dp[y][x][0], dp[y][x][1]), max(dp[y][x][2], dp[y][x][3]))
		}
	}

	fmt.Println(dpl[cc-1]) // printing the maximum sum of submatrix ending at the last column
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
