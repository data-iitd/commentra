package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of points
	N, _ := strconv.Atoi(readLine())

	// Initialize lists to store x and y coordinates
	x := make([]int, N)
	y := make([]int, N)

	// Read the x and y coordinates for each point
	for i := 0; i < N; i++ {
		x[i], _ = strconv.Atoi(readLine())
		y[i], _ = strconv.Atoi(readLine())
	}

	// Call the solve function with the number of points and their coordinates
	solve(N, x, y)
}

// ReadLine reads a string line from stdin
func readLine() string {
	r := bufio.NewReader(os.Stdin)
	line, _, _ := r.ReadLine()
	return strings.TrimRight(string(line), "\r\n")
}

// Solve the problem
func solve(N int, x []int, y []int) {
	// Create a list of indices from 0 to N-1
	indices := make([]int, N)
	for i := 0; i < N; i++ {
		indices[i] = i
	}

	// Generate all possible permutations of the indices
	permutations := generatePermutations(indices)

	// Initialize a list to store the total distances for each permutation
	distances := make([]float64, len(permutations))

	// Iterate through each permutation of indices
	for i, permutation := range permutations {
		totalDistance := 0.0

		// Calculate the total distance for the current permutation
		for j := 0; j < N - 1; j++ {
			f, t := permutation[j:j+2]  // Get the current and next index
			// Calculate the Euclidean distance between the two points
			distance := math.Sqrt(float64((x[t] - x[f]) * (x[t] - x[f]) + (y[t] - y[f]) * (y[t] - y[f])))
			totalDistance += distance  // Accumulate the total distance

		}

		// Append the total distance for the current permutation to the list
		distances[i] = totalDistance
	}

	// Calculate the average distance across all permutations
	result := sum(distances) / float64(len(distances))

	// Print the average distance
	fmt.Printf("%.2f\n", result)
}

// GeneratePermutations generates all possible permutations of the given list
func generatePermutations(list []int) [][]int {
	permutations := make([][]int, 0)

	// Generate all possible permutations of the indices
	for i := 0; i < len(list); i++ {
		for j := i + 1; j < len(list); j++ {
			for k := j + 1; k < len(list); k++ {
				permutations = append(permutations, []int{list[i], list[j], list[k]})
			}
		}
	}

	return permutations
}

// Sum returns the sum of the given list of numbers
func sum(numbers []float64) float64 {
	result := 0.0
	for _, number := range numbers {
		result += number
	}
	return result
}

// 