package main

import (
	"fmt"
	"math"
)

func main() {
	// Declare variables for input dimensions and the answer
	var N, M int
	var ans int
	
	// Read input values for N and M
	fmt.Scan(&N, &M)
	
	// Calculate the number of valid positions based on the dimensions
	if N == 1 && M == 1 {
		// If both dimensions are 1, there's only one position
		ans += 1
	} else if 1 < N && 1 < M {
		// If both dimensions are greater than 1, calculate the inner positions
		ans += (N - 2) * (M - 2)
	} else {
		// If one dimension is 1, count the edge positions
		ans += (N * M) - 2
	}

	// Output the calculated answer
	fmt.Println(ans)
}

/*  ----------------------------------------  */

// max function returns the maximum value from a variable number of integers
func max(x ...int) int {
	var res int = x[0]
	for i := 1; i < len(x); i++ {
		res = int(math.Max(float64(x[i]), float64(res)))
	}
	return res
}

// min function returns the minimum value from a variable number of integers
func min(x ...int) int {
	var res int = x[0]
	for i := 1; i < len(x); i++ {
		res = int(math.Min(float64(x[i]), float64(res)))
	}
	return res
}

// pow function calculates x raised to the power of y
func pow(x, y int) int { return int(math.Pow(float64(x), float64(y))) }

// abs function returns the absolute value of an integer
func abs(x int) int { return int(math.Abs(float64(x))) }

// floor function returns the largest integer less than or equal to x
func floor(x int) int { return int(math.Floor(float64(x))) }

// SortBy is a type that implements sorting based on absolute values
type SortBy []int

// Len returns the number of elements in the SortBy slice
func (a SortBy) Len() int { return len(a) }

// Swap exchanges the elements with indexes i and j in the SortBy slice
func (a SortBy) Swap(i, j int) { a[i], a[j] = a[j], a[i] }

// Less reports whether the element with index i should sort before the element with index j
func (a SortBy) Less(i, j int) bool { return abs(a[i]) < abs(a[j]) }
