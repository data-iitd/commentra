package main

import (
	"fmt"
	"math"
)

func main() {
	// Read the number of elements from user input
	var n int
	fmt.Scan(&n)

	// Initialize a slice to store the elements
	l := make([]int, n)

	// Loop to read 'n' integers from user input and append them to the slice
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}

	// Initialize the answer variable to n - 1 (to account for n-1 gaps between n elements)
	ans := n - 1

	// Initialize a variable to keep track of the last element processed
	last := 0

	// Loop through each element in the slice
	for _, i := range l {
		// Calculate the distance from the last element to the current element
		// and add 1 for the step to the current element
		ans += int(math.Abs(float64(last-i))) + 1

		// Update 'last' to the current element for the next iteration
		last = i
	}

	// Print the final calculated answer
	fmt.Println(ans)
}

// <END-OF-CODE>
