// Package main is the entry point for the program.
package main

// Import necessary libraries
import (
	"fmt"
	"math"
)

// Function to find the solution
func solve(N int, x []int, y []int) {
	// Initialize an empty list to store distances
	distances := []float64{}

	// Generate all possible permutations of indices from 0 to N-1
	indices := make([]int, N)
	for i := 0; i < N; i++ {
		indices[i] = i
	}
	permutations := make([][]int, 0)
	for i := 0; i < N; i++ {
		for j := i + 1; j < N; j++ {
			for k := j + 1; k < N; k++ {
				permutations = append(permutations, []int{i, j, k})
			}
		}
	}

	// For each permutation, calculate the total distance between adjacent points
	for _, permutation := range permutations {
		totalDistance := 0.0
		for i := 0; i < N-1; i++ {
			// Get the first and second indices of the current pair
			f, t := permutation[i], permutation[i+1]
			// Calculate the Euclidean distance between the points (x[f], y[f]) and (x[t], y[t])
			distance := math.Sqrt(math.Pow(float64(x[t]-x[f]), 2) + math.Pow(float64(y[t]-y[f]), 2))
			// Add the distance to the total distance
			totalDistance += distance
		}
		// Append the total distance to the distances list
		distances = append(distances, totalDistance)
	}

	// Calculate the average distance from all permutations
	result := 0.0
	for _, distance := range distances {
		result += distance
	}
	result /= float64(len(distances))

	// Print the result
	fmt.Println(result)
}

// Main function to read input and call the solve function
func main() {
	// Function to read tokens from standard input
	iterateTokens := func() func() string {
		scanner := bufio.NewScanner(os.Stdin)
		scanner.Split(bufio.ScanWords)
		return func() string {
			scanner.Scan()
			return scanner.Text()
		}
	}

	// Read the number of points and their coordinates from input
	tokens := iterateTokens()
	N, _ := strconv.Atoi(tokens())
	x := make([]int, N)
	y := make([]int, N)
	for i := 0; i < N; i++ {
		x[i], _ = strconv.Atoi(tokens())
		y[i], _ = strconv.Atoi(tokens())
	}

	// Call the solve function with the given input
	solve(N, x, y)
}

// END-OF-CODE
