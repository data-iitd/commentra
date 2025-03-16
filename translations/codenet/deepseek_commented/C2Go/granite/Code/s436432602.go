
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements (n) and the target value (k)
	n, _ := strconv.Atoi(read(reader))
	k, _ := strconv.Atoi(read(reader))

	// Declare an array to store the elements
	a := make([]int, n)

	// Read n elements into the array a
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(read(reader))
	}

	// Allocate memory for the dynamic programming array dp
	dp := make([]int, k+1)

	// Iterate from 1 to k to fill the dp array
	for i := 1; i <= k; i++ {
		// Initialize the win flag to 0
		win := 0

		// Check each element in the array a to see if it can be subtracted from i
		for j := 0; j < n && a[j] <= i; j++ {
			if dp[i-a[j]] == 0 {
				// If the resulting value is zero, set win to 1
				win = 1
			}
		}

		// Set dp[i] to the win flag
		dp[i] = win
	}

	// Print the result based on the value of dp[k]
	fmt.Println(dp[k])
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

