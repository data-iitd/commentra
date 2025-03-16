package main

import (
	"fmt"
)

func main() {
	var n, count int
	fmt.Scan(&n)   // Read the first integer 'n' from the input
	fmt.Scan(&count) // Read the second integer 'count' from the input
	printIsland(n, count) // Call the printIsland function with the arguments 'n' and 'count'
}

// Function to check if it's possible to place the required number of 'L' islands in the grid
func printIsland(n, count int) {
	a := (n + 1) / 2 // Calculate the side length 'a' of the square grid of size 'n x n'
	b := n / 2       // Calculate the square of the side length 'b' of the grid
	max := a*a + b*b // Calculate the maximum number of 'L' islands that can be placed in the grid

	// Check if the count is greater than the maximum number of 'L' islands that can be placed in the grid
	if count > max {
		fmt.Println("NO") // If yes, print "NO" and return from the function
		return
	}

	fmt.Println("YES") // If not, print "YES" to indicate that it's possible to place the required number of 'L' islands in the grid

	// Loop to create the grid
	for i := 0; i < n; i++ {
		var sb []rune // Initialize a slice of runes to store a row of the grid
		for j := 0; j < n; j++ {
			// If the cell is in the position where an 'L' island can be placed, append an 'L' character to the slice and decrement the count
			if (i+j)%2 == 0 && count > 0 {
				sb = append(sb, 'L')
				count--
			} else {
				// Otherwise, append an 'S' character to the slice
				sb = append(sb, 'S')
			}
		}
		// Print the contents of the slice to represent a row of the grid
		fmt.Println(string(sb))
	}
}

// <END-OF-CODE>
