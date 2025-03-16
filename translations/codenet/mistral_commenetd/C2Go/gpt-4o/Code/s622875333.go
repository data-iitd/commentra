package main

import (
	"fmt"
)

func main() {
	// Variables declaration
	var n, r, i, j, p, c int
	a := make([]int, 100)
	b := make([]int, 100)

	// Infinite loop until user inputs 0 for both n and r
	for {
		fmt.Print("Enter the number of elements in array a: ")
		fmt.Scan(&n)
		fmt.Print("Enter the number of rotations: ")
		fmt.Scan(&r)

		if n == 0 && r == 0 { // Exit the loop if n and r are both 0
			break
		}

		// Initialize array a with the given size
		for i = 0; i < n; i++ {
			a[i] = n - i // Set the initial values of array a
		}

		// Rotate the array r times
		for i = 0; i < r; i++ {
			fmt.Printf("\nBefore rotation %d:\n", i+1)
			// Print the current state of array a before rotation
			for j = 0; j < n; j++ {
				fmt.Printf("%d ", a[j])
			}
			fmt.Println()

			// Create a copy of array a and store it in array b
			for j = 0; j < n; j++ {
				b[j] = a[j] // Copy each element of array a to array b
			}

			// Read the number of elements to be rotated and the position from user
			fmt.Print("Enter the number of elements to be rotated: ")
			fmt.Scan(&c)
			fmt.Print("Enter the position: ")
			fmt.Scan(&p)

			// Rotate the array b by c positions to the left
			for j = 0; j < c; j++ {
				b[j] = b[j+1] // Shift each element of array b one position to the left
			}

			// Rotate the first part of array a by c positions to the left
			for j = 0; j < c; j++ {
				a[j] = b[p-1+j] // Shift each element of the first part of array a by c positions to the left
			}

			// Rotate the second part of array a by (p-c) positions to the right
			for j = c; j < n; j++ {
				a[j] = b[j-c] // Shift each element of the second part of array a by (p-c) positions to the right
			}

			// Print the current state of array a after rotation
			fmt.Printf("\nAfter rotation %d:\n", i+1)
			for j = 0; j < n; j++ {
				fmt.Printf("%d ", a[j])
			}
			fmt.Println()
		}

		// Print the first element of the final array a
		fmt.Printf("\nThe first element of the final array is: %d\n", a[0])
	}
}

// <END-OF-CODE>
