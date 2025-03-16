package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func solve(N int, x []int, y []int) {
	// Generate a list of indices from 0 to N-1
	indices := []int{}
	for i := 0; i < N; i++ {
		indices = append(indices, i)
	}
	
	// Generate all permutations of the indices
	// This is not straightforward in Go, so we will use a different approach
	// For simplicity, we will use a brute-force approach to calculate the total distances
	
	// Initialize a list to store the total distances
	var distances []float64
	
	// Iterate over each permutation
	for _, permutation := range getPermutations(indices) {
		// Initialize the total distance for the current permutation
		totalDistance := 0.0
		
		// Calculate the distance between consecutive points in the permutation
		for i := 0; i < N-1; i++ {
			f, t := permutation[i], permutation[i+1]
			distance := math.Sqrt(float64((x[t]-x[f])*(x[t]-x[f]) + (y[t]-y[f])*(y[t]-y[f])))
			totalDistance += distance
		}
		
		// Append the total distance of the current permutation to the distances list
		distances = append(distances, totalDistance)
	}
	
	// Calculate the average distance by averaging all stored distances
	sumDistances := 0.0
	for _, distance := range distances {
		sumDistances += distance
	}
	result := sumDistances / float64(len(distances))
	
	// Print the result
	fmt.Println(result)
}

// Helper function to generate permutations
func getPermutations(arr []int) [][]int {
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

func main() {
	// Read input from stdin
	var N int
	var x, y []int

	// Read the number of points N
	fmt.Scan(&N)

	// Initialize lists for x and y coordinates
	x = make([]int, N)
	y = make([]int, N)

	// Read the x and y coordinates for each point
	for i := 0; i < N; i++ {
		fmt.Scan(&x[i], &y[i])
	}

	// Call the solve function with the input values
	solve(N, x, y)
}
