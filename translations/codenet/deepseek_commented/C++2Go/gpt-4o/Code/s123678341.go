package main

import (
	"fmt"
	"sort"
)

func main() {
	// Step 1: Reading Inputs
	var X, Y, Z, K int
	fmt.Scan(&X, &Y, &Z, &K)

	// Step 2: Slice Initialization and Input
	A := make([]int64, X)
	B := make([]int64, Y)
	C := make([]int64, Z)

	for i := 0; i < X; i++ {
		fmt.Scan(&A[i])
	}
	for i := 0; i < Y; i++ {
		fmt.Scan(&B[i])
	}
	for i := 0; i < Z; i++ {
		fmt.Scan(&C[i])
	}

	// Step 3: Sorting
	sort.Slice(A, func(i, j int) bool {
		return A[i] > A[j]
	})
	sort.Slice(B, func(i, j int) bool {
		return B[i] > B[j]
	})
	sort.Slice(C, func(i, j int) bool {
		return C[i] > C[j]
	})

	// Step 4: Combining A and B
	AB := []int64{}
	for i := 0; i < X; i++ {
		for j := 0; j < Y; j++ {
			AB = append(AB, A[i]+B[j])
		}
	}

	// Step 5: Sorting AB
	sort.Slice(AB, func(i, j int) bool {
		return AB[i] > AB[j]
	})

	// Step 6: Combining AB and C
	ABC := []int64{}
	for i := 0; i < min(K, len(AB)); i++ {
		for j := 0; j < Z; j++ {
			ABC = append(ABC, AB[i]+C[j])
		}
	}

	// Step 7: Sorting ABC
	sort.Slice(ABC, func(i, j int) bool {
		return ABC[i] > ABC[j]
	})

	// Step 8: Output
	for i := 0; i < K; i++ {
		fmt.Println(ABC[i])
	}
}

// Helper function to get the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
