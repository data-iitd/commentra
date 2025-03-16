package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the values of N and M from standard input
	var N, M int
	fmt.Scan(&N, &M)

	// Read the array A from standard input
	A := make([]int64, N)
	for i := 0; i < N; i++ {
		var a int64
		fmt.Scan(&a)
		A[i] = a
	}

	// Calculate cumulative remainders of the array A when divided by M
	cumRemainders := make([]int64, N+1)
	cumRemainders[0] = 0
	for i := 1; i <= N; i++ {
		cumRemainders[i] = (cumRemainders[i-1] + A[i-1]) % int64(M)
	}

	// Count the occurrences of each remainder using a map
	remainderCounts := make(map[int64]int)
	for _, remainder := range cumRemainders {
		remainderCounts[remainder]++
	}

	// Initialize a variable to count the number of valid combinations
	combinations := int64(0)

	// Calculate the number of combinations of indices that have the same remainder
	for _, count := range remainderCounts {
		combinations += count * (count - 1) / 2 // Combinations of 2 from count
	}

	// Output the total number of combinations found
	fmt.Println(combinations)
}

// <END-OF-CODE>
