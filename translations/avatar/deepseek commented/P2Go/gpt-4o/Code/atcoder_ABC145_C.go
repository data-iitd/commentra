package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func solve(N int, x []int, y []int) {
	// Generate a list of indices from 0 to N-1
	indices := make([]int, N)
	for i := 0; i < N; i++ {
		indices[i] = i
	}

	// Initialize a slice to store the total distances for each permutation
	var distances []float64

	// Generate all permutations of the indices
	permutations := permute(indices)

	// Iterate over each permutation
	for _, permutation := range permutations {
		// Initialize the total distance for the current permutation
		totalDistance := 0.0

		// Calculate the distance between consecutive points in the permutation
		for i := 0; i < N-1; i++ {
			f := permutation[i]
			t := permutation[i+1]
			distance := math.Sqrt(float64((x[t]-x[f])*(x[t]-x[f]) + (y[t]-y[f])*(y[t]-y[f])))
			totalDistance += distance
		}

		// Append the total distance of the current permutation to the distances slice
		distances = append(distances, totalDistance)
	}

	// Calculate the average distance by averaging all stored distances
	var sum float64
	for _, d := range distances {
		sum += d
	}
	result := sum / float64(len(distances))

	// Print the result
	fmt.Println(result)
}

func permute(arr []int) [][]int {
	var result [][]int
	permuteHelper(arr, 0, &result)
	return result
}

func permuteHelper(arr []int, start int, result *[][]int) {
	if start == len(arr)-1 {
		// Make a copy of the current permutation and add it to the result
		perm := make([]int, len(arr))
		copy(perm, arr)
		*result = append(*result, perm)
		return
	}
	for i := start; i < len(arr); i++ {
		arr[start], arr[i] = arr[i], arr[start] // Swap
		permuteHelper(arr, start+1, result)
		arr[start], arr[i] = arr[i], arr[start] // Swap back
	}
}

func main() {
	var N int
	fmt.Scan(&N)

	// Initialize slices for x and y coordinates
	x := make([]int, N)
	y := make([]int, N)

	// Read the x and y coordinates for each point
	for i := 0; i < N; i++ {
		fmt.Scan(&x[i], &y[i])
	}

	// Call the solve function with the input values
	solve(N, x, y)
}

// <END-OF-CODE>
