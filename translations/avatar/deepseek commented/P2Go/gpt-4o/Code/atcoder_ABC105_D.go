package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the values of N and M from the standard input
	var N, M int
	fmt.Scan(&N, &M)

	// Read the array A from the standard input
	A := make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Calculate the cumulative remainders of the array A modulo M
	cumRemainders := make([]int64, N+1)
	cumRemainders[0] = 0
	for i := 1; i <= N; i++ {
		cumRemainders[i] = (cumRemainders[i-1] + A[i-1]) % int64(M)
	}

	// Count the occurrences of each remainder
	remainderCounts := make(map[int64]int)
	for _, remainder := range cumRemainders {
		remainderCounts[remainder]++
	}

	// Initialize the number of combinations
	combinations := int64(0)

	// Calculate the number of combinations where the difference between two remainders is a multiple of M
	for _, count := range remainderCounts {
		combinations += int64(count * (count - 1) / 2)
	}

	// Print the number of combinations
	fmt.Println(combinations)
}

// <END-OF-CODE>
