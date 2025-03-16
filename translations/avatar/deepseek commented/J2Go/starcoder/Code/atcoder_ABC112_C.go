package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a constant MAX for the maximum value
const MAX = 100

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of points:")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	x := make([]int, n)
	y := make([]int, n)
	h := make([]int, n)
	fmt.Println("Enter the coordinates and heights of each point:")
	for i := 0; i < n; i++ {
		fmt.Printf("Enter the coordinates and height of point %d: ", i+1)
		fmt.Scanf("%d %d %d\n", &x[i], &y[i], &h[i])
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
func check(n int, x []int, y []int, h []int, cx int, cy int) int {
	ch := -1 // Initialize ch to -1
	for i := 0; i < n; i++ { // Loop through each point
		if h[i] > 0 { // If the height of the point is greater than 0
			ch = abs(x[i]-cx) + abs(y[i]-cy) + h[i] // Calculate the height difference
			break // Break the loop as we found a valid height
		}
	}

	// Verify if the calculated height matches the height of all points
	for i := 0; i < n; i++ {
		if h[i]!= max(ch-abs(x[i]-cx)-abs(y[i]-cy), 0) {
			return -1 // If any point does not match, return -1
		}
	}
	return ch // Return the calculated height if all points match
}

// abs returns the absolute value of x
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// max returns the maximum of x or y
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

