package main

import (
	"fmt"
	"math"
)

func main() {
	// Take input of number of test cases and number of elements in each test case
	var n, x int
	fmt.Scan(&n, &x)

	// Initialize a slice 'a' to store the given elements
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize a 2D slice 'b' of size n x n
	b := make([][]int, n)
	for i := range b {
		b[i] = make([]int, n)
	}

	// Iterate through each row of slice 'a'
	for i := 0; i < n; i++ {
		// Initialize a variable 'm' to store the minimum element in the current row
		m := a[i]

		// Iterate through each column of slice 'b'
		for j := 0; j < n; j++ {
			// Calculate the index 'k' based on the current row and column indices
			k := i - j

			// If the index 'k' is negative, add the size of list 'n' to make it positive
			if k < 0 {
				k += n
			}

			// Update the minimum value of 'm' with the minimum value of 'a[k]'
			m = int(math.Min(float64(m), float64(a[k])))

			// Update the corresponding cell in slice 'b' with the minimum value of 'm'
			b[j][i] = m
		}
	}

	// Initialize a variable 'm' with a large value to keep track of the minimum sum
	m = math.MaxInt64

	// Iterate through each row of slice 'b'
	for i, j := range b {
		// Calculate the sum of elements in the current row and add 'x * i' to it
		sumRow := 0
		for _, value := range j {
			sumRow += value
		}
		sumRow += x * i

		// Update the minimum value of 'm' with the sum of the current row
		m = int(math.Min(float64(m), float64(sumRow)))
	}

	// Print the minimum sum
	fmt.Println(m)
}

// <END-OF-CODE>
