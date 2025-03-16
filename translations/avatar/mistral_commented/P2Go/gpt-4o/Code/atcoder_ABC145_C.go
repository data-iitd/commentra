package main

import (
	"fmt"
	"math"
	"os"
)

// Function to find the solution
func solve(N int, x []int, y []int) {
	// Initialize a slice to store distances
	var distances []float64

	// Generate all possible permutations of indices from 0 to N-1
	indices := make([]int, N)
	for i := 0; i < N; i++ {
		indices[i] = i
	}

	// Function to calculate permutations
	var permute func([]int, int)
	permute = func(arr []int, n int) {
		if n == 1 {
			totalDistance := 0.0
			for i := 0; i < N-1; i++ {
				f, t := arr[i], arr[i+1]
				distance := math.Sqrt(float64((x[t]-x[f])*(x[t]-x[f]) + (y[t]-y[f])*(y[t]-y[f])))
				totalDistance += distance
			}
			distances = append(distances, totalDistance)
			return
		}
		for i := 0; i < n; i++ {
			permute(arr, n-1)
			if n%2 == 1 {
				arr[0], arr[n-1] = arr[n-1], arr[0]
			} else {
				arr[i], arr[n-1] = arr[n-1], arr[i]
			}
		}
	}

	// Generate permutations
	permute(indices, N)

	// Calculate the average distance from all permutations
	sum := 0.0
	for _, distance := range distances {
		sum += distance
	}
	result := sum / float64(len(distances))

	// Print the result
	fmt.Println(result)
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

// <END-OF-CODE>
