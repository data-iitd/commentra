package main

import (
	"fmt"
)

func main() {
	var i, n, ans int // Declare variables for iteration, size of vector, and answer count
	fmt.Scan(&n) // Input the size of the vector
	p := make([]int, n) // Initialize a slice of size n

	// Input the elements of the vector
	for i = 0; i < n; i++ {
		fmt.Scan(&p[i]) // Read each element into the slice
	}

	ans = 0 // Initialize the answer counter to zero

	// Loop through the slice to check for specific conditions
	for i = 0; i < n - 1; i++ {
		// Check if the current element matches its expected position (1-based index)
		if p[i] == i + 1 {
			p[i + 1] = p[i] // Set the next element to the current element
			ans += 1 // Increment the answer counter
		}
	}

	// Check if the last element matches its expected position
	if p[n - 1] == n {
		ans += 1 // Increment the answer counter if the condition is met
	}

	fmt.Println(ans) // Output the final count of matches
}

