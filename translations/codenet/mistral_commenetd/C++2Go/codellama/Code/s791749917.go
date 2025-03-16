
package main

import (
	"fmt"
)

func main() {
	// Initialize variables
	var H, W int
	fmt.Scan(&H, &W)

	// Initialize answer variable
	var ans int

	// Check if the grid has only one cell
	if H == 1 || W == 1 {
		ans = 1 // The answer is 1 in this case
	} else {
		// Calculate the total number of cells in the grid
		m := H * W

		// Check if the total number of cells is even
		if m%2 == 0 {
			ans = m / 2 // The answer is half of the total number of cells if it's even
		} else {
			ans = m/2+1 // The answer is half of the total number of cells plus one if it's odd
		}
	}

	// Output the answer
	fmt.Println(ans)

	// Return 0 to indicate successful execution
	return 0
}

