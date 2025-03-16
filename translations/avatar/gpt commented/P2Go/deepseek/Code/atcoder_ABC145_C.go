package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

// solve calculates the average distance of all permutations of points
func solve(N int, x []int, y []int) {
	// Generate all possible permutations of the indices
	// This is a simplified version for demonstration purposes
	// In a real scenario, you would use a library to generate permutations
	
	// Initialize a list to store the total distances for each permutation
	var distances []float64
	
	// Iterate through each permutation of indices
	for _, permutation := range generatePermutations(N) {
		total_distance := 0.0
		
		// Calculate the total distance for the current permutation
		for i := 0; i < N - 1; i++ {
			f, t := permutation[i], permutation[i + 1]  // Get the current and next index
			// Calculate the Euclidean distance between the two points
			distance := math.Sqrt(float64((x[t] - x[f]) * (x[t] - x[f]) + (y[t] - y[f]) * (y[t] - y[f])))
			total_distance += distance  // Accumulate the total distance
		}
		
		// Append the total distance for the current permutation to the list
		distances = append(distances, total_distance)
	}
	
	// Calculate the average distance across all permutations
	sumDistances := 0.0
	for _, distance := range distances {
		sumDistances += distance
	}
	result := sumDistances / float64(len(distances))
	
	// Print the average distance
	fmt.Println(result)
}

// generatePermutations generates all permutations of the indices
func generatePermutations(N int) [][]int {
	var result [][]int
	var permute func([]int, int)
	permute = func(arr []int, n int) {
		if n == 1 {
			tmp := make([]int, len(arr))
			copy(tmp, arr)
			result = append(result, tmp)
		} else {
			for i := 0; i < n; i++ {
				permute(arr, n - 1)
				if n % 2 == 1 {
					arr[0], arr[n-1] = arr[n-1], arr[0]
				} else {
					arr[i], arr[n-1] = arr[n-1], arr[i]
				}
			}
		}
	}
	arr := make([]int, N)
	for i := 0; i < N; i++ {
		arr[i] = i
	}
	permute(arr, N)
	return result
}

// main function to read input and call solve
func main() {
	// Read the number of points
	var N int
	fmt.Scan(&N)
	
	// Initialize slices to store x and y coordinates
	x := make([]int, N)
	y := make([]int, N)
	
	// Read the x and y coordinates for each point
	for i := 0; i < N; i++ {
		fmt.Scan(&x[i], &y[i])
	}
	
	// Call the solve function with the number of points and their coordinates
	solve(N, x, y)
}
