
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements in the array from standard input
	N, _ := strconv.Atoi(strings.TrimSpace(os.Args[1]))

	// Allocate memory for the array A of size N
	A := make([]int, N)

	// Read each element of the array A from standard input
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(strings.TrimSpace(os.Args[i+2]))
	}

	// Check if the conditions for a possible solution are met
	if possible(N, A) {
		// Print "YES" if the conditions are met
		fmt.Println("YES")
	} else {
		// Print "NO" if the conditions are not met
		fmt.Println("NO")
	}
}

// Check if the given conditions for a possible solution are met
func possible(N int, A []int) bool {
	sum := 0 // Initialize sum to 0

	// Calculate the sum of all elements in the array A
	for i := 0; i < N; i++ {
		sum += A[i]
	}

	// Calculate the expected sum based on the number of elements in the array
	NS := (N * (N + 1)) / 2

	// Check if the sum of all elements is equal to the expected sum
	if sum%NS != 0 {
		return false
	}

	// Calculate the common difference between consecutive elements
	K := sum / NS

	// Check each pair of consecutive elements to see if their difference is valid
	for i := 0; i < N; i++ {
		j := (i == 0) ? (N - 1) : (i - 1)
		d := K - (A[i] - A[j]) // Calculate the difference

		// Check if the difference is valid
		if d < 0 || d%N != 0 {
			return false
		}
	}

	// If all checks pass, return true
	return true
}

