package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	var a, b, c int
	fmt.Scan(&a, &b, &c)

	// Define an array to store the array elements
	arr := []int{a, b, c}

	// Define a dynamic programming array of size maxn
	maxn := 4010
	dp := make([]int, maxn)

	// Initialize the dynamic programming array with minimum values
	for i := 0; i < maxn; i++ {
		dp[i] = -1 << 31 // Setting all elements to minimum value
	}

	dp[0] = 0 // Setting the first element to 0

	// Fill the dynamic programming array using two nested loops
	for i := 0; i < 3; i++ { // Looping through the array elements
		for j := arr[i]; j < maxn; j++ { // Looping through the dynamic programming array
			if dp[j] < dp[j-arr[i]]+1 {
				dp[j] = dp[j-arr[i]] + 1
			}
		}
	}

	// Print the result, which is the maximum length ending at the nth index
	fmt.Println(dp[n])
}
