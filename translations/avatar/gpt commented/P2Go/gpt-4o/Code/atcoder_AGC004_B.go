package main

import (
	"fmt"
	"math"
)

func main() {
	// Read input values: n (number of elements) and x (a multiplier)
	var n, x int
	fmt.Scan(&n, &x)

	// Read the list of integers 'a' from input
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize a 2D slice 'b' to store minimum values
	b := make([][]int, n)
	for i := range b {
		b[i] = make([]int, n)
	}

	// Fill the 2D slice 'b' with minimum values from 'a'
	for i := 0; i < n; i++ {
		m := a[i] // Start with the current element
		for j := 0; j < n; j++ {
			k := i - j // Calculate the index to wrap around
			if k < 0 {
				k += n // Wrap around if index is negative
			}
			m = int(math.Min(float64(m), float64(a[k]))) // Update m to be the minimum value found
			b[j][i] = m // Store the minimum value in the 2D slice 'b'
		}
	}

	// Initialize a large value for comparison
	m := int(1e15)

	// Calculate the minimum sum of elements in each row of 'b' plus the weighted index
	for i, row := range b {
		sum := 0
		for _, value := range row {
			sum += value
		}
		m = int(math.Min(float64(m), float64(sum+x*i))) // Update m with the minimum found
	}

	// Print the final minimum value
	fmt.Println(m)
}

// <END-OF-CODE>
