

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize a Scanner object to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Read three integers from the user
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	maxn := 4010
	a, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	b, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	c, _ := strconv.Atoi(scanner.Text())

	// Store the coin values in an array
	arr := []int{a, b, c}

	// Initialize a dp array with all elements set to Integer.MIN_VALUE
	dp := make([]int, maxn)
	for i := 0; i < n; i++ {
		dp[i] = -100000000
	}

	// Set the base case where dp[0] is 0
	dp[0] = 0

	// Iterate over the coin values and update the dp array
	for i := 0; i < 3; i++ {
		for j := arr[i]; j < maxn; j++ {
			dp[j] = max(dp[j], dp[j-arr[i]]+1)
		}
	}

	// Print the value of dp[n]
	fmt.Println(dp[n])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// END-OF-CODE