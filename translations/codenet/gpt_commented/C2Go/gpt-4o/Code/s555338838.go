package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var len int
	var a [101]int

	// Read the length of the array
	fmt.Scan(&len)

	// Read the elements of the array
	for i := 0; i < len; i++ {
		fmt.Scan(&a[i])
	}

	// Perform insertion sort
	for j := 1; j < len; j++ {
		// Print the current state of the array
		for i := 0; i < len; i++ {
			if i != 0 {
				fmt.Printf(" ")
			}
			fmt.Print(a[i])
		}
		fmt.Println() // Move to the next line after printing the array

		// Store the current element to be positioned
		key := a[j]

		// Shift elements of the sorted segment to the right
		i := j - 1
		for i >= 0 && a[i] > key {
			a[i+1] = a[i]
			i--
		}

		// Place the key in its correct position
		a[i+1] = key
	}

	// Print the sorted array
	for i := 0; i < len; i++ {
		if i != 0 {
			fmt.Printf(" ")
		}
		fmt.Print(a[i])
	}
	fmt.Println() // Move to the next line after printing the sorted array
}

// <END-OF-CODE>
