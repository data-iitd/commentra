package main

import (
	"fmt"
	"sort"
)

func main() {
	// Initialize input variables
	var X, Y, Z, K int // Number of elements in slices A, B, C and the limit for output
	fmt.Scan(&X, &Y, &Z, &K) // Read input values for X, Y, Z, and K from standard input

	// Initialize slices A, B, and C
	A := make([]int64, X) // A slice of size X
	B := make([]int64, Y) // B slice of size Y
	C := make([]int64, Z) // C slice of size Z

	// Read input values for slices A, B, and C from standard input
	for i := 0; i < X; i++ {
		fmt.Scan(&A[i]) // Read each element of slice A
	}
	for i := 0; i < Y; i++ {
		fmt.Scan(&B[i]) // Read each element of slice B
	}
	for i := 0; i < Z; i++ {
		fmt.Scan(&C[i]) // Read each element of slice C
	}

	// Sort slices A, B, and C in descending order
	sort.Slice(A, func(i, j int) bool {
		return A[i] > A[j]
	})
	sort.Slice(B, func(i, j int) bool {
		return B[i] > B[j]
	})
	sort.Slice(C, func(i, j int) bool {
		return C[i] > C[j]
	})

	// Create a new slice AB by adding each element of A to each element of B
	AB := []int64{}
	for i := 0; i < X; i++ {
		for j := 0; j < Y; j++ {
			AB = append(AB, A[i]+B[j]) // Add A[i] and B[j] and append the sum into slice AB
		}
	}

	// Sort slice AB in descending order
	sort.Slice(AB, func(i, j int) bool {
		return AB[i] > AB[j]
	})

	// Create a new slice ABC by adding each element of AB to each element of C
	ABC := []int64{}
	for i := 0; i < min(K, len(AB)); i++ {
		for j := 0; j < Z; j++ {
			ABC = append(ABC, AB[i]+C[j]) // Add AB[i] and C[j] and append the sum into slice ABC
		}
	}

	// Sort slice ABC in descending order
	sort.Slice(ABC, func(i, j int) bool {
		return ABC[i] > ABC[j]
	})

	// Print K smallest elements of slice ABC
	for i := 0; i < K; i++ {
		fmt.Println(ABC[i]) // Print each element of slice ABC
	}
}

// Helper function to get the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
