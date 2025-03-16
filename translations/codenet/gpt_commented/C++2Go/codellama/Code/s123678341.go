package main

import (
	"fmt"
	"sort"
)

func main() {
	// Input the sizes of the three arrays and the number K
	var X, Y, Z, K int
	fmt.Scan(&X, &Y, &Z, &K)

	// Declare slices to hold the input values
	A := make([]int, X)
	B := make([]int, Y)
	C := make([]int, Z)

	// Read values into slice A
	for i := range A {
		fmt.Scan(&A[i])
	}

	// Read values into slice B
	for i := range B {
		fmt.Scan(&B[i])
	}

	// Read values into slice C
	for i := range C {
		fmt.Scan(&C[i])
	}

	// Sort the slices in descending order to facilitate maximum sum calculations
	sort.Slice(A, func(i, j int) bool { return A[i] > A[j] })
	sort.Slice(B, func(i, j int) bool { return B[i] > B[j] })
	sort.Slice(C, func(i, j int) bool { return C[i] > C[j] })

	// Create a slice to store the sums of elements from A and B
	AB := make([]int, 0)

	// Calculate all possible sums of elements from A and B
	for i := 0; i < X; i++ {
		for j := 0; j < Y; j++ {
			AB = append(AB, A[i]+B[j])
		}
	}

	// Sort the sums in descending order
	sort.Slice(AB, func(i, j int) bool { return AB[i] > AB[j] })

	// Create a slice to store the final sums including elements from C
	ABC := make([]int, 0)

	// Calculate sums of the top K elements from AB with each element from C
	for i := 0; i < min(K, len(AB)); i++ {
		for j := 0; j < Z; j++ {
			ABC = append(ABC, AB[i]+C[j])
		}
	}

	// Sort the final sums in descending order
	sort.Slice(ABC, func(i, j int) bool { return ABC[i] > ABC[j] })

	// Output the top K sums from the final slice
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

