package main

import (
	"fmt"
)

func main() {
	var n, count int
	fmt.Scan(&n)   // Reading the first integer input (size of the grid)
	fmt.Scan(&count) // Reading the second integer input (number of 'L' characters)
	printIsland(n, count) // Calling the printIsland function with the inputs
}

// Function to print the island pattern based on the given size and count of 'L' characters
func printIsland(n, count int) {
	a := (n + 1) / 2 // Calculating the number of 'L' characters in the first diagonal
	b := n / 2       // Calculating the number of 'L' characters in the second diagonal
	max := a*a + b*b // Calculating the maximum possible number of 'L' characters

	// Checking if the requested count exceeds the maximum possible 'L' characters
	if count > max {
		fmt.Println("NO") // Printing "NO" if count is too high
		return            // Returning from the function as further execution is unnecessary
	}

	fmt.Println("YES") // Printing "YES" as the count is within the allowed range

	// Building the island grid
	for i := 0; i < n; i++ {
		var sb []rune // Creating a slice of runes to build the row
		for j := 0; j < n; j++ {
			if (i+j)%2 == 0 && count > 0 { // Checking if the position should be 'L'
				sb = append(sb, 'L') // Appending 'L' to the slice
				count--               // Decrementing the count of 'L' characters
			} else {
				sb = append(sb, 'S') // Appending 'S' to the slice
			}
		}
		fmt.Println(string(sb)) // Printing the constructed row
	}
}

// <END-OF-CODE>
