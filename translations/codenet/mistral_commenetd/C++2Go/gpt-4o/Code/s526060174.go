package main

import (
	"fmt"
)

func main() {
	var n, m int // Declare variables n and m for input size
	var k, a int // Declare variables k and a for intermediate calculations
	x := make([]int, 32) // Initialize a slice x of size 32 with zeros (index 0 will be unused)

	// Read input values for n and m
	fmt.Scan(&n, &m)

	// Process each input value for n times
	for i := 0; i < n; i++ {
		fmt.Scan(&k) // Read the number of elements in the current input

		// Process each element in the current input
		for j := 0; j < k; j++ {
			fmt.Scan(&a) // Read the value of the current element
			x[a]++ // Increment the count of the current value in the slice x
		}
	}

	// Initialize answer variable to zero
	ans := 0

	// Check each value from 1 to m and increment the answer if the count is equal to n
	for i := 1; i <= m; i++ {
		if x[i] == n { // Check if the count of the current value is equal to n
			ans++ // Increment the answer if true
		}
	}

	// Output the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
