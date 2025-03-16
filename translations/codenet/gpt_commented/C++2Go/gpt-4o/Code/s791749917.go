package main

import (
	"fmt"
)

func main() {
	var H, W int64 // Declare variables for height and width
	fmt.Scan(&H, &W) // Input the height and width from the user

	var ans int64 // Variable to store the final answer
	// Check if either height or width is 1
	if H == 1 || W == 1 {
		ans = 1 // If either dimension is 1, the answer is 1
	} else {
		m := H * W // Calculate the total number of cells (H * W)
		// Check if the total number of cells is even or odd
		if m%2 == 0 {
			ans = m / 2 // If even, half of the cells can be filled
		} else {
			ans = m/2 + 1 // If odd, half plus one cell can be filled
		}
	}

	fmt.Println(ans) // Output the final answer
}

// <END-OF-CODE>
