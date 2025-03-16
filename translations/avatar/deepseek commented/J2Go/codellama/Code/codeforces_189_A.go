
package main

import (
	"fmt"
	"math"
)

func main() {
	// Initialize a Scanner object to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Read three integers from the user
	var n, maxn, a, b, c int
	fmt.Scan(&n, &maxn, &a, &b, &c)

	// Store the coin values in an array
	arr := []int{a, b, c}

	// Initialize a dp array with all elements set to Integer.MIN_VALUE
	dp := make([]int, maxn)
	for i := 0; i < n; i++ {
		dp[i] = math.MinInt32
	}

	// Set the base case where dp[0] is 0
	dp[0] = 0

	// Iterate over the coin values and update the dp array
	for i := 0; i < 3; i++ {
		for j := arr[i]; j < len(dp); j++ {
			dp[j] = max(dp[j], dp[j-arr[i]]+1)
		}
	}

	// Print the value of dp[n]
	fmt.Println(dp[n])
}

// 