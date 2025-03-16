package main

import (
	"bufio"
	"fmt"
	"os"
)

const MAX = 100

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read the number of points
	scanner.Scan()
	n := parseInt(scanner.Text())

	// Initialize slices to store x, y coordinates and heights
	x := make([]int, n)
	y := make([]int, n)
	h := make([]int, n)

	// Read the x, y coordinates and heights for each point
	for i := 0; i < n; i++ {
		scanner.Scan()
		x[i] = parseInt(scanner.Text())
		scanner.Scan()
		y[i] = parseInt(scanner.Text())
		scanner.Scan()
		h[i] = parseInt(scanner.Text())
	}

	// Iterate through all possible coordinates (i, j) within the defined range
	for i := 0; i <= MAX; i++ {
		for j := 0; j <= MAX; j++ {
			// Check the height at the current coordinate (i, j)
			ch := check(n, x, y, h, i, j)
			// If the height is valid (greater than 0), print the coordinates and height
			if ch > 0 {
				fmt.Println(i, j, ch)
			}
		}
	}
}

// Method to check the height at a given coordinate (cx, cy)
func check(n int, x, y, h []int, cx, cy int) int {
	ch := -1

	// Calculate the initial height based on the first point with a positive height
	for i := 0; i < n; i++ {
		if h[i] > 0 {
			ch = abs(x[i] - cx) + abs(y[i] - cy) + h[i]
			break
		}
	}

	// Validate the height against all points
	for i := 0; i < n; i++ {
		// If the calculated height does not match the expected height, return -1
		if h[i] != max(ch-abs(x[i]-cx)-abs(y[i]-cy), 0) {
			return -1
		}
	}

	// Return the calculated height if all checks pass
	return ch
}

// Helper function to parse string to int
func parseInt(s string) int {
	var num int
	fmt.Sscanf(s, "%d", &num)
	return num
}

// Helper function to get absolute value
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// Helper function to get maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// End-of-code comment
