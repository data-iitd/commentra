
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Read the total number of items (n) to be processed
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Define the maximum size for the dp array
	maxn := 4010

	// Read three integer values (a, b, c) which represent the sizes of items
	scanner.Scan()
	a, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	b, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	c, _ := strconv.Atoi(scanner.Text())

	// Store the sizes of items in an array for easier access
	arr := []int{a, b, c}

	// Initialize a dp array to store the maximum number of items that can be formed
	dp := make([]int, maxn)

	// Set all dp values to Integer.MIN_VALUE to indicate uncomputed states
	for i := 0; i < n; i++ {
		dp[i] = -100000000
	}

	// Base case: zero items can be formed with zero size
	dp[0] = 0

	// Iterate through each item size (a, b, c)
	for i := 0; i < 3; i++ {
		// Update the dp array for each possible size from the current item size
		for j := arr[i]; j < maxn; j++ {
			// Calculate the maximum number of items that can be formed
			dp[j] = max(dp[j], dp[j-arr[i]]+1)
		}
	}

	// Output the maximum number of items that can be formed with size n
	fmt.Println(dp[n])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

