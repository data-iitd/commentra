package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Use bufio for faster input reading
	reader := bufio.NewReader(os.Stdin)

	// Initialize a constant N for the size of the arrays
	const N = 368

	// Create two slices to track the values for 'M' and 'F'
	m := make([]int, N) // Slice to track 'M' values
	f := make([]int, N) // Slice to track 'F' values

	// Read the number of operations from input
	var t int
	fmt.Fscan(reader, &t)

	for i := 0; i < t; i++ {
		// Read the operation type and the indices a and b
		var x string
		var a, b int
		fmt.Fscan(reader, &x, &a, &b)

		b++ // Increment b by 1 for range adjustment

		// Update the corresponding slice based on the operation type
		if x == "M" {
			m[a] += 2  // Increment the value at index a in the 'M' slice
			m[b] -= 2  // Decrement the value at index b in the 'M' slice
		} else {
			f[a] += 2  // Increment the value at index a in the 'F' slice
			f[b] -= 2  // Decrement the value at index b in the 'F' slice
		}
	}

	// Initialize variables to track cumulative sums and the minimum value
	a, b, c := 0, 0, 0

	// Iterate through the range of N to calculate cumulative sums and find the minimum
	for i := 0; i < N; i++ {
		a += m[i] // Update cumulative sum for 'M'
		b += f[i] // Update cumulative sum for 'F'

		// Update the minimum value if the current minimum of a and b is greater than c
		if min(a, b) > c {
			c = min(a, b) // Set c to the new minimum value
		}
	}

	// Print the final minimum value found
	fmt.Println(c)
}

// Helper function to find the minimum of two integers
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

// <END-OF-CODE>
