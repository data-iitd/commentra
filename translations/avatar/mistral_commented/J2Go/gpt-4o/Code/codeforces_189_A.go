package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of elements in the array from the console

	maxn := 4010 // Defining the maximum size of the dynamic programming array

	// Reading the three integers representing the array elements
	var a, b, c int
	fmt.Scan(&a, &b, &c)

	// Defining a slice to store the array elements
	arr := []int{a, b, c}

	dp := make([]int, maxn) // Creating a dynamic programming slice of size maxn

	// Initializing the dynamic programming slice with minimum values
	for i := 0; i < n; i++ {
		dp[i] = -1 << 31 // Setting all elements to minimum value (Integer.MIN_VALUE equivalent)
	}

	dp[0] = 0 // Setting the first element to 0

	// Filling the dynamic programming slice using two nested loops
	for i := 0; i < 3; i++ { // Looping through the array elements
		for j := arr[i]; j < len(dp); j++ { // Looping through the dynamic programming slice
			dp[j] = max(dp[j], dp[j-arr[i]]+1) // Updating the maximum length ending at j
		}
	}

	// Printing the result, which is the maximum length ending at the nth index
	fmt.Println(dp[n])
}

// max function to return the maximum of two integers
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

// <END-OF-CODE>
