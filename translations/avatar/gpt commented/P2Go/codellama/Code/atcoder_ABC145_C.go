package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func solve(N int, x []int, y []int) {
	// Create a list of indices from 0 to N-1
	indices := make([]int, N)
	for i := 0; i < N; i++ {
		indices[i] = i
	}

	// Generate all possible permutations of the indices
	permutations := permutations(indices)

	// Initialize a list to store the total distances for each permutation
	distances := make([]float64, 0)

	// Iterate through each permutation of indices
	for _, permutation := range permutations {
		totalDistance := 0.0

		// Calculate the total distance for the current permutation
		for i := 0; i < N-1; i++ {
			f, t := permutation[i], permutation[i+1] // Get the current and next index
			// Calculate the Euclidean distance between the two points
			distance := math.Sqrt(math.Pow(float64(x[t]-x[f]), 2) + math.Pow(float64(y[t]-y[f]), 2))
			totalDistance += distance // Accumulate the total distance
		}

		// Append the total distance for the current permutation to the list
		distances = append(distances, totalDistance)
	}

	// Calculate the average distance across all permutations
	result := sum(distances) / float64(len(distances))

	// Print the average distance
	fmt.Println(result)
}

func permutations(indices []int) [][]int {
	// Generate all possible permutations of the indices
	permutations := make([][]int, 0)
	for i := 0; i < len(indices); i++ {
		for j := i + 1; j < len(indices); j++ {
			for k := j + 1; k < len(indices); k++ {
				permutations = append(permutations, []int{indices[i], indices[j], indices[k]})
			}
		}
	}
	return permutations
}

func sum(distances []float64) float64 {
	// Calculate the sum of the distances
	sum := 0.0
	for _, distance := range distances {
		sum += distance
	}
	return sum
}

func main() {
	// Generator function to iterate over tokens from standard input
	iterateTokens := func() <-chan string {
		ch := make(chan string)
		go func() {
			for _, line := range strings.Split(os.Getenv("INPUT"), "\n") {
				for _, word := range strings.Split(line, " ") {
					ch <- word
				}
			}
			close(ch)
		}()
		return ch
	}

	// Create an iterator for the input tokens
	tokens := iterateTokens()

	// Read the number of points
	N, _ := strconv.Atoi(<-tokens)

	// Initialize lists to store x and y coordinates
	x := make([]int, N)
	y := make([]int, N)

	// Read the x and y coordinates for each point
	for i := 0; i < N; i++ {
		x[i], _ = strconv.Atoi(<-tokens)
		y[i], _ = strconv.Atoi(<-tokens)
	}

	// Call the solve function with the number of points and their coordinates
	solve(N, x, y)
}

// Entry point of the program
func main() {
	main()
}

