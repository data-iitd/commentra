package main

import (
	"fmt"
	"math"
)

func main() {
	// Initialize the minimum value to a large number
	minA := math.Pow(10, 9) + 1
	// Initialize the number of ways to achieve the maximum profit
	num := 0
	
	// Read the number of elements and an unused variable 't'
	var n, t int
	fmt.Scan(&n, &t)
	// Create a slice to store the elements
	A := make([]int, n)
	
	// Read the elements into the slice
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	
	// Iterate through the slice to find the maximum profit
	for i := 0; i < n; i++ {
		// Update the minimum value found so far
		if float64(minA) > float64(A[i]) {
			minA = A[i]
		} else {
			// Check if the current profit is equal to the maximum profit found so far
			if f == A[i] - minA {
				num++
			} else if f < A[i] - minA {
				// Update the maximum profit and reset the count if a new maximum is found
				num = 1
				f = A[i] - minA
			}
		}
	}
	
	// Output the number of ways to achieve the maximum profit
	fmt.Println(num)
}
