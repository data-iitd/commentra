package main

import (
	"fmt"
	"math"
)

// Define a constant for the maximum coordinate value
const MAX = 100

func main() {
	// Create a Scanner object to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of points
	var n int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n)

	// Initialize arrays to store x, y coordinates and heights
	x := make([]int, n)
	y := make([]int, n)
	h := make([]int, n)

	// Read the x, y coordinates and heights for each point
	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &x[i], &y[i], &h[i])
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
func check(n int, x []int, y []int, h []int, cx int, cy int) int {
	ch := -1

	// Calculate the initial height based on the first point with a positive height
	for i := 0; i < n; i++ {
		if h[i] > 0 {
			ch = math.Abs(float64(x[i]-cx)) + math.Abs(float64(y[i]-cy)) + float64(h[i])
			break
		}
	}

	// Validate the height against all points
	for i := 0; i < n; i++ {
		// If the calculated height does not match the expected height, return -1
		if h[i] != int(math.Max(float64(ch)-math.Abs(float64(x[i]-cx))-math.Abs(float64(y[i]-cy)), 0)) {
			return -1
		}
	}

	// Return the calculated height if all checks pass
	return int(ch)
}

// 