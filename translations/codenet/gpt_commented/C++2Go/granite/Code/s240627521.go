
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Read the number of elements
	N := readInt()

	// Initialize a slice to store the elements
	A := make([]int, N)

	// Input the elements into the slice
	for i := 0; i < N; i++ {
		A[i] = readInt()
	}

	// Sort the slice in descending order
	sort.Slice(A, func(i, j int) bool {
		return A[i] > A[j]
	})

	// Initialize variables to track the minimum difference and the corresponding index
	index := 0
	max := 1 << 30

	// Find the element in the slice that minimizes the difference with twice the second largest element
	for i := 1; i < N; i++ {
		// Calculate the absolute difference and update if it's smaller than the current max
		if diff := abs(A[0]-2*A[i]); diff < max {
			max = diff
			index = i // Store the index of the element that gives the minimum difference
		}
	}

	// Output the largest element and the element that minimizes the difference
	fmt.Printf("%d %d\n", A[0], A[index])
}

func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

