package main

import (
	"fmt"
)

func main() {
	// Initialize variables
	var n int

	// Read the number of elements in the array from the standard input
	fmt.Print("Enter the number of elements in the array: ")
	fmt.Scan(&n)

	// Allocate memory for the array and read its elements
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Printf("Enter element %d: ", i+1)
		fmt.Scan(&a[i])
	}

	// Initialize a counter to keep track of the current element in the array
	curr := 0

	// Iterate through the array and increment the counter whenever the current element is one more than the previous one
	for i := 0; i < n; i++ {
		if a[i] == curr+1 {
			curr++
		}
	}

	// Check if the counter is greater than zero, and if so, print the number of elements that are not consecutive
	if curr > 0 {
		fmt.Printf("The array has %d non-consecutive elements.\n", n-curr)
	} else {
		fmt.Println("-1")
	}
}

