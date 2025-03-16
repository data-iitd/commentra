package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	// Reading number of elements
	var N int
	fmt.Scan(&N)

	// Reading list of elements
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Removing consecutive duplicates from list A
	A = A[:len(A)-1]
	for i := 1; i < len(A); i++ {
		if A[i] == A[i-1] {
			A = append(A[:i], A[i+1:]...)
			i--
		}
	}

	// Initializing variables for main logic
	i := 1
	ans := 0

	// Main logic to find peaks
	for i < len(A)-1 {
		if A[i-1] < A[i] && A[i] > A[i+1] || A[i-1] > A[i] && A[i] < A[i+1] {
			ans++
			i++
		}
		i++
	}

	// Output the total number of peaks found
	fmt.Println(ans + 1)
}

