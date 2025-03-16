
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func solve(N int, x []int, y []int) {
	// Create a list of indices from 0 to N-1
	indices := make([]int, N)
	for i := range indices {
		indices[i] = i
	}

	// Generate all possible permutations of the indices
	permutations := make([][]int, 0)
	generatePermutations(indices, 0, &permutations)

	// Initialize a list to store the total distances for each permutation
	distances := make([]float64, 0)

	// Iterate through each permutation of indices
	for _, permutation := range permutations {
		totalDistance := 0.0

		// Calculate the total distance for the current permutation
		for i := 0; i < N-1; i++ {
			f := permutation[i]
			t := permutation[i+1]

			// Calculate the Euclidean distance between the two points
			distance := math.Sqrt(math.Pow(float64(x[t]-x[f]), 2) + math.Pow(float64(y[t]-y[f]), 2))
			totalDistance += distance // Accumulate the total distance
		}

		// Append the total distance for the current permutation to the list
		distances = append(distances, totalDistance)
	}

	// Calculate the average distance across all permutations
	result := 0.0
	for _, distance := range distances {
		result += distance
	}
	result /= float64(len(distances))

	// Print the average distance
	fmt.Println(result)
}

func generatePermutations(indices []int, start int, permutations *[][]int) {
	if start == len(indices)-1 {
		*permutations = append(*permutations, append([]int{}, indices...))
	} else {
		for i := start; i < len(indices); i++ {
			indices[start], indices[i] = indices[i], indices[start]
			generatePermutations(indices, start+1, permutations)
			indices[start], indices[i] = indices[i], indices[start]
		}
	}
}

func main() {
	// Read input from standard input
	reader := bufio.NewReader(os.Stdin)

	// Read the number of points
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Initialize lists to store x and y coordinates
	x := make([]int, N)
	y := make([]int, N)

	// Read the x and y coordinates for each point
	for i := 0; i < N; i++ {
		x[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
		y[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}

	// Call the solve function with the number of points and their coordinates
	solve(N, x, y)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

