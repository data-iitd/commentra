package main

import (
	"fmt"
	"math"
)

func main() {
	// Ask the user for the number of elements in the list
	var n int
	fmt.Scan(&n)

	// Initialize a slice to store the integers
	l := make([]int, n)

	// Iterate n times and append each integer to the slice
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}

	// Initialize a variable to store the answer
	ans := n - 1

	// Initialize a variable to store the previous integer in the slice
	last := 0

	// Iterate through each integer in the slice
	for _, i := range l {
		// Calculate the absolute difference between the previous integer and the current integer
		// Add 1 to account for the number of steps between the two integers
		ans += int(math.Abs(float64(last-i))) + 1

		// Update the value of the previous integer
		last = i
	}

	// Print the value of the answer
	fmt.Println(ans)
}

// <END-OF-CODE>
