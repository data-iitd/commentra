package main

import (
	"fmt"
	"math"
)

const MAX = 100 // Define a constant MAX for the maximum value

func main() {
	var n int
	fmt.Scan(&n) // Read the number of points from the user input
	x := make([]int, n)
	y := make([]int, n)
	h := make([]int, n)

	// Read the coordinates and heights of each point from the user input
	for i := 0; i < n; i++ {
		fmt.Scan(&x[i], &y[i], &h[i])
	}

	// Iterate over a range of possible coordinates (i, j) up to MAX
	for i := 0; i <= MAX; i++ {
		for j := 0; j <= MAX; j++ {
			ch := check(n, x, y, h, i, j) // Call the check function to determine if it is a valid center
			if ch > 0 { // If the check function returns a valid height
				fmt.Printf("%d %d %d\n", i, j, ch) // Print the center coordinates and height
			}
		}
	}
}

// Check function to determine if a point (cx, cy) is a valid center
func check(n int, x, y, h []int, cx, cy int) int {
	ch := -1 // Initialize ch to -1
	for i := 0; i < n; i++ { // Loop through each point
		if h[i] > 0 { // If the height of the point is greater than 0
			ch = math.Abs(float64(x[i]-cx)) + math.Abs(float64(y[i]-cy)) + float64(h[i]) // Calculate the height difference
			break // Break the loop as we found a valid height
		}
	}

	// Verify if the calculated height matches the height of all points
	for i := 0; i < n; i++ {
		if h[i] != int(math.Max(float64(ch-math.Abs(float64(x[i]-cx))-math.Abs(float64(y[i]-cy))), 0)) {
			return -1 // If any point does not match, return -1
		}
	}
	return int(ch) // Return the calculated height if all points match
}

// <END-OF-CODE>
