package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var len int
	var a [101]int

	// Read the length of the array from the user
	fmt.Print("Enter the length of the array: ")
	fmt.Scan(&len)

	// Read the elements of the array from the user
	fmt.Printf("Enter %d integers: ", len)
	for i := 0; i < len; i++ {
		fmt.Scan(&a[i])
	}

	// Sort the array using insertion sort algorithm
	for j := 1; j < len; j++ {
		// Print the current state of the array
		for i := 0; i < len; i++ {
			if i != 0 {
				fmt.Printf(" %d", a[i])
			} else {
				fmt.Printf("%d", a[i])
			}
		}
		fmt.Println("")

		// Set the current key to the next element
		key := a[j]

		// Swap the current key with the previous element if it is greater
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
			fmt.Printf(" %d", a[i])
		} else {
			fmt.Printf("%d", a[i])
		}
	}
	fmt.Println("")
}

// <END-OF-CODE>
