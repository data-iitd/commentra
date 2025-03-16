package main

import (
	"fmt"
)

func main() {
	var N, M int
	fmt.Scan(&N) // Read the first integer input, which is the size of the grid
	fmt.Scan(&M) // Read the second integer input, which is the number of operations

	// Initialize a 2D slice 'black' with dimensions (N+2) x (N+2)
	black := make([][]int, N+2)
	for i := range black {
		black[i] = make([]int, N+2)
	}

	// Loop through M operations
	for m := 1; m <= M; m++ {
		var x, y int
		fmt.Scan(&x) // Read the x-coordinate of the current operation
		fmt.Scan(&y) // Read the y-coordinate of the current operation

		// Increment the elements in the 'black' array within the 3x3 neighborhood of (x, y)
		for xx := x - 1; xx <= x+1; xx++ {
			for yy := y - 1; yy <= y+1; yy++ {
				if black[xx][yy]++; black[xx][yy] == 9 { // Increment the element and check if it reaches 9
					fmt.Println(m) // Print the current operation number
					return         // Exit the program
				}
			}
		}
	}

	// If no element reaches 9 after all operations, print -1
	fmt.Println("-1")
}

// <END-OF-CODE>
