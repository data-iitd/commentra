package main

import (
	"fmt" // Importing required Go package for input and output
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of elements in the array from the console

	beacon := make([]int, 1000001) // Creating a slice of size 1000001 to store the indices of beacons
	dp := make([]int, 1000001)      // Creating a slice of size 1000001 to store the length of the longest subsequence ending at each index

	for i := 0; i < n; i++ { // Loop to read the elements and their indices from the console
		var a, index int
		fmt.Scan(&a, &index) // Reading the element and its corresponding index
		beacon[a] = index    // Storing the index of the beacon for the given element
	}

	max := 0 // Initializing max variable to store the maximum length of a subsequence

	if beacon[0] != 0 {
		dp[0] = 1 // If the first beacon exists, the length of the subsequence ending at index 0 is 1
	}

	for i := 1; i < 1000001; i++ { // Loop to calculate the length of the longest subsequence ending at each index
		if beacon[i] != 0 && beacon[i] < i {
			dp[i] = dp[i-beacon[i]-1] + 1 // Update the length of the subsequence if the beacon exists and its index is less than the current index
		} else if beacon[i] != 0 {
			dp[i] = 1 // If the beacon exists but its index is greater than or equal to the current index, the length of the subsequence is 1
		} else {
			dp[i] = dp[i-1] // If there is no beacon, the length of the subsequence remains the same as the previous index
		}
		max = maxInt(max, dp[i]) // Updating the maximum length of the subsequence
	}

	fmt.Print(n - max) // Printing the difference between the total number of elements and the maximum length of the subsequence
}

// maxInt is a helper function to return the maximum of two integers
func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}
