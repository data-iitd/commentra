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
	for i := range a {
		fmt.Scan(&a[i])
	}

	// Initialize a 2D list 'b' with None values to store minimum values
	b := make([][]int, n)
	for i := range b {
		b[i] = make([]int, n)
	}

	// Fill the 2D list 'b' with minimum values from 'a'
	for i := range b {
		m := a[i] // Start with the current element
		for j := range b[i] {
			k := i - j // Calculate the index to wrap around
			if k < 0 {
				k += n // Wrap around if index is negative
			}
			m = int(math.Min(float64(m), float64(a[k]))) // Update m to be the minimum value found
			b[i][j] = m                                   // Store the minimum value in the 2D list 'b'
		}
	}

	// Initialize a large value for comparison
	m := 100000000000000000

	// Calculate the minimum sum of elements in each row of 'b' plus the weighted index
	for i, j := range b {
		m = int(math.Min(float64(m), float64(sum(j)+x*i))) // Update m with the minimum found
	}

	// Print the final minimum value
	fmt.Println(m)
}

// sum calculates the sum of elements in a list
func sum(a []int) int {
	var s int
	for _, v := range a {
		s += v
	}
	return s
}

// 