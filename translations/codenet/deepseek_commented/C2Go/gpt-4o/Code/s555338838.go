package main

import (
	"fmt"
)

func main() {
	var key, i, j, len int
	var a [101]int

	// Step 1: Read the length of the array
	fmt.Scan(&len)

	// Step 2: Read the elements of the array
	for i = 0; i < len; i++ {
		fmt.Scan(&a[i])
	}

	// Step 3: Perform Insertion Sort
	for j = 1; j < len; j++ {
		// Print the array before each iteration
		for i = 0; i < len; i++ {
			if i != 0 {
				fmt.Printf(" ")
			}
			fmt.Printf("%d", a[i])
		}
		fmt.Println()

		// Store the current element to be inserted
		key = a[j]

		// Shift elements to the right to make space for the key
		for i = j - 1; i >= 0 && a[i] > key; i-- {
			a[i+1] = a[i]
		}

		// Insert the key into the correct position
		a[i+1] = key
	}

	// Step 4: Print the sorted array
	for i = 0; i < len; i++ {
		if i != 0 {
			fmt.Printf(" ")
		}
		fmt.Printf("%d", a[i])
	}
	fmt.Println()
}

// <END-OF-CODE>
