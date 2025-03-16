package main

import (
	"fmt"
	"math"
)

func main() {
	// Read the values of n and x
	var n, x int
	fmt.Scan(&n, &x)

	// Read the list of integers a
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize a 2D slice b with zero values
	// b[j][i] will store the minimum value in the circular array from i to j
	b := make([][]int, n)
	for i := range b {
		b[i] = make([]int, n)
	}

	// Calculate the minimum value in a circular array for each starting position i and ending position j
	for i := 0; i < n; i++ {
		m := a[i] // Initialize m with the current element
		for j := 0; j < n; j++ {
			k := (i - j + n) % n // Calculate the index in the circular array
			m = int(math.Min(float64(m), float64(a[k]))) // Update m with the minimum value in the circular array
			b[j][i] = m // Store the minimum value in b
		}
	}

	// Find the minimum sum of each row in b plus x times the row index
	minValue := math.MaxInt64
	for i, row := range b {
		sum := 0
		for _, value := range row {
			sum += value
		}
		minValue = int(math.Min(float64(minValue), float64(sum+x*i)))
	}

	// Print the minimum value found
	fmt.Println(minValue)
}

// <END-OF-CODE>
