package main

import (
	"fmt"
	"math"
)

// Main function is the entry point of our program
func main() {
	// Declare and initialize variables
	var N, M int
	var ans int

	// Read N and M from the standard input
	fmt.Scan(&N, &M)

	// Check if N and M are equal to 1
	if N == 1 && M == 1 {
		// If so, increment the ans variable
		ans += 1
	} else if 1 < N && 1 < M {
		// If N and M are greater than 1, calculate the area of the rectangle
		ans += (N - 2) * (M - 2)
	} else {
		// If N or M is equal to 1, calculate the number of points on the edge
		ans += (N * M) - 2
	}

	// Print the value of ans to the standard output
	fmt.Println(ans)
}

// Helper functions
func max(x ...int) int {
	// Find the maximum value in the slice x
	var res int = x[0]
	for i := 1; i < len(x); i++ {
		res = int(math.Max(float64(x[i]), float64(res)))
	}
	return res
}

func min(x ...int) int {
	// Find the minimum value in the slice x
	var res int = x[0]
	for i := 1; i < len(x); i++ {
		res = int(math.Min(float64(x[i]), float64(res)))
	}
	return res
}
func pow(x, y int) int {
	// Calculate x raised to the power of y
	return int(math.Pow(float64(x), float64(y)))
}
func abs(x int) int {
	// Calculate the absolute value of x
	return int(math.Abs(float64(x)))
}
func floor(x int) int {
	// Round x down to the nearest integer
	return int(math.Floor(float64(x)))
}

// Helper type and function for sorting a slice of integers based on their absolute values
type SortBy []int

func (a SortBy) Len() int           { return len(a) }
func (a SortBy) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a SortBy) Less(i, j int) bool { return abs(a[i]) < abs(a[j]) }
