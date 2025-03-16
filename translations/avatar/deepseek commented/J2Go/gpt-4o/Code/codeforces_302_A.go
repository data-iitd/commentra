package main

import (
	"fmt"
)

func main() {
	// Step 1: Read the input values for n and k
	var n, k int
	fmt.Scan(&n, &k) // Read the size of the array and the number of queries

	// Step 2: Read the array elements
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i]) // Read each element of the array
	}

	// Step 3: Initialize two counters, o and e, to count the number of 1s and 0s in the array, respectively
	var res string // To store the result
	o, e := 0, 0   // Counters for 1s and 0s

	// Step 4: Iterate through the array to count the number of 1s and 0s
	for i := 0; i < n; i++ {
		if arr[i] == 1 {
			o++ // Increment the counter for 1s
		} else {
			e++ // Increment the counter for 0s
		}
	}

	// Step 5: For each query, determine if the length of the subarray is odd
	for i := 0; i < k; i++ {
		var l, r int
		fmt.Scan(&l, &r) // Read the left and right index of the subarray

		if (r-l+1)%2 == 1 {
			res += "0\n" // Append "0" if the length is odd
		} else {
			// Step 6: If the length of the subarray is even, check if the number of 1s and 0s is sufficient
			if (r-l+1)/2 <= o && (r-l+1)/2 <= e {
				res += "1\n" // Append "1" if the condition is satisfied
			} else {
				res += "0\n" // Append "0" if the condition is not satisfied
			}
		}
	}

	// Step 7: Print the result
	fmt.Print(res)
}
