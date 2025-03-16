package main

import (
	"fmt"
	"math"
)

func main() {
	// Initialize minimum value of array A to a large number
	minA := math.Pow(10, 9) + 1
	num := 0

	// Read number of elements and time t from the standard input
	var n, t int
	fmt.Scan(&n, &t)

	// Create a slice A of size n to store the input elements
	A := make([]int, n)

	// Read each element of slice A from the standard input
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
		// Check if the current element is smaller than the minimum value
		if float64(minA) > float64(A[i]) {
			// Update the minimum value of array A
			minA = A[i]
		} else {
			// Calculate the difference between the current element and the minimum value
			diff := A[i] - minA

			// If the difference is equal to the previous difference, increment the count of similar differences
			if diff == num {
				num++
			} else if diff > num {
				// If the difference is greater than the previous difference, reset the count to 1 and update the previous difference
				num = 1
				num = diff
			}
		}
	}

	// Print the count of similar differences on the standard output
	fmt.Println(num)
}
