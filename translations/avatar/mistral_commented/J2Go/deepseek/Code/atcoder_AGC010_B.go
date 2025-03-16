package main

import (
	"fmt"
)

func main() {
	// Read the number of elements in the array from standard input
	var N int
	fmt.Scan(&N)

	// Allocate memory for the array A of size N
	A := make([]int, N)

	// Read each element of the array A from standard input
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
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
	var sum int64 = 0 // Initialize sum to 0

	// Calculate the sum of all elements in the array A
	for i := 0; i < N; i++ {
		sum += int64(A[i])
	}

	// Calculate the expected sum based on the number of elements in the array
	var NS int64 = int64(N) * int64(N+1) / 2

	// Check if the sum of all elements is equal to the expected sum
	if sum%NS != 0 {
		return false
	}

	// Calculate the common difference between consecutive elements
	var K int64 = sum / NS

	// Check each pair of consecutive elements to see if their difference is valid
	for i := 0; i < N; i++ {
		j := i - 1
		if i == 0 {
			j = N - 1
		}
		d := K - int64(A[i]-A[j]) // Calculate the difference

		// Check if the difference is valid
		if d < 0 || d%int64(N) != 0 {
			return false
		}
	}

	// If all checks pass, return true
	return true
}

