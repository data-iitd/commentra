package main

import (
	"fmt"
	"math"
)

func main() {
	// Taking the number of points, n, and the number of dimensions, d, as input
	var n, d int
	fmt.Scan(&n, &d)

	// Initializing a slice 'points' of size 'n' to store the coordinates of each point
	points := make([][]int, n)
	for i := 0; i < n; i++ {
		points[i] = make([]int, d)
		for j := 0; j < d; j++ {
			fmt.Scan(&points[i][j])
		}
	}

	// Defining a function 'dist' to calculate the Euclidean distance between two points
	dist := func(x, y []int) float64 {
		// Initializing a variable 'tmp' to store the sum of squared differences between corresponding elements of 'x' and 'y'
		var tmp float64

		// Iterating through each dimension 'i' from 0 to 'd'
		for i := 0; i < d; i++ {
			// Adding the square of the difference between the 'i'th elements of 'x' and 'y' to 'tmp'
			tmp += math.Pow(float64(x[i]-y[i]), 2)
		}

		// Returning the square root of 'tmp' as the Euclidean distance between 'x' and 'y'
		return math.Sqrt(tmp)
	}

	// Initializing a variable 'count' to store the number of distinct pairs of points with integer distance
	count := 0

	// Iterating through each point 'i' in 'points'
	for i := 0; i < n; i++ {
		// Iterating through each point 'j' from 'i+1' to the last point in 'points'
		for j := i + 1; j < n; j++ {
			// Checking if the Euclidean distance between 'points[i]' and 'points[j]' is an integer
			if dist(points[i], points[j]) == float64(int(dist(points[i], points[j]))) {
				// Incrementing the 'count' variable if the condition is true
				count++
			}
		}
	}

	// Printing the final value of 'count'
	fmt.Println(count)
}
