package main

import (
	"fmt"
	"math"
	"os"
)

var mod = int(1e9 + 7) // Modulo value for modulo operations

func main() {
	var N int
	fmt.Scan(&N) // Read the number of elements

	a := make([]int, N) // Create a slice to hold the elements
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i]) // Read each element
	}

	maxVal := 0        // Initialize the maximum value to 0
	maxSign := 0       // Initialize the sign of the maximum value to 0
	maxIndex := -1     // Initialize the index of the maximum value to -1

	// Find the element with the maximum absolute value
	for i, a0 := range a {
		if abs(a0) > maxVal {
			maxVal = abs(a0)
			maxSign = sign(a0)
			maxIndex = i
		}
	}

	// If the maximum value is zero, print 0
	if maxSign == 0 {
		fmt.Println(0)
		return
	}

	// If the maximum value is positive, print the sequence of operations
	if maxSign == 1 {
		fmt.Println(2*N - 1)
		for i := 0; i < N; i++ {
			fmt.Printf("%d %d\n", maxIndex+1, i+1) // Print the swap operations
		}
		for i := 0; i < N-1; i++ {
			fmt.Printf("%d %d\n", i+1, i+2) // Print the increment operations
		}
	} else { // If the maximum value is negative
		fmt.Println(2*N - 1)
		for i := 0; i < N; i++ {
			fmt.Printf("%d %d\n", maxIndex+1, i+1) // Print the swap operations
		}
		for i := N - 2; i >= 0; i-- {
			fmt.Printf("%d %d\n", i+2, i+1) // Print the decrement operations in reverse
		}
	}
}

// Function to determine the sign of a number
func sign(x int) int {
	if x > 0 {
		return 1
	} else if x < 0 {
		return -1
	}
	return 0
}

// Function to get the absolute value
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
