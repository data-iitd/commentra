package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner to read input from the console
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of elements in the array and the number of queries
	var n, k int
	fmt.Scan(&n, &k)

	// Initialize an array to hold the input values
	arr := make([]int, n)

	// Populate the array with input values
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	// StringBuffer to store the results of the queries
	res := ""

	// Counters for the number of 1s (o) and 0s (e) in the array
	o, e := 0, 0

	// Count the number of 1s and 0s in the array
	for i := 0; i < n; i++ {
		if arr[i] == 1 {
			o++ // Increment count of 1s
		} else {
			e++ // Increment count of 0s
		}
	}

	// Process each query
	for i := 0; i < k; i++ {
		// Read the left and right indices for the current query
		var l, r int
		fmt.Scan(&l, &r)

		// Check if the number of elements in the range is odd
		if (r-l+1)%2 == 1 {
			res += "0\n" // If odd, append "0" to results
		} else {
			// If even, check if we can form a valid pair of 1s and 0s
			if (r-l+1)/2 <= o && (r-l+1)/2 <= e {
				res += "1\n" // Append "1" if valid pairs can be formed
			} else {
				res += "0\n" // Otherwise, append "0"
			}
		}
	}

	// Output the results of all queries
	fmt.Print(res)
}

