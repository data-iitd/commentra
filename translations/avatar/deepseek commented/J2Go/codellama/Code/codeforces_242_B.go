package main

import (
	"fmt"
	"math"
)

func main() {
	// Creating a Scanner object to read input
	sc := new(Scanner)
	var n int // Declaring variable n to store the number of elements
	fmt.Scan(&n) // Reading the integer value of n

	// Initializing two slices to store the elements
	a := make([]int, n)
	b := make([]int, n)

	// Initializing variables to track the minimum and maximum values
	left := math.MaxInt32
	right := 0

	// Looping through n elements to read and update the lists and variables
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Reading element into list a
		fmt.Scan(&b[i]) // Reading element into list b
		if a[i] < left {
			left = a[i] // Updating left with the minimum value
		}
		if b[i] > right {
			right = b[i] // Updating right with the maximum value
		}
	}

	// Looping through the lists to find the target element
	for i := 0; i < n; i++ {
		if a[i] == left && b[i] == right {
			fmt.Println(i + 1) // Printing the 1-based index of the target element
			return // Returning from the method after finding the target
		}
	}

	// If no such element is found, print -1
	fmt.Println(-1)
}

// 