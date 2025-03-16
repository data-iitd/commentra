package main

import (
	"fmt"
)

func main() {
	// Read the number of elements
	var n int
	fmt.Scan(&n)

	// Initialize a slice to store the elements
	a := make([]int, n)

	// Input the elements into the slice
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize the answer counter
	ans := 0

	// Loop until an odd number is found in the slice
	for {
		// Check each element in the slice
		foundOdd := false
		for i := 0; i < n; i++ {
			// If the current element is odd, print the answer and exit
			if a[i]%2 == 1 {
				fmt.Println(ans)
				return
			}
			// If the current element is even, divide it by 2
			a[i] /= 2
		}
		// Increment the answer counter for each complete iteration
		ans++
	}
}

// <END-OF-CODE>
