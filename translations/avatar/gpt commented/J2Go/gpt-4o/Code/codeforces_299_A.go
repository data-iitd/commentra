package main

import (
	"fmt"
	"sort"
)

func main() {
	// Create a variable to read input from the user
	var n int
	// Read the number of elements in the array
	fmt.Scan(&n)

	// Initialize a slice to store the input values
	a := make([]int, n)

	// Loop to read n integers from the user and store them in the slice
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Sort the slice in ascending order
	sort.Ints(a)

	// Store the minimum value from the sorted slice
	min := a[0]

	// Check if all elements in the slice are divisible by the minimum value
	for _, value := range a {
		if value%min != 0 {
			// If any element is not divisible, print -1 and exit
			fmt.Println(-1)
			return
		}
	}

	// If all elements are divisible, print the minimum value
	fmt.Println(min)
}

// <END-OF-CODE>
