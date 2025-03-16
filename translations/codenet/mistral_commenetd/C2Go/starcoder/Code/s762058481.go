
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

// Function to return the minimum of two integers
func chmin(a, b int) int {
	// If 'a' is greater than 'b', return 'b'
	if a > b {
		return b
	}
	// Otherwise, return 'a'
	return a
}

// Main function
func main() {
	// Read the number of elements 'n' from the standard input
	var n int
	fmt.Scanf("%d", &n)

	// Allocate memory for two arrays 'dp' and 'h' of size 'n'
	dp := make([]int, n)
	h := make([]int, n)

	// Initialize all elements of 'dp' to a large value
	for i := 0; i < n; i++ {
		dp[i] = 10000
	}

	// Read the height of each element from the standard input
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &h[i])
	}

	// Initialize the first element of 'dp' to 0
	dp[0] = 0

	// Iterate through the array 'dp' from the second element to the last
	for i := 1; i < n; i++ {
		// Calculate the cost to reach the current index 'i' from the previous index 'i - 1'
		if i == 1 {
			dp[1] = abs(h[1] - h[0])
		}
		// Calculate the minimum cost to reach the current index 'i' from the previous index 'i - 1' or the previous previous index 'i - 2'
		else {
			dp[i] = chmin(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]))
		}
	}

	// Print the minimum cost to reach the last index 'n - 1'
	fmt.Printf("%d\n", dp[n-1])
}

