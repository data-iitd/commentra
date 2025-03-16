package main

import (
	"fmt"
)

func main() {
	// Read the size of the island (n) and the number of 'L' characters (count) from the input
	var n, count int
	fmt.Scan(&n, &count)

	// Call the function to print the island pattern based on the input values
	printIsland(n, count)
}

func printIsland(n, count int) {
	// Calculate the number of 'L' and 'S' characters that can be placed on the island
	a := (n + 1) / 2 // Number of 'L' characters in the first half
	b := n / 2       // Number of 'L' characters in the second half
	max := a*a + b*b // Maximum number of 'L' characters that can fit in the island

	// Check if the provided count exceeds the maximum possible 'L' characters
	if count > max {
		fmt.Println("NO") // Print "NO" if the count is too high
		return            // Exit the function
	}

	// If the count is valid, print "YES"
	fmt.Println("YES")

	// Loop through each row of the island
	for i := 0; i < n; i++ {
		row := make([]byte, n) // Create a slice of bytes to construct the row

		// Loop through each column of the island
		for j := 0; j < n; j++ {
			// Place 'L' if the sum of indices is even and there are still 'L' characters left
			if (i+j)%2 == 0 && count > 0 {
				row[j] = 'L' // Set 'L' in the current row
				count--      // Decrement the count of 'L' characters
			} else {
				row[j] = 'S' // Set 'S' in the current row
			}
		}

		// Print the constructed row of the island
		fmt.Println(string(row))
	}
}

// <END-OF-CODE>
