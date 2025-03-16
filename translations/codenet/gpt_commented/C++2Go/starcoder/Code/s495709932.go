package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Optimize input/output operations
	// Read the number of elements in the array
	N, _ := strconv.Atoi(strings.TrimSpace(os.Args[1]))

	// Initialize a vector to store the elements
	A := make([]int, N)

	// Read the elements into the vector
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(strings.TrimSpace(os.Args[i+2]))
	}

	// Initialize a variable to keep track of the maximum difference
	answer := 0

	// Iterate through all pairs of elements to find the maximum difference
	for i := 0; i < N-1; i++ {
		for j := i + 1; j < N; j++ {
			// Calculate the absolute difference between the two elements
			diff := int(math.Abs(float64(A[i] - A[j])))

			// Update the maximum difference found so far
			answer = int(math.Max(float64(answer), float64(diff)))
		}
	}

	// Output the maximum difference
	fmt.Println(answer)
}

