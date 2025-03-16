package main

import (
	"fmt"
	"math"
)

func main() {
	// Read an integer input which represents the number of elements
	var n int
	fmt.Scan(&n)

	// Read a line of input, split it into individual strings, convert them to integers, and store them in a slice
	r := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&r[i])
	}

	// Initialize the answer with the absolute value of the first element in the slice
	ans := int(math.Abs(float64(r[0])))

	// Iterate through the slice starting from the second element
	for i := 1; i < n; i++ {
		// Add the absolute difference between the current element and the previous element to the answer
		ans += int(math.Abs(float64(r[i] - r[i-1])))
	}

	// Print the final computed answer
	fmt.Println(ans)
}

// <END-OF-CODE>
