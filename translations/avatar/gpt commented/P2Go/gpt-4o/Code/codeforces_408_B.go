package main

import (
	"fmt"
	"strings"
)

func solution() {
	// Read the first line of input which represents the colors bought
	var boughtLine string
	fmt.Scanln(&boughtLine)

	// Count the occurrences of each color bought using a map
	boughtCount := make(map[rune]int)
	for _, color := range boughtLine {
		boughtCount[color]++
	}

	// Read the second line of input which represents the colors made
	var madeLine string
	fmt.Scanln(&madeLine)

	// Count the occurrences of each color made using a map
	madeCount := make(map[rune]int)
	for _, color := range madeLine {
		madeCount[color]++
	}

	// Initialize the result variable to store the total count of matched colors
	res := 0

	// Iterate through each color in the madeCount
	for color, madeQty := range madeCount {
		// If a color made is not found in the bought colors, return -1
		if boughtQty, exists := boughtCount[color]; !exists {
			fmt.Println(-1)
			return
		} else {
			// Add the minimum of the bought and made counts for each color to the result
			res += min(boughtQty, madeQty)
		}
	}

	// Print the total count of matched colors
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
	// Set the number of test cases (currently set to 1)
	t := 1
	// Loop through each test case
	for i := 0; i < t; i++ {
		solution()
	}
}

// Entry point of the program
// <END-OF-CODE>
