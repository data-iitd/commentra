
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Function to read tokens from standard input
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read the number of points and their coordinates from input
	N := nextInt(scanner)
	x := make([]int, N)
	y := make([]int, N)
	for i := 0; i < N; i++ {
		x[i] = nextInt(scanner)
		y[i] = nextInt(scanner)
	}

	// Call the solve function with the given input
	solve(N, x, y)
}

func solve(N int, x []int, y []int) {
	// Initialize an empty list to store distances
	distances := make([]float64, 0)

	// Generate all possible permutations of indices from 0 to N-1
	indices := make([]int, N)
	for i := 0; i < N; i++ {
		indices[i] = i
	}
	permutations := make([][]int, 0)
	generatePermutations(indices, 0, &permutations)

	// For each permutation, calculate the total distance between adjacent points
	for _, permutation := range permutations {
		totalDistance := 0.0
		for i := 0; i < N-1; i++ {
			// Get the first and second indices of the current pair
			f := permutation[i]
			t := permutation[i+1]
			// Calculate the Euclidean distance between the points (x[f], y[f]) and (x[t], y[t])
			distance := float64(((x[t]-x[f])*(x[t]-x[f])) + ((y[t]-y[f])*(y[t]-y[f])))
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

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, err := strconv.Atoi(scanner.Text())
	if err!= nil {
		panic(err)
	}
	return num
}

