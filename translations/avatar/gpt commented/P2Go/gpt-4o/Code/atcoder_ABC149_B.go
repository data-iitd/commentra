package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read a line of input
	var input string
	fmt.Scanln(&input)

	// Split the input into parts and convert each part to an integer
	parts := strings.Split(input, " ")
	cookies := make([]int, len(parts))
	for i, part := range parts {
		cookies[i], _ = strconv.Atoi(part)
	}

	// Calculate the leftover cookies after taking some from the third type
	leftOver := cookies[0] - cookies[2]

	// Determine the number of cookies Takahashi can take, ensuring it's not negative
	takahashi := max(0, leftOver)

	// Print the number of cookies Takahashi can take, and the remaining cookies of the second type
	if takahashi > 0 {
		fmt.Println(takahashi, cookies[1])
	} else {
		fmt.Println(takahashi, max(0, cookies[1]-abs(leftOver)))
	}
}

// Helper function to calculate the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Helper function to calculate the absolute value of an integer
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
