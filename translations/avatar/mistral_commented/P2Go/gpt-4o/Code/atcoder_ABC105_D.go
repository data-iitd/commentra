package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read input number of rows and columns
	var N, M int
	fmt.Scan(&N, &M)

	// Initialize slice 'A' with given dimensions
	A := make([]int64, N)
	for i := 0; i < N; i++ {
		var a int64
		fmt.Scan(&a)
		A[i] = a
	}

	// Calculate cumulative remainders
	cumRemainders := make([]int64, N+1)
	for i := 1; i <= N; i++ {
		cumRemainders[i] = (cumRemainders[i-1] + A[i-1]) % int64(M)
	}

	// Count the occurrences of each cumulative remainder
	remainderCounts := make(map[int64]int)
	for _, r := range cumRemainders {
		remainderCounts[r]++
	}

	// Calculate the number of combinations of elements having the same remainder
	combinations := int64(0)
	for _, count := range remainderCounts {
		combinations += int64(count) * (int64(count) - 1) / 2
	}

	// Print the result
	fmt.Println(combinations)
}

// <END-OF-CODE>
