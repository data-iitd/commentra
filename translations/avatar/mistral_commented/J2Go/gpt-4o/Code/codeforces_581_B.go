package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of elements in the array
	a := make([]int64, n) // Creating a slice of size n to store the elements

	for i := 0; i < n; i++ { // Loop to read the elements of the array from the input
		fmt.Scan(&a[i])
	}

	dp := make([]int64, n+1) // Creating a slice of size n+1 to store the maximum subarray sum ending at each index
	for i := range dp {
		dp[i] = -1 // Initializing all the elements of the dp slice with -1
	}
	dp[n-1] = a[n-1] // Setting the last element of the dp slice with the last element of the array

	for i := n - 1; i >= 0; i-- { // Loop to calculate the maximum subarray sum ending at each index
		dp[i] = max(dp[i+1], a[i])
	}

	for i := 0; i < n; i++ { // Loop to print the answer for each test case
		if a[i] > dp[i+1] { // If the current element is greater than the maximum subarray sum ending at next index
			fmt.Print(0, " ") // Print 0 as the answer
		} else {
			fmt.Print(dp[i+1]-a[i]+1, " ") // Else print the length of the subarray ending at current index
		}
	}

	fmt.Println() // Printing a newline character at the end of the output
}

// max function to return the maximum of two int64 values
func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
