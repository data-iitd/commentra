package main

import (
	"fmt"
)

func main() {
	// Create a Scanner object to read input from the console
	var n, count int
	fmt.Scan(&n, &count)
	
	// Call the method to print the island pattern based on the input values
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
		return // Exit the method
	}
	
	// If the count is valid, print "YES"
	fmt.Println("YES")
	
	// Loop through each row of the island
	for i := 0; i < n; i++ {
		var sb string // Create a string to construct the row
		
		// Loop through each column of the island
		for j := 0; j < n; j++ {
			// Place 'L' if the sum of indices is even and there are still 'L' characters left
			if (i + j) % 2 == 0 && count > 0 {
				sb += "L" // Append 'L' to the current row
				count-- // Decrement the count of 'L' characters
			} else {
				sb += "S" // Append 'S' to the current row
			}
		}
		
		// Print the constructed row of the island
		fmt.Println(sb)
	}
}
