
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() {
	// Optimize input/output operations
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the number of elements in the array
	N, _ := fmt.Fscanf(reader, "%d\n", &N)

	// Initialize a slice to store the elements
	A := make([]int64, N)

	// Read the elements into the slice
	for i := 0; i < N; i++ {
		fmt.Fscanf(reader, "%d", &A[i])
	}

	// Initialize a variable to keep track of the maximum difference
	answer := int64(0)

	// Iterate through all pairs of elements to find the maximum difference
	for i := 0; i < N-1; i++ {
		for j := i + 1; j < N; j++ {
			// Calculate the absolute difference between the two elements
			diff := int64(abs(A[i]-A[j]))

			// Update the maximum difference found so far
			if diff > answer {
				answer = diff
			}
		}
	}

	// Output the maximum difference
	fmt.Fprintf(writer, "%d\n", answer)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

