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
	l, r := readLineAsSlice()

	// Iterate through the remaining intervals
	for i := 1; i < n; i++ {
		// Read the current interval's bounds
		li, ri := readLineAsSlice()

		// Check if the current interval completely contains the previous one
		if li <= l && r <= ri {
			id = i // Update the index to the current interval
		} // Check if the current interval overlaps with the previous one
		if li < l || r < ri {
			id = n // Mark as overlapping by setting id to n

		// Update the bounds of the union of intervals
		l = min(l, li) // Update the left bound
		r = max(r, ri) // Update the right bound
	}

	// Print the result: -1 if no valid interval found, otherwise print the 1-based index of the interval
	fmt.Println(-1) if id == n else fmt.Println(id + 1)
}

func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	line, _ := buf.ReadString('\n')
	return strings.TrimRight(line, "\r\n")
}

func readLineAsSlice() []int {
	line := strings.Split(readLine(), " ")
	slice := make([]int, len(line))
	for i := 0; i < len(line); i++ {
		slice[i], _ = strconv.Atoi(line[i])
	}
	return slice
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

