package main

import (
	"fmt"
)

func main() {
	// Read an integer n from the standard input
	var n int
	fmt.Scan(&n)

	// Allocate a slice p of size n to store the input integers
	p := make([]int, n)

	// Read the integers into the slice p
	for i := 0; i < n; i++ {
		fmt.Scan(&p[i])
	}

	// Initialize the variable ans to 0
	ans := 0

	// Iterate through the slice p from index 0 to n-3
	for i := 0; i < n-2; i++ {
		// Check if the current element p[i] is smaller than the next two elements p[i+1] and p[i+2]
		if p[i] < p[i+1] && p[i+1] < p[i+2] {
			// Increment the ans variable if both conditions are true
			ans++
		}

		// Check if the current element p[i] is greater than the next two elements p[i+1] and p[i+2]
		if p[i] > p[i+1] && p[i+1] > p[i+2] {
			// Increment the ans variable if both conditions are true
			ans++
		}
	}

	// Print the value of ans to the standard output
	fmt.Println(ans)
}

// <END-OF-CODE>
