package main

import (
	"fmt"
	"math"
)

func main() {
	// Read the number of elements
	var n int
	fmt.Scan(&n)

	// Read the elements into a slice and convert them to integers
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize a slice 'b' with zeros to store the positions of elements
	b := make([]int, n)

	// Populate the slice 'b' with the indices of elements from slice 'a'
	for i := 0; i < n; i++ {
		b[a[i]-1] = i // Store the index of each element in 'b' based on its value in 'a'
	}

	// Initialize the result variable to accumulate the total distance
	res := 0

	// Calculate the total distance between consecutive elements in 'b'
	for i := 1; i < n; i++ {
		res += int(math.Abs(float64(b[i] - b[i-1]))) // Add the absolute difference of indices to the result
	}

	// Print the final result
	fmt.Println(res)
}

// <END-OF-CODE>
