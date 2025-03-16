package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func solution() {
	// Create a new scanner to read input
	scanner := bufio.NewScanner(os.Stdin)
	// Read the first line of input which represents the colors bought
	scanner.Scan()
	line := scanner.Text()
	// Split the line into individual colors and count their occurrences
	colorsBought := make(map[rune]int)
	for _, color := range line {
		colorsBought[color]++
	}
	
	// Read the second line of input which represents the colors made
	scanner.Scan()
	line = scanner.Text()
	// Split the line into individual colors and count their occurrences
	colorsMade := make(map[rune]int)
	for _, color := range line {
		colorsMade[color]++
	}
	
	// Initialize the result variable to store the total count of matched colors
	var res int
	
	// Iterate through each color in the colorsMade
	for color := range colorsMade {
		// If a color made is not found in the bought colors, return -1
		if _, exists := colorsBought[color]; !exists {
			fmt.Println(-1)
			return
		}
		// Add the minimum of the bought and made counts for each color to the result
		res += min(colorsBought[color], colorsMade[color])
	}
	
	// Print the total count of matched colors
	fmt.Println(res)
}

func main() {
	// Set the number of test cases (currently set to 1)
	t := 1
	// Loop through each test case
	for i := 0; i < t; i++ {
		solution()
	}
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
