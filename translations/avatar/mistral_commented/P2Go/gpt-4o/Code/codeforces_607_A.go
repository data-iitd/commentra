package main

import (
	"fmt"
)

func main() {
	// Initialize the number of test cases
	var n int
	fmt.Scan(&n)

	// Initialize a slice 'l' of size 1000010 with zeros
	l := make([]int, 1000010)
	// Initialize a slice 'dp' of size 1000010 with zeros
	dp := make([]int, 1000010)

	// Read input for 'n' test cases
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		// Assign value 'b' to index 'a' in slice 'l'
		l[a] = b
	}

	// Check if the first element of the slice 'l' is positive
	if l[0] > 0 {
		// Set the first element of 'dp' to 1
		dp[0] = 1
	}

	// Initialize a variable 'mx' to keep track of the maximum length of a subsequence
	mx := 0

	// Iterate through the slice 'l' from index 1 to 1000010
	for i := 1; i < 1000010; i++ {
		// If the current element of 'l' is zero, set the corresponding element of 'dp' to the previous element
		if l[i] == 0 {
			dp[i] = dp[i-1]
		} else if l[i] >= i {
			// If the current element of 'l' is greater than or equal to 'i', set the corresponding element of 'dp' to 1
			dp[i] = 1
		} else {
			// If the current element of 'l' is less than 'i', calculate the length of the longest subsequence ending at 'i - l[i] - 1'
			// and add 1 to get the length of the subsequence ending at 'i'
			dp[i] = dp[i-l[i]-1] + 1
		}
		// Update the maximum length of a subsequence if a longer one is found
		if dp[i] > mx {
			mx = dp[i]
		}
	}

	// Print the answer, which is the number of elements in the longest subsequence that is not a subsequence of the given sequence
	fmt.Println(n - mx)
}

// <END-OF-CODE>
