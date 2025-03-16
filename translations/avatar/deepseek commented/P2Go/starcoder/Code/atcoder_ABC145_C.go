
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of points N
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))

	// Initialize lists for x and y coordinates
	x := make([]int, N)
	y := make([]int, N)

	// Read the x and y coordinates for each point
	for i := 0; i < N; i++ {
		x[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		y[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}

	// Call the solve function with the input values
	solve(N, x, y)
}

func solve(N int, x []int, y []int) {
	// Generate a list of indices from 0 to N-1
	indices := make([]int, N)
	for i := 0; i < N; i++ {
		indices[i] = i
	}

	// Generate all permutations of the indices
	permutations := generatePermutations(indices)

	// Initialize a list to store the total distances for each permutation
	distances := make([]float64, 0)

	// Iterate over each permutation
	for _, permutation := range permutations {
		// Initialize the total distance for the current permutation
		totalDistance := 0.0

		// Calculate the distance between consecutive points in the permutation
		for i := 0; i < N-1; i++ {
			f, t := permutation[i:i+2][0], permutation[i:i+2][1]
			distance := math.Sqrt(math.Pow(float64(x[t]-x[f]), 2) + math.Pow(float64(y[t]-y[f]), 2))
			totalDistance += distance
		}

		// Append the total distance of the current permutation to the distances list
		distances = append(distances, totalDistance)
	}

	// Calculate the average distance by averaging all stored distances
	result := sum(distances) / float64(len(distances))

	// Print the result
	fmt.Printf("%.2f\n", result)
}

func generatePermutations(indices []int) [][]int {
	// Initialize a list to store all permutations
	permutations := make([][]int, 0)

	// Generate all permutations of the indices
	for _, permutation := range permute(indices) {
		permutations = append(permutations, permutation)
	}

	// Return the list of permutations
	return permutations
}

func permute(indices []int) [][]int {
	// Initialize a list to store all permutations
	permutations := make([][]int, 0)

	// Base case: if the indices list is empty, return the list of permutations
	if len(indices) == 0 {
		return permutations
	}

	// Recursive case: iterate over each index in the indices list
	for i := 0; i < len(indices); i++ {
		// Get the current index
		index := indices[i]

		// Get the rest of the indices
		rest := indices[:i]
		rest = append(rest, indices[i+1:]...)

		// Generate all permutations of the rest of the indices
		for _, permutation := range permute(rest) {
			// Append the current index to the front of the permutation
			permutation = append([]int{index}, permutation...)

			// Append the permutation to the list of permutations
			permutations = append(permutations, permutation)
		}
	}

	// Return the list of permutations
	return permutations
}

func sum(numbers []float64) float64 {
	// Initialize the sum
	sum := 0.0

	// Iterate over each number in the list
	for _, number := range numbers {
		// Add the number to the sum
		sum += number
	}

	// Return the sum
	return sum
}

