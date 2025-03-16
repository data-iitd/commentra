package main

import (
	"fmt"
	"math"
	"sort"
)

// Function to find the solution
func solve(N int, x []int, y []int) {
	// Initialize an empty list to store distances
	var distances []float64

	// Generate all possible permutations of indices from 0 to N-1
	indices := make([]int, N)
	for i := 0; i < N; i++ {
		indices[i] = i
	}

	// For each permutation, calculate the total distance between adjacent points
	for _, permutation := range permutations(indices) {
		totalDistance := 0.0
		for i := 0; i < N-1; i++ {
			// Get the first and second indices of the current pair
			f, t := permutation[i], permutation[i+1]
			// Calculate the Euclidean distance between the points (x[f], y[f]) and (x[t], y[t])
			distance := math.Sqrt(float64((x[t]-x[f])*(x[t]-x[f]) + (y[t]-y[f])*(y[t]-y[f])))
			// Add the distance to the total distance
			totalDistance += distance
		}
		// Append the total distance to the distances list
		distances = append(distances, totalDistance)
	}

	// Calculate the average distance from all permutations
	sumDistances := 0.0
	for _, distance := range distances {
		sumDistances += distance
	}
	result := sumDistances / float64(len(distances))

	// Print the result
	fmt.Println(result)
}

// Helper function to generate permutations
func permutations(arr []int) [][]int {
	var helper func([]int, int)
	res := [][]int{}

	helper = func(arr []int, n int) {
		if n == 1 {
			tmp := make([]int, len(arr))
			copy(tmp, arr)
			res = append(res, tmp)
		} else {
			for i := 0; i < n; i++ {
				helper(arr, n-1)
				if n%2 == 1 {
					arr[0], arr[n-1] = arr[n-1], arr[0]
				} else {
					arr[i], arr[n-1] = arr[n-1], arr[i]
				}
			}
		}
	}
	helper(arr, len(arr))
	return res
}

// Main function to read input and call the solve function
func main() {
	var N int
	fmt.Scan(&N)

	x := make([]int, N)
	y := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&x[i], &y[i])
	}

	// Call the solve function with the given input
	solve(N, x, y)
}

