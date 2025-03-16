package main

import (
	"fmt"
	"strings"
)

func solution() {
	// Read the first line of input and create a map for the bought colors
	var line string
	fmt.Scanln(&line)
	boughtCount := make(map[rune]int)
	for _, color := range line {
		boughtCount[color]++
	}

	// Read the second line of input and create a map for the colors to be made
	fmt.Scanln(&line)
	madeCount := make(map[rune]int)
	for _, color := range line {
		madeCount[color]++
	}

	// Initialize the result variable to store the total number of colors that can be made
	res := 0

	// Iterate over each color in the 'madeCount' map
	for color, madeQty := range madeCount {
		// Check if the color is not in the 'boughtCount' map
		if boughtQty, exists := boughtCount[color]; !exists {
			// If a color is not bought, print -1 and exit
			fmt.Println(-1)
			return
		} else {
			// Calculate the minimum of the counts of the current color in both 'boughtCount' and 'madeCount'
			// and add this to the result
			res += min(boughtQty, madeQty)
		}
	}

	// Print the final result
	fmt.Println(res)
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	// Set the number of test cases to 1
	t := 1
	// Run the solution function for one test case
	for i := 0; i < t; i++ {
		solution()
	}
}

// <END-OF-CODE>
