package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a buffered reader for input
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements
	var N int
	fmt.Fscan(reader, &N)

	// Read the list of integers
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &A[i])
	}

	// Remove consecutive duplicates from the list
	var uniqueA []int
	for i := 0; i < N; i++ {
		if i == 0 || A[i] != A[i-1] {
			uniqueA = append(uniqueA, A[i])
		}
	}

	// Update N to the new length of uniqueA after removing duplicates
	N = len(uniqueA)

	// Initialize the index and answer counter
	i := 1
	ans := 0

	// Loop through the list to count the number of peaks and valleys
	for i < N-1 {
		// Check if the current element is a peak or a valley
		if (uniqueA[i-1] < uniqueA[i] && uniqueA[i] > uniqueA[i+1]) || (uniqueA[i-1] > uniqueA[i] && uniqueA[i] < uniqueA[i+1]) {
			ans++ // Increment the answer for each peak/valley found
			i++   // Skip the next element to avoid double counting
		}
		i++ // Move to the next element
	}

	// Print the total count of peaks and valleys plus one
	fmt.Println(ans + 1)
}

// <END-OF-CODE>
