package main

import (
	"fmt"
	"math"
)

func main() {
	// Create a variable to read input from the console
	var n int
	// Read the number of elements in the array
	fmt.Scan(&n)

	// Initialize a slice to hold the input integers
	arr := make([]int, n)

	// Populate the slice with integers from user input
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	// Initialize the answer with the first element of the slice plus one
	ans := arr[0] + 1

	// Calculate the total distance based on the differences between consecutive elements
	for i := 1; i < n; i++ {
		// Add the absolute difference between the current and previous element, plus 2
		ans += int(math.Abs(float64(arr[i] - arr[i-1]))) + 2
	}

	// Output the final calculated answer
	fmt.Println(ans)
}

// <END-OF-CODE>
