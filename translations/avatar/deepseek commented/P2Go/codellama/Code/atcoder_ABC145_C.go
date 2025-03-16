
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

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
			f, t := permutation[i], permutation[i+1]
			distance := math.Sqrt(math.Pow(float64(x[t]-x[f]), 2) + math.Pow(float64(y[t]-y[f]), 2))
			totalDistance += distance
		}

		// Append the total distance of the current permutation to the distances list
		distances = append(distances, totalDistance)
	}

	// Calculate the average distance by averaging all stored distances
	result := sum(distances) / float64(len(distances))

	// Print the result
	fmt.Println(result)
}

func generatePermutations(indices []int) [][]int {
	// Initialize a list to store the permutations
	permutations := make([][]int, 0)

	// Iterate over each index in the indices list
	for i := 0; i < len(indices); i++ {
		// Generate all permutations of the remaining indices
		remainingIndices := make([]int, len(indices)-1)
		copy(remainingIndices, indices)
		remainingIndices = append(remainingIndices[:i], remainingIndices[i+1:]...)
		remainingPermutations := generatePermutations(remainingIndices)

		// Append the current index to each permutation in the remaining permutations list
		for _, permutation := range remainingPermutations {
			permutation = append(permutation, indices[i])
			permutations = append(permutations, permutation)
		}
	}

	// If there are no remaining indices, return a list with a single empty permutation
	if len(indices) == 0 {
		permutations = append(permutations, []int{})
	}

	// Return the permutations list
	return permutations
}

func sum(numbers []float64) float64 {
	// Initialize the sum to 0
	sum := 0.0

	// Iterate over each number in the numbers list
	for _, number := range numbers {
		// Add the current number to the sum
		sum += number
	}

	// Return the sum
	return sum
}

func main() {
	// Function to iterate over tokens in the input
	iterateTokens := func() func() string {
		// Read the input from stdin
		reader := bufio.NewReader(os.Stdin)

		// Function to iterate over tokens in the input
		nextToken := func() string {
			// Read a line from the input
			line, _ := reader.ReadString('\n')

			// Split the line into words
			words := strings.Fields(line)

			// Return the next word in the list
			return words[0]
		}

		// Return the nextToken function
		return nextToken
	}()

	// Get the tokens from the input
	tokens := iterateTokens()

	// Read the number of points N
	N, _ := strconv.Atoi(tokens())

	// Initialize lists for x and y coordinates
	x := make([]int, N)
	y := make([]int, N)

	// Read the x and y coordinates for each point
	for i := 0; i < N; i++ {
		x[i], _ = strconv.Atoi(tokens())
		y[i], _ = strconv.Atoi(tokens())
	}

	// Call the solve function with the input values
	solve(N, x, y)
}

