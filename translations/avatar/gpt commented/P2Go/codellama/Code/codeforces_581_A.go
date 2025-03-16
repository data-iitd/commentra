package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read two integers from input and unpack them into variables a and b
	a, b := readInts()

	// Calculate the minimum of a and b, and the half of the difference between the maximum and minimum values
	// Print the minimum value and the calculated half difference
	fmt.Println(min(a, b), (max(a, b) - min(a, b)) / 2)
}

func readInts() (int, int) {
	var a, b int
	fmt.Scan(&a, &b)
	return a, b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// 