<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// We declare the variables N and A of type int
var N int
var A [1 << 18]int

// We declare a 3-dimensional array dp of size (1 << 18) x 2 x 20
var dp [1 << 18][2][20]int

func main() {
	// Read the value of N from the standard input
	fmt.Scanf("%d", &N)

	// Read the values of the array A from the standard input
	for i := 1; i <= N; i++ {
		fmt.Scanf("%d", &A[i])
	}

	// Initialize dp array with minimum values
	for i := 0; i <= N; i++ {
		for j := 0; j < 20; j++ {
			dp[i][0][j] = -(1 << 60) // Initialize dp[i][0][j] with a very large negative value
			dp[i][1][j] = -(1 << 60) // Initialize dp[i][1][j] with a very large negative value
		}
	}

	// Base case: dp[0][0][10] = 0
	dp[0][0][10] = 0

	// Iterate through all the elements of the array A
	for i := 1; i <= N; i++ {
		for j := 6; j <= 14; j++ { // We only consider the cases where j is between 6 and 14
			if dp[i-1][0][j]!= -(1 << 60) { // If dp[i-1][0][j] is not equal to the very large negative value
				dp[i][1][j+1] = max(dp[i][1][j+1], dp[i-1][0][j]+A[i]) // Update dp[i][1][j+1] with the maximum of its current value and dp[i-1][0][j] + A[i]
				dp[i][0][j-1] = max(dp[i][0][j-1], dp[i-1][0][j]) // Update dp[i][0][j-1] with the maximum of its current value and dp[i-1][0][j]
			}
			if dp[i-1][1][j]!= -(1 << 60) { // If dp[i-1][1][j] is not equal to the very large negative value
				dp[i][0][j-1] = max(dp[i][0][j-1], dp[i-1][1][j]) // Update dp[i][0][j-1] with the maximum of its current value and dp[i-1][1][j]
			}
		}
	}

	// Calculate the value of T1 and T2
<<<<<<< HEAD
	V := 10 + (N/2) - (N-(N/2))
=======
	V := 10 + (N / 2) - (N - (N / 2))
>>>>>>> 98c87cb78a (data updated)
	T1 := dp[N][0][V]
	T2 := dp[N][1][V]

	// Print the maximum value of T1 and T2
	fmt.Printf("%d\n", max(T1, T2))
}

// We define the function max() to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

