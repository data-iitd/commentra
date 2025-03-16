package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of intervals
	n, _ := strconv.Atoi(readLine())

	// Initialize the index for the result
	id := 0

	// Read the first interval's bounds
	l, r := readInterval()

	// Iterate through the remaining intervals
	for i := 1; i < n; i++ {
		// Read the current interval's bounds
		li, ri := readInterval()

		// Check if the current interval completely contains the previous one
		if li <= l && r <= ri {
			id = i // Update the index to the current interval
		}
		// Check if the current interval overlaps with the previous one
		if li < l || r < ri {
			id = n // Mark as overlapping by setting id to n
		}

		// Update the bounds of the union of intervals
		l = min(l, li) // Update the left bound
		r = max(r, ri) // Update the right bound
	}

	// Print the result: -1 if no valid interval found, otherwise print the 1-based index of the interval
	fmt.Println(-1 if id == n else id + 1)
}

func readLine() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func readInterval() (int, int) {
	line := readLine()
	parts := strings.Split(line, " ")
	return strconv.Atoi(parts[0]), strconv.Atoi(parts[1])
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