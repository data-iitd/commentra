package main

import (
	"fmt"
	"math"
)

const INF = int(1e9 + 5) // Initializing a large constant value

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of elements in the arrays

	a := make([]int, n) // Creating a slice to store the first array elements
	b := make([]int, n) // Creating a slice to store the second array elements

	left := INF
	right := 0 // Initializing left and right variables to store the minimum and maximum elements respectively

	// Reading the elements of the arrays and updating the minimum and maximum elements
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Reading an element from the first array
		fmt.Scan(&b[i]) // Reading an element from the second array
		left = int(math.Min(float64(left), float64(a[i]))) // Finding the minimum element in the first array
		right = int(math.Max(float64(right), float64(b[i]))) // Finding the maximum element in the second array
	}

	// Checking if there is an element that has the same minimum and maximum value in both arrays
	for i := 0; i < n; i++ {
		if left == a[i] && right == b[i] { // Checking if the current element in both arrays has the same minimum and maximum value
			fmt.Println(i + 1) // If true, printing the index of the element (1-based index)
			return // Exiting the program after finding the element
		}
	}

	// If no such element is found, printing -1
	fmt.Println(-1)
}

// <END-OF-CODE>
