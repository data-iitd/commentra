package main

import (
	"fmt"
	"sort"
)

func main() {
	// Step 1: Reading Inputs
	var X, Y, Z, K int
	fmt.Scan(&X, &Y, &Z, &K)

	// Step 2: Vector Initialization and Input
	A := make([]int, X)
	B := make([]int, Y)
	C := make([]int, Z)
	for i := range A {
		fmt.Scan(&A[i])
	}
	for i := range B {
		fmt.Scan(&B[i])
	}
	for i := range C {
		fmt.Scan(&C[i])
	}

	// Step 3: Sorting
	sort.Slice(A, func(i, j int) bool { return A[i] > A[j] })
	sort.Slice(B, func(i, j int) bool { return B[i] > B[j] })
	sort.Slice(C, func(i, j int) bool { return C[i] > C[j] })

	// Step 4: Combining A and B
	AB := make([]int, 0, X*Y)
	for i := 0; i < X; i++ {
		for j := 0; j < Y; j++ {
			AB = append(AB, A[i]+B[j])
		}
	}

	// Step 5: Sorting AB
	sort.Slice(AB, func(i, j int) bool { return AB[i] > AB[j] })

	// Step 6: Combining AB and C
	ABC := make([]int, 0, K)
	for i := 0; i < min(K, len(AB)); i++ {
		for j := 0; j < Z; j++ {
			ABC = append(ABC, AB[i]+C[j])
		}
	}

	// Step 7: Sorting ABC
	sort.Slice(ABC, func(i, j int) bool { return ABC[i] > ABC[j] })

	// Step 8: Output
	for i := 0; i < K; i++ {
		fmt.Println(ABC[i])
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

